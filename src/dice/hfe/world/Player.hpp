#pragma once

#include <dice/hfe/io/NetworkableBase.hpp>
#include <dice/hfe/world/IPlayer.hpp>
#include <dice/hfe/WeakPtr.hpp>
#include <dice/hfe/IConsoleSaveable.hpp>

namespace dice
{
    namespace hfe
    {
        namespace world
        {
            const uint32_t CID_Player = 0xC3EA;

            class Player : public IPlayer, public IConsoleSaveable, public io::NetworkableBase {
            public:
                virtual void moveTo(const Vec3*) = 0; // 0x338

                char _0x68[0x28];
                WeakPtr<world::IObject>* m_vehicle; // 0x0090
                world::ICameraObject* m_camera;  // 0x0098
                char _0xa0[0x54];
                char m_isAIPlayer;  // 0x00F4
                char m_isAlive;  // 0x00F5
                char _0x00F6[2];
            };
        }
    }
}
