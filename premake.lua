workspace "Hazel"
	architecture"x64"

	configuration
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="${cfg.buildcfg}-${cfg.system}-${cfg.architecture}"

project "GameEngine"
	location"GameEngine"
	kind"SharedLib"
	language"C++"

	targetdir("bin/"..outputdir.."/prj.name")
	targetdir("bin/int/"..outputdir.."/prj.name")

	HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL
	