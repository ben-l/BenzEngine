#include "Application.h"
#include "Log.h"
#include "events/ApplicationEvent.h"

namespace BensEngine {

    Application::Application()
    {
    }
    
    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        BE_TRACE(e);
        while(true);
    }

}
