project(Engine)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)


add_library(test SHARED
		src/bepch.cpp
		src/Application.cpp
		src/LinuxWindow.cpp
		src/Log.cpp
)
target_precompile_headers(test
		PRIVATE include/bepch.h
)
