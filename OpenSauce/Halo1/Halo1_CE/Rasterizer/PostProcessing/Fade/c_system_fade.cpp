/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#include "Common/Precompile.hpp"
#include "Rasterizer/PostProcessing/Fade/c_system_fade.hpp"

#if !PLATFORM_IS_DEDI

#include "Rasterizer/PostProcessing/PostProcessing.hpp"
#include "Rasterizer/PostProcessing/c_post_processing_main.hpp"
#include "Rasterizer/PostProcessing/Fade/c_shader_fade.hpp"
#include "Rasterizer/PostProcessing/Fade/c_shader_instance_fade.hpp"

namespace Yelo
{
    namespace Rasterizer
    {
        namespace PostProcessing
        {
            namespace Fade
            {
                c_system_fade c_system_fade::g_fade_system;

                static TagGroups::s_pass_definition g_shader_passes[1] =
                {
                    { "EffectFade", { 0, 0 }, 0 },
                };

                static TagGroups::s_technique_definition g_shader_techniques[1] =
                {
                    {
                        "PostProcess",
                        { 1, 1, 1 },
                        { 0 },
                        { NUMBEROF(g_shader_passes), &g_shader_passes[0], NULL }
                    }
                };

                static s_shader_fade_definition g_shader_fade_definition;

                static c_shader_fade g_shader_fade;
                static c_shader_instance_fade g_shader_instance_fade;
                static TagGroups::s_effect_postprocess_quad_definition g_quad_definition;
                static Render::c_quad_instance* g_quad_instance;

                c_system_fade& c_system_fade::Instance()
                {
                    return g_fade_system;
                }

                bool c_system_fade::IsReady()
                {
                    return m_members.m_flags.is_ready;
                }

                bool c_system_fade::IsUnloaded()
                {
                    return m_members.m_flags.is_unloaded;
                }

                void c_system_fade::Initialize()
                {
                    m_members.status = Enums::pp_component_status_uninitialised;

                    m_members.m_flags.is_ready = false;
                    m_members.m_flags.is_unloaded = false;

                    g_shader_fade_definition.runtime.flags.valid_shader_bit = false;
                    g_shader_fade_definition.techniques.Count = NUMBEROF(g_shader_techniques);
                    g_shader_fade_definition.techniques.Address = &g_shader_techniques[0];

                    // initialise the effect
                    g_quad_definition.tessellation.x = 5;
                    g_quad_definition.tessellation.y = 5;
                    g_quad_definition.x_bounds.lower = 0;
                    g_quad_definition.x_bounds.upper = 1;
                    g_quad_definition.y_bounds.lower = 0;
                    g_quad_definition.y_bounds.upper = 1;

                    // initialise the bloom shader
                    g_shader_fade.Ctor();
                    g_shader_fade.SetShaderDefinition(&g_shader_fade_definition);
                    g_shader_fade.SetupShader();

                    // initialise the shader instance
                    g_shader_instance_fade.Ctor();
                    g_shader_instance_fade.SetShader(&g_shader_fade);
                }

                void c_system_fade::Dispose()
                {
                    m_members.status = Enums::pp_component_status_uninitialised;

                    m_members.m_flags.is_ready = false;
                    m_members.m_flags.is_unloaded = false;

                    g_shader_instance_fade.Dtor();
                    g_shader_fade.Dtor();
                }

                void c_system_fade::InitializeResources_Base(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* parameters)
                {
                    // create the direct3d resources of the shader
                    auto hr = CreateShader();

                    Validate();

                    if (SUCCEEDED(hr))
                    {
                        m_members.status = Enums::pp_component_status_initialised;
                    }
                    else
                    {
                        m_members.status = Enums::pp_component_status_initialisation_failed;
                    }

                    UpdateStatus();
                }

                void c_system_fade::OnLostDevice_Base()
                {
                    // call on device lost on the shaders effect
                    if (!m_members.m_flags.is_unloaded)
                    {
                        SetDeviceLost();
                    }
                    Validate();

                    UpdateStatus();
                }

                void c_system_fade::OnResetDevice_Base(D3DPRESENT_PARAMETERS* parameters)
                {
                    // call on device reset on the shaders effect
                    auto hr = E_FAIL;
                    if (!m_members.m_flags.is_unloaded)
                    {
                        hr = SetDeviceReset();
                    }
                    Validate();

                    if (SUCCEEDED(hr))
                    {
                        m_members.status = Enums::pp_component_status_initialised;
                    }
                    else
                    {
                        m_members.status = Enums::pp_component_status_initialisation_failed;
                    }

                    UpdateStatus();
                }

                void c_system_fade::ReleaseResources_Base()
                {
                    // release the direct 3d resources
                    DestroyShader();
                    Validate();

                    m_members.status = Enums::pp_component_status_uninitialised;

                    UpdateStatus();
                }

                void c_system_fade::Unload()
                {
                    // release the direct3d resources of the shader
                    DestroyShader();
                    Validate();

                    m_members.status = Enums::pp_component_status_uninitialised;
                    m_members.m_flags.is_unloaded = true;

                    UpdateStatus();
                }

                void c_system_fade::Load()
                {
                    auto hr = E_FAIL;
                    // create the direct3d resources of the shader
                    if (m_members.m_flags.is_unloaded)
                    {
                        hr = CreateShader();

                        Validate();

                        if (SUCCEEDED(hr))
                        {
                            m_members.status = Enums::pp_component_status_initialised;
                        }
                        else
                        {
                            m_members.status = Enums::pp_component_status_initialisation_failed;
                        }

                        m_members.m_flags.is_unloaded = false;
                    }

                    UpdateStatus();
                }

                HRESULT c_system_fade::CreateShader()
                {
                    g_quad_instance = c_post_processing_main::Instance().Globals().quad_collection.CreateQuadInstance(g_quad_definition);

                    return g_shader_fade.LoadShader(c_post_processing_main::Instance().Globals().render_device);
                }

                void c_system_fade::DestroyShader()
                {
                    safe_release(g_quad_instance);
                    // release the shader effect
                    g_shader_fade.UnloadShader();
                }

                void c_system_fade::SetDeviceLost()
                {
                    // call OnDeviceLost on the shader effect
                    g_shader_fade.OnDeviceLost();
                }

                HRESULT c_system_fade::SetDeviceReset()
                {
                    // call OnDeviceReset on the shader effect
                    return g_shader_fade.OnDeviceReset();
                }

                void c_system_fade::Validate()
                {
                    g_shader_fade.Validate();
                    g_shader_instance_fade.Validate();
                }

                void c_system_fade::UpdateStatus()
                {
                    m_members.m_flags.is_ready = false;
                    do
                    {
                        if (m_members.status != Enums::pp_component_status_initialised)
                        {
                            break;
                        }
                        if (!g_shader_instance_fade.IsValid())
                        {
                            break;
                        }
                        if (!g_quad_instance)
                        {
                            break;
                        }

                        m_members.m_flags.is_ready = true;
                    } while (false);
                }

                HRESULT c_system_fade::FadeCurrentResult(real fade_amount)
                {
                    return g_shader_instance_fade.Render(c_post_processing_main::Instance().Globals().render_device, g_quad_instance, fade_amount);
                }
            };
        };
    };
};
#endif
