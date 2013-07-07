dofile("bin2c.lua")

local file = io.open("scripts/MSaveFileLua.c", "w")
file:write(bin2c({"scripts/MSaveFile.lua"}))
file:close()

-- Particle system project
solution "MSaveFile"
    configurations { "Debug", "Release" }
    language "C++"
    
    -- make sure we can search and link properly
    libdirs { os.getenv("MSDKDIR") .. "/SDK/MCore/Libs",
          os.getenv("MSDKDIR") .. "/SDK/MEngine/Libs",
          "." }
    includedirs { os.getenv("MSDKDIR") .. "/SDK/MCore/Includes",
              os.getenv("MSDKDIR") .. "/SDK/MEngine/Includes",
            os.getenv("HOME") .. "/dev/MEvent/include",
            "tinyxml"}

    defines { "M_SAVE_FILE_BUILD" }
    
    -- OS defines
    if os.is("windows") then
        defines { "WIN32" }
    end

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize" }  

    dofile("proj-dynamic.lua")
    dofile("proj-static.lua")

    dofile("proj-test.lua")
