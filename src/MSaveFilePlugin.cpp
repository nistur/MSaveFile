#include "MSaveFilePlugin.h"
#include "MSaveFileImpl.h"
#include "MSaveFileScript.h"

void StartPlugin(void)
{
    MResource::registerFactory("MSaveFile", MSaveFileImpl::getNew);
    initScript();
}

void EndPlugin(void)
{
    MResource::unregisterFactory("MSaveFile", MSaveFileImpl::getNew);
}