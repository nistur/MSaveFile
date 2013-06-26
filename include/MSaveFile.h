#ifndef _M_SAVE_FILE_H
#define _M_SAVE_FILE_H

#include "MSaveFilePlugin.h"

#include <MEngine.h>
#include <MResource.h>

enum MSaveFileMode
{
    M_SAVE_FILE_MODE_BINARY,
    M_SAVE_FILE_MODE_TEXT,
    M_SAVE_FILE_MODE_ANY
};

class MSaveFile : public MResource
{
public:
    virtual void destroy() = 0;

    virtual void setInt(const char* key, const int val) = 0;
    virtual void setFloat(const char* key, const float val) = 0;
    virtual void setString(const char* key, const char* val) = 0;

    virtual bool getInt(const char* key, int& val) = 0;
    virtual bool getFloat(const char* key, float& val) = 0;
    virtual bool getString(const char* key, char* val) = 0;

    virtual bool hasKey(const char* key) = 0;

    virtual void save() = 0;
    virtual void load() = 0;

    virtual void save(const char* filename, MSaveFileMode mode) = 0;
    virtual void load(const char* filename, MSaveFileMode mode) = 0;
};

#define MSaveFileGetNew(save, filename, mode) \
{\
    save = (MSaveFile*)MResource::getNew("MSaveFile"); \
    if(save) \
      save->load(filename, mode); \
}

#endif/*_M_SAVE_FILE_H*/
