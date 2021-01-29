#include <bepch.h>
#include <OpenGLContext.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace BensEngine {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
        : m_WindowHandle(windowHandle)
    {
        //BE_CORE_ASSERT(windowHandle, "Handle is null");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        //BE_CORE_ASSERT(status, "Failed to initialize Glad!");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}
