$input a_position
$input a_texcoord0
$input a_color0

$output v_color0
$output v_texcoord0

/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "bgfx_shader.sh"

uniform mat4 gpu_ModelViewProjectionMatrix;

void main()
{
	v_color0 = a_color0;
	v_texcoord0 = vec2(a_position.xy);
//	gl_Position = gpu_ModelViewProjectionMatrix * vec4(a_position, 1.0);

	gl_Position = mul(u_modelViewProj, vec4(a_position, 1.0) );
}