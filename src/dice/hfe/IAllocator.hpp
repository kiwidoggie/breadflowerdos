#pragma once

#include "IBase.hpp"

namespace dice
{
    namespace hfe
    {
        class IAllocator : public IBase
        {
        public:
            virtual void alloc(uint32_t) = 0;
            virtual void free(void*) = 0;
            virtual void alloc(uint32_t, char const*, uint32_t) = 0;
            virtual void free(void*, char const*, uint32_t) = 0;
        };
    }
}
