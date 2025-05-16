#pragma once

#include "IBase.hpp"

namespace dice::hfe
{
	class IAllocator : public IBase
	{
	public:
		virtual void alloc(uint32_t) = 0;
		virtual void free(void*) = 0;
		virtual void alloc(uint32_t, const char*, uint32_t) = 0;
		virtual void free(void*, const char*, uint32_t) = 0;
	};
}	 // namespace dice::hfe
