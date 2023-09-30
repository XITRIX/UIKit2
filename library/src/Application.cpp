/*
 * Copyright 2011-2019 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
#include <Application.hpp>
#include <CoreGraphics/CGLayer.hpp>
#include <SDLVideo.hpp>

int Application::run() {
    auto layer = new CGLayer();
    layer->setFrame({ 20, 20, 280, 280 });
    layer->backgroundColor = CGColor::white;

    auto layer2 = new CGLayer();
    layer2->setFrame({ 120, 120, 280, 44 });
    layer2->backgroundColor = CGColor::black;
    layer2->setCornerRadius(12);

    layer->addSublayer(layer2);

    auto video = new SDLVideo();
    video->rootLayer = layer;
    video->runMainLoop();
    delete video;
    return 0;
}