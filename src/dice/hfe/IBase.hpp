#pragma once

#include <cstdint>

namespace dice
{
    namespace hfe
    {
        class IBase
        {
        public:
            virtual void addRef() = 0;
            virtual uint32_t getRef() = 0;
            virtual uint32_t release() = 0;
            virtual IBase* queryInterface(uint32_t p_param) = 0;
        };
    }
}
