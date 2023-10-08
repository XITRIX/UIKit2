//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/CGContext.hpp>
#include <nanovg_bgfx.h>
#include "CGContext+Continous.hpp"

CGContext* CGContext::current = nullptr;

CGContext::CGContext(bgfx::ViewId viewId) {
    // Set view 0 to the same dimensions as the window and to clear the color buffer.
    bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR);
    bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);

    nvgContext = nvgCreate(1, viewId);
    bgfx::setViewMode(viewId, bgfx::ViewMode::Sequential);

    rootViewId = viewId;
//    contexts.push_back(nvgContext);
}

CGContext::~CGContext() {
    nvgDelete(nvgContext);
}

void CGContext::save() const {
    nvgSave(nvgContext);
}

void CGContext::restore() const {
    nvgRestore(nvgContext);
}

void CGContext::beginFrame(int windowWidth, int windowHeight, CGFloat devicePixelRatio) {
    nvgBeginFrame(nvgContext, (float) windowWidth, (float) windowHeight, 1);
    nvgScale(nvgContext, devicePixelRatio, devicePixelRatio);

    CGSize newFrameSize = { (CGFloat) windowWidth, (CGFloat) windowHeight };
//    if (m_currentFrameSize != newFrameSize) {
//        for (auto fb : framebuffersQueue) {
//            nvgluDeleteFramebuffer(fb);
//        }
//        framebuffersQueue.clear();
//    }

    m_currentFrameSize = newFrameSize;
    m_currentFrameScale = devicePixelRatio;


}

void CGContext::endFrame() {
    nvgEndFrame(nvgContext);

    for (auto fb: framebuffers) {
        nvgluDeleteFramebuffer(fb);
    }
    framebuffers.clear();
    fbCounter = 0;
}

void CGContext::pushContext() {
    save();
    auto _ctm = ctm();

    NVGLUframebuffer* fb;
//    if (framebuffersQueue.empty()) {
        float scale = m_currentFrameScale;
        fb = nvgluCreateFramebuffer(nvgContext,
                                    (int) (m_currentFrameSize.width * scale),
                                    (int) (m_currentFrameSize.height * scale),
                                    0);
//    } else {
//        fb = framebuffersQueue.back();
//        framebuffersQueue.pop_back();
//    }

    framebuffers.push_back(fb);
    fbCounter++;

    nvgEndFrame(nvgContext);

    auto fbViewId = rootViewId - fbCounter;

    bgfx::setViewClear(fbViewId, BGFX_CLEAR_COLOR, 0);
    bgfx::setViewRect(fbViewId, 0, 0, bgfx::BackbufferRatio::Equal);

    nvgluSetViewFramebuffer(fbViewId, fb);

    save();
    nvgluBindFramebuffer(fb);
    nvgBeginFrame(nvgContext, m_currentFrameSize.width * m_currentFrameScale, m_currentFrameSize.height * m_currentFrameScale, 1);
    setCtm(_ctm * CGAffineTransform::scale(m_currentFrameScale)); // Apply previous fb ctm
    save();
}

void CGContext::popContext(CGFloat withAlpha) {
    restore();
    auto _ctm = ctm();
    nvgEndFrame(nvgContext);

    NVGLUframebuffer* fb = framebuffers.back();
    framebuffers.pop_back();

    nvgluBindFramebuffer(framebuffers.empty() ? nullptr : framebuffers.back());
    restore();

    setCtm(CGAffineTransform::scale(m_currentFrameScale));
    NVGpaint paint = nvgImagePattern(nvgContext, 0, 0, m_currentFrameSize.width, m_currentFrameSize.height, 0, fb->image, withAlpha);
    nvgBeginPath(nvgContext);
    nvgRect(nvgContext, 0, 0, m_currentFrameSize.width, m_currentFrameSize.height);
    nvgFillPaint(nvgContext, paint);
    nvgFill(nvgContext);
    nvgEndFrame(nvgContext);
//    bgfx::frame();

//    framebuffersQueue.push_back(fb);
    nvgluDeleteFramebuffer(fb);

//    setCtm(_ctm);
    restore();
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
