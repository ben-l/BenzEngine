#include "Application.h"
#include "GLFW/glfw3.h"
#include "Log.h"
#include "events/ApplicationEvent.h"

namespace BensEngine {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }
    
    Application::~Application()
    {
    }

    void Application::Run()
    {
        /*
        WindowResizeEvent e(1280, 720);
        BE_TRACE(e);
        while(true);
        */
        while (m_Running){
            glClearColor(1, 0, 1, 1); // requires -lglut
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

}
