#include <BensEngine.h>
#include <imgui.h>

class ExampleLayer : public BensEngine::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {
        }

        void OnUpdate() override
        {
            //BE_INFO("ExampleLayer::Update");
            if(BensEngine::Input::IsKeyPressed(BE_KEY_TAB))
                    BE_TRACE("Tab key is pressed");
        }

        virtual void OnImGuiRender() override{
            ImGui::Begin("Test");
            ImGui::Text("Hello World");
            ImGui::End();
        }

        void OnEvent(BensEngine::Event& event) override
        {
            // BE_TRACE("{0}", event);
            if(event.GetEventType() == BensEngine::EventType::KeyPressed)
            {
                BensEngine::KeyPressedEvent& e = (BensEngine::KeyPressedEvent&)event;
                BE_TRACE("{0}", (char)e.GetKeyCode());
            }
        }
};

class Sandbox : public BensEngine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox()
    {
    }
};

BensEngine::Application* BensEngine::CreateApplication()
{
    return new Sandbox();
}
