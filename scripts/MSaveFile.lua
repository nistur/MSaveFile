--[[
MSaveFile
wrapper around standard "c-like" interface for MSaveFile
--]]

MSaveFile = function(filename, mode)

    file = 
    {
--------------------------------------------------------------------------------
        open = function(self, filename, mode)
            self._fileID = saveFileOpen(filename, mode)
        end,
        
        close = function(self)
            if not self._fileID then return end
            saveFileClose(self._fileID)
            self._fileID = nil
        end,
--------------------------------------------------------------------------------
        setInt = function(self, key, val)
            if not self._fileID then return end
            if not val then return end
            if not type(val) == "number" then return end

            saveFileSetInt(self._fileID, key, val)
        end,

        setFloat = function(self, key, val)
            if not self._fileID then return end
            if not val then return end
            if not type(val) == "number" then return end

            saveFileSetFloat(self._fileID, key, val)
        end,

        setString = function(self, key, val)
            if not self._fileID then return end
            if not val then return end
            if not type(val) == "string" then return end

            saveFileSetString(self._fileID, key, val)
        end,
--------------------------------------------------------------------------------
        getInt = function(self, key)
            if not self._fileID then return end
            return saveFileGetInt(self._fileID, key)
        end,

        getFloat = function(self, key)
            if not self._fileID then return end
            return saveFileGetFloat(self._fileID, key)
        end,

        getString = function(self, key)
            if not self._fileID then return end
            return saveFileGetString(self._fileID, key)
        end,
--------------------------------------------------------------------------------

        --[[
        TODO: get this to be able to serialise any arbitrary data
        --]]
        set = function(self, key, val)
            if not self._fileID then return end
            if type(val) == "number" then
                saveFileSetFloat(self._fileID, key, val)
            elseif type(val) == "string" then
                saveFileSetString(self._fileID, key, val)
            elseif type(val) == "table" then
                for k,v in ipairs(val) do
                    self:set(key .. "." .. k, v)
                end
            end
        end,

        get = function(self, key, val)
            if not self._fileID then return end
            if type(val) == "table" then
                for k,v in ipairs(val) do
                    val[k] = self:get(key .. "." .. k, v)
                end
            end
        end,
--------------------------------------------------------------------------------
    }

    file:open(filename, mode or "M_SAVE_FILE_MODE_ANY")
    
    return file
end