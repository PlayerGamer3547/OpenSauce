/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

#pragma once

#include <yelo/cseries/KillCxxExceptions.hpp>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "resource.h"
#include <windows.h>
#include <sal.h>

#include <WinSock2.h>

#include <shlobj.h>
#include <shlwapi.h>
#pragma comment (lib, "shlwapi.lib")

#define _USE_MATH_DEFINES // hurrrrrrrrrr, i like math!
#include <math.h>
#include <d3dx9math.h>

#if !PLATFORM_IS_DEDI
	#include <d3dx9.h>

	#define DIRECTINPUT_VERSION 0x0800
	#include <Dinput.h>
#endif

#include <vld.h>

//////////////////////////////////////////////////////////////////////////
// STD C includes
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <io.h>
#include <errno.h>
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// STL includes
#include <array>
#include <iterator>
#include <memory> // std::unique_ptr
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <thread>
#include <random>
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// Boost includes
#ifdef API_DEBUG
	#define BOOST_LIB_DIAGNOSTIC
#endif

#include <boost/preprocessor.hpp>
#include <boost/static_assert.hpp>

#include <boost/integer/static_log2.hpp>
//////////////////////////////////////////////////////////////////////////


#include <TinyXml/tinyxml.hpp>


//////////////////////////////////////////////////////////////////////////
// GameSpy includes & definitions

#if defined(YELO_USE_GAMESPY_OPEN)

	/*
		GameSpy SDK bug fix:
		There is a bug in GHTTP that causes HTTP redirects to fail if both
		the 'Content-Location' and 'Location' headers are returned by the server.

		Use the following on line 1695 in ghttpProcess.c to fix this:

			// Find the new location.
            /////////////////////////
            location = strstr(headers, "\r\nLocation:");// YELO: UPDATE THIS LINE
            if(location)
            {
                char * end;

                // Find the start of the URL.
                /////////////////////////////
                location += 11;							// YELO: UPDATE THIS LINE

	*/
//	STATIC_ASSERT(false); // comment this out once the fix is applied

	// Just to make sure we're always using ASCII
	#undef GSI_UNICODE

	#include <GameSpyOpen/ghttp/ghttp.h>
	
	#define YELO_VERSION_CHECK_ENABLE

#endif
//////////////////////////////////////////////////////////////////////////

#if !defined(_DEBUG)
	#define YELO_NO_NETWORK
#endif

//#define API_DEBUG_MEMORY

#include "Common/Platform.hpp"

#if PLATFORM_IS_DEDI
	#define API_NO_7ZIP_CODEC
	#define API_NO_ZIP_CODEC
#endif

#include <blam/cseries/cseries.hpp>
#include <blam/scenario/scenario_location.hpp>
#include <yelo/open_sauce/blam_memory_upgrades.hpp>

#include <yelo/cseries/errors_yelo.hpp>
#include <blam/cseries/errors.hpp>
#include <yelo/cseries/memory_yelo.hpp>

#include "Settings/Settings.hpp"