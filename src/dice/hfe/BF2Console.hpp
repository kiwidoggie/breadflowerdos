#pragma once
#include <cstdint>

namespace dice::hfe
{
	class BF2Console
	{
	public:
		uint8_t m_unknown00[8];
		void* m_unknown08;
		void* m_unknown10;
	};

	static_assert(sizeof(BF2Console) == 0x18);
}	 // namespace dice::hfe
