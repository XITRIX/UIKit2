static const uint8_t vs_common_glsl[402] =
{
	0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x83, 0xf2, 0xe1, 0x01, 0x00, 0x1d, 0x67, // VSH............g
	0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, // pu_ModelViewProj
	0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x04, 0x01, 0x00, 0x00, // ectionMatrix....
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x01, 0x00, 0x00, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, // ......W...attrib
	0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, // ute vec4 a_color
	0x30, 0x3b, 0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, // 0;.attribute vec
	0x33, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x61, // 3 a_position;.va
	0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, // rying vec4 v_col
	0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, // or0;.varying vec
	0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, // 2 v_texcoord0;.u
	0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x6d, 0x61, 0x74, 0x34, 0x20, 0x67, 0x70, 0x75, 0x5f, // niform mat4 gpu_
	0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, // ModelViewProject
	0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, // ionMatrix;.void 
	0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x5f, 0x63, 0x6f, // main ().{.  v_co
	0x6c, 0x6f, 0x72, 0x30, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, // lor0 = a_color0;
	0x0a, 0x20, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, // .  v_texcoord0 =
	0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x79, 0x3b, 0x0a, //  a_position.xy;.
	0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, //   vec4 tmpvar_1;
	0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, // .  tmpvar_1.w = 
	0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, // 1.0;.  tmpvar_1.
	0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, // xyz = a_position
	0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, // ;.  gl_Position 
	0x3d, 0x20, 0x28, 0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, // = (gpu_ModelView
	0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, // ProjectionMatrix
	0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, 0x3b, 0x0a, 0x7d, 0x0a, //  * tmpvar_1);.}.
	0x0a, 0x00,                                                                                     // ..
};
static const uint8_t vs_common_essl[438] =
{
	0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x83, 0xf2, 0xe1, 0x01, 0x00, 0x1d, 0x67, // VSH............g
	0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, // pu_ModelViewProj
	0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x04, 0x01, 0x00, 0x00, // ectionMatrix....
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0x01, 0x00, 0x00, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, // ......{...attrib
	0x75, 0x74, 0x65, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, // ute highp vec4 a
	0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, // _color0;.attribu
	0x74, 0x65, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x33, 0x20, 0x61, 0x5f, // te highp vec3 a_
	0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, // position;.varyin
	0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, // g highp vec4 v_c
	0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, // olor0;.varying h
	0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, // ighp vec2 v_texc
	0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68, // oord0;.uniform h
	0x69, 0x67, 0x68, 0x70, 0x20, 0x6d, 0x61, 0x74, 0x34, 0x20, 0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, // ighp mat4 gpu_Mo
	0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, // delViewProjectio
	0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, // nMatrix;.void ma
	0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // in ().{.  v_colo
	0x72, 0x30, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x20, // r0 = a_color0;. 
	0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20, 0x61, //  v_texcoord0 = a
	0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x79, 0x3b, 0x0a, 0x20, 0x20, // _position.xy;.  
	0x68, 0x69, 0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // highp vec4 tmpva
	0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, // r_1;.  tmpvar_1.
	0x77, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // w = 1.0;.  tmpva
	0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, // r_1.xyz = a_posi
	0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, // tion;.  gl_Posit
	0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x28, 0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, // ion = (gpu_Model
	0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, // ViewProjectionMa
	0x74, 0x72, 0x69, 0x78, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, // trix * tmpvar_1)
	0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                             // ;.}...
};
static const uint8_t vs_common_spv[1240] =
{
	0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x83, 0xf2, 0xe1, 0x01, 0x00, 0x1d, 0x67, // VSH............g
	0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, // pu_ModelViewProj
	0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x04, 0x01, 0x00, 0x00, // ectionMatrix....
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0x04, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, // ............#...
	0x01, 0x00, 0x0b, 0x00, 0x08, 0x00, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, // ......y.........
	0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, // ..............GL
	0x53, 0x4c, 0x2e, 0x73, 0x74, 0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, // SL.std.450......
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x0a, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, // ......main....8.
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x52, 0x00, // ..<...K...N...R.
	0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00, // ................
	0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, // ......main......
	0x06, 0x00, 0x26, 0x00, 0x00, 0x00, 0x55, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x42, 0x6c, 0x6f, // ..&...UniformBlo
	0x63, 0x6b, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0b, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, // ck........&.....
	0x00, 0x00, 0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, // ..gpu_ModelViewP
	0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x00, // rojectionMatrix.
	0x00, 0x00, 0x05, 0x00, 0x03, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, // ......(.........
	0x05, 0x00, 0x38, 0x00, 0x00, 0x00, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00, // ..8...a_color0..
	0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, // ......<...a_posi
	0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x40, 0x65, // tion......K...@e
	0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, // ntryPointOutput.
	0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x00, 0x00, 0x05, 0x00, // gl_Position.....
	0x09, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, // ..N...@entryPoin
	0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, // tOutput.v_color0
	0x00, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x52, 0x00, 0x00, 0x00, 0x40, 0x65, 0x6e, 0x74, 0x72, 0x79, // ......R...@entry
	0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x2e, 0x76, 0x5f, 0x74, 0x65, // PointOutput.v_te
	0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x00, 0x00, 0x00, 0x48, 0x00, 0x04, 0x00, 0x26, 0x00, // xcoord0...H...&.
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x26, 0x00, // ..........H...&.
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, // ......#.......H.
	0x05, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, // ..&.............
	0x00, 0x00, 0x47, 0x00, 0x03, 0x00, 0x26, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, 0x00, // ..G...&.......G.
	0x04, 0x00, 0x28, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, // ..(...".......G.
	0x04, 0x00, 0x28, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, // ..(...!.......G.
	0x04, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, // ..8...........G.
	0x04, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, // ..<...........G.
	0x04, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, // ..K...........G.
	0x04, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, // ..N...........G.
	0x04, 0x00, 0x52, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, // ..R.............
	0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, // ......!.........
	0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x17, 0x00, // .......... .....
	0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x17, 0x00, // ................
	0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x17, 0x00, // ................
	0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x15, 0x00, // ................
	0x04, 0x00, 0x16, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, // ...... .......+.
	0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x2b, 0x00, // .............?+.
	0x04, 0x00, 0x16, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, // ......$.........
	0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1e, 0x00, // ..%.............
	0x03, 0x00, 0x26, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x27, 0x00, // ..&...%... ...'.
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x27, 0x00, // ......&...;...'.
	0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x29, 0x00, // ..(....... ...).
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x37, 0x00, // ......%... ...7.
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x37, 0x00, // ..........;...7.
	0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x3b, 0x00, // ..8....... ...;.
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x3b, 0x00, // ..........;...;.
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x4a, 0x00, // ..<....... ...J.
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x4a, 0x00, // ..........;...J.
	0x00, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x4a, 0x00, // ..K.......;...J.
	0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x51, 0x00, // ..N....... ...Q.
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x51, 0x00, // ..........;...Q.
	0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, // ..R.......6.....
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, // ................
	0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x39, 0x00, // ......=.......9.
	0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x3d, 0x00, // ..8...=.......=.
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x07, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x6f, 0x00, // ..<...O.......o.
	0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, // ..=...=.........
	0x00, 0x00, 0x41, 0x00, 0x05, 0x00, 0x29, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x28, 0x00, // ..A...)...q...(.
	0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x25, 0x00, 0x00, 0x00, 0x72, 0x00, // ..$...=...%...r.
	0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x74, 0x00, // ..q...Q.......t.
	0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, // ..=.......Q.....
	0x00, 0x00, 0x75, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x51, 0x00, // ..u...=.......Q.
	0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x02, 0x00, // ......v...=.....
	0x00, 0x00, 0x50, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x74, 0x00, // ..P.......w...t.
	0x00, 0x00, 0x75, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x91, 0x00, // ..u...v.........
	0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x72, 0x00, 0x00, 0x00, 0x77, 0x00, // ......x...r...w.
	0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x4b, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x3e, 0x00, // ..>...K...x...>.
	0x03, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x52, 0x00, // ..N...9...>...R.
	0x00, 0x00, 0x6f, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00, 0x00, 0x03, // ..o.......8.....
	0x05, 0x00, 0x01, 0x00, 0x10, 0x00, 0x40, 0x00,                                                 // ......@.
};
static const uint8_t vs_common_mtl[893] =
{
	0x56, 0x53, 0x48, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x83, 0xf2, 0xe1, 0x01, 0x00, 0x1d, 0x67, // VSH............g
	0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, // pu_ModelViewProj
	0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x04, 0x01, 0x00, 0x00, // ectionMatrix....
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0x03, 0x00, 0x00, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, // ......9...#inclu
	0x64, 0x65, 0x20, 0x3c, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x73, 0x74, 0x64, 0x6c, 0x69, 0x62, // de <metal_stdlib
	0x3e, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65, 0x20, 0x3c, 0x73, 0x69, 0x6d, 0x64, // >.#include <simd
	0x2f, 0x73, 0x69, 0x6d, 0x64, 0x2e, 0x68, 0x3e, 0x0a, 0x0a, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, // /simd.h>..using 
	0x6e, 0x61, 0x6d, 0x65, 0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, // namespace metal;
	0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x5f, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c, // ..struct _Global
	0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x78, 0x34, 0x20, // .{.    float4x4 
	0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, // gpu_ModelViewPro
	0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x3b, 0x0a, 0x7d, // jectionMatrix;.}
	0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, // ;..struct xlatMt
	0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x0a, 0x7b, 0x0a, 0x09, 0x66, 0x6c, 0x6f, // lMain_out.{..flo
	0x61, 0x74, 0x20, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x5f, 0x70, 0x6f, // at bgfx_metal_po
	0x69, 0x6e, 0x74, 0x53, 0x69, 0x7a, 0x65, 0x20, 0x5b, 0x5b, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x5f, // intSize [[point_
	0x73, 0x69, 0x7a, 0x65, 0x5d, 0x5d, 0x20, 0x3d, 0x20, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, // size]] = 1;.    
	0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x5f, 0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, // float4 _entryPoi
	0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, // ntOutput_v_color
	0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, 0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x30, 0x29, 0x5d, // 0 [[user(locn0)]
	0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x20, 0x5f, 0x65, // ];.    float2 _e
	0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, // ntryPointOutput_
	0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x5b, 0x5b, 0x75, 0x73, // v_texcoord0 [[us
	0x65, 0x72, 0x28, 0x6c, 0x6f, 0x63, 0x6e, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, // er(locn1)]];.   
	0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, //  float4 gl_Posit
	0x69, 0x6f, 0x6e, 0x20, 0x5b, 0x5b, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x5d, 0x5d, // ion [[position]]
	0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, // ;.};..struct xla
	0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, 0x6e, 0x0a, 0x7b, 0x0a, 0x20, 0x20, // tMtlMain_in.{.  
	0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, //   float4 a_color
	0x30, 0x20, 0x5b, 0x5b, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x28, 0x30, 0x29, // 0 [[attribute(0)
	0x5d, 0x5d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x33, 0x20, 0x61, // ]];.    float3 a
	0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x5b, 0x5b, 0x61, 0x74, 0x74, 0x72, // _position [[attr
	0x69, 0x62, 0x75, 0x74, 0x65, 0x28, 0x31, 0x29, 0x5d, 0x5d, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, // ibute(1)]];.};..
	0x76, 0x65, 0x72, 0x74, 0x65, 0x78, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, // vertex xlatMtlMa
	0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, // in_out xlatMtlMa
	0x69, 0x6e, 0x28, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x69, // in(xlatMtlMain_i
	0x6e, 0x20, 0x69, 0x6e, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, 0x69, 0x6e, 0x5d, // n in [[stage_in]
	0x5d, 0x2c, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x20, 0x5f, 0x47, 0x6c, 0x6f, // ], constant _Glo
	0x62, 0x61, 0x6c, 0x26, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x20, 0x5b, 0x5b, 0x62, 0x75, // bal& _mtl_u [[bu
	0x66, 0x66, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, // ffer(0)]]).{.   
	0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x5f, 0x6f, 0x75, 0x74, //  xlatMtlMain_out
	0x20, 0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x7b, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, //  out = {};.    o
	0x75, 0x74, 0x2e, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, // ut.gl_Position =
	0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x28, 0x69, 0x6e, 0x2e, 0x61, 0x5f, 0x70, 0x6f, 0x73, //  float4(in.a_pos
	0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x20, 0x31, 0x2e, 0x30, 0x29, 0x20, 0x2a, 0x20, 0x5f, 0x6d, // ition, 1.0) * _m
	0x74, 0x6c, 0x5f, 0x75, 0x2e, 0x67, 0x70, 0x75, 0x5f, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, // tl_u.gpu_ModelVi
	0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, // ewProjectionMatr
	0x69, 0x78, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x5f, 0x65, 0x6e, 0x74, // ix;.    out._ent
	0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, 0x76, 0x5f, // ryPointOutput_v_
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x3d, 0x20, 0x69, 0x6e, 0x2e, 0x61, 0x5f, 0x63, 0x6f, // color0 = in.a_co
	0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6f, 0x75, 0x74, 0x2e, 0x5f, 0x65, // lor0;.    out._e
	0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x5f, // ntryPointOutput_
	0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, 0x20, 0x69, 0x6e, // v_texcoord0 = in
	0x2e, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x79, 0x3b, 0x0a, // .a_position.xy;.
	0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x6f, 0x75, 0x74, 0x3b, 0x0a, //     return out;.
	0x7d, 0x0a, 0x0a, 0x00, 0x03, 0x05, 0x00, 0x01, 0x00, 0x10, 0x00, 0x40, 0x00,                   // }..........@.
};
extern const uint8_t* vs_common_pssl;
extern const uint32_t vs_common_pssl_size;
