#pragma once
#include <bepch.h>
#include <Core.h>
#include <Window.h>
#include <LayerStack.h>
#include <ApplicationEvent.h>
#include <ImGuiLayer.h>

namespace BenzEngine {
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);

            inline Window& GetWindow() { return *m_Window; }
            inline static Application& Get() { return *s_Instance; }
        private:
            bool OnWindowClose(WindowCloseEvent& e);

            std::unique_ptr<Window> m_Window;
            ImGuiLayer* m_ImGuiLayer;
            bool m_Running = true;
            LayerStack m_LayerStack;

        private:
            static Application* s_Instance;
    };
    // to be defined in client (sandboxapp)
    Application* CreateApplication();
}
