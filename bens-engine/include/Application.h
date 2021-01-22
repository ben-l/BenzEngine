#pragma once
#include <bepch.h>
#include <Core.h>
#include <Window.h>
#include <LayerStack.h>
#include <ApplicationEvent.h>

namespace BensEngine {
    class BENS_ENGINE_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);
        private:
            bool OnWindowClose(WindowCloseEvent& e);

            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
            LayerStack m_LayerStack;
    };
    // to be defined in client (sandboxapp)
    Application* CreateApplication();
}
