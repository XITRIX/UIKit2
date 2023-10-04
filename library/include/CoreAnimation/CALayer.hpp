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
    std::string tag = "";
    /// Defaults to 1.0 but if the layer is associated with a view,
    /// the view sets this value to match the screen.
    float contentsScale = 1.0f;
    CALayerContentsGravity contentsGravity = CALayerContentsGravity::resize;

    [[nodiscard]] CGImage* contents() { return m_contents; };
    void setContents(CGImage* contents) { m_contents = contents; };

    [[nodiscard]] CGRect frame();
    void setFrame(CGRect frame);

    [[nodiscard]] CGRect bounds() const { return m_bounds; }
    void setBounds(CGRect bounds);

    [[nodiscard]] CGPoint position() const { return m_position; }
    void setPosition(CGPoint position);

    [[nodiscard]] CGPoint anchorPoint() const { return m_anchorPoint; }
    void setAnchorPoint(CGPoint anchorPoint);

    [[nodiscard]] CGFloat opacity() const { return m_opacity; }
    void setOpacity(CGFloat opacity);

    [[nodiscard]] CATransform3D transform() const { return m_transform; }
    void setTransform(CATransform3D transform);

    [[nodiscard]] CGAffineTransform affineTransform() const;
    void setAffineTransform(CGAffineTransform transform);

    [[nodiscard]] CGFloat cornerRadius() const { return m_cornerRadius; }
    void setCornerRadius(CGFloat cornerRadius);

    [[nodiscard]] std::optional<CGColor> backgroundColor() const { return m_backgroundColor; }
    void setBackgroundColor(std::optional<CGColor> backgroundColor);

    [[nodiscard]] CALayer* mask() const { return m_mask; }
    void setMask(CALayer* mask) { m_mask = mask; }

    virtual void draw();

    [[nodiscard]] std::vector<CALayer*> sublayers() const { return m_sublayers; }
    void addSublayer(CALayer* layer);

    // MARK: - Animations
    void onWillSet(std::string keyPath);

private:
    float m_zPosition = 0;
    CGPoint m_position = CGPoint::zero;
    CGRect m_bounds = CGRect::zero;
    CGPoint m_anchorPoint = { 0.5f, 0.5f };
    CGFloat m_opacity = 1;
    std::vector<CALayer*> m_sublayers;
    float m_cornerRadius = 0;
    CGImage* m_contents = nullptr;
    CATransform3D m_transform = CATransform3D::identity;
    std::optional<CGColor> m_backgroundColor;

    CALayer* m_mask = nullptr;
};

