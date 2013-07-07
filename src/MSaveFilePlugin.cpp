#include "MSaveFilePlugin.h"
#include "MSaveFileImpl.h"
#include "MSaveFileScript.h"

#ifdef  M_USE_GAME_EVENT

#include "MSaveFileLua.c"
#include "MEventListener.h"

class MSaveFileEventListener : public MEventListener
{
public:
    void onEvent(const char* event)
    {
        if(strcmp(event, "MScriptInit") == 0)
        {
            MScriptContext* script = MEngine::getInstance()->getScriptContext();
            script->parse((const char*)scriptsMSaveFile);
        }
    }
};
#endif/*M_USE_GAME_EVENT*/

void MPluginStart(MSaveFile)
{
    MResource::registerFactory("MSaveFile", MSaveFileImpl::getNew);
    initScript();
}

void MPluginEnd(MSaveFile)
{
    MResource::unregisterFactory("MSaveFile", MSaveFileImpl::getNew);
}