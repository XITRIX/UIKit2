/*
 * Copyright 2011-2019 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
#include <Application.hpp>
#include <CoreAnimation/CALayer.hpp>
#include <SDLVideo.hpp>

int Application::run() {
    auto video = new SDLVideo();

    auto layer = new CALayer();
    layer->setFrame({ 20, 20, 280, 280 });
    layer->backgroundColor = CGColor::white;

    auto layer2 = new CALayer();
    layer2->setFrame({ 120, 120, 280, 44 });
    layer2->backgroundColor = CGColor::black;
    layer2->setCornerRadius(12);

    layer->addSublayer(layer2);

    auto image = CGImage::FromPath("img/demo_icon.jpg");
    layer2->setContents(image);

    video->rootLayer = layer;
    video->runMainLoop();
    delete video;
    return 0;
}