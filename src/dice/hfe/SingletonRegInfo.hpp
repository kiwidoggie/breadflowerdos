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
		class SingletonRegInfo
		{
		public:
			std::string name;
			IBase* singleton;
			uint32_t iid;
			uint32_t cid;
			uint32_t unknown18;

			SingletonRegInfo(std::string p_ClassName, IBase* p_Class, uint32_t p_IID = 0, uint32_t p_CID = 0, uint32_t p_Param5 = 4)
				: name(p_ClassName), singleton(p_Class), iid(p_IID), cid(p_CID), unknown18(p_Param5) {
			}
		};
	}
}
