//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

#include <CoreGraphics/CGAffineTransform.hpp>
#include <CATransform3D.hpp>

typedef float CGFloat;

struct CGPoint {
    CGFloat x;
    CGFloat y;

    CGPoint(CGFloat x, CGFloat y): x(x), y(y) {}
    CGPoint(): CGPoint(0, 0) {}

    bool operator==(const CGPoint& rhs) const;
    CGPoint operator+(const CGPoint& first) const;
    CGPoint operator-(const CGPoint& first) const;
    CGPoint& operator+=(const CGPoint& rhs);
    CGPoint& operator-=(const CGPoint& rhs);
    CGPoint operator/(const float& rhs);
    CGPoint operator*(const float& rhs);

    CGPoint applying(CGAffineTransform transform) const;
    CGFloat magnitude() const;

    static CGPoint zero;
};

struct CGSize {
    CGFloat width;
    CGFloat height;

    CGSize(CGFloat width, CGFloat height): width(width), height(height) {}
    CGSize(): CGSize(0, 0) {}

    static CGSize zero;
};

struct CGRect {
    CGPoint origin{};
    CGSize size{};

    CGRect(CGFloat x, CGFloat y, CGFloat width, CGFloat height): origin(x, y), size(width, height) {}
    CGRect(CGPoint origin, CGSize size): origin(origin), size(size) {}
    CGRect(): CGRect(0, 0, 0, 0) {}

    [[nodiscard]] CGFloat width() const { return size.width; }
    [[nodiscard]] CGFloat height() const { return size.height; }

    [[nodiscard]] CGFloat minX() const { return origin.x; }
    [[nodiscard]] CGFloat minY() const { return origin.y; }

    [[nodiscard]] CGFloat maxX() const { return origin.x + size.width; }
    [[nodiscard]] CGFloat maxY() const { return origin.y + size.height; }

    [[nodiscard]] bool contains(CGPoint point) const;
    [[nodiscard]] bool intersects(const CGRect& other) const;
    CGRect& offsetBy(const CGPoint& offset);
    CGRect& offsetBy(const CGFloat& offsetX, const CGFloat& offsetY);

    bool operator==(const CGRect& rhs) const;
    CGRect operator+(const CGRect& rhs) const;
    CGRect operator-(const CGRect& rhs) const;
    CGRect operator*(const CGFloat& rhs) const;

    CGRect applying(CGAffineTransform transform);
    CGRect applying(CATransform3D transform);

    [[nodiscard]] CGRect intersection(CGRect other) const;
    [[nodiscard]] bool isNull() const;

    static CGRect null;
    static CGRect zero;
};