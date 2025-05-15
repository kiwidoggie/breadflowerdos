#pragma once

#include <map>
#include <string>

#include <dice/hfe/world/IObject.hpp>
#include <dice/hfe/IConsoleSaveable.hpp>

namespace dice
{
    namespace hfe
    {
        namespace world
        {
            const uint32_t CID_Object = 0xC379;

            class Object : public IObject, public IConsoleSaveable {
            public:
                virtual void getLayerId() = 0;
                virtual void setLayerId() = 0;
                virtual void updateFlagsRecursive() = 0;
                virtual void initNetworkableComp() = 0;
                virtual void analyseNetworkableObject() = 0;

                unsigned int m_refCount;                   // 0x108
                Mat4 m_transfrom;                          // 0x10C
                char _0x14c[0x4];
                Mat4* m_transformInverse;                  // 0x150
                Mat4* m_localTransform;                    // 0x158
                Vec3 m_positionSecondary;                  // 0x160
                Vec3 m_rotationSecondary;                  // 0x16C
                float m_boundingSphereRadius;              // 0x178
                char _0x17c[0x34];
                std::map<unsigned int, IObjectComp*> m_components;  // 0x1B0
                std::string m_name;                        // 0x1E0
                char _0x1e8[0x8];
                unsigned int m_originalFlags;              // 0x1F0
                char _0x1f4[0x14];
                unsigned char m_inputId;                   // 0x208
                unsigned char m_childId;                   // 0x209
                char _0x013A_0x020A;
                unsigned char m_layer;                     // 0x20B
                unsigned char m_group;                     // 0x20C
                unsigned char m_isDestroyed;               // 0x20D
                char _0x013E_0x020E;
                unsigned char m_isOvergrowth;              // 0x20F
                unsigned char m_notInAI;                   // 0x210
                unsigned char m_disableChildren;           // 0x211
                unsigned char m_objectInDestoryList;       // 0x212
            };
        }
    }
}

