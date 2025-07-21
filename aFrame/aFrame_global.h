#ifndef AFRAME_GLOBAL_H
#define AFRAME_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AFRAME_LIBRARY)
#  define AFRAME_EXPORT Q_DECL_EXPORT
#else
#  define AFRAME_EXPORT Q_DECL_IMPORT
#endif

#endif // AFRAME_GLOBAL_H
