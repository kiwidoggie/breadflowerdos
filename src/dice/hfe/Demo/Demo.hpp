#pragma once
#include <cstdint>

#include <dice/hfe/EventCategory.hpp>
#include <dice/hfe/EventNode.hpp>

namespace dice
{
    namespace hfe
    {
        namespace Demo
        {
            class Demo
            {
            private:
                uint64_t m_unknown08;
                uint64_t m_unknown10;
                uint64_t m_unknown18;
                uint8_t m_unknown20;

            public:
                Demo();
                virtual void handleEvent(dice::hfe::EventCategory p_category, uint32_t p_param2, dice::hfe::EventNode* p_node, void* p_param4);
            };
            static_assert(sizeof(Demo) == 0x28, "incorrect demo size");
        }
    }
}