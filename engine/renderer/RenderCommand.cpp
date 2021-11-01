#include <bepch.h>
#include <RenderCommand.h>
#include <OpenGLRendererAPI.h>

namespace BenzEngine {
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
