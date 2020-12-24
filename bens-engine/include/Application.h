#pragma once
#include "Core.h"

namespace BensEngine {
    class BENS_ENGINE_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();
    };
    // to be defined in client (sandboxapp)
    Application* CreateApplication();
}
