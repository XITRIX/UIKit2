//
// Created by Даниил Виноградов on 27.09.2023.
//

#include <CoreGraphics/CGLayer.hpp>
#include <CoreGraphics/CGContext.hpp>

CGRect CGLayer::frame() {
    return { position.x, position.y, bounds.size.width, bounds.size.height };
}

void CGLayer::setFrame(CGRect frame) {
    position = frame.origin;
    bounds.size = frame.size;
}

void CGLayer::draw() {
    auto context = CGContext::current;

    context->beginPath();
    context->setFillColor(backgroundColor);
    context->fill(frame(), cornerRadius(), true);

    for (auto layer: sublayers()) {
        layer->draw();
    }
}

void CGLayer::addSublayer(CGLayer* layer) {
    m_sublayers.push_back(layer);
}