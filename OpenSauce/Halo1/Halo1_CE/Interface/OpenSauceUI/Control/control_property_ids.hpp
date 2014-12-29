/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI

#include "Interface/OpenSauceUI/resource_id.hpp"

namespace Yelo
{
	namespace Interface { namespace OpenSauceUI
	{
#pragma region Base
#define K_PROPERTY_POSITION_ID			RESOURCE_ID_DEBUG("Position")
#define K_PROPERTY_SIZE_ID				RESOURCE_ID_DEBUG("Size")
#define K_PROPERTY_DOCK_ID				RESOURCE_ID_DEBUG("Dock")
#define K_PROPERTY_MARGIN_ID			RESOURCE_ID_DEBUG("Margin")
#define K_PROPERTY_PADDING_ID			RESOURCE_ID_DEBUG("Padding")
#define K_PROPERTY_HIDDEN_ID			RESOURCE_ID_DEBUG("Hidden")
#define K_PROPERTY_DISABLED_ID			RESOURCE_ID_DEBUG("Disabled")
#pragma endregion

#pragma region Check Box
#define K_PROPERTY_CHECKED_ID			RESOURCE_ID_DEBUG("Checked")
#pragma endregion
		
#pragma region Label
#define K_PROPERTY_TEXT_ID				RESOURCE_ID_DEBUG("Text")
#define K_PROPERTY_TEXTTYPEFACE_ID		RESOURCE_ID_DEBUG("TextTypeface")
#define K_PROPERTY_TEXTSIZE_ID			RESOURCE_ID_DEBUG("TextSize")
#define K_PROPERTY_TEXTBOLD_ID			RESOURCE_ID_DEBUG("TextBold")
#define K_PROPERTY_TEXTCOLOR_ID			RESOURCE_ID_DEBUG("TextColor")
#define K_PROPERTY_TEXTVALIGNMENT_ID	RESOURCE_ID_DEBUG("TextVAlignment")
#define K_PROPERTY_TEXTHALIGNMENT_ID	RESOURCE_ID_DEBUG("TextHAlignment")
#define K_PROPERTY_TEXTWRAP_ID			RESOURCE_ID_DEBUG("TextWrap")
#define K_PROPERTY_TEXTPADDING_ID		RESOURCE_ID_DEBUG("TextPadding")
#pragma endregion

#pragma region Scroll Control
#define K_PROPERTY_INNERSIZE_ID			RESOURCE_ID_DEBUG("InnerSize")
#define K_PROPERTY_SCROLLH_ID			RESOURCE_ID_DEBUG("ScrollH")
#define K_PROPERTY_SCROLLV_ID			RESOURCE_ID_DEBUG("ScrollV")
#define K_PROPERTY_AUTOHIDEBARS_ID		RESOURCE_ID_DEBUG("AutoHideBars")
#pragma endregion

#pragma region Slider
#define K_PROPERTY_CLAMPTONOTCHES_ID	RESOURCE_ID_DEBUG("ClampToNotches")
#define K_PROPERTY_NOTCHCOUNT_ID		RESOURCE_ID_DEBUG("NotchCount")
#pragma endregion

#pragma region Text Box
#define K_PROPERTY_EDITABLE_ID			RESOURCE_ID_DEBUG("Editable")
#pragma endregion

#pragma region Page Control
#define K_PROPERTY_TEXTFORMAT_ID		RESOURCE_ID_DEBUG("TextFormat")
#define K_PROPERTY_PAGECOUNT_ID			RESOURCE_ID_DEBUG("PageCount")
#define K_PROPERTY_USEFINISHBUTTON_ID	RESOURCE_ID_DEBUG("UseFinishButton")

#define K_PROPERTY_BACKBUTTONTEXT_ID				RESOURCE_ID_DEBUG("BackButtonText")
#define K_PROPERTY_BACKBUTTONTEXTTYPEFACE_ID		RESOURCE_ID_DEBUG("BackButtonTextTypeface")
#define K_PROPERTY_BACKBUTTONTEXTSIZE_ID			RESOURCE_ID_DEBUG("BackButtonTextSize")
#define K_PROPERTY_BACKBUTTONTEXTBOLD_ID			RESOURCE_ID_DEBUG("BackButtonTextBold")
#define K_PROPERTY_BACKBUTTONTEXTCOLOR_ID			RESOURCE_ID_DEBUG("BackButtonTextColor")
#define K_PROPERTY_BACKBUTTONTEXTVALIGNMENT_ID		RESOURCE_ID_DEBUG("BackButtonTextVAlignment")
#define K_PROPERTY_BACKBUTTONTEXTHALIGNMENT_ID		RESOURCE_ID_DEBUG("BackButtonTextHAlignment")
#define K_PROPERTY_BACKBUTTONTEXTWRAP_ID			RESOURCE_ID_DEBUG("BackButtonTextWrap")
#define K_PROPERTY_BACKBUTTONTEXTPADDING_ID			RESOURCE_ID_DEBUG("BackButtonTextPadding")

#define K_PROPERTY_NEXTBUTTONTEXT_ID				RESOURCE_ID_DEBUG("NextButtonText")
#define K_PROPERTY_NEXTBUTTONTEXTTYPEFACE_ID		RESOURCE_ID_DEBUG("NextButtonTextTypeface")
#define K_PROPERTY_NEXTBUTTONTEXTSIZE_ID			RESOURCE_ID_DEBUG("NextButtonTextSize")
#define K_PROPERTY_NEXTBUTTONTEXTBOLD_ID			RESOURCE_ID_DEBUG("NextButtonTextBold")
#define K_PROPERTY_NEXTBUTTONTEXTCOLOR_ID			RESOURCE_ID_DEBUG("NextButtonTextColor")
#define K_PROPERTY_NEXTBUTTONTEXTVALIGNMENT_ID		RESOURCE_ID_DEBUG("NextButtonTextVAlignment")
#define K_PROPERTY_NEXTBUTTONTEXTHALIGNMENT_ID		RESOURCE_ID_DEBUG("NextButtonTextHAlignment")
#define K_PROPERTY_NEXTBUTTONTEXTWRAP_ID			RESOURCE_ID_DEBUG("NextButtonTextWrap")
#define K_PROPERTY_NEXTBUTTONTEXTPADDING_ID			RESOURCE_ID_DEBUG("NextButtonTextPadding")

#define K_PROPERTY_FINISHBUTTONTEXT_ID				RESOURCE_ID_DEBUG("FinishButtonText")
#define K_PROPERTY_FINISHBUTTONTEXTTYPEFACE_ID		RESOURCE_ID_DEBUG("FinishButtonTextTypeface")
#define K_PROPERTY_FINISHBUTTONTEXTSIZE_ID			RESOURCE_ID_DEBUG("FinishButtonTextSize")
#define K_PROPERTY_FINISHBUTTONTEXTBOLD_ID			RESOURCE_ID_DEBUG("FinishButtonTextBold")
#define K_PROPERTY_FINISHBUTTONTEXTCOLOR_ID			RESOURCE_ID_DEBUG("FinishButtonTextColor")
#define K_PROPERTY_FINISHBUTTONTEXTVALIGNMENT_ID	RESOURCE_ID_DEBUG("FinishButtonTextVAlignment")
#define K_PROPERTY_FINISHBUTTONTEXTHALIGNMENT_ID	RESOURCE_ID_DEBUG("FinishButtonTextHAlignment")
#define K_PROPERTY_FINISHBUTTONTEXTWRAP_ID			RESOURCE_ID_DEBUG("FinishButtonTextWrap")
#define K_PROPERTY_FINISHBUTTONTEXTPADDING_ID		RESOURCE_ID_DEBUG("FinishButtonTextPadding")
#pragma endregion

#pragma region Button
#define K_PROPERTY_DEPRESSED_ID			RESOURCE_ID_DEBUG("Depressed")
#define K_PROPERTY_ISTOGGLE_ID			RESOURCE_ID_DEBUG("IsToggle")
#define K_PROPERTY_TOGGLESTATE_ID		RESOURCE_ID_DEBUG("ToggleState")
#define K_PROPERTY_IMAGE_ID				RESOURCE_ID_DEBUG("Image")
#define K_PROPERTY_IMAGEALPHA_ID		RESOURCE_ID_DEBUG("ImageAlpha")
#pragma endregion

#pragma region Progress Bar
#define K_PROPERTY_VERTICAL_ID			RESOURCE_ID_DEBUG("Vertical")
#define K_PROPERTY_HORIZONTAL_ID		RESOURCE_ID_DEBUG("Horizontal")
#define K_PROPERTY_CYCLESPEED_ID		RESOURCE_ID_DEBUG("CycleSpeed")
#define K_PROPERTY_AUTOLABEL_ID			RESOURCE_ID_DEBUG("AutoLabel")
#pragma endregion

#pragma region General
#define K_PROPERTY_VALUE_ID				RESOURCE_ID_DEBUG("Value")
#define K_PROPERTY_COLOR_ID				RESOURCE_ID_DEBUG("Color")
#define K_PROPERTY_MIN_ID				RESOURCE_ID_DEBUG("Min")
#define K_PROPERTY_MAX_ID				RESOURCE_ID_DEBUG("Max")
#pragma endregion
	};};
};
#endif