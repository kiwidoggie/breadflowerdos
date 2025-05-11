#pragma once
#include <cstdint>
#include <vector>

namespace dice
{
    namespace hfe
    {
        class BF2Engine;
        class IModule;

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

            bool initModules(void);
            bool initLateModules(void);
            bool initFileSystem(void);
            bool initRenderer(void);
            bool initNetwork(void);

            bool shutdownModules();
            void shutdownNetwork(void);
        };
        static_assert(sizeof(BF2EngineSetup) == 0x20);

        extern std::vector<IModule*> g_modules;
    }
}