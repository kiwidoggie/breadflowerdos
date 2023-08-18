#pragma once

namespace dice
{
    namespace hfe
    {
        class BF2;

        class BF2Engine
        {
        private:
            dice::hfe::BF2* m_bf2Instance;

        public:
            BF2Engine(dice::hfe::BF2* p_Instance);
            virtual ~BF2Engine();
            virtual void filterGameInput();
            virtual void filterPlayerInput();
            virtual void handleEvent();
        };
    }
}