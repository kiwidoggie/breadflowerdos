#pragma once
#include <cstdint>

namespace dice
{
    namespace hfe
    {
        class BF2Engine;

        class BF2EngineSetup
        {
        public:
            BF2Engine* m_engine;
            void* m_unknown08;
            void* m_unknown10;
            uint8_t m_unknown18;

        public:
            BF2EngineSetup(BF2Engine* p_Engine);
            ~BF2EngineSetup();
        };
    }
}