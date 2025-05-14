#pragma once

#include "IMemoryPool.hpp"

namespace dice
{
    namespace hfe
    {
        const uint32_t CID_MemoryPool = 0x9C73;

        class MemoryPool : public IMemoryPool
        {
        public:
            uint32_t m_refCount;
            char m_unknown0C[0x3C];

        public:
            static IBase* create(uint32_t, IBase*);
            MemoryPool();

            virtual void addRef() override;
            virtual uint32_t getRef() override;
            virtual uint32_t release() override;
            virtual IBase* queryInterface(uint32_t) override;
            virtual void alloc(uint32_t) override;
            virtual void free(void*) override;
            virtual void alloc(uint32_t, char const*, uint32_t) override;
            virtual void free(void*, char const*, uint32_t) override;
            virtual void init(int32_t, int32_t, bool) override;
            virtual ~MemoryPool();
        };
#if defined(WIN32)
        // TODO: Win32 static_assert
#else
        static_assert(sizeof(MemoryPool) == 0x48); // bf2: 0084d6d3
#endif
    }
}
