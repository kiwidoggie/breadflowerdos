#pragma once

namespace dice
{
    namespace hfe
    {
        constexpr float PI = 3.14159265f;

        inline float degToRad(float angleDeg) {
            return angleDeg * (PI / 180.0f);
        }

        inline float radToDeg(float angleRad) {
            return angleRad / (PI / 180.0f);
        }

        inline float lerp(float a, float b, float alpha) {
            return a + (b - a) * alpha;
        }

        inline float clamp(float val, float minVal, float maxVal)
        {
            if (val >= maxVal)
                val = maxVal;
            if (val < minVal)
                val = minVal;
            return val;
        }
    }
}