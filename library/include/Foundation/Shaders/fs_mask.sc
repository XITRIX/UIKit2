$input v_color0
$input v_texcoord0

#include "bgfx_shader.sh"

uniform vec4 u_maskframe;
//uniform sampler2D u_texture;
SAMPLER2D(u_texture, 0);

void main()
{
    vec2 maskCoordinate = vec2(
        ((v_texcoord0.x - u_maskframe.x) / u_maskframe.w),
        ((v_texcoord0.y - u_maskframe.y) / u_maskframe.z)
    );

    vec4 maskColour = texture2D(u_texture, maskCoordinate);
//    gl_FragColor = vec4(v_color0.rgb, v_color0.a * maskColour.a);{
    gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0);
}