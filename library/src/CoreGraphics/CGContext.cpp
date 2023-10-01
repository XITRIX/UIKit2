//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/CGContext.hpp>
#include "CGContext+Continous.hpp"

CGContext* CGContext::current = nullptr;

void CGContext::save() const {
    nvgSave(nvgContext);
}

void CGContext::restore() const {
    nvgRestore(nvgContext);
}

void CGContext::beginFrame(int windowWidth, int windowHeight, CGFloat devicePixelRatio) {
    nvgBeginFrame(nvgContext, (float) windowWidth, (float) windowHeight, 1);
    nvgScale(nvgContext, devicePixelRatio, devicePixelRatio);

    m_currentFrameSize = { (CGFloat) windowWidth, (CGFloat) windowHeight };
    m_currentFrameScale = devicePixelRatio;
}

void CGContext::endFrame() {
    nvgEndFrame(nvgContext);
    m_currentFrameSize = CGSize::zero;
    m_currentFrameScale = 0;
}

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

int CGContext::loadImage(const uint8_t* data, CGSize size) const {
    return nvgCreateImageRGBA(
            nvgContext
            , (int) size.width
            , (int) size.height
            , 0
            , data
    );
}

void CGContext::unloadImage(int imageID) const {
    nvgDeleteImage(nvgContext, imageID);
}

CGSize CGContext::imageSize(int imgTextureID) const {
    int width, height;
    nvgImageSize(nvgContext, imgTextureID, &width, &height);
    return { (CGFloat) width, (CGFloat) height};
}

void CGContext::drawImage(int imgTextureID, CGRect atRect) const {
    NVGpaint imgPaint = nvgImagePattern(nvgContext, atRect.minX(), atRect.minY(), atRect.width(), atRect.height(), 0, imgTextureID, 1);
    nvgBeginPath(nvgContext);
    nvgRect(nvgContext, atRect.minX(), atRect.minY(), atRect.width(), atRect.height());
    nvgFillPaint(nvgContext, imgPaint);
    nvgFill(nvgContext);

}

CGAffineTransform CGContext::ctm() const {
    float matrix[6];
    nvgCurrentTransform(nvgContext, matrix);
    return {matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5]};
}

void CGContext::setCtm(CGAffineTransform ctm) const {
    nvgResetTransform(nvgContext);
    nvgTransform(nvgContext, ctm.m11, ctm.m12, ctm.m21, ctm.m22, ctm.tX, ctm.tY);
}

void CGContext::rotateBy(CGFloat byAngle) const {
    nvgRotate(nvgContext, byAngle);
}

void CGContext::scaleBy(CGFloat sx, CGFloat sy) const {
    nvgScale(nvgContext, sx, sy);
}

void CGContext::translateBy(CGFloat tx, CGFloat ty) const {
    nvgTranslate(nvgContext, tx, ty);
}

void CGContext::concatenate(CGAffineTransform transform) const {
    setCtm(ctm() * transform);
}
