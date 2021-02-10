cmake_minimum_required(VERSION 3.19.2)
set (CMAKE_CXX_STANDARD 17)

project(BensEngine)

include_directories(
		bens-engine/core
		bens-engine/events
		bens-engine/imgui
		bens-engine/renderer
		bens-engine/vendor/glfw/include
		bens-engine/vendor/glad/include
		bens-engine/vendor/spdlog/include
		bens-engine/vendor/imgui
		bens-engine/vendor/imgui/backends
		bens-engine/vendor/glm/glm
		bens-engine/platform/linux
		bens-engine/platform/opengl
)

add_subdirectory(bens-engine)
add_subdirectory(sandbox)

