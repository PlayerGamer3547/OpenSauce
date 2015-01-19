/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#include "Common/Precompile.hpp"
#include "Engine/Game.hpp"

#include "Engine/Objects.hpp"
#include "Engine/Units.hpp"
#include "Engine/AI.hpp"

namespace Yelo
{
	namespace Game
	{
#if PLATFORM_TYPE == PLATFORM_SAPIEN
		FUNC_PTR(UI_WIDGETS_SAFE_TO_LOAD,						PTR_NULL, PTR_NULL, 0x5BC480);
		FUNC_PTR(GAME_INITIALIZE_FOR_NEW_MAP_HOOK,				PTR_NULL, PTR_NULL, 0x618337);
		FUNC_PTR(GAME_DISPOSE_FROM_OLD_MAP_HOOK,				PTR_NULL, PTR_NULL, 0x617419);

		void PLATFORM_API InitializeForNewMap()
		{
			Objects::Units::InitializeForNewMap();
			AI::InitializeForNewMap();
		}

		void PLATFORM_API DisposeFromOldMap()
		{
			Objects::Units::DisposeFromOldMap();
			AI::DisposeFromOldMap();
		}

		API_FUNC_NAKED void InitializeForNewMapHook()
		{
			static uintptr_t CALL_ADDRESS = GET_FUNC_PTR(UI_WIDGETS_SAFE_TO_LOAD);

			_asm
			{
				call	CALL_ADDRESS
				pop		ecx
				call	InitializeForNewMap
				retn
			}
		}

		API_FUNC_NAKED void DisposeFromOldMapHook()
		{
			_asm
			{
				mov     byte ptr [eax+1], 0
				call	DisposeFromOldMap
				retn
			}
		}
#endif

		void Initialize()
		{
#if PLATFORM_TYPE == PLATFORM_SAPIEN
			Memory::WriteRelativeJmp(&InitializeForNewMapHook, GET_FUNC_VPTR(GAME_INITIALIZE_FOR_NEW_MAP_HOOK), true);
			Memory::WriteRelativeJmp(&DisposeFromOldMapHook, GET_FUNC_VPTR(GAME_DISPOSE_FROM_OLD_MAP_HOOK), true);
#endif

			AI::Initialize();
		}

		void Dispose()
		{
			AI::Dispose();
		}
	};
};