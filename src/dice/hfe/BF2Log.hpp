#pragma once

#include <cstdint>
#include <string>

namespace dice
{
    namespace hfe
    {
        class BF2Log
        {
        public:
            char m_unknown08;
            char m_unknown09;
            char m_unknown0A;
            char m_unknown0B;
            std::string m_unknown10;
            std::string m_unknown18;
            std::string m_unknown20;
            std::string m_unknown28;
            uint64_t m_unknown30;
            uint64_t m_unknown38;
        public:
            virtual ~BF2Log();
            virtual bool initDebugCallback();
            bool initLogFiles();
        };
#if defined(WIN32)
        // TODO: Win32 static_assert
#else
        static_assert(sizeof(BF2Log) == 0x40); // bf2: 004dcf37
#endif
    }
}