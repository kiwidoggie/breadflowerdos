#pragma once
#include <dice/hfe/IEventListener.hpp>
#include <dice/hfe/world/IObject.hpp>
#include <dice/hfe/io/NetworkableDescriptor.hpp>
#include <dice/hfe/io/NetworkableStateMask.hpp>
#include <dice/hfe/Hash.hpp>

#include <cstdint>
#include <map>
#include <vector>
#include <list>

namespace dice
{
    namespace hfe
    {
        enum class EventCategory;

        namespace io
        {
            struct ObjectDescriptor
            {
                char _0x00[16];
            };
    
            struct OBJECTINFO
            {
                unsigned int m_ClassId;
                world::IObject* m_Object;
            };

            class SocketManager;

            const uint32_t CID_NetworkManager = 0x4ADDB7FE;

            class NetworkManager :
                public IEventListener
            {
            private:
                std::map<unsigned short, world::IObject*> m_ObjectMap; // 0x08
                short m_LastNetId; // 0x38
                char m_Unknown3A[0x6];
                std::map<unsigned short, NetworkableDescriptor*> m_DescriptorMap; // 0x40
                Hash<unsigned int, NetworkableDescriptor*, UIntHashFunc> m_DescriptorHashMap;// 0x70
                std::map<unsigned short, NetworkableDescriptor*> m_StaticDescriptrors; // 0x88
                std::map<unsigned short, NetworkableDescriptor*> m_ScopableDescriptors; // 0xB8
                std::map<unsigned short, NetworkableDescriptor*> m_UnknownE8; // 0xE8
                int m_Unknown118;
                int m_Unknown11C;
                int m_GlobalPredictionMode;
                char m_Unknown124;
                char m_Unknonw125[3];
                std::map<int, ObjectDescriptor> m_TempIdToDesc; // 0x128
                int m_Unknown158;
                int m_Unknown15C;
                std::vector<std::pair<NetworkableDescriptor const*, NetworkableStateMask>> m_StateMasks; // 0x160
                std::list<std::list<std::pair<INetworkableObject*, NetworkableDescriptor*>>> m_ScopableRootDescriptors; // 0x178

            public:
                NetworkManager();
                virtual void handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*);
                virtual ~NetworkManager();

            };
#if defined(WIN32)
            // TODO: Win32 static_assert
#else
            static_assert(sizeof(NetworkManager) == 0x188);
#endif

        }
    }
}