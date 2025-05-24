#pragma once

#include <cstdint>

namespace dice::hfe
{
	const uint32_t IID_IBase = 1;

	class IBase
	{
	public:
		virtual void addRef() = 0;
		virtual uint32_t getRef() = 0;
		virtual uint32_t release() = 0;
		virtual IBase* queryInterface(uint32_t p_param) = 0;
	};
}	 // namespace dice::hfe
