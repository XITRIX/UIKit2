//
// Created by Даниил Виноградов on 01.10.2023.
//

#pragma once

#include <CoreGraphics/Geometry.hpp>

enum class CALayerContentsGravity {
    bottom, bottomLeft, bottomRight,
    center, left, right,
    top, topLeft, topRight,
    resize, resizeAspect, resizeAspectFill
};

class CALayer;
struct ContentsGravityTransformation {
    CGPoint offset;
    CGSize scale;
    CGSize size;

    explicit ContentsGravityTransformation(CALayer* layer);

private:
    CGSize defaultScale = CGSize(1.0, 1.0);
};