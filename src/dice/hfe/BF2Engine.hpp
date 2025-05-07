#pragma once
#include <cstdint>
#include <cstddef>
#include <dice/hfe/io/IInputFilter.hpp>
#include <dice/hfe/IEventListener.hpp>

namespace dice
{
    namespace hfe
    {
        namespace Demo
        {
            class Demo;
        };

        class BF2;
        class TickCalculator;

        // BF2Engine size: 0x160 (validated from bf2: 0040b360)
        class BF2Engine : private io::IInputFilter, private IEventListener
        {
        public:
            BF2* m_bf2;
            void* m_unknown18;
            void* m_unknown20;
            void* m_unknown28;
            void* m_unknown30;
            void* m_unknown38;
            void* m_unknown40;
            uint32_t m_unknown48;
            uint64_t m_unknown50;
            uint64_t m_unknown58;
            void* m_unknown60;
            uint32_t m_unknown6C;
            void* m_unknown70;
            void* m_unknown78;
            uint8_t m_unkown80[8];
            void* m_unknown88;
            void* m_unknown90;
            uint8_t m_unknown98[4];
            uint32_t m_unknown9C;
            uint64_t m_unknownA0;
            uint8_t m_unknownA8[4];
            uint32_t m_unknownAC;
            uint8_t m_unknownB0[8];
            TickCalculator* m_tickCalculator;
            uint8_t m_unknownC0[72];
            Demo::Demo* m_demo;
            uint8_t m_unknown110[80];

        public:
            BF2Engine(dice::hfe::BF2* p_Instance);
            // TODO: override these
            virtual ~BF2Engine();
            virtual void filterGameInput();
            virtual void filterPlayerInput();
            virtual void handleEvent();
            bool mainLoop();
        };

        static_assert(sizeof(BF2Engine) == 0x160);
        static_assert(offsetof(dice::hfe::BF2Engine, m_bf2) == 0x10);
        static_assert(offsetof(dice::hfe::BF2Engine, m_unknownA0) == 0xA0);
        static_assert(offsetof(dice::hfe::BF2Engine, m_tickCalculator) == 0xB8);
        static_assert(offsetof(dice::hfe::BF2Engine, m_demo) == 0x108);
    }
}