//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/CGContext.hpp>
#include "CGContext+Continous.hpp"
#include <cmath>

CGContext* CGContext::current = nullptr;

void CGContext::beginPath() const {
    nvgBeginPath(nvgContext);
}

void CGContext::fill(CGRect rect) const {
    nvgRect(nvgContext, (float) rect.origin.x, (float) rect.origin.y, (float) rect.size.width, (float) rect.size.height);
    nvgFill(nvgContext);
}

void CGContext::fill(CGRect rect, float cornerRadius, bool continuous) const {
    if (continuous)
        nvgContinousRect(nvgContext, rect, cornerRadius);
    else
        nvgRoundedRect(nvgContext, (float) rect.origin.x, (float) rect.origin.y, (float) rect.size.width, (float) rect.size.height, cornerRadius);
    nvgFill(nvgContext);
}

void CGContext::setFillColor(CGColor color) const {
    nvgFillColor(nvgContext, nvgRGBA(color.r(), color.g(), color.b(), color.a()));
}