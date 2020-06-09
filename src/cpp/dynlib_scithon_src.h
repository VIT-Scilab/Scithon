#ifndef __DYNLIB_SCITHON_SRC_H__
#define __DYNLIB_SCITHON_SRC_H__

#ifdef _MSC_VER
#ifdef SCITHON_EXPORTS
#define SCITHON_SRC_IMPEXP __declspec(dllexport)
#else
#define SCITHON_SRC_IMPEXP __declspec(dllimport)
#endif
#else
#define SCITHON_SRC_IMPEXP
#endif

#endif
