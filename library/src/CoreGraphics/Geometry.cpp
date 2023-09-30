//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/Geometry.hpp>

CGPoint CGPoint::zero = { 0, 0 };
CGSize CGSize::zero = { 0, 0 };
CGRect CGRect::null = {INFINITY, INFINITY, 0, 0 };
CGRect CGRect::zero = { 0, 0, 0, 0 };

// MARK: - PRIVATE -
float min(float a, float b, float c, float d) {
    auto minValue = (a < b) ? a : b;
    minValue = (minValue < c) ? minValue : c;
    minValue = (minValue < d) ? minValue : d;
    return minValue;
}

float max(float a, float b, float c, float d) {
    auto maxValue = (a > b) ? a : b;
    maxValue = (maxValue > c) ? maxValue : c;
    maxValue = (maxValue > d) ? maxValue : d;
    return maxValue;
}

float isEqual(float val1, float val2) {
    if (isnan(val1) && isnan(val2))
        return true;
    return val1 == val2;
}

// MARK: - CGPOINT -
bool CGPoint::operator==(const CGPoint& rhs) const {
    return this->x == rhs.x && this->y == rhs.y;
}

CGPoint CGPoint::operator+(const CGPoint& first) const {
    return { x + first.x, y + first.y };
}

CGPoint CGPoint::operator-(const CGPoint& first) const {
    return { x - first.x, y - first.y };
}

CGPoint& CGPoint::operator+=(const CGPoint& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

CGPoint& CGPoint::operator-=(const CGPoint& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

CGPoint CGPoint::operator/(const float& rhs) {
    auto res = *this;
    res.x /= rhs;
    res.y /= rhs;
    return res;
}

CGPoint CGPoint::operator*(const float& rhs) {
    auto res = *this;
    res.x *= rhs;
    res.y *= rhs;
    return res;
}

CGPoint CGPoint::applying(CGAffineTransform t) const {
    return {x * t.m11 + y * t.m21 + t.tX,
                 x * t.m12 + y * t.m22 + t.tY};

}

CGFloat CGPoint::magnitude() const {
    return sqrtf(x * x + y * y);
}

// MARK: - CGCGRect -
bool CGRect::contains(CGPoint point) const {
    return
            (point.x >= minX()) && (point.x < maxX()) &&
            (point.y >= minY()) && (point.y < maxY());
}

bool CGRect::intersects(const CGRect& other) const {
    return !((minX() > other.maxX() || maxX() < other.minX()) || (minY() > other.maxY() || maxY() < other.minY()));
}

CGRect& CGRect::offsetBy(const CGPoint& offset) {
    origin.x += offset.x;
    origin.y += offset.y;
    return *this;
}

CGRect& CGRect::offsetBy(const float& offsetX, const float& offsetY) {
    origin.x += offsetX;
    origin.y += offsetY;
    return *this;
}

bool CGRect::operator==(const CGRect& rhs) const {
    return
            this->origin.x == rhs.origin.x && this->origin.y == rhs.origin.y &&
            this->size.width == rhs.size.width && this->size.height == rhs.size.height;
}

CGRect CGRect::operator+(const CGRect& rhs) const {
    return {
            this->origin.x + rhs.origin.x,
            this->origin.y + rhs.origin.y,
            this->size.width + rhs.size.width,
            this->size.height + rhs.size.height
    };
}

CGRect CGRect::operator-(const CGRect& rhs) const {
    return {
            this->origin.x - rhs.origin.x,
            this->origin.y - rhs.origin.y,
            this->size.width - rhs.size.width,
            this->size.height - rhs.size.height
    };
}

CGRect CGRect::operator*(const float& rhs) const {
    return {
            this->origin.x * rhs,
            this->origin.y * rhs,
            this->size.width * rhs,
            this->size.height * rhs
    };
}

CGRect CGRect::applying(CGAffineTransform t) {
    if (t.isIdentity()) { return *this; }

    auto newTopLeft = CGPoint(minX(), minY()).applying(t);
    auto newTopRight = CGPoint(maxX(), minY()).applying(t);
    auto newBottomLeft = CGPoint(minX(), maxY()).applying(t);
    auto newBottomRight = CGPoint(maxX(), maxY()).applying(t);

    auto newMinX = min(newTopLeft.x, newTopRight.x, newBottomLeft.x, newBottomRight.x);
    auto newMaxX = max(newTopLeft.x, newTopRight.x, newBottomLeft.x, newBottomRight.x);

    auto newMinY = min(newTopLeft.y, newTopRight.y, newBottomLeft.y, newBottomRight.y);
    auto newMaxY = max(newTopLeft.y, newTopRight.y, newBottomLeft.y, newBottomRight.y);

    // XXX: What happens if the point that was furthest left is now on the right (because of a rotation)?
    // i.e. Should do we return a normalised CGRect or one with a negative width?
    return {newMinX,
                newMinY,
                newMaxX - newMinX,
                newMaxY - newMinY};
}

CGRect CGRect::applying(CATransform3D t) {
    if (t == CATransform3DIdentity) { return *this; }

    auto topLeft = t.transformingVector(minX(), minY(), 0);
    auto topRight = t.transformingVector(maxX(), minY(), 0);
    auto bottomLeft = t.transformingVector(minX(), maxY(), 0);
    auto bottomRight = t.transformingVector(maxX(), maxY(), 0);

    auto newMinX = min(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);
    auto newMaxX = max(topLeft.x, topRight.x, bottomLeft.x, bottomRight.x);

    auto newMinY = min(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);
    auto newMaxY = max(topLeft.y, topRight.y, bottomLeft.y, bottomRight.y);

    return {newMinX, newMinY, newMaxX - newMinX, newMaxY - newMinY};
}

CGRect CGRect::intersection(CGRect other) const {
    auto largestMinX = fmaxf(minX(), other.minX());
    auto largestMinY = fmaxf(minY(), other.minY());

    auto smallestMaxX = fmaxf(maxX(), other.maxX());
    auto smallestMaxY = fmaxf(maxY(), other.maxY());

    auto width = smallestMaxX - largestMinX;
    auto height = smallestMaxY - largestMinY;

    if (width > 0 && height > 0) {
        // The intersection CGRectangle has dimensions, i.e. there is an intersection:
        return {largestMinX, largestMinY, width, height};
    } else {
        return null;
    }
}

bool CGRect::isNull() const {
    return *this == null;
}