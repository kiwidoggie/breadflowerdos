#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
#include <dice/hfe/io/IInputFilter.hpp>
#include <dice/hfe/IEventListener.hpp>

namespace dice
{
    namespace hfe
    {
        class BF2;
        class BF2Console;
        class BF2EngineSetup;
        class BF2Log;
        class Demo;
        class Mutex;
        class TickCalculator;

        // BF2Engine size: 0x160 (validated from bf2: 0040b360)
        class BF2Engine : 
            public io::IInputFilter, 
            public IEventListener
        {
        public:
            BF2* m_bf2;
            BF2EngineSetup* m_setup;
            void* m_unknown20;
            BF2Console* m_console;
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
            BF2Log* m_log;
            uint8_t m_unknownA8[4];
            uint32_t m_unknownAC;
            uint8_t m_unknownB0[8];
            TickCalculator* m_tickCalculator;
            uint8_t m_unknownC0[72];
            Demo* m_demo;
            uint64_t m_unknown110;
            uint64_t m_unknown118;
            uint64_t m_unknown120;
            Mutex* m_unknown128;
            Mutex* m_unknown130;
            uint8_t m_unknown138[40];

        public:
            BF2Engine(BF2* p_Instance);
            virtual ~BF2Engine();
            virtual void filterGameInput(io::GameInput* p_GameInput) override;
            virtual void filterPlayerInput(io::PlayerInput* p_PlayerInput) override;
            virtual void handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*) override;

        public:
            bool init(std::string& p_Param1);
            bool mainLoop();
            bool initEngine();
            bool shutdownEngine();
            bool initLocalization();

            void closeLog();
            bool startGame(bool, bool);
            bool getMenuActive() const;
            void initDefaultSettings();
            bool parseParameters(std::string const&);
        };

        extern BF2Engine* g_bf2Engine;
        static void initSettingsRepostitory();

        static_assert(sizeof(BF2Engine) == 0x160);
        static_assert(offsetof(dice::hfe::BF2Engine, m_bf2) == 0x10);
        static_assert(offsetof(dice::hfe::BF2Engine, m_log) == 0xA0);
        static_assert(offsetof(dice::hfe::BF2Engine, m_tickCalculator) == 0xB8);
        static_assert(offsetof(dice::hfe::BF2Engine, m_demo) == 0x108);
    }
}