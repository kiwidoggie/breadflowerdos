#pragma once

#include "IProfilerClient.hpp"

namespace dice
{
    namespace hfe
    {
        const uint32_t CID_Profiler = 0x0A5D5;

        class Profiler : public IProfilerClient
        {
        public:
            bool m_enabled;
            uint32_t m_refCount;
            char m_unknown10[0x2268];
        public:
            static IBase* create(uint32_t, IBase*);
            Profiler(bool);

            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual IBase* queryInterface(uint32_t) override;
            virtual void startGlobalTimer() override;
            virtual void stopGlobalTimer() override;
            virtual void startTimer(unsigned int&, char const*, float) override;
            virtual void stopTimer(unsigned int) override;
            virtual void getTimerIdByName(char const*, unsigned int&) override;
            virtual void setEnable(bool) override;
            virtual bool getEnable() override;
            virtual void pauseVTune() override;
            virtual bool getEnablePageFaults() const override;
            virtual void setEnablePageFaults(bool) override;
            virtual void reportToFile(std::string const&) override;
            virtual ~Profiler();
        };
#if defined(WIN32)
        // TODO: Win32 static_assert
#else
        static_assert(sizeof(Profiler) == 0x2278); // bf2: 0084d663
#endif

        extern Profiler* g_profiler;
        extern Profiler* g_profilerClient;
    }
}
