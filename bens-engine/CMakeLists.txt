project(Engine)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/imgui)


add_library(test SHARED
		src/bepch.cpp
		src/Application.cpp
		src/LinuxWindow.cpp
		src/Log.cpp
		src/Layer.cpp
		src/LayerStack.cpp
		src/imgui/ImGuiLayer.cpp
		platform/opengl/ImGuiOpenGLRenderer.cpp
)
target_precompile_headers(test
		PRIVATE include/bepch.h
)
target_compile_definitions(test PRIVATE GLFW_INCLUDE_NONE)
