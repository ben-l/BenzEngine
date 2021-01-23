project(Engine)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glad)

file(GLOB
		SOURCES CONFIGURE_DEPENDS
		src/*.cpp
		src/imgui/*.cpp
		platform/opengl/*.cpp
		platform/linux/*.cpp
		vendor/imgui/*.cpp
)

add_library(test SHARED
		${SOURCES}

)
target_precompile_headers(test
		PRIVATE include/bepch.h
)
target_compile_definitions(test PRIVATE GLFW_INCLUDE_NONE)
