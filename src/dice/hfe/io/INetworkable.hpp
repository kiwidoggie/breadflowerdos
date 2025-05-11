#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/io/INetworkableInfo.hpp>

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class BaseLineData;
            class BitStream;
            class INetworkableObject;

            class INetworkable : public IBase
            {
            public:
                virtual ~INetworkable() = 0;
                virtual void init(void*) = 0;
                virtual void reset() = 0;
                virtual void addedToManager() = 0;
                virtual void removedFromManager() = 0;
                virtual void getGhostStateMask() = 0;
                virtual void updateStateMask(unsigned int*) = 0;
                virtual void getNetUpdate(BitStream&, BaseLineData*, unsigned int, int) = 0;
                virtual void setNetUpdate(BitStream&, float, bool, BaseLineData*, int) = 0;
                virtual void getBaseLine(BaseLineData*) = 0;
                virtual void setGhostActive(bool) = 0;
                virtual void getMinimumBitSize() = 0;
                virtual void getAverageUpdateDeltaTime() = 0;

                unsigned short m_NetId; // 0x08
                char m_Unknown0C[0x5];
                INetworkableInfo* m_NetworkableInfo; // 0x10
                char m_GhostActive; // 0x18
                char m_Unknown19[0x3];
                float m_Priority;
                char m_IsServerSide; // 0x20
                char m_Unknown21[0x7];
                INetworkableObject* m_NetObj; // 0x28
            };

            static_assert(sizeof(INetworkable) == 0x30);
        }
    }
}