#include <bepch.h>
#include <OpenGLContext.h>
#include <Log.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace BensEngine {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
        : m_WindowHandle(windowHandle)
    {
        BE_CORE_ASSERT(windowHandle, "Handle is null");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        BE_CORE_ASSERT(status, "Failed to initialize Glad!");
        BE_CORE_INFO("OpenGL Info:");
        BE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        BE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        BE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}
