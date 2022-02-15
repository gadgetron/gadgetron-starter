//StarterGadget_lib_export.h

#ifndef STARTERGADGET_EXPORT_H_
#define STARTERGADGET_EXPORT_H_

#if defined (WIN32)
#if defined (STARTERGADGET_LIB_EXPORTS)
#define EXPORTSTARTERGADGET __declspec(dllexport)
#else
#define EXPORTSTARTERGADGET __declspec(dllimport)
#endif
#else
#define EXPORTSTARTERGADGET
#endif

#endif /* STARTERGADGET_EXPORT_H_ */