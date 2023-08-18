#pragma once
#include <cstdint>
#include <cstddef>
#include <time.h>

namespace dice
{
    namespace hfe
    {
        class System
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

            virtual void addRef();
            virtual uint32_t getRef();
            virtual uint32_t release();
            virtual System* queryInterface(uint32_t p_param);
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
    }
}