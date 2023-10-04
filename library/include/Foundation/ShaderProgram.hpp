//
// Created by Даниил Виноградов on 01.10.2023.
//

#pragma once

#include <string>
#include <bgfx/bgfx.h>
#include <CoreGraphics/Geometry.hpp>
#include <CoreGraphics/CGImage.hpp>

struct MaskShaderProgram {
    ~MaskShaderProgram();
    bgfx::ProgramHandle program;
    bgfx::UniformHandle maskFrame;
    bgfx::UniformHandle maskTexture;
};

class ShaderProgram {
public:
    static void deactivateAll();
    static MaskShaderProgram* mask();

private:
    static MaskShaderProgram* _mask;
};