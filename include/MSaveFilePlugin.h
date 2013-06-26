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

extern "C"
{

EXPORT void StartPlugin();
EXPORT void EndPlugin();

}
#endif/*__M_SAVE_FILE_PLUGIN_H__*/