//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

#include <CoreGraphics/Geometry.hpp>
#include <CoreGraphics/CGColor.hpp>
#include <CoreGraphics/CGContext.hpp>
#include <CoreGraphics/CGImage.hpp>
#include <vector>
#include <CATransform3D.hpp>
#include <CoreAnimation/ContentsGravityTransformation.hpp>

class CALayer {
public:
    /// Defaults to 1.0 but if the layer is associated with a view,
    /// the view sets this value to match the screen.
    float contentsScale = 1.0f;
    CALayerContentsGravity contentsGravity = CALayerContentsGravity::resize;

    CGColor backgroundColor = CGColor::clear;

    [[nodiscard]] CGImage* contents() { return m_contents; };
    void setContents(CGImage* contents) { m_contents = contents; };

    [[nodiscard]] CGRect frame();
    void setFrame(CGRect frame);

    [[nodiscard]] CGRect bounds() const { return m_bounds; }
    void setBounds(CGRect bounds) { m_bounds = bounds; }

    [[nodiscard]] CGPoint position() const { return m_position; }
    void setPosition(CGPoint position) { m_position = position; }

    [[nodiscard]] CGPoint anchorPoint() const { return m_anchorPoint; }
    void setAnchorPoint(CGPoint anchorPoint) { m_anchorPoint = anchorPoint; }

    [[nodiscard]] CATransform3D transform() const { return m_transform; }
    void setTransform(CATransform3D transform) { m_transform = transform; }

    [[nodiscard]] CGAffineTransform affineTransform() const;
    void setAffineTransform(CGAffineTransform transform);

    [[nodiscard]] float cornerRadius() const { return m_cornerRadius; }
    void setCornerRadius(float cornerRadius) { m_cornerRadius = cornerRadius; }

    virtual void draw();

    [[nodiscard]] std::vector<CALayer*> sublayers() const { return m_sublayers; }
    void addSublayer(CALayer* layer);

private:
    float m_zPosition = 0;
    CGPoint m_position = CGPoint::zero;
    CGRect m_bounds = CGRect::zero;
    CGPoint m_anchorPoint = { 0.5f, 0.5f };
    std::vector<CALayer*> m_sublayers;
    float m_cornerRadius = 0;
    CGImage* m_contents = nullptr;
    CATransform3D m_transform = CATransform3D::identity;
};

