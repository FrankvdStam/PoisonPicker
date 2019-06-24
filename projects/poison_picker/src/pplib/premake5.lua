project "pplib"
	location "pplib"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir	  ("obj/" .. outputdir .. "/%{prj.name}")
		
	files
	{
		"src/**.h",
		"src/**.cpp",
		"include/**.h",
		"include/**.cpp",
	}
	
	includedirs
	{
		"include/",
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
