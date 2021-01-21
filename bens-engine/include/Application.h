#pragma once
#include <bepch.h>
#include <Core.h>
#include <ApplicationEvent.h>
#include <Window.h>

namespace BensEngine {
    class BENS_ENGINE_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);
        private:
            bool OnWindowClose(WindowCloseEvent& e);

            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
    };
    // to be defined in client (sandboxapp)
    Application* CreateApplication();
}
