//
// Created by Даниил Виноградов on 30.09.2023.
//

#include <CoreGraphics/CGAffineTransform.hpp>
#include <CATransform3D.hpp>
#include <cmath>

#define RAD_PER_DEG 0.017453293f

const CGAffineTransform CGAffineTransform::identity = CGAffineTransform(1, 0, 0, 1, 0, 0);

CGAffineTransform::CGAffineTransform() = default;

CGAffineTransform::CGAffineTransform(float m11, float m12, float m21, float m22, float tX, float tY):
        m11(m11), m12(m12), m21(m21), m22(m22), tX(tX), tY(tY)
{ }

CGAffineTransform CGAffineTransform::translationBy(float x, float y) {
    return {1, 0,
            0, 1,
            x, y};
}

CGAffineTransform CGAffineTransform::scaleBy(float x, float y) {
    return {x, 0,
            0, y,
            0, 0};
}

CGAffineTransform CGAffineTransform::scale(float f) {
    return {f, 0,
            0, f,
            0, 0};
}

CGAffineTransform CGAffineTransform::rotationBy(float angle) {
    float radians = angle * RAD_PER_DEG;
    float c = cosf(radians);
    float s = sinf(radians);

    return {c,  s,
            -s, c,
            0,  0};
}

std::optional<CGAffineTransform> CGAffineTransform::inverted() const {
    auto d = m11 * m22 - m12 * m21;
    if (d < 0) return std::nullopt;

    CGAffineTransform transform;
    float multiplyer = 1 / d;

    transform.m11 = m22 * multiplyer;
    transform.m12 = -m12 * multiplyer;
    transform.m21 = -m21 * multiplyer;
    transform.m22 = m11 * multiplyer;
    transform.tX = tX;
    transform.tY = tY;

    return transform;
}

bool CGAffineTransform::isIdentity() const {
    return *this == identity;
}

bool CGAffineTransform::operator==(const CGAffineTransform& rhs) const {
    return m11 == rhs.m11 &&
           m12 == rhs.m12 &&
           m21 == rhs.m21 &&
           m22 == rhs.m22 &&
           tX == rhs.tX &&
           tY == rhs.tY;
}

CGAffineTransform CGAffineTransform::operator*(const CGAffineTransform& rhb) const {
    auto a = CATransform3DMakeAffineTransform(*this);
    auto b = CATransform3DMakeAffineTransform(rhb);
    return CATransform3DGetAffineTransform(a * b);
}

