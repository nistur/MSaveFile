#ifndef __M_SAVE_FILE_PLUGIN_H__
#define __M_SAVE_FILE_PLUGIN_H__

#ifdef WIN32
# include <windows.h>
# ifdef M_SAVE_FILE_BUILD
#  define EXPORT __declspec(dllexport)
# else
#  define EXPORT __declspec(dllimport)
# endif
#else
# define EXPORT
#endif

#ifdef  MPluginStart
# undef MPluginStart
#endif/*MPluginStart*/

#ifdef  MPluginEnd
# undef MPluginEnd
#endif/*MPluginEnd*/

#ifdef  M_SAVE_FILE_STATIC

#define MPluginStart(x) \
x##Start()

#define MPluginEnd(x)  \
x##End()

#else/*!M_SCRIPT_EXT_STATIC*/

#define MPluginStart(x) \
StartPlugin()

#define MPluginEnd(x)  \
EndPlugin()

#endif/*M_SCRIPT_EXT_STATIC*/

extern "C"
{

EXPORT void MPluginStart(MSaveFile);
EXPORT void MPluginEnd  (MSaveFile);

}
#endif/*__M_SAVE_FILE_PLUGIN_H__*/