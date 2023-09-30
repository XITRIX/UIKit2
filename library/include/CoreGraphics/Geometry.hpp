//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

typedef float CGFloat;

struct CGPoint {
    CGFloat x;
    CGFloat y;

    static CGPoint zero;

    CGPoint(CGFloat x, CGFloat y): x(x), y(y) {}
    CGPoint(): CGPoint(0, 0) {}
};

struct CGSize {
    CGFloat width;
    CGFloat height;

    static CGSize zero;

    CGSize(CGFloat width, CGFloat height): width(width), height(height) {}
    CGSize(): CGSize(0, 0) {}
};

struct CGRect {
    CGPoint origin{};
    CGSize size{};

    static CGRect zero;

    CGRect(CGFloat x, CGFloat y, CGFloat width, CGFloat height): origin(x, y), size(width, height) {}
    CGRect(CGPoint origin, CGSize size): origin(origin), size(size) {}
    CGRect(): CGRect(0, 0, 0, 0) {}

    [[nodiscard]] CGFloat width() const { return size.width; }
    [[nodiscard]] CGFloat height() const { return size.height; }

    [[nodiscard]] CGFloat minX() const { return origin.x; }
    [[nodiscard]] CGFloat minY() const { return origin.y; }

    [[nodiscard]] CGFloat maxX() const { return origin.x + size.width; }
    [[nodiscard]] CGFloat maxY() const { return origin.y + size.height; }
};