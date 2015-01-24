--	Yelo: Open Sauce SDK
--		Halo 1 (CE) Edition

--	See license\OpenSauce\Halo1_CE for specific license information

HaloCEServer_Game =
{
--////////////////////////////////////////////////////////////////////////
-- AI.cpp
	["K_AI_GLOBALS"] =                                           0x6E73F4,
	["K_ACTORS"] =                                               0x6E7400,
	["K_SWARMS"] =                                               0x6E73FC,
	["K_SWARM_COMPONENTS"] =                                     0x6E73F8,
	["K_PROPS"] =                                                0x6E7360,
	["K_ENCOUNTERS"] =                                           0x6E7368,
	["K_SQUADS"] =                                               0x6E736C,
	["K_PLATOONS"] =                                             0x6E7364,
	["K_AI_PURSUITS"] =                                          0x6E7370,

	["K_AI_COMMUNICATION_REPLIES"] =                             0x5F4474,
	["K_AI_CONVERSATIONS"] =                                     0x6E7374,

	["K_AI_UPDATE_HOOK"] =                                       0x42A959,
	["K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_HOOK"] =                0x40B115,
	["K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_RETN"] =                0x40B11A,
	
--////////////////////////////////////////////////////////////////////////
-- Console.cpp
	["K_TERMINAL_GLOBALS"] =                                     0x5BFC2C,
	["K_CONSOLE_GLOBALS"] =                                      0x5C3D30,

	["K_CONSOLE_UPDATE_HOOK"] =                                  0x4B3637,
	
--////////////////////////////////////////////////////////////////////////
-- Effects.cpp
	["K_CONTRAILS"] =                                            0x6E1C6C,
	["K_CONTRAIL_POINTS"] =                                      0x6E1C68,
	["K_PARTICLES"] =                                            0x6E1C50,
	["K_EFFECTS"] =                                              0x6E1C5C,
	["K_EFFECT_LOCATIONS"] =                                     0x6E1C60,
	["K_PARTICLE_SYSTEMS"] =                                     0x6E1C54,
	["K_PARTICLE_SYSTEM_PARTICLES"] =                            0x6E1C58,
	["K_STRUCTURE_DETAIL_OBJECTS"] =                             0x6260F4,
	["K_STRUCTURE_DECALS"] =                                     0x626104,
	["K_BREAKABLE_SURFACE_GLOBALS"] =                            0x5C5BB0,
	["K_DECALS"] =                                               0x6E1C64,
	["K_DECAL_GLOBALS"] =                                        0x5BD808,

	["K_EFFECTS_UPDATE_HOOK"] =                                  0x4500C7,
	
--////////////////////////////////////////////////////////////////////////
-- GameBuildNumber.cpp
	["K_GAME_BUILD_VERSION"] =                                   0x564B34,
	["K_GAME_BUILD_VERSION_GAMESPY"] =                           0x626398,
	["K_NETWORK_VERSION_ID1"] =                                  0x4C3866,
	["K_NETWORK_VERSION_ID2"] =                                  0x4C3A43,
	["K_NETWORK_VERSION_ID3"] =                                  0x4CB583,

	["K_GAME_STATE_HEADER_IS_VALID_HOOK"] =                      0x4F7187 + 0x30,
	["K_GAME_STATE_HEADER_IS_VALID_HOOK_RET"] =                  0x4F71DB + 0x30,
	["K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK"] =                  0x4F6F3E + 0x30,
	["K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_TRUE"] =         0x4F6F9E + 0x30,
	["K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_FALSE"] =        0x4F7059 + 0x30,
	
--////////////////////////////////////////////////////////////////////////
-- GameEngine.cpp
	["K_CTF_GLOBALS"] =                                          0x5BDBB8,
	["K_SLAYER_GLOBALS"] =                                       0x5BE108,
	["K_ODDBALL_GLOBALS"] =                                      0x5BDE78,
	["K_KING_GLOBALS"] =                                         0x5BDBF0,
	["K_RACE_GLOBALS"] =                                         0x5BDFC0,
	["K_GLOBAL_VARIANT"] =                                       0x5F5498,
	["K_GAME_ENGINES"] =                                         0x599288,
	["K_GAME_ENGINE"] =                                          0x5F5574,
	
--////////////////////////////////////////////////////////////////////////
-- FixFunc4F7440()
	["K_FUNC4F7440JMPTABLE"] =                                   0x4DE6AC,
	["K_FUNC4F7440JMPPTR"] =                                     0x4DE5C5,
	
--////////////////////////////////////////////////////////////////////////
-- FixFunc4F7580()
	["K_FUNC4F7580JMPTABLE"] =                                   0x4DE7AC,
	["K_FUNC4F7580JMPPTR"] =                                     0x4DE723,
	
--////////////////////////////////////////////////////////////////////////
-- Initialize()
	["K_GAME_ENGINE_INIT_MOD"] =                                 0x459854,

	["K_GAME_ENGINE_INITIALIZE_FOR_NEW_MAP_HOOK"] =              0x459988,
	["K_GAME_ENGINE_UPDATE_HOOK"] =                              0x45BDCB,
	
--////////////////////////////////////////////////////////////////////////
-- GameState.cpp
	["K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_0"] =                  0x4B4091 + 0x30,
	["K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_1"] =                  0x4F6E40 + 0x30,
	
	["K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_0"] =                  0x4F6EDD + 0x30,
	["K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_1"] =                  0x4F7023 + 0x30,
	["K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_2"] =                  0x4F7115 + 0x30,
	
	["K_GAME_STATE_AFTER_LOAD_PROCS_REF_0"] =                    0x4F6C02 + 1 + 0x30,
	["K_GAME_STATE_AFTER_LOAD_PROCS_REF_1"] =                    0x4F6EE8 + 1 + 0x30,
	["K_GAME_STATE_AFTER_LOAD_PROCS_REF_2"] =                    0x4F713E + 1 + 0x30,
	
	["K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_0"] =                  0x4F6C07 + 1 + 0x30,
	["K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_1"] =                  0x4F6EED + 1 + 0x30,
	["K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_2"] =                  0x4F7143 + 1 + 0x30,
	
	["K_MAIN_GLOBALS"] =                                         0x61CFE0,
	["K_PHYSICAL_MEMORY_GLOBALS"] =                              0x5B9278,
	["K_PHYSICAL_MEMORY_INITIALIZE"] =                           0x4450C0,
	["K_PHYSICAL_MEMORY_ALLOCATION_SIZE"] =                      0x4450E2,
	["K_GAME_STATE_GLOBALS"] =                                   0x5E66A4,
	["K_GAME_GLOBALS"] =                                         0x5BD8B0,
	["K_GAME_TIME_GLOBALS"] =                                    0x5F55BC,
	["K_GAME_ALLEGIANCE_GLOBALS"] =                              0x5BD8B4,
	["K_GLOBAL_GAME_GLOBALS"] =                                  0x629460,
	["K_GLOBAL_PHYSICS"] =                                       0x5AD5CC,
	["K_GLOBAL_POINT_PHYSICS"] =                                 0x5C5BB4,
	["K_DEVELOPER_MODE"] =                                       0x6E1C86,
	["K_TRANSPORT_DUMPING"] =                                    0x597918,
	["K_DEVMODE_ENABLED"] =                                      0x62585E,

	["K_GAME_INITIALIZE_HOOK"] =                                 0x4582B0,
	["K_GAME_INITIALIZE_FOR_NEW_MAP_HOOK"] =                     0x4588B5,
	["K_GAME_DISPOSE_FROM_OLD_MAP_HOOK"] =                       0x458A18,
	
	["K_GAME_SCENARIO_SWITCH_BSP_CALL_0"] =                      0x479F80,
	["K_GAME_SCENARIO_SWITCH_BSP_CALL_1"] =                      0x4B6547,
	["K_GAME_SCENARIO_SWITCH_BSP_CALL_2"] =                      0x4B6671,
	["K_GAME_SCENARIO_SWITCH_BSP_CALL_3"] =                      0x4FCE1C,
	["K_GAME_SCENARIO_SWITCH_BSP_CALL_4"] =                      0x4FD485,
	
	["K_GAME_DISPOSE_FROM_OLD_BSP_HOOK"] =                       0x443526,

	["K_GAME_CREATE_NETWORK_SERVER"] =                           0x4C96C0,
	["K_GAME_CREATE_NETWORK_CLIENT"] =                           0x4C3550,
	
--////////////////////////////////////////////////////////////////////////
-- Lights.cpp
	["K_LIGHTS"] =                                               0x6C7150,
	["K_LIGHT_GAME_GLOBALS"] =                                   0x620A40,
	["K_LIGHT_CLUSTER"] =                                        0x6C7160,
	["K_CLUSTER_LIGHT_REFERENCE"] =                              0x6C7164,
	["K_LIGHT_CLUSTER_REFERENCE"] =                              0x6C7168,
	
--////////////////////////////////////////////////////////////////////////
-- Players.cpp
	["K_PLAYERS"] =                                              0x6E1480,
	["K_TEAMS"] =                                                0x6E147C,
	["K_PLAYERS_GLOBALS"] =                                      0x6E1478,
	["K_PLAYER_CONTROL_GLOBALS"] =                               0x5BE18C,
	["K_PLAYER_EFFECTS"] =                                       0x5F5094,
	["K_MACHINE_TO_PLAYER_TABLE"] =                              0x5BE190,

	["K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK"] =                    0x4727A1,
	["K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK_RETN"] =               0x4728C0,

	["K_PLAYERS_UPDATE_BEFORE_GAME_SERVER_HOOK"] =               0x46EE37,
	["K_PLAYERS_UPDATE_BEFORE_GAME_CLIENT_HOOK"] =               0x46F26B,
	["K_PLAYERS_UPDATE_AFTER_GAME_HOOK"] =                       0x46F5FB,
	
--////////////////////////////////////////////////////////////////////////
-- Players.NearbyObjects
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE_RETN"] =  0x472CE8,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_PTR"] =         0x472CC8,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_LAST_ENTRY_TYPE"] = 0x472CC2,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE"] =       0x472CF4,

	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE_RETN"] =  0x472DE8,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_PTR"] =         0x472DC8,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_LAST_ENTRY_TYPE"] = 0x472DC2,
	["K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE"] =       0x472DF4,
	
--////////////////////////////////////////////////////////////////////////
-- Players.ActionResults
	["K_PLAYER_HANDLE_ACTION_JMP_TABLE_ADJUST_SIZE"] =           0x473C03,
	["K_PLAYER_HANDLE_ACTION_JMP_TABLE_RETN"] =                  0x473EFB,
	["K_PLAYER_HANDLE_ACTION_LAST_ENTRY_TYPE"] =                 0x473C08,
	["K_PLAYER_HANDLE_ACTION_JMP_PTR"] =                         0x473C19,
	["K_PLAYER_HANDLE_ACTION_JMP_TABLE"] =                       0x473F08,
}

HaloCEServer_Game_Index =
{
	[1] = "K_AI_GLOBALS",
	[2] = "K_ACTORS",
	[3] = "K_SWARMS",
	[4] = "K_SWARM_COMPONENTS",
	[5] = "K_PROPS",
	[6] = "K_ENCOUNTERS",
	[7] = "K_SQUADS",
	[8] = "K_PLATOONS",
	[9] = "K_AI_PURSUITS",
	[10] = "K_AI_COMMUNICATION_REPLIES",
	[11] = "K_AI_CONVERSATIONS",
	[12] = "K_AI_UPDATE_HOOK",
	[13] = "K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_HOOK",
	[14] = "K_ACTOR_ACTION_HANDLE_VEHICLE_EXIT_RETN",
	[15] = "K_TERMINAL_GLOBALS",
	[16] = "K_CONSOLE_GLOBALS",
	[17] = "K_CONSOLE_UPDATE_HOOK",
	[18] = "K_CONTRAILS",
	[19] = "K_CONTRAIL_POINTS",
	[20] = "K_PARTICLES",
	[21] = "K_EFFECTS",
	[22] = "K_EFFECT_LOCATIONS",
	[23] = "K_PARTICLE_SYSTEMS",
	[24] = "K_PARTICLE_SYSTEM_PARTICLES",
	[25] = "K_STRUCTURE_DETAIL_OBJECTS",
	[26] = "K_STRUCTURE_DECALS",
	[27] = "K_BREAKABLE_SURFACE_GLOBALS",
	[28] = "K_DECALS",
	[29] = "K_DECAL_GLOBALS",
	[30] = "K_EFFECTS_UPDATE_HOOK",
	[31] = "K_GAME_BUILD_VERSION",
	[32] = "K_GAME_BUILD_VERSION_GAMESPY",
	[33] = "K_NETWORK_VERSION_ID1",
	[34] = "K_NETWORK_VERSION_ID2",
	[35] = "K_NETWORK_VERSION_ID3",
	[36] = "K_GAME_STATE_HEADER_IS_VALID_HOOK",
	[37] = "K_GAME_STATE_HEADER_IS_VALID_HOOK_RET",
	[38] = "K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK",
	[39] = "K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_TRUE",
	[40] = "K_GAME_STATE_HEADER_TRY_AND_LOAD_HOOK_RET_FALSE",
	[41] = "K_CTF_GLOBALS",
	[42] = "K_SLAYER_GLOBALS",
	[43] = "K_ODDBALL_GLOBALS",
	[44] = "K_KING_GLOBALS",
	[45] = "K_RACE_GLOBALS",
	[46] = "K_GLOBAL_VARIANT",
	[47] = "K_GAME_ENGINES",
	[48] = "K_GAME_ENGINE",
	[49] = "K_FUNC4F7440JMPTABLE",
	[50] = "K_FUNC4F7440JMPPTR",
	[51] = "K_FUNC4F7580JMPTABLE",
	[52] = "K_FUNC4F7580JMPPTR",
	[53] = "K_GAME_ENGINE_INIT_MOD",
	[54] = "K_GAME_ENGINE_INITIALIZE_FOR_NEW_MAP_HOOK",
	[55] = "K_GAME_ENGINE_UPDATE_HOOK",
	[56] = "K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_0",
	[57] = "K_GAME_STATE_BEFORE_SAVE_PROCS_CALL_1",
	[58] = "K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_0",
	[59] = "K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_1",
	[60] = "K_GAME_STATE_BEFORE_LOAD_PROCS_CALL_2",
	[61] = "K_GAME_STATE_AFTER_LOAD_PROCS_REF_0",
	[62] = "K_GAME_STATE_AFTER_LOAD_PROCS_REF_1",
	[63] = "K_GAME_STATE_AFTER_LOAD_PROCS_REF_2",
	[64] = "K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_0",
	[65] = "K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_1",
	[66] = "K_GAME_STATE_AFTER_LOAD_PROCS_COUNT_2",
	[67] = "K_MAIN_GLOBALS",
	[68] = "K_PHYSICAL_MEMORY_GLOBALS",
	[69] = "K_PHYSICAL_MEMORY_INITIALIZE",
	[70] = "K_PHYSICAL_MEMORY_ALLOCATION_SIZE",
	[71] = "K_GAME_STATE_GLOBALS",
	[72] = "K_GAME_GLOBALS",
	[73] = "K_GAME_TIME_GLOBALS",
	[74] = "K_GAME_ALLEGIANCE_GLOBALS",
	[75] = "K_GLOBAL_GAME_GLOBALS",
	[76] = "K_GLOBAL_PHYSICS",
	[77] = "K_GLOBAL_POINT_PHYSICS",
	[78] = "K_DEVELOPER_MODE",
	[79] = "K_TRANSPORT_DUMPING",
	[80] = "K_DEVMODE_ENABLED",
	[81] = "K_GAME_INITIALIZE_HOOK",
	[82] = "K_GAME_INITIALIZE_FOR_NEW_MAP_HOOK",
	[83] = "K_GAME_DISPOSE_FROM_OLD_MAP_HOOK",
	[84] = "K_GAME_SCENARIO_SWITCH_BSP_CALL_0",
	[85] = "K_GAME_SCENARIO_SWITCH_BSP_CALL_1",
	[86] = "K_GAME_SCENARIO_SWITCH_BSP_CALL_2",
	[87] = "K_GAME_SCENARIO_SWITCH_BSP_CALL_3",
	[88] = "K_GAME_SCENARIO_SWITCH_BSP_CALL_4",
	[89] = "K_GAME_DISPOSE_FROM_OLD_BSP_HOOK",
	[90] = "K_GAME_CREATE_NETWORK_SERVER",
	[91] = "K_GAME_CREATE_NETWORK_CLIENT",
	[92] = "K_LIGHTS",
	[93] = "K_LIGHT_GAME_GLOBALS",
	[94] = "K_LIGHT_CLUSTER",
	[95] = "K_CLUSTER_LIGHT_REFERENCE",
	[96] = "K_LIGHT_CLUSTER_REFERENCE",
	[97] = "K_PLAYERS",
	[98] = "K_TEAMS",
	[99] = "K_PLAYERS_GLOBALS",
	[100] = "K_PLAYER_CONTROL_GLOBALS",
	[101] = "K_PLAYER_EFFECTS",
	[102] = "K_MACHINE_TO_PLAYER_TABLE",
	[103] = "K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK",
	[104] = "K_PLAYER_SPAWN__CREATE_UNIT_MP_HOOK_RETN",
	[105] = "K_PLAYERS_UPDATE_BEFORE_GAME_SERVER_HOOK",
	[106] = "K_PLAYERS_UPDATE_BEFORE_GAME_CLIENT_HOOK",
	[107] = "K_PLAYERS_UPDATE_AFTER_GAME_HOOK",
	[108] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE_RETN",
	[109] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_PTR",
	[110] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_LAST_ENTRY_TYPE",
	[111] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_SERVER_JMP_TABLE",
	[112] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE_RETN",
	[113] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_PTR",
	[114] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_LAST_ENTRY_TYPE",
	[115] = "K_PLAYER_EXAMINE_NEARBY_OBJECTS_CLIENT_JMP_TABLE",
	[116] = "K_PLAYER_HANDLE_ACTION_JMP_TABLE_ADJUST_SIZE",
	[117] = "K_PLAYER_HANDLE_ACTION_JMP_TABLE_RETN",
	[118] = "K_PLAYER_HANDLE_ACTION_LAST_ENTRY_TYPE",
	[119] = "K_PLAYER_HANDLE_ACTION_JMP_PTR",
	[120] = "K_PLAYER_HANDLE_ACTION_JMP_TABLE",
}