dofile("bin2c.lua")
dofile("os.lua")

local _EMBED_DIR = _WORKING_DIR .. "/scripts/"
-- embed all lua files in the embed dir
for i, filename in os.dir(_EMBED_DIR, "%.lua$") do
    local file = io.open(_EMBED_DIR .. filename:gsub("%.lua$", "Lua%.c"), "w")
    file:write(bin2c({path.getrelative(_WORKING_DIR, _EMBED_DIR .. filename)}))
    file:close()
end

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
            os.getenv("HOME") .. "/dev/MEvent/include", -- need to put plugins in a sensible place
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
