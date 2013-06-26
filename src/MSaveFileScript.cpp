#include "MSaveFileScript.h"
#include "MSaveFileImpl.h"

#include <MEngine.h>

int scriptSaveFileOpen()
{
    MEngine* engine = MEngine::getInstance();
    MSystemContext* system = engine->getSystemContext();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 2) return 0;

    std::string fileStr = script->getString(0);
    std::string modeStr = script->getString(1);

    MSaveFileMode mode = M_SAVE_FILE_MODE_ANY;
    if(modeStr == "M_SAVE_FILE_MODE_BINARY")
        mode = M_SAVE_FILE_MODE_BINARY;
    else if(modeStr == "M_SAVE_FILE_MODE_TEXT")
        mode = M_SAVE_FILE_MODE_TEXT;
    else if(modeStr == "M_SAVE_FILE_MODE_ANY")
        mode = M_SAVE_FILE_MODE_ANY;


    // where do we want to save this?
    char path[256];
    getGlobalFilename(path, system->getWorkingDirectory(), fileStr.c_str());

    MSaveFileImpl* save = (MSaveFileImpl*)MSaveFileImpl::getNew();
    save->load(path, mode);
    script->pushPointer(save);

    return 1;
}

int scriptSaveFileClose()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 1) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    if(save)
        save->destroy();

    return 0;
}
//--------------------------------------------------------------------------------
int scriptSaveFileSetInt()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 3) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);
    int val = script->getInteger(2);

    if(save)
        save->setInt(key.c_str(), val);

    return 0;
}

int scriptSaveFileSetFloat()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 3) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);
    float val = script->getFloat(2);

    if(save)
        save->setFloat(key.c_str(), val);

    return 0;
}

int scriptSaveFileSetString()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 3) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);
    std::string val = script->getString(2);

    if(save)
        save->setString(key.c_str(), val.c_str());

    return 0;
}
//--------------------------------------------------------------------------------
int scriptSaveFileGetInt()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 2) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);

    if(!save) return 0;
    if(!save->hasKey(key.c_str())) return 0;

    int val = 0;
    save->getInt(key.c_str(), val);
    script->pushInteger(val);

    return 1;
}

int scriptSaveFileGetFloat()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 2) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);

    if(!save) return 0;
    if(!save->hasKey(key.c_str())) return 0;

    float val = 0;
    save->getFloat(key.c_str(), val);
    script->pushFloat(val);

    return 1;
}

int scriptSaveFileGetString()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 2) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    std::string key = script->getString(1);

    if(!save) return 0;
    if(!save->hasKey(key.c_str())) return 0;

    char val[256];
    memset(val, 0, 256);
    save->getString(key.c_str(), val);
    script->pushString(val);

    return 1;
}
//--------------------------------------------------------------------------------
int scriptSaveFileSave()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 1) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    if(save)
        save->save();

    return 0;
}

int scriptSaveFileLoad()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    if(script->getArgsNumber() != 1) return 0;

    MSaveFileImpl* save = (MSaveFileImpl*)script->getPointer(0);
    if(save)
        save->load();

    return 0;
}
//--------------------------------------------------------------------------------
void initScript()
{
    MEngine* engine = MEngine::getInstance();
    MScriptContext* script = engine->getScriptContext();

    script->addFunction("saveFileOpen", scriptSaveFileOpen);
    script->addFunction("saveFileClose", scriptSaveFileClose);
    
    // setters
    script->addFunction("saveFileSetInt", scriptSaveFileSetInt);
    script->addFunction("saveFileSetFloat", scriptSaveFileSetFloat);
    script->addFunction("saveFileSetString", scriptSaveFileSetString);
    
    // getters
    script->addFunction("saveFileGetInt", scriptSaveFileGetInt);
    script->addFunction("saveFileGetFloat", scriptSaveFileGetFloat);
    script->addFunction("saveFileGetString", scriptSaveFileGetString);

    // save/load
    script->addFunction("saveFileSave", scriptSaveFileSave);
    script->addFunction("saveFileLoad", scriptSaveFileLoad);
}