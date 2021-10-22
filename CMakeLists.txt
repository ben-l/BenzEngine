cmake_minimum_required(VERSION 3.19.2)
set (CMAKE_CXX_STANDARD 17)

project(BenzEngine)

include_directories(
		engine/core
		engine/events
		engine/imgui
		engine/renderer
		engine/vendor/glfw/include
		engine/vendor/glad/include
		engine/vendor/spdlog/include
		engine/vendor/imgui
		engine/vendor/imgui/backends
		engine/vendor/glm/glm
		engine/platform/linux
		engine/platform/opengl
)

add_subdirectory(engine)
add_subdirectory(sandbox)

