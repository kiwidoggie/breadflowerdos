#pragma once

namespace dice
{
    namespace hfe
    {
        template <class T>
        class WeakPtr
        {
        public:
            unsigned int m_refCount; // 0x0
            T* m_ptr;
        };
    }
}
