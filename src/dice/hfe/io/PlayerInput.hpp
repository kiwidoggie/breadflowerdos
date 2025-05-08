#pragma once

#include <cstddef>

namespace dice
{
    namespace hfe
    {
        namespace io
        {

            enum class PlayerInputMap : unsigned int
            {
                PIYaw = 0,
                PIPitch = 1,
                PIRoll = 2,
                PIThrottle = 3,
                PIMouseLookX = 4,
                PIMouseLookY = 5,
                PICameraX = 6,
                PICameraY = 7,
                PIFire = 8,
                PIAction = 9,
                PIUse = 10,
                PIMouseLook = 11,
                PIAltSprint = 12,
                PISprint = 13,
                PIWeaponSelect1 = 14,
                PIWeaponSelect2 = 15,
                PIWeaponSelect3 = 16,
                PIWeaponSelect4 = 17,
                PIWeaponSelect5 = 18,
                PIWeaponSelect6 = 19,
                PIWeaponSelect7 = 20,
                PIWeaponSelect8 = 21,
                PIWeaponSelect9 = 22,
                PIPositionSelect1 = 23,
                PIPositionSelect2 = 24,
                PIPositionSelect3 = 25,
                PIPositionSelect4 = 26,
                PIPositionSelect5 = 27,
                PIPositionSelect6 = 28,
                PIPositionSelect7 = 29,
                PIPositionSelect8 = 30,
                PIAltFire = 31,
                PIReload = 32,
                PISelectFunc = 33,
                PIDrop = 34,
                PIToggleCameraMode = 35,
                PIToggleCamera = 36,
                PILie = 37,
                PICrouch = 38,
                PICameraMode1 = 39,
                PICameraMode2 = 40,
                PICameraMode3 = 41,
                PICameraMode4 = 42,
                PISelectPrimWeapon = 43,
                PISelectSecWeapon = 44,
                PIToggleWeapon = 45,
                PIToggleFireRate = 46,
                PIFlareFire = 47,
                PIRadio1 = 48,
                PIRadio2 = 49,
                PIRadio3 = 50,
                PIRadio4 = 51,
                PIRadio5 = 52,
                PIRadio6 = 53,
                PIRadio7 = 54,
                PIRadio8 = 55,
                PIScreenShot = 56,
                PIToolTip = 57,
                PISayAll = 58,
                PISayTeam = 59,
                PINextItem = 60,
                PIPrevItem = 61,
                PICommunication = 62,
                PIShowScoreBoard = 63,
                PINone = 64 // used as unset value
            };

            class PlayerInput {
            public:
                union {
                    float m_inputs[64];
                    //
                    struct {
                        float PIYaw;
                        float PIPitch;
                        float PIRoll;
                        float PIThrottle;
                        float PIMouseLookX;
                        float PIMouseLookY;
                        float PICameraX;
                        float PICameraY;
                        float PIFire;
                        float PIAction;
                        float PIUse;
                        float PIMouseLook;
                        float PIAltSprint;
                        float PISprint;
                        float PIWeaponSelect1;
                        float PIWeaponSelect2;
                        float PIWeaponSelect3;
                        float PIWeaponSelect4;
                        float PIWeaponSelect5;
                        float PIWeaponSelect6;
                        float PIWeaponSelect7;
                        float PIWeaponSelect8;
                        float PIWeaponSelect9;
                        float PIPositionSelect1;
                        float PIPositionSelect2;
                        float PIPositionSelect3;
                        float PIPositionSelect4;
                        float PIPositionSelect5;
                        float PIPositionSelect6;
                        float PIPositionSelect7;
                        float PIPositionSelect8;
                        float PIAltFire;
                        float PIReload;
                        float PISelectFunc;
                        float PIDrop;
                        float PIToggleCameraMode;
                        float PIToggleCamera;
                        float PILie;
                        float PICrouch;
                        float PICameraMode1;
                        float PICameraMode2;
                        float PICameraMode3;
                        float PICameraMode4;
                        float PISelectPrimWeapon;
                        float PISelectSecWeapon;
                        float PIToggleWeapon;
                        float PIToggleFireRate;
                        float PIFlareFire;
                        float PIRadio1;
                        float PIRadio2;
                        float PIRadio3;
                        float PIRadio4;
                        float PIRadio5;
                        float PIRadio6;
                        float PIRadio7;
                        float PIRadio8;
                        float PIScreenShot;
                        float PIToolTip;
                        float PISayAll;
                        float PISayTeam;
                        float PINextItem;
                        float PIPrevItem;
                        float PICommunication;
                        float PIShowScoreBoard;
                    };
                };

                unsigned long long m_flags; // 0x100
                unsigned int _0x108;
                unsigned int _0x10C;
                unsigned int _0x110;
                unsigned char _0x0111;

                inline float* getInput(PlayerInputMap f) {
                    if ((m_flags >> (unsigned long long)f) & 1ULL) {
                        return &m_inputs[static_cast<size_t>(f)];
                    }
                    return nullptr;
                }

                inline void setInput(PlayerInputMap f, float value = 1.0f) {
                    m_flags |= 1ULL << (unsigned long long)f;
                    m_inputs[static_cast<size_t>(f)] = value;
                }
            };

            static_assert(sizeof(PlayerInput) == 0x118);

        }
    }
}