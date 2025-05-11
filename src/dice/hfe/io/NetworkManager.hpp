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
                unsigned int m_classId;
                world::IObject* m_object;
            };

            class SocketManager;

            const uint32_t CID_NetworkManager = 0x4ADDB7FE;

            class NetworkManager :
                public IEventListener
            {
            private:
                std::map<unsigned short, world::IObject*> m_objectMap; // 0x08
                short m_lastNetId; // 0x38
                char _0x3a[0x6];
                std::map<unsigned short, NetworkableDescriptor*> m_descriptorMap; // 0x40
                Hash<unsigned int, NetworkableDescriptor*, UIntHashFunc> m_descriptorHashMap;// 0x70
                std::map<unsigned short, NetworkableDescriptor*> m_staticDescriptrors; // 0x88
                std::map<unsigned short, NetworkableDescriptor*> m_scopableDescriptors; // 0xB8
                std::map<unsigned short, NetworkableDescriptor*> _0xE8; // 0xE8
                int _0x118;
                int _0x11C;
                int m_globalPredictionMode;
                char _124;
                char _125[3];
                std::map<int, ObjectDescriptor> m_tempIdToDesc; // 0x128
                int _0x158;
                int _0x15C;
                std::vector<std::pair<NetworkableDescriptor const*, NetworkableStateMask>> m_stateMasks; // 0x160
                std::list<std::list<std::pair<INetworkableObject*, NetworkableDescriptor*>>> m_scopableRootDescriptors; // 0x178

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