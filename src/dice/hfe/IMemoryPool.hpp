#pragma once

#include "IAllocator.hpp"

namespace dice::hfe
{
	const uint32_t IID_IMemoryPool = 0x9C45;

	class IMemoryPool : public IAllocator
	{
	public:
		virtual void init(int32_t, int32_t, bool) = 0;
	};
}	 // namespace dice::hfe
