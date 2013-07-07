        
    project "test"
        kind "ConsoleApp"
        language "C++"

        files {
            "src/MSaveFileImpl.cpp",
            "include/**.h",
            "**.md",
            "tinyxml/**",
            "test/**",
            os.getenv("MSDKDIR") .. "SDK/**.h"
        }
        includedirs { "include", "test/testsuite" }
        targetdir "bin"

        postbuildcommands { "bin/test" }