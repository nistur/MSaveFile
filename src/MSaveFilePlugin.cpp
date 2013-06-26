#include "MSaveFilePlugin.h"
#include "MSaveFileImpl.h"

void StartPlugin(void)
{
    MResource::registerFactory("MSaveFile", MSaveFileImpl::getNew);
}

void EndPlugin(void)
{
    MResource::unregisterFactory("MSaveFile", MSaveFileImpl::getNew);
}