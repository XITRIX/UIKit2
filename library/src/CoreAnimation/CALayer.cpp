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

    auto currentFrame = frame();

    // Background color
    context->beginPath();
    context->setFillColor(backgroundColor);
    context->fill(currentFrame, cornerRadius(), true);

    // Contents
    if (m_contents) {
        auto contentsGravity = ContentsGravityTransformation(this);
//        GPU_SetAnchor(m_contents->pointee, _anchorPoint.x, _anchorPoint.y);
//        GPU_SetRGBA(m_contents->pointee, 255, 255, 255, _opacity * 255);
//
//        GPU_BlitTransform(
//                m_contents->pointee,
//                NULL,
//                renderer,
//                contentsGravity.offset.x,
//                contentsGravity.offset.y,
//                0, // rotation in degrees
//                contentsGravity.scale.width / contentsScale,
//                contentsGravity.scale.height / contentsScale
//        );
//
//        // False attempt
//        context->drawImage(m_contents->textureID(), {
//                contentsGravity.offset.x,
//                contentsGravity.offset.y,
//                contentsGravity.scale.width / contentsScale,
//                contentsGravity.scale.height / contentsScale
//        });
//
        context->drawImage(m_contents->textureID(), {currentFrame});
    }

    context->translateBy(currentFrame.minX(), currentFrame.minY());

    for (auto layer: sublayers()) {
        layer->draw();
    }

    context->restore();
}

void CALayer::addSublayer(CALayer* layer) {
    m_sublayers.push_back(layer);
}