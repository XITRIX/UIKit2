//
// Created by Даниил Виноградов on 30.09.2023.
//

#include <CoreGraphics/CGImage.hpp>
#include <romfs/romfs.hpp>
#include <bimg/decode.h>
#include <Platform.hpp>
#include <CoreGraphics/CGContext.hpp>

CGImage::~CGImage() {
    CGContext::current->unloadImage(m_imgTextureID);
}

CGImage* CGImage::FromPath(const std::string& path) {
    auto data = romfs::get(path);

    bimg::ImageContainer* imageContainer = bimg::imageParse(
            Platform::getDefaultAllocator()
            , data.data()
            , data.size()
            , bimg::TextureFormat::RGBA8
    );

    auto imageID = CGContext::current->loadImage(
            (const uint8_t*)imageContainer->m_data,
            {
                    (CGFloat) imageContainer->m_width,
                    (CGFloat) imageContainer->m_height
            });
    bimg::imageFree(imageContainer);

    auto image = new CGImage();
    image->m_imgTextureID = imageID;
    return image;
}

CGSize CGImage::size() const {
    return CGContext::current->imageSize(m_imgTextureID);
}
