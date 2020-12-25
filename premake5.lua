workspace "BensEngine"
	architecture "x64"

	configurations
	{
			"Debug",
			"Release",
			"Dist"
	}

outputdir = "%{cfg.build}-%{cfg.system}-%{cfg.architecture}"

project "BensEngine"
	location "bens-engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

	files {
			"%{prj.name}/include/**.h",
			"%{prj.name}/src/**.cpp"

	}
	includedirs {
			"%{prj.name}/include",
			"%{prj.name}/vendor/spdlog/include/"
	}
	
	filter "system:linux"
		systemversion "latest"
		postbuildcommands{
				("cp %{cfg.buildtarget.relpath} ../lib/" .. outputdir .. "/sandbox/lib")
		}
	filter "configurations:Debug"
		defines "BE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BE_DIST"
		optimize "On"


project "Sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/" .. outputdir .. "/%{prj.name}")

	files {
			"%{prj.name}/include/**.h",
			"%{prj.name}/src/**.cpp"

	}
	includedirs {
			"BensEngine/vendor/spdlog/include/",
			"BensEngine/include"
	}

	links {
			"BensEngine"
	}
	
	filter "system:linux"
		systemversion "latest"
		postbuildcommands{
				("cp %{cfg.buildtarget.relpath} ../lib/" .. outputdir .. "/sandbox/lib")
		}
	filter "configurations:Debug"
		defines "BE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BE_DIST"
		optimize "On"
