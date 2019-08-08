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
