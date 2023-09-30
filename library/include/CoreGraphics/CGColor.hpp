//
// Created by Даниил Виноградов on 27.09.2023.
//

#pragma once

struct CGColor {
public:
    CGColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);

    [[nodiscard]] unsigned char r() const;
    [[nodiscard]] unsigned char g() const;
    [[nodiscard]] unsigned char b() const;
    [[nodiscard]] unsigned char a() const;

    static CGColor clear;
    static CGColor black;
    static CGColor white;
    static CGColor red;
    static CGColor yellow;
private:
    int color = 0;
};