/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/


//////////////////////////////////////////////////////////////////////////
// ShaderDraw.cpp
#if __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_SHADERDRAW
	ENGINE_PTR(void*, RASTERIZER_ENVIRONMENT_DRAW_LIGHTMAP_SHADER_DRAW__DRAW_SHADER_LIGHTMAP_PTR,	0x51A4E4, PTR_NULL);
	ENGINE_PTR(void*, RASTERIZER_MODEL_DRAW_ENVIRONMENT_SHADER_DRAW__DRAW_SHADER_ENVIRONMENT_PTR,	0x52EB05, PTR_NULL);
	ENGINE_PTR(void*, RASTERIZER_MODEL_DRAW_ENVIRONMENT_SHADER_DRAW__DRAW_SHADER_MODEL_PTR,			0x52EB0F, PTR_NULL);

	FUNC_PTR(RASTERIZER_ENVIRONMENT_DRAW_LIGHTMAP,								0x522D40, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_DRAW_ENVIRONMENT_SHADER_ENVIRONMENT,				0x52B710, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_MODEL_DRAW_ENVIRONMENT_SHADER_MODEL,					0x52D430, FUNC_PTR_NULL);
#else
	#error Undefined engine layout include for: __EL_RASTERIZER_SHADEREXTENSION
#endif