//
// Created by Даниил Виноградов on 30.09.2023.
//

#pragma once

#include <CoreGraphics/Geometry.hpp>
#include <Foundation/Data.hpp>
#include <string>

class CGImage {
public:
    ~CGImage();

    [[nodiscard]] CGSize size() const;
    [[nodiscard]] int textureID() const { return m_imgTextureID; }

    static CGImage* FromPath(const std::string& path);
private:
    friend class CGContext;

    std::optional<Data> sourceData;
    int m_imgTextureID = 0;
};
