//
// Created by Даниил Виноградов on 29.09.2023.
//

#pragma once

CGPoint topLeft(CGFloat x, CGFloat y, CGRect rect, CGFloat cornerRadius) {
    return {rect.origin.x + (x * cornerRadius),
            rect.origin.y + (y * cornerRadius)};
}
CGPoint topRight(CGFloat x, CGFloat y, CGRect rect, CGFloat cornerRadius) {
    return {rect.origin.x + rect.size.width - (x * cornerRadius),
            rect.origin.y + (y * cornerRadius)};
}
CGPoint btmRight(CGFloat x, CGFloat y, CGRect rect, CGFloat cornerRadius) {
    return {rect.origin.x + rect.size.width - (x * cornerRadius),
            rect.origin.y + rect.size.height - (y * cornerRadius)};
}
CGPoint btmLeft(CGFloat x, CGFloat y, CGRect rect, CGFloat cornerRadius) {
    return {rect.origin.x + (x * cornerRadius),
            rect.origin.y + rect.size.height - (y * cornerRadius)};
}

void nvgContinousRect(NVGcontext* nvgContext, CGRect rect, float cornerRadius) {
    CGPoint topLeft1;
    CGPoint topLeft2;
    CGPoint topLeft3;

    CGPoint topRight1;
    CGPoint topRight2;
    CGPoint topRight3;

    CGPoint btmRight1;
    CGPoint btmRight2;
    CGPoint btmRight3;

    CGPoint btmLeft1;
    CGPoint btmLeft2;
    CGPoint btmLeft3;

    topLeft1 = topLeft(1.528665, 0.0, rect, cornerRadius);
    nvgMoveTo(nvgContext, topLeft1.x, topLeft1.y);
    topRight1 = topRight(1.528665, 0.0, rect, cornerRadius);
    nvgLineTo(nvgContext, topRight1.x, topRight1.y);

    topRight1 = topRight(0.63149379, 0.07491139, rect, cornerRadius);
    topRight2 = topRight(1.08849296, 0.0, rect, cornerRadius);
    topRight3 = topRight(0.86840694, 0.0, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topRight2.x, topRight2.y,
                topRight3.x, topRight3.y,
                topRight1.x, topRight1.y);

    topRight1 = topRight(0.63149379, 0.07491139, rect, cornerRadius);
    nvgLineTo(nvgContext, topRight1.x, topRight1.y);

    topRight1 = topRight(0.07491139, 0.63149379, rect, cornerRadius);
    topRight2 = topRight(0.37282383, 0.16905956, rect, cornerRadius);
    topRight3 = topRight(0.16905956, 0.37282383, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topRight2.x, topRight2.y,
                topRight3.x, topRight3.y,
                topRight1.x, topRight1.y);

    topRight1 = topRight(0.0, 1.52866498, rect, cornerRadius);
    topRight2 = topRight(0.0, 0.86840694, rect, cornerRadius);
    topRight3 = topRight(0.0, 1.08849296, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topRight2.x, topRight2.y,
                topRight3.x, topRight3.y,
                topRight1.x, topRight1.y);

    btmRight1 = btmRight(0.0, 1.528665, rect, cornerRadius);
    nvgLineTo(nvgContext, btmRight1.x, btmRight1.y);

    btmRight1 = btmRight(0.07491139, 0.63149379, rect, cornerRadius);
    btmRight2 = btmRight(0.0, 1.08849296, rect, cornerRadius);
    btmRight3 = btmRight(0.0, 0.86840694, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmRight2.x, btmRight2.y,
                btmRight3.x, btmRight3.y,
                btmRight1.x, btmRight1.y);

    btmRight1 = btmRight(0.07491139, 0.63149379, rect, cornerRadius);
    nvgLineTo(nvgContext, btmRight1.x, btmRight1.y);

    btmRight1 = btmRight(0.63149379, 0.07491139, rect, cornerRadius);
    btmRight2 = btmRight(0.16905956, 0.37282383, rect, cornerRadius);
    btmRight3 = btmRight(0.37282383, 0.16905956, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmRight2.x, btmRight2.y,
                btmRight3.x, btmRight3.y,
                btmRight1.x, btmRight1.y);

    btmRight1 = btmRight(1.52866498, 0.0, rect, cornerRadius);
    btmRight2 = btmRight(0.86840694, 0.0, rect, cornerRadius);
    btmRight3 = btmRight(1.08849296, 0.0, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmRight2.x, btmRight2.y,
                btmRight3.x, btmRight3.y,
                btmRight1.x, btmRight1.y);

    btmLeft1 = btmLeft(1.528665, 0.0, rect, cornerRadius);
    nvgLineTo(nvgContext, btmLeft1.x, btmLeft1.y);

    btmLeft1 = btmLeft(0.63149379, 0.07491139, rect, cornerRadius);
    btmLeft2 = btmLeft(1.08849296, 0.0, rect, cornerRadius);
    btmLeft3 = btmLeft(0.86840694, 0.0, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmLeft2.x, btmLeft2.y,
                btmLeft3.x, btmLeft3.y,
                btmLeft1.x, btmLeft1.y);

    btmLeft1 = btmLeft(0.63149379, 0.07491139, rect, cornerRadius);
    nvgLineTo(nvgContext, btmLeft1.x, btmLeft1.y);

    btmLeft1 = btmLeft(0.07491139, 0.63149379, rect, cornerRadius);
    btmLeft2 = btmLeft(0.37282383, 0.16905956, rect, cornerRadius);
    btmLeft3 = btmLeft(0.16905956, 0.37282383, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmLeft2.x, btmLeft2.y,
                btmLeft3.x, btmLeft3.y,
                btmLeft1.x, btmLeft1.y);

    btmLeft1 = btmLeft(0.0, 1.52866498, rect, cornerRadius);
    btmLeft2 = btmLeft(0.0, 0.86840694, rect, cornerRadius);
    btmLeft3 = btmLeft(0.0, 1.08849296, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                btmLeft2.x, btmLeft2.y,
                btmLeft3.x, btmLeft3.y,
                btmLeft1.x, btmLeft1.y);

    topLeft1 = topLeft(0.0, 1.528665, rect, cornerRadius);
    nvgLineTo(nvgContext, topLeft1.x, topLeft1.y);

    topLeft1 = topLeft(0.07491139, 0.63149379, rect, cornerRadius);
    topLeft2 = topLeft(0.0, 1.08849296, rect, cornerRadius);
    topLeft3 = topLeft(0.0, 0.86840694, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topLeft2.x, topLeft2.y,
                topLeft3.x, topLeft3.y,
                topLeft1.x, topLeft1.y);

    topLeft1 = topLeft(0.07491139, 0.63149379, rect, cornerRadius);
    nvgLineTo(nvgContext, topLeft1.x, topLeft1.y);

    topLeft1 = topLeft(0.63149379, 0.07491139, rect, cornerRadius);
    topLeft2 = topLeft(0.16905956, 0.37282383, rect, cornerRadius);
    topLeft3 = topLeft(0.37282383, 0.16905956, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topLeft2.x, topLeft2.y,
                topLeft3.x, topLeft3.y,
                topLeft1.x, topLeft1.y);

    topLeft1 = topLeft(1.52866498, 0.0, rect, cornerRadius);
    topLeft2 = topLeft(0.86840694, 0.0, rect, cornerRadius);
    topLeft3 = topLeft(1.08849296, 0.0, rect, cornerRadius);
    nvgBezierTo(nvgContext,
                topLeft2.x, topLeft2.y,
                topLeft3.x, topLeft3.y,
                topLeft1.x, topLeft1.y);
}