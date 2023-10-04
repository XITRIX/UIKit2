//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/CGColor.hpp>

CGColor CGColor::clear(0, 0, 0, 0);
CGColor CGColor::white(255, 255, 255);
CGColor CGColor::black(0, 0, 0);
CGColor CGColor::red(255, 0, 0);
CGColor CGColor::yellow(255, 255, 0);
CGColor CGColor::orange(255, 155, 0);

CGColor::CGColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    color = ((a << 24) | (b << 16) | (g << 8) | r);
}

unsigned char CGColor::r() const {
    return (color) & 0xff;
}

unsigned char CGColor::g() const {
    return (color >> 8) & 0xff;
}

unsigned char CGColor::b() const {
    return (color >> 16) & 0xff;
}

unsigned char CGColor::a() const {
    return (color >> 24) & 0xff;
}

bool CGColor::operator==(const CGColor& rhs) const {
    return this->color == rhs.color;
}