/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

#define K_AI_GLOBALS 0x6E73D4
#define K_ACTORS 0x6E73E0
#define K_SWARMS 0x6E73DC
#define K_SWARM_COMPONENTS 0x6E73D8
#define K_PROPS 0x6E7340
#define K_ENCOUNTERS 0x6E7348
#define K_SQUADS 0x6E734C
#define K_PLATOONS 0x6E7344
#define K_AI_PURSUITS 0x6E7350
#define K_AI_COMMUNICATION_REPLIES 0x5F4454
#define K_AI_CONVERSATIONS 0x6E7354
#define K_AI_UPDATE_HOOK 0x42A959
#define K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_HOOK 0x40B115
#define K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_RETN 0x40B11A
#define K_PROP_STATUS_REFRESH_HOOK 0x41C9DE
#define K_PROP_STATUS_REFRESH_RETN 0x41C9E4
#define K_ACTOR_INPUT_UPDATE_HOOK 0x429CB7
#define K_ACTOR_INPUT_UPDATE_RETN 0x429CBE
#define K_TERMINAL_GLOBALS 0x5BFC0C
#define K_CONSOLE_GLOBALS 0x5C3D10
#define K_CONSOLE_UPDATE_HOOK 0x4B33C7
#define K_CONTRAILS 0x6E1C4C
#define K_CONTRAIL_POINTS 0x6E1C48
#define K_PARTICLES 0x6E1C30
#define K_EFFECTS 0x6E1C3C
#define K_EFFECT_LOCATIONS 0x6E1C40
#define K_PARTICLE_SYSTEMS 0x6E1C34
#define K_PARTICLE_SYSTEM_PARTICLES 0x6E1C38
#define K_STRUCTURE_DETAIL_OBJECTS 0x6260D4
#define K_BREAKABLE_SURFACE_GLOBALS 0x5C5B90
#define K_DECALS 0x6E1C44
#define K_DECAL_GLOBALS 0x5BD7E8
#define K_EFFECTS_UPDATE_HOOK 0x44FE97
#define K_GAME_BUILD_VERSION 0x564ADC
#define K_NETWORK_VERSION_ID1 0x4C3636
#define K_NETWORK_VERSION_ID2 0x4C3813
#define K_NETWORK_VERSION_ID3 0x4CB1A3
#define K_GAME_STATE_HEADER_IS_VALID_HOOK 0x4F6D77
#define K_GAME_STATE_HEADER_IS_VALID_HOOK_RET 0x4F6DCB
#define K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK 0x4F6B2E
#define K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_TRUE 0x4F6B8E
#define K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_FALSE 0x4F6C49
#define K_CTF_GLOBALS 0x5BDB98
#define K_SLAYER_GLOBALS 0x5BE0E8
#define K_ODDBALL_GLOBALS 0x5BDE58
#define K_KING_GLOBALS 0x5BDBD0
#define K_RACE_GLOBALS 0x5BDFA0
#define K_GLOBAL_VARIANT 0x5F5478
#define K_GAME_ENGINES 0x599288
#define K_GAME_ENGINE 0x5F5554
#define K_FUNC4F7440JMPTABLE 0x4D0D9D
#define K_FUNC4F7440JMPPTR 0x4DE175
#define K_FUNC4F7580JMPTABLE 0x45E841
#define K_FUNC4F7580JMPPTR 0x4DE2D3
#define K_GAME_ENGINE_INIT_MOD 0x459624
#define K_GAME_ENGINE_INITIALIZE_FOR_NEW_MAP_HOOK 0x459758
#define K_GAME_ENGINE_UPDATE_HOOK 0x45BB9B
#define K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_0 0x4B3E51
#define K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_1 0x4F6A30
#define K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_0 0x4F6ACD
#define K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_1 0x4F6C13
#define K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_2 0x4F6D05
#define K_GAME_STATE_AFTER_LOAD_PROCS_REF_0 0x4F67F3
#define K_GAME_STATE_AFTER_LOAD_PROCS_REF_1 0x4F6AD9
#define K_GAME_STATE_AFTER_LOAD_PROCS_REF_2 0x4F6D2F
#define K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_0 0x4F67F8
#define K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_1 0x4F6ADE
#define K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_2 0x4F6D34
#define K_MAIN_GLOBALS 0x61CFC0
#define K_PHYSICAL_MEMORY_GLOBALS 0x5B9258
#define K_PHYSICAL_MEMORY_INITIALIZE 0x444EE0
#define K_PHYSICAL_MEMORY_ALLOCATION_SIZE 0x444F02
#define K_GAME_STATE_GLOBALS 0x5E6684
#define K_GAME_GLOBALS 0x5BD890
#define K_GAME_TIME_GLOBALS 0x5F559C
#define K_GAME_ALLEGIANCE_GLOBALS 0x5BD894
#define K_GLOBAL_GAME_GLOBALS 0x629440
#define K_GLOBAL_PHYSICS 0x5AD5BC
#define K_GLOBAL_POINT_PHYSICS 0x5C5B94
#define K_DEVELOPER_MODE 0x6E1C66
#define K_TRANSPORT_DUMPING 0x5F4CA4
#define K_DEVMODE_ENABLED 0x62583E
#define K_GAME_INITIALIZE_HOOK 0x458080
#define K_GAME_INITIALIZE_FOR_NEW_MAP_HOOK 0x458685
#define K_GAME_DISPOSE_FROM_OLD_MAP_HOOK 0x4587E8
#define K_GAME_SCENARIO_SWITCH_BSP_CALL_0 0x478D00
#define K_GAME_SCENARIO_SWITCH_BSP_CALL_1 0x4B6317
#define K_GAME_SCENARIO_SWITCH_BSP_CALL_2 0x4B6441
#define K_GAME_SCENARIO_SWITCH_BSP_CALL_3 0x4FC9DC
#define K_GAME_SCENARIO_SWITCH_BSP_CALL_4 0x4FD045
#define K_GAME_DISPOSE_FROM_OLD_BSP_HOOK 0x443516
#define K_GAME_CREATE_NETWORK_SERVER 0x4C9480
#define K_GAME_CREATE_NETWORK_CLIENT 0x4C3320
#define K_LIGHTS 0x6C7130
#define K_LIGHT_GAME_GLOBALS 0x620A20
#define K_LIGHT_CLUSTER 0x6C7140
#define K_CLUSTER_LIGHT_REFERENCE 0x6C7144
#define K_LIGHT_CLUSTER_REFERENCE 0x6C7148
#define K_TEAMS 0x6E145C
#define K_PLAYER_CONTROL_GLOBALS 0x5BE16C
#define K_PLAYER_EFFECTS 0x5F5074
#define K_MACHINE_TO_PLAYER_TABLE 0x5BE170
#define K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK 0x472521
#define K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK_RETN 0x472640
#define K_PLAYERS_UPDATE_BEFORE_GAME_SERVER_HOOK 0x46EB87
#define K_PLAYERS_UPDATE_BEFORE_GAME_CLIENT_HOOK 0x46EFBB
#define K_PLAYERS_UPDATE_AFTER_GAME_HOOK 0x46F34B
#define K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE 0x49BA0A
#define K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE 0x4E4130
#define K_PLAYER_HANDLE_ACTION_JMP_TABLE_ADJUST_SIZE 0x473983
#define K_PLAYER_HANDLE_ACTION_JMP_TABLE_RETN 0x473C7B
#define K_PLAYER_HANDLE_ACTION_LAST_ENTRY_TYPE 0x473988
#define K_PLAYER_HANDLE_ACTION_JMP_PTR 0x473999
#define K_PLAYER_HANDLE_ACTION_JMP_TABLE 0x4A7987
