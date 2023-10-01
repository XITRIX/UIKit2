//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreAnimation/CALayer.hpp>
#include <CoreGraphics/CGContext.hpp>

CGRect CALayer::frame() {
    // Create a rectangle based on `bounds.size` * `transform` at `position` offset by `anchorPoint`
    auto transformedBounds = m_bounds.applying(m_transform);

    auto anchorPointOffset = CGPoint(
            transformedBounds.width() * m_anchorPoint.x,
            transformedBounds.height() * m_anchorPoint.y
    );

    return {m_position.x - anchorPointOffset.x,
            m_position.y - anchorPointOffset.y,
            transformedBounds.width(),
            transformedBounds.height()};
}

void CALayer::setFrame(CGRect frame) {
    setPosition(CGPoint(frame.origin.x + (frame.width() * m_anchorPoint.x),
                      frame.origin.y + (frame.height() * m_anchorPoint.y)));

    auto inverseTransformOpt = affineTransform().inverted();
    if (!inverseTransformOpt.has_value()) {
//        assertionFailure("You tried to set the frame of a CALayer whose transform cannot be inverted. This is undefined behaviour.");
        return;
    }
    auto inverseTransform = inverseTransformOpt.value();


    // If we are shrinking the view with a transform and then setting a
    // new frame, the layer's actual `bounds` is bigger (and vice-versa):
    auto nonTransformedBoundSize = frame.applying(inverseTransform).size;

    auto bounds = m_bounds;
    bounds.size = nonTransformedBoundSize;
    setBounds(bounds);
}

CGAffineTransform CALayer::affineTransform() const {
    return CATransform3DGetAffineTransform(m_transform);
}

void CALayer::setAffineTransform(CGAffineTransform transform) {
    this->setTransform(CATransform3DMakeAffineTransform(transform));
}

void CALayer::draw() {
    auto context = CGContext::current;
    context->save();

    // The basis for all our transformations is `position` (in parent coordinates), which in this layer's
    // coordinates is `anchorPoint`. To make this happen, we translate (in our parent's coordinate system
    // – which may in turn be affected by its parents, and so on) to `position`, and then render rectangles
    // which may (and often do) start at a negative `origin` based on our (bounds) `size` and `anchorPoint`:
    auto parentOriginTransform = CATransform3DMakeAffineTransform(context->ctm());
    auto translationToPosition = CATransform3DMakeTranslation(m_position.x, m_position.y, m_zPosition);
    auto transformAtPositionInParentCoordinates = parentOriginTransform * translationToPosition;

    auto modelViewTransform = transformAtPositionInParentCoordinates * m_transform;

    // Now that we're in our own coordinate system based around `anchorPoint` (which is generally the middle of
    // bounds.size), we need to find the top left of the rectangle in order to be able to render rectangles.
    // Since we have already applied our own `transform`, we can work in our own (`bounds.size`) units.
    auto deltaFromAnchorPointToOrigin = CGPoint(-(m_bounds.width() * m_anchorPoint.x),
                                              -(m_bounds.height() * m_anchorPoint.y));
    auto renderedBoundsRelativeToAnchorPoint = CGRect(deltaFromAnchorPointToOrigin, m_bounds.size);

    // Big performance optimization. Don't render anything that's entirely offscreen:
    auto rendererBounds = CGRect(0, 0, (CGFloat) context->width(), (CGFloat) context->height());
    auto absoluteFrame = renderedBoundsRelativeToAnchorPoint.applying(modelViewTransform);
    if (!absoluteFrame.intersects(rendererBounds)) { return; }

    context->setCtm(CATransform3DGetAffineTransform(modelViewTransform));

    // `position` is always relative from the parent's origin, but the global GPU matrix is currently
    // focused on `self.position` rather than the `origin` we calculated to render rectangles.
    // We need to be at `origin` here though so we can translate to the next `position` in each sublayer.
    //
    // We also subtract `bounds` to get the strange but useful scrolling effect as on iOS.
    auto translationFromAnchorPointToOrigin = CATransform3DMakeTranslation(
            deltaFromAnchorPointToOrigin.x - m_bounds.origin.x,
            deltaFromAnchorPointToOrigin.y - m_bounds.origin.y,
            0 // If we moved (e.g.) forward to render `self`, all sublayers should start at that same zIndex
    );

    // This transform is referred to as the `parentOriginTransform` in our sublayers (see above):
    auto transformAtSelfOrigin = modelViewTransform * translationFromAnchorPointToOrigin;

    // Background color
    context->beginPath();
    context->setFillColor(backgroundColor);
    context->fill(renderedBoundsRelativeToAnchorPoint, cornerRadius(), true);

    // Contents
    if (m_contents) {
        auto contentsGravityValues = ContentsGravityTransformation(this);

        auto size = contentsGravityValues.size / contentsScale;
        auto position = CGPoint(contentsGravityValues.offset.x - size.width / 2,
                                contentsGravityValues.offset.y - size.height / 2);

        context->drawImage(m_contents->textureID(), {
                position.x,
                position.y,
                size.width,
                size.height
        });
    }

    context->save();
    context->setCtm(CATransform3DGetAffineTransform(transformAtSelfOrigin));
    for (auto layer: sublayers()) {
        layer->draw();
    }
    context->restore();

    context->restore();
}

void CALayer::addSublayer(CALayer* layer) {
    m_sublayers.push_back(layer);
}