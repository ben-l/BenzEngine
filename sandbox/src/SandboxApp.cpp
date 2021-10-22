#include <BenzEngine.h>
#include <imgui.h>

class ExampleLayer : public BenzEngine::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {
        }

        void OnUpdate() override
        {
            //BE_INFO("ExampleLayer::Update");
            if(BenzEngine::Input::IsKeyPressed(BE_KEY_TAB))
                    BE_TRACE("Tab key is pressed");
        }

        virtual void OnImGuiRender() override{
            ImGui::Begin("Test");
            ImGui::Text("Hello World");
            ImGui::End();
        }

        void OnEvent(BenzEngine::Event& event) override
        {
            // BE_TRACE("{0}", event);
            if(event.GetEventType() == BenzEngine::EventType::KeyPressed)
            {
                BenzEngine::KeyPressedEvent& e = (BenzEngine::KeyPressedEvent&)event;
                BE_TRACE("{0}", (char)e.GetKeyCode());
            }
        }
};

class Sandbox : public BenzEngine::Application
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

BenzEngine::Application* BenzEngine::CreateApplication()
{
    return new Sandbox();
}
