
    project "MSaveFileStatic"
        kind "StaticLib"
        language "C++"

        -- include all the files, including Maratis SDK ones
        files {
            "src/**.cpp",
            "include/**.h",
            "**.md",
            "tinyxml/**",
            os.getenv("MSDKDIR") .. "SDK/**.h"
        }
        includedirs { "include", "scripts", "tinyxml" }
        targetdir "bin"
        targetname "MSaveFile"

        -- split the files up a bit nicer inside Visual Studio
        vpaths { 
            ["MCore/*"] = os.getenv("MSDKDIR") .. "/SDK/MCore/Includes/**.h",
            ["MEngine/*"] = os.getenv("MSDKDIR") .. "/SDK/MEngine/Includes/**.h",
            ["TinyXML/*"] = "tinyxml/**",
            ["Plugin/*"] = { "**.h", "**.cpp" },
            ["Doc/*"] = { "**.md" }
        }
        defines { "M_SAVE_FILE_STATIC" }

        -- link to Maratis
        links { "MCore", "MEngine" }