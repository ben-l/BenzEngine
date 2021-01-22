#include <BensEngine.h>

class ExampleLayer : public BensEngine::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {
        }

        void OnUpdate() override
        {
            BE_INFO("ExampleLayer::Update");
        }

        void OnEvent(BensEngine::Event& event) override
        {
            BE_TRACE("{0}", event);
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
