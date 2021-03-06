/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI

namespace Yelo
{
    namespace Rasterizer
    {
        namespace PostProcessing
        {
            class c_shader_data_base
            {
            protected:
                enum
                {
                    k_data_source_id_max_length = 48,
                };

            public:
                virtual ~c_shader_data_base() {}

                virtual void Ctor() = 0;
                virtual void Dtor() = 0;

                virtual const char* DataSourceID() = 0;
                virtual const void* GetData(uint32& data_size) = 0;
                virtual void Dispose() = 0;
                virtual const bool IsBinary() = 0;
                virtual const char* GetIncludePath() = 0;
                virtual const D3DXMACRO* GetMacros() = 0;
            };
        }
    }
}
#endif
