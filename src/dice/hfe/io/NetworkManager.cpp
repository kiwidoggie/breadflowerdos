#include "NetworkManager.hpp"
#include <cstring>
#include <dice/hfe/EventCategory.hpp>
#include <dice/hfe/ISettingsRepostitory.hpp>

using namespace dice::hfe::io;

// bf2: 007c7440
NetworkManager::NetworkManager()
{
	// TODO: Implement

	auto s_Buffer = new uint8_t[0x8000];
	if (s_Buffer != nullptr)
	{
		memset(s_Buffer, 0, 0x8000);
	}
}

NetworkManager::~NetworkManager()
{
	// TODO: Implement
}

// bf2: 007c8900
void NetworkManager::handleEvent(
	EventCategory p_Category, uint32_t p_ID,
	[[maybe_unused]] EventNode* p_EventNode, void* p_Unknown)
{
	if (p_Category != EventCategory::ECCore ||
		p_ID != 1)	  // ECCoreCEChangedSetting
	{
		return;
	}

	if (*(uint32_t*)p_Unknown == 1005)
	{
		uint32_t interpolationTime = 100;
		g_settings->U32Get("GSInterpolationTime", interpolationTime);
		m_interpolationTime = interpolationTime;
	}
	else if (*(uint32_t*)p_Unknown == 1006)
	{
		uint32_t extrapolationTime = 1200;
		g_settings->U32Get("GSExtrapolationTime", extrapolationTime);
		m_extrapolationTime = extrapolationTime;
	}
}
