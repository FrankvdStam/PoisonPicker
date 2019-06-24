workspace "PoisonPicker"
	startproject "simulator"
	
	configurations
	{
		"Debug",
		"Release",
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "graphics"
	include "projects/simulator/libraries/glfw/"
	include "projects/simulator/libraries/glad/"
	include "projects/simulator/libraries/imgui/"
	
group "desktop"
	include "projects/cli/"
	include "projects/simulator/"

group "arduino"
	include "projects/poison_picker/"

group ""
	include "projects/poison_picker/src/pplib/"

--project "monitor"
--	location "monitor"
--	kind "ConsoleApp"
--	language "C++"
--
--	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
--	objdir	  ("obj/" .. outputdir .. "/%{prj.name}")
--		
--	files
--	{
--		"%{prj.name}/src/**.h",
--		"%{prj.name}/src/**.cpp",
--	}
--	
--	pchheader "monitor_pch.h"
--	pchsource "monitor/src/monitor_pch.cpp"
--
--	includedirs
--	{
--		"%{prj.name}/src",
--		"%{IncludeDir.glfw}",
--		"%{IncludeDir.glad}",
--		"%{IncludeDir.imgui}",
--		"%{IncludeDir.asio}",
--		"%{IncludeDir.websocketpp}"
--	}
--	
--	links
--	{
--		"glfw",
--		"glad",
--		"imgui",
--	}    	
--
--	defines
--	{
--		"GLFW_INCLUDE_NONE",
--		"ASIO_STANDALONE",
--		"ASIO_HAS_STD_TYPE_TRAITS",
--		"_WEBSOCKETPP_CPP11_TYPE_TRAITS_"
--	}
--
--	
--	filter "system:linux"
--		cppdialect "C++17"
--		staticruntime "On"
--		systemversion "latest"
--		
--		defines
--		{
--			"MONITOR_LINUX"
--		}
--
--		links
--		{
--			"dl",
--			"pthread",
--			"Xrandr",
--			"Xi",
--			"X11",
--
--		}		
--
--	filter "system:windows"
--		cppdialect "C++17"
--		staticruntime "On"
--		systemversion "latest"
--		
--		links
--		{
--			"opengl32.lib"
--		}
--		
--		defines
--		{
--			"MONITOR_WINDOWS"
--		}
--		
--	filter {"system:windows", "configurations:Debug"}
--		buildoptions "/MTd"
--		
--	filter {"system:windows", "configurations:Release"}
--		buildoptions "/MT"
--		
--	filter "configurations:Debug"
--		defines "DEBUG"
--		symbols "On"
--
--	filter "configurations:Release"
--		defines "RELEASE"
--		optimize "On"
--		
--		
--