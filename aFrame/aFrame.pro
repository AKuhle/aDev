########################################################################
# configuration
########################################################################
QT += widgets

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++17

# degbug
CONFIG(debug, debug|release) {
TARGET = aFramed
}

# release
CONFIG(release, debug|release) {
TARGET = aFrame
}

# pathes
UI_DIR = ../../../../GeneratedFiles/aFrame
MOC_DIR = ../../../../GeneratedFiles/aFrame
DESTDIR = ../../../../Apps


########################################################################
# defines
########################################################################
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += __NO_FRAME_main__

DEFINES += AFRAME_LIBRARY
DEFINES += _USE_QT_


########################################################################
# include pathes for aFrame
########################################################################
INCLUDEPATH += nlohmann_json/include

INCLUDEPATH += aApp
INCLUDEPATH += aApp/Qt

INCLUDEPATH += aUtil
INCLUDEPATH += aUtil/Cmds
INCLUDEPATH += aUtil/Interface
INCLUDEPATH += aUtil/Qt
INCLUDEPATH += aUtil/StdHelper
INCLUDEPATH += aUtil/VarPool

INCLUDEPATH += aMath
INCLUDEPATH += aMath/Obj2D
INCLUDEPATH += aMath/Obj3D

INCLUDEPATH += aGraphic
INCLUDEPATH += aGraphic/Interface
INCLUDEPATH += aGraphic/Qt
INCLUDEPATH += aGraphic/Style

INCLUDEPATH += aWin
INCLUDEPATH += aWin/Ctrl
INCLUDEPATH += aWin/Layout
INCLUDEPATH += aWin/Qt
INCLUDEPATH += aWin/Tools


########################################################################
# HEADERS
########################################################################
HEADERS += \
    aApp/aAppBase.h \
    aApp/aAppMainWin.h \
    aApp/aApp_def.h \
    aApp/main.h \
    aFrame_def.h \
    aFrame_global.h \
    aFrame.h \
    aGraphic/Interface/aBrushI.h \
    aGraphic/Interface/aCursorI.h \
    aGraphic/Interface/aPainterI.h \
    aGraphic/Interface/aPenI.h \
    aGraphic/Interface/aPixmapI.h \
    aGraphic/Qt/aBrush.h \
    aGraphic/Qt/aCursor.h \
    aGraphic/Qt/aPainter.h \
    aGraphic/Qt/aPen.h \
    aGraphic/Qt/aPixmap.h \
    aGraphic/Style/aStyleItem.h \
    aGraphic/Style/aStyleItemBorder.h \
    aGraphic/Style/aStyleItemBorderSolid.h \
    aGraphic/Style/aStyleItemBorderSolidFrame.h \
    aGraphic/Style/aStyleItemFill.h \
    aGraphic/Style/aStyleItemFillGradient.h \
    aGraphic/Style/aStyleItemFillSolid.h \
    aGraphic/aGraphic_def.h \
    aMath/Obj2D/aDimension2D.h \
    aMath/Obj2D/aDimension2D.inl \
    aMath/Obj2D/aMathObj2D.h \
    aMath/Obj2D/aParametricLine2D.h \
    aMath/Obj2D/aParametricLine2D.inl \
    aMath/Obj2D/aPoint2D.h \
    aMath/Obj2D/aPoint2D.inl \
    aMath/Obj2D/aRect2D.h \
    aMath/Obj2D/aRect2D.inl \
    aMath/Obj2D/aVector2D.h \
    aMath/Obj2D/aVector2D.inl \
    aMath/Obj3D/aMathObj3D.h \
    aMath/aMathObj.h \
    aMath/aMath_def.h \
    aUtil/Cmds/aCmd.h \
    aUtil/Cmds/aCmdBase.h \
    aUtil/Cmds/aCmdMgr.h \
    aUtil/Cmds/aCmdStack.h \
    aUtil/Cmds/aCmdThread.h \
    aUtil/Interface/aProgressCbI.h \
    aUtil/Interface/aProgressMgrI.h \
    aUtil/Interface/aThreadCb_i.h \
    aUtil/Interface/aThread_i.h \
    aUtil/Interface/aUrl_sysi.h \
    aUtil/Qt/aJsonFile.h \
    aUtil/Qt/aProgressCb.h \
    aUtil/Qt/aProgressMgr.h \
    aUtil/Qt/aThread.h \
    aUtil/Qt/aUrl_sys.h \
    aUtil/StdHelper/listHelper.h \
    aUtil/StdHelper/vectorHelper.h \
    aUtil/VarPool/aPoolVarBase.h \
    aUtil/VarPool/aPoolVarBool.h \
    aUtil/VarPool/aPoolVarColor.h \
    aUtil/VarPool/aPoolVarDbl.h \
    aUtil/VarPool/aPoolVarS64.h \
    aUtil/VarPool/aPoolVarString.h \
    aUtil/VarPool/aPoolVarU64.h \
    aUtil/VarPool/aVarPool.h \
    aUtil/VarPool/qBaseVarPool.inl \
    aUtil/aArgument.h \
    aUtil/aColor.h \
    aUtil/aDimension.h \
    aUtil/aHelper.h \
    aUtil/aHelper.inl \
    aUtil/aMargin.h \
    aUtil/aPath.h \
    aUtil/aPoint.h \
    aUtil/aRect.h \
    aUtil/aStopwatch.h \
    aUtil/aString.h \
    aUtil/aSynchronize.h \
    aUtil/aUrl.h \
    aUtil/aUrl_qt.h \
    aUtil/aUtil_def.h \
    aUtil/aVersionInfo.h \
    aWin/Ctrl/aBtn.h \
    aWin/Ctrl/aCtrl.h \
    aWin/Ctrl/aPushBtn.h \
    aWin/Ctrl/aSpacer.h \
    aWin/Ctrl/aToolBtn.h \
    aWin/Layout/aLayoutCentralWin.h \
    aWin/Layout/aLayoutHoriVert.h \
    aWin/Layout/aLayoutMainWin.h \
    aWin/Layout/aLayout_i.h \
    aWin/Qt/aBaseWin_sys.h \
    aWin/Tools/aBorderResizeTool.h \
    aWin/Tools/aBtnTool.h \
    aWin/Tools/aParentCtrlTool.h \
    aWin/Tools/aToolBase.h \
    aWin/Tools/aToolCb.h \
    aWin/Tools/aToolMgr.h \
    aWin/aBaseWin.h \
    aWin/aMainWin.h \
    aWin/aMainWinMdi.h \
    aWin/aTitleBar.h \
    aWin/aToolBar.h \
    aWin/aWinStyle.h \
    aWin/aWin_def.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    aApp/Qt/aAppMainWin.cpp \
    aApp/aAppBase.cpp \
    aApp/main.cpp \
    aFrame.cpp \
    aGraphic/Interface/aPainterI.cpp \
    aGraphic/Qt/aBrush.cpp \
    aGraphic/Qt/aCursor.cpp \
    aGraphic/Qt/aPainter.cpp \
    aGraphic/Qt/aPen.cpp \
    aGraphic/Qt/aPixmap.cpp \
    aGraphic/Style/aStyleItem.cpp \
    aGraphic/Style/aStyleItemBorder.cpp \
    aGraphic/Style/aStyleItemBorderSolid.cpp \
    aGraphic/Style/aStyleItemBorderSolidFrame.cpp \
    aGraphic/Style/aStyleItemFill.cpp \
    aGraphic/Style/aStyleItemFillGradient.cpp \
    aGraphic/Style/aStyleItemFillSolid.cpp \
    aMath/Obj2D/aMathObj2D.cpp \
    aMath/Obj3D/aMathObj3D.cpp \
    aMath/aMathObj.cpp \
    aUtil/Cmds/aCmd.cpp \
    aUtil/Cmds/aCmdBase.cpp \
    aUtil/Cmds/aCmdMgr.cpp \
    aUtil/Cmds/aCmdStack.cpp \
    aUtil/Cmds/aCmdThread.cpp \
    aUtil/Qt/aJsonFile.cpp \
    aUtil/Qt/aProgressCb.cpp \
    aUtil/Qt/aProgressMgr.cpp \
    aUtil/Qt/aThread.cpp \
    aUtil/Qt/aUrl_sys.cpp \
    aUtil/VarPool/aPoolVarBool.cpp \
    aUtil/VarPool/aPoolVarColor.cpp \
    aUtil/VarPool/aPoolVarDbl.cpp \
    aUtil/VarPool/aPoolVarS64.cpp \
    aUtil/VarPool/aPoolVarString.cpp \
    aUtil/VarPool/aPoolVarU64.cpp \
    aUtil/VarPool/aVarPool.cpp \
    aUtil/aArgument.cpp \
    aUtil/aColor.cpp \
    aUtil/aDimension.cpp \
    aUtil/aHelper.cpp \
    aUtil/aMargin.cpp \
    aUtil/aPath.cpp \
    aUtil/aPoint.cpp \
    aUtil/aRect.cpp \
    aUtil/aStopwatch.cpp \
    aUtil/aString.cpp \
    aUtil/aUrl.cpp \
    aUtil/aVersionInfo.cpp \
    aWin/Ctrl/aBtn.cpp \
    aWin/Ctrl/aCtrl.cpp \
    aWin/Ctrl/aPushBtn.cpp \
    aWin/Ctrl/aSpacer.cpp \
    aWin/Ctrl/aToolBtn.cpp \
    aWin/Layout/aLayoutCentralWin.cpp \
    aWin/Layout/aLayoutHoriVert.cpp \
    aWin/Layout/aLayoutMainWin.cpp \
    aWin/Layout/aLayout_i.cpp \
    aWin/Qt/aBaseWin_sys.cpp \
    aWin/Tools/aBorderResizeTool.cpp \
    aWin/Tools/aBtnTool.cpp \
    aWin/Tools/aParentCtrlTool.cpp \
    aWin/Tools/aToolBase.cpp \
    aWin/Tools/aToolCb.cpp \
    aWin/Tools/aToolMgr.cpp \
    aWin/aBaseWin.cpp \
    aWin/aBaseWin_events.cpp \
    aWin/aBaseWin_handler.cpp \
    aWin/aMainWin.cpp \
    aWin/aMainWinMdi.cpp \
    aWin/aTitleBar.cpp \
    aWin/aToolBar.cpp \
    aWin/aWinStyle.cpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Documents/boxModel.png \
    Documents/dark_style.json
