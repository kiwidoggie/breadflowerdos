#pragma once
#include <mutex>

namespace dice 
{
    namespace hfe 
    {
        class Mutex 
        {
        public:
            std::mutex m_Mutex;

        public:
            Mutex();
            ~Mutex();
        };
    }
}
