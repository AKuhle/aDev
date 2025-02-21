QT += widgets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17


########################################################################
# defines
########################################################################
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += _USE_QT_


########################################################################
# debug configuration
########################################################################
CONFIG(debug, debug|release) {
TARGET = qLibd
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
TARGET = qLib
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/qLib
MOC_DIR = ../../../../GeneratedFiles/qLib
DESTDIR = ../../../../Apps


# Default rules for deployment.
#unix {
#    target.path = $$[QT_INSTALL_PLUGINS]/generic
#}
#!isEmpty(target.path): INSTALLS += target


########################################################################
# HEADERS
########################################################################
HEADERS += \
    Application/applicationDefs.h \
    Application/main.h \
    Application/qAppBase.h \
    Application/qAppMainWin.h \
    Application/qAppMainWin_i.h \
    Application/qAppMainWin_qt.h \
    Collection/collectionDefs.h \
    Collection/qUniquePtrList.h \
    Collection/qUniquePtrList.inl \
    Graphic/graphicDefs.h \
    Graphic/qBorderObj.h \
    Graphic/qBorderSolid.h \
    Graphic/qCursor.h \
    Graphic/qFillObj.h \
    Graphic/qFillSolid.h \
    Graphic/qGraphicObj.h \
    Graphic/qPainter.h \
    Graphic/qPainter_qt.h \
    Graphic/qPen.h \
    Graphic/qPen_qt.h \
    Math/mathDefs.h \
    Math/qDimension2D.h \
    Math/qDimension2D.inl \
    Math/qMathObj.h \
    Math/qMathObj2D.h \
    Math/qMathObj3D.h \
    Math/qRect2D.h \
    Math/qRect2D.inl \
    Math/qVector2D.h \
    Math/qVector2D.inl \
    Object/Value/qValue.h \
    Object/Value/qValue_bool.h \
    Object/Value/qValue_dbl.h \
    Object/Value/qValue_s32.h \
    Object/Value/qValue_u32.h \
    Object/objectDefs.h \
    Object/qColor.h \
    Object/qMargin.h \
    Object/qString16.h \
    Object/qVersionInfo.h \
    Tool/qBorderResizeTool.h \
    Tool/qParentControlTool.h \
    Tool/qToolBase.h \
    Tool/qToolMgr.h \
    Tool/toolDefs.h \
    Util/qUtil.h \
    Util/qUtil.inl \
    Util/utilDefs.h \
    Win/FrameWin/qMainWin.h \
    Win/FrameWin/qMainWinMdi.h \
    Win/FrameWin/qSysWin.h \
    Win/FrameWin/qSysWin_i.h \
    Win/FrameWin/qSysWin_qt.h \
    Win/FrameWin/qTitleBar.h \
    Win/FrameWin/qWin.h \
    Win/Layout/qLayout.h \
    Win/Layout/qLayoutMainWin.h \
    Win/Layout/qLayoutObj.h \
    Win/WinStyle/qWinStyle.h \
    Win/WinStyle/qWinStyleFactory.h \
    Win/WinStyle/qWinStyleFactory_dark.h \
    Win/winDefs.h \
    qLib.h \
    qLibDefs.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    Application/main.cpp \
    Application/qAppBase.cpp \
    Application/qAppMainWin_qt.cpp \
    Graphic/qBorderObj.cpp \
    Graphic/qBorderSolid.cpp \
    Graphic/qCursor.cpp \
    Graphic/qFillObj.cpp \
    Graphic/qFillSolid.cpp \
    Graphic/qGraphicObj.cpp \
    Graphic/qPainter_qt.cpp \
    Graphic/qPen_qt.cpp \
    Math/qMathObj.cpp \
    Math/qMathObj2D.cpp \
    Math/qMathObj3D.cpp \
    Object/Value/qValue_bool.cpp \
    Object/Value/qValue_dbl.cpp \
    Object/Value/qValue_s32.cpp \
    Object/Value/qValue_u32.cpp \
    Object/qColor.cpp \
    Object/qMargin.cpp \
    Object/qString16.cpp \
    Object/qVersionInfo.cpp \
    Tool/qBorderResizeTool.cpp \
    Tool/qParentControlTool.cpp \
    Tool/qToolBase.cpp \
    Tool/qToolMgr.cpp \
    Win/FrameWin/qMainWin.cpp \
    Win/FrameWin/qMainWinMdi.cpp \
    Win/FrameWin/qSysWin_qt.cpp \
    Win/FrameWin/qTitleBar.cpp \
    Win/FrameWin/qWin.cpp \
    Win/FrameWin/qWin_handler.cpp \
    Win/Layout/qLayout.cpp \
    Win/Layout/qLayoutMainWin.cpp \
    Win/Layout/qLayoutObj.cpp \
    Win/WinStyle/qWinStyle.cpp \
    Win/WinStyle/qWinStyleFactory.cpp \
    Win/WinStyle/qWinStyleFactory_dark.cpp
