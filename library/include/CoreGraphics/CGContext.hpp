//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <nanovg.h>
#include <CoreGraphics/Geometry.hpp>
#include <CoreGraphics/CGColor.hpp>
#include <CoreGraphics/CGAffineTransform.hpp>

#pragma once

class CGContext {
public:
    NVGcontext* nvgContext = nullptr;

    static CGContext* current;

    void save() const;
    void restore() const;

    [[nodiscard]] int width() const { return (int) m_currentFrameSize.width; }
    [[nodiscard]] int height() const { return (int) m_currentFrameSize.height; }

    void beginFrame(int windowWidth, int windowHeight, CGFloat devicePixelRatio);
    void endFrame();

    // Setting Fill, Stroke, and Shadow Colors
    void beginPath() const;
    void fill(CGRect rect) const;
    void fill(CGRect rect, float cornerRadius, bool continuous = false) const;
    void setFillColor(CGColor color) const;

    // Working with the Current Transformation Matrix
    [[nodiscard]] CGAffineTransform ctm() const;
    void setCtm(CGAffineTransform ctm) const;

    void rotateBy(CGFloat angle) const;
    void scaleBy(CGFloat sx, CGFloat sy) const;
    void translateBy(CGFloat tx, CGFloat ty) const;
    void concatenate(CGAffineTransform transform) const;

    // Image Context
    int loadImage(const uint8_t* data, CGSize size) const;
    void unloadImage(int imageID) const;
    [[nodiscard]] CGSize imageSize(int imgTextureID) const;
    void drawImage(int imgTextureID, CGRect atRect) const;

private:
    CGSize m_currentFrameSize;
    CGFloat m_currentFrameScale = 0;
};