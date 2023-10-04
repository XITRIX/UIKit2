//
// Created by Даниил Виноградов on 01.10.2023.
//

#include <Foundation/ShaderProgram.hpp>
#include <Foundation/Shaders/vs_common.bin.h>
#include <Foundation/Shaders/fs_mask.bin.h>

#include <bx/bx.h>
#include <bgfx/embedded_shader.h>

static const bgfx::EmbeddedShader s_embeddedShaders[] =
{
    BGFX_EMBEDDED_SHADER(vs_common),
    BGFX_EMBEDDED_SHADER(fs_mask),

    BGFX_EMBEDDED_SHADER_END()
};

MaskShaderProgram::~MaskShaderProgram() {
    bgfx::destroy(maskFrame);
    bgfx::destroy(maskTexture);
    bgfx::destroy(program);
}

MaskShaderProgram* ShaderProgram::_mask = nullptr;

MaskShaderProgram* ShaderProgram::mask() {
    if (_mask) return _mask;

    bgfx::RendererType::Enum type = bgfx::getRendererType();
    auto program = bgfx::createProgram(
            bgfx::createEmbeddedShader(s_embeddedShaders, type, "vs_common")
            , bgfx::createEmbeddedShader(s_embeddedShaders, type, "fs_mask")
            , true
    );

    auto maskFrame = bgfx::createUniform("u_maskframe", bgfx::UniformType::Vec4);
    auto maskTexture = bgfx::createUniform("u_masktexture", bgfx::UniformType::Sampler);

    _mask = new MaskShaderProgram { program, maskFrame, maskTexture };
    return _mask;
}
