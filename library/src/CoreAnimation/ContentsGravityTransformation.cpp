//
// Created by Даниил Виноградов on 01.10.2023.
//

#include <CoreAnimation/ContentsGravityTransformation.hpp>
#include <CoreAnimation/CALayer.hpp>

ContentsGravityTransformation::ContentsGravityTransformation(CALayer* layer) {
    auto scaledContents = CGSize(
            layer->contents()->size().width / layer->contentsScale,
            layer->contents()->size().height / layer->contentsScale
    );

    auto bounds = layer->bounds();

    auto distanceToMinX = -((bounds.width() - scaledContents.width) * layer->anchorPoint().x);
    auto distanceToMinY = -((bounds.height() - scaledContents.height) * layer->anchorPoint().y);
    auto distanceToMaxX = (bounds.width() - scaledContents.width) * (1 - layer->anchorPoint().x);
    auto distanceToMaxY = (bounds.height() - scaledContents.height) * (1 - layer->anchorPoint().y);

    switch (layer->contentsGravity) {
        case CALayerContentsGravity::resize: {
            this->offset = CGPoint::zero;
            scale = CGSize(bounds.width() / scaledContents.width, bounds.height() / scaledContents.height);
            break;
        }
        case CALayerContentsGravity::resizeAspectFill: {
            offset = CGPoint::zero;
            auto maxScale = std::max(bounds.width() / scaledContents.width, bounds.height() / scaledContents.height);
            scale = CGSize(maxScale, maxScale);
            break;
        }
        case CALayerContentsGravity::resizeAspect: {
            offset = CGPoint::zero;
            auto minScale = std::min(bounds.width() / scaledContents.width, bounds.height() / scaledContents.height);
            scale = CGSize(minScale, minScale);
            break;
        }
        case CALayerContentsGravity::center: {
            offset = CGPoint::zero;
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::left: {
            offset = CGPoint(distanceToMinX, 0.0);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::right: {
            offset = CGPoint(distanceToMaxX, 0.0);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::top: {
            offset = CGPoint(0.0, distanceToMinY);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::bottom: {
            offset = CGPoint(0.0, distanceToMaxY);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::topLeft: {
            offset = CGPoint(distanceToMinX, distanceToMinY);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::topRight: {
            offset = CGPoint(distanceToMaxX, distanceToMinY);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::bottomLeft: {
            offset = CGPoint(distanceToMinX, distanceToMaxY);
            scale = defaultScale;
            break;
        }
        case CALayerContentsGravity::bottomRight: {
            offset = CGPoint(distanceToMaxX, distanceToMaxY);
            scale = defaultScale;
            break;
        }
    }
}
