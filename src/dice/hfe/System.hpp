#pragma once
#include <cstdint>
#include <cstddef>
#include <time.h>
#include <dice/hfe/IBase.hpp>

namespace dice
{
    namespace hfe
    {
        class ClassManager;
        class BF2Engine;

        class System : private IBase
        {
        private:
            uint32_t m_refCount;
            // static_assert(offsetof(System, m_refCount) == 8, "reference count at wrong offset");
            uint32_t m_simulationRate;
            uint64_t m_exactTime;
            uint64_t m_unknown18;
            uint8_t m_unknown20;
            uint32_t m_unknown24;
            uint32_t m_unknown28;

        public:
            System();
            virtual ~System();

            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual System* queryInterface(uint32_t p_param) override;
            virtual void dtor0();
            virtual void dtor1();
            virtual uint64_t getExactTime();
            virtual time_t getWallClockTime();
            virtual void sleep(uint32_t p_duration);
            virtual uint32_t getSimulationRate();
            virtual float getSimulationRatio();
            virtual void storeAndTurnOffFPUExceptions();
            virtual void restoreFPUExceptions();
        };

        // Global reference
        extern System* g_system;
        extern ClassManager* g_classManager;
        extern BF2Engine* g_bf2Engine;
    }
}