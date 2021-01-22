cmake_minimum_required(VERSION 3.19.2)

project(BensEngine)

include_directories(
		bens-engine/include
		bens-engine/include/events
		bens-engine/vendor/glfw/include
		bens-engine/vendor/glad/include
		bens-engine/vendor/spdlog/include
		bens-engine/vendor/imgui
)

add_subdirectory(bens-engine)
add_subdirectory(sandbox)

