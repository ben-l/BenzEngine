#include "bepch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include <OpenGLVertexArray.h>

namespace BenzEngine {

    VertexArray* VertexArray::Create()
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None: BE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr; 
            case RendererAPI::OpenGL: return new OpenGLVertexArray();
        }
        BE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
