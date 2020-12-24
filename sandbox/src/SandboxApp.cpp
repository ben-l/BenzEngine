#include <BensEngine.h>

class Sandbox : public BensEngine::Application
{
public:
    Sandbox()
    {
    }
    ~Sandbox()
    {
    }
};

BensEngine::Application* BensEngine::CreateApplication()
{
    return new Sandbox();
}
