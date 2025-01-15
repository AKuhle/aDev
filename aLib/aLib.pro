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
TARGET = aLibd
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
TARGET = aLib
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/qLib
MOC_DIR = ../../../../GeneratedFiles/qLib
DESTDIR = ../../../../Apps


# Default rules for deployment.
# unix {
#     target.path = $$[QT_INSTALL_PLUGINS]/generic
# }
# !isEmpty(target.path): INSTALLS += target


########################################################################
# HEADERS
########################################################################
HEADERS += \
    aApp/aApp_def.h \
    aApp/aBaseApp.h \
    aApp/aMainWinApp.h \
    aApp/aMainWinApp_i.h \
    aApp/aMainWinApp_qt.h \
    aApp/main.h \
    aGraphic/GraphicObj/aBorderObj.h \
    aGraphic/GraphicObj/aBorderSolid.h \
    aGraphic/GraphicObj/aFillObj.h \
    aGraphic/GraphicObj/aFillSolid.h \
    aGraphic/GraphicObj/aGraphicObj.h \
    aGraphic/aCursor.h \
    aGraphic/aCursor_qt.h \
    aGraphic/aGraphic_def.h \
    aGraphic/aPainter.h \
    aGraphic/aPainter_qt.h \
    aGraphic/aPen.h \
    aGraphic/aPen_qt.h \
    aMath/Obj2D/aDimension2D.h \
    aMath/Obj2D/aDimension2D.inl \
    aMath/Obj2D/aMathObj2D.h \
    aMath/Obj2D/aRect2D.h \
    aMath/Obj2D/aRect2D.inl \
    aMath/Obj2D/aVector2D.h \
    aMath/Obj2D/aVector2D.inl \
    aMath/Obj3D/aMathObj3D.h \
    aMath/aMathObj.h \
    aMath/aMath_def.h \
    aUtil/Collection/aMap.h \
    aUtil/Collection/aUniquePtrList.h \
    aUtil/Collection/aUniquePtrList.inl \
    aUtil/Collection/aVector.h \
    aUtil/Collection/aVector.inl \
    aUtil/aArgument.h \
    aUtil/aColor.h \
    aUtil/aHelper.h \
    aUtil/aHelper.inl \
    aUtil/aMargin.h \
    aUtil/aString.h \
    aUtil/aUtil_def.h \
    aUtil/aVersionInfo.h \
    aWin/Framework/aBaseWin.h \
    aWin/Framework/aMainWin.h \
    aWin/Framework/aMdiMainWin.h \
    aWin/Framework/aSysWin.h \
    aWin/Framework/aSysWin_i.h \
    aWin/Framework/aSysWin_qt.h \
    aWin/Framework/aTitleBar.h \
    aWin/Layout/aLayout.h \
    aWin/Layout/aLayoutMainWin.h \
    aWin/Layout/aLayoutObj.h \
    aWin/Style/aWinStyle.h \
    aWin/Style/aWinStyleFactory.h \
    aWin/Style/aWinStyleFactory_dark.h \
    aWin/Tool/aBorderResizeTool.h \
    aWin/Tool/aParentControlTool.h \
    aWin/Tool/aToolBase.h \
    aWin/Tool/aToolMgr.h \
    aWin/aWin_def.h \
    aLib.h \
    aLib_def.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    aApp/aBaseApp.cpp \
    aApp/aMainWinApp_qt.cpp \
    aApp/main.cpp \
    aGraphic/GraphicObj/aBorderObj.cpp \
    aGraphic/GraphicObj/aBorderSolid.cpp \
    aGraphic/GraphicObj/aFillObj.cpp \
    aGraphic/GraphicObj/aFillSolid.cpp \
    aGraphic/GraphicObj/aGraphicObj.cpp \
    aGraphic/aCursor_qt.cpp \
    aGraphic/aPainter_qt.cpp \
    aGraphic/aPen_qt.cpp \
    aMath/Obj2D/aMathObj2D.cpp \
    aMath/Obj3D/aMathObj3D.cpp \
    aMath/aMathObj.cpp \
    aUtil/aArgument.cpp \
    aUtil/aColor.cpp \
    aUtil/aMargin.cpp \
    aUtil/aString.cpp \
    aUtil/aVersionInfo.cpp \
    aWin/Framework/aBaseWin.cpp \
    aWin/Framework/aBaseWin_handler.cpp \
    aWin/Framework/aMainWin.cpp \
    aWin/Framework/aMdiMainWin.cpp \
    aWin/Framework/aSysWin_qt.cpp \
    aLib.cpp \
    aWin/Framework/aTitleBar.cpp \
    aWin/Layout/aLayout.cpp \
    aWin/Layout/aLayoutMainWin.cpp \
    aWin/Layout/aLayoutObj.cpp \
    aWin/Style/aWinStyle.cpp \
    aWin/Style/aWinStyleFactory.cpp \
    aWin/Style/aWinStyleFactory_dark.cpp \
    aWin/Tool/aBorderResizeTool.cpp \
    aWin/Tool/aParentControlTool.cpp \
    aWin/Tool/aToolBase.cpp \
    aWin/Tool/aToolMgr.cpp
