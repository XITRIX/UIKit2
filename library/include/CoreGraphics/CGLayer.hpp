//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

#include <CoreGraphics/Geometry.hpp>
#include <CoreGraphics/CGColor.hpp>
#include <CoreGraphics/CGContext.hpp>
#include <vector>

class CGLayer {
public:
    CGPoint position = CGPoint::zero;
    CGRect bounds = CGRect::zero;
    CGColor backgroundColor = CGColor::clear;

    CGRect frame();
    void setFrame(CGRect frame);

    virtual void draw();

    void addSublayer(CGLayer* layer);
    [[nodiscard]] std::vector<CGLayer*> sublayers() const { return m_sublayers; }

    void setCornerRadius(float cornerRadius) { m_cornerRadius = cornerRadius; }
    [[nodiscard]] float cornerRadius() const { return m_cornerRadius; }

private:
    std::vector<CGLayer*> m_sublayers;
    float m_cornerRadius = 0;
};

