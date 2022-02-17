//StarterGadget_lib_export.h

#ifndef STARTERGADGETS_EXPORT_H_
#define STARTERGADGETS_EXPORT_H_

#if defined (WIN32)
#if defined (STARTERGADGETS_LIB_EXPORTS)
#define EXPORTSTARTERGADGETS __declspec(dllexport)
#else
#define EXPORTSTARTERGADGETS __declspec(dllimport)
#endif
#else
#define EXPORTSTARTERGADGETS
#endif

#endif /* STARTERGADGETS_EXPORT_H_ */