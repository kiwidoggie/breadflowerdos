#pragma once

#include <string>
#include <cstdint>
#include <cstddef>

namespace dice
{
	namespace hfe
	{
		class ISettingsRepostitory;

		// bf2: 007451d2
		struct SingletonRegInfo
		{
			std::string name;
			IBase* singleton;
			uint32_t unknown10;
			uint32_t unknown14;
			uint32_t unknown18;
			std::string name2;

			SingletonRegInfo(std::string p_ClassName, IBase* p_Class)
				: name(p_ClassName), singleton(p_Class), unknown10(0), unknown14(0), unknown18(4), name2(p_ClassName) {}
		};
	}
}
