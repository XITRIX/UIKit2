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
    layer->tag = "Layer 1";
    layer->setFrame({ 20, 20, 280, 280 });
    layer->setBackgroundColor(CGColor::white);

    auto layer2 = new CALayer();
    layer2->tag = "Layer 2";
    layer2->setFrame({ 50, 80, 280, 44 });
    layer2->setBackgroundColor(CGColor::green);
    layer2->setCornerRadius(18);
    layer2->setOpacity(0.5);

    auto layer3 = new CALayer();
    layer3->tag = "Layer 3";
    layer3->setFrame({ 0, 0, 80, 80 });
    layer3->setBackgroundColor(CGColor::orange);
//    layer3->setCornerRadius(18);
    layer3->setOpacity(0.5);

    auto layer4 = new CALayer();
    layer4->tag = "Layer 4";
    layer4->setFrame({ 20, 20, 80, 80 });
    layer4->setBackgroundColor(CGColor::red);
//    layer4->setCornerRadius(18);
    layer4->setOpacity(0.7);

    auto layer5 = new CALayer();
    layer5->tag = "Layer 5";
    layer5->setFrame({ 220, 220, 80, 80 });
    layer5->setBackgroundColor(CGColor::green);
//    layer5->setCornerRadius(18);
    layer5->setOpacity(0.5);

    layer2->addSublayer(layer3);
    layer->addSublayer(layer4);
    layer->addSublayer(layer2);
    layer->addSublayer(layer5);

    auto image = CGImage::FromPath("img/demo_icon.jpg");
    layer2->setContents(image);
    layer2->setAffineTransform(CGAffineTransform::rotationBy(45));
    layer2->contentsGravity = CALayerContentsGravity::resizeAspect;

    video->rootLayer = layer;
    video->runMainLoop();
    delete video;
    return 0;
}