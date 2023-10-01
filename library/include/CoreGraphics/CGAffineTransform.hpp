//
// Created by Даниил Виноградов on 30.09.2023.
//

#pragma once

#include <optional>

struct CGAffineTransform {
public:
    float m11{}, m12{}, m21{}, m22{}, tX{}, tY{};

    CGAffineTransform();
    CGAffineTransform(float m11, float m12, float m21, float m22, float tX, float tY);

    static CGAffineTransform translationBy(float x, float y);
    static CGAffineTransform scaleBy(float x, float y);
    static CGAffineTransform scale(float factor);
    static CGAffineTransform rotationBy(float angle);

    std::optional<CGAffineTransform> inverted() const;
    bool isIdentity() const;

    static const CGAffineTransform identity;

    bool operator==(const CGAffineTransform& rhs) const;
    CGAffineTransform operator*(const CGAffineTransform& rhs) const;
};

