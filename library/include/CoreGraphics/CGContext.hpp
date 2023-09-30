//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <nanovg.h>
#include <CoreGraphics/Geometry.hpp>
#include <CoreGraphics/CGColor.hpp>

#pragma once

class CGContext {
public:
    NVGcontext* nvgContext = nullptr;

    static CGContext* current;

    void beginPath() const;
    void fill(CGRect rect) const;
    void fill(CGRect rect, float cornerRadius, bool continuous = false) const;
    void setFillColor(CGColor color) const;
};