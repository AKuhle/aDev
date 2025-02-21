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
    aGraphic/aFont.h \
    aGraphic/aFont_qt.h \
    aGraphic/aGraphic_def.h \
    aGraphic/aPainter.h \
    aGraphic/aPainter_qt.h \
    aGraphic/aPen.h \
    aGraphic/aPen_qt.h \
    aGraphic/aPixmap.h \
    aGraphic/aPixmap_i.h \
    aGraphic/aPixmap_qt.h \
    aMath/Obj2D/aDimension2D.h \
    aMath/Obj2D/aDimension2D.inl \
    aMath/Obj2D/aMathObj2D.h \
    aMath/Obj2D/aRect2D.h \
    aMath/Obj2D/aRect2D.inl \
    aMath/Obj2D/aTransform2D.h \
    aMath/Obj2D/aTransform2D.inl \
    aMath/Obj2D/aVector2D.h \
    aMath/Obj2D/aVector2D.inl \
    aMath/Obj3D/aMathObj3D.h \
    aMath/aMathObj.h \
    aMath/aMath_def.h \
    aPic/aChannel.h \
    aPic/aChannel.inl \
    aPic/aLayerStack.h \
    aPic/aLayer_i.h \
    aPic/aLayer_rgb8.h \
    aPic/aPicBuffer.h \
    aPic/qPicDefs.h \
    aUtil/Cmds/aCmd.h \
    aUtil/Cmds/aCmdBase.h \
    aUtil/Cmds/aCmdMgr.h \
    aUtil/Cmds/aCmdStack.h \
    aUtil/Cmds/aCmdThread.h \
    aUtil/Collection/aMap.h \
    aUtil/Collection/aPtrList.h \
    aUtil/Collection/aPtrList.inl \
    aUtil/Collection/aSharedPtrList.h \
    aUtil/Collection/aSharedPtrList.inl \
    aUtil/Collection/aUniquePtrDeque.h \
    aUtil/Collection/aUniquePtrDeque.inl \
    aUtil/Collection/aUniquePtrList.h \
    aUtil/Collection/aUniquePtrList.inl \
    aUtil/Collection/aUniquePtrVec.h \
    aUtil/Collection/aUniquePtrVec.inl \
    aUtil/Collection/aVector.h \
    aUtil/Collection/aVector.inl \
    aUtil/aArgument.h \
    aUtil/aColor.h \
    aUtil/aHelper.h \
    aUtil/aHelper.inl \
    aUtil/aMargin.h \
    aUtil/aPath.h \
    aUtil/aProgressMgr_qt.h \
    aUtil/aProgress_cb.h \
    aUtil/aStopwatch.h \
    aUtil/aString.h \
    aUtil/aSynchronize.h \
    aUtil/aThread.h \
    aUtil/aThread_cb.h \
    aUtil/aThread_qt.h \
    aUtil/aUrl.h \
    aUtil/aUrl_qt.h \
    aUtil/aUtil_def.h \
    aUtil/aVersionInfo.h \
    aWin/Ctrl/aButton.h \
    aWin/Ctrl/aCtrl.h \
    aWin/Ctrl/aCtrlMgr.h \
    aWin/Ctrl/aHoriSpacer.h \
    aWin/Ctrl/aLabel.h \
    aWin/Ctrl/aProgressCtrl.h \
    aWin/Ctrl/aScrollBar.h \
    aWin/Ctrl/aToolButton.h \
    aWin/DocView/aDoc.h \
    aWin/DocView/aView.h \
    aWin/Framework/aBaseWin.h \
    aWin/Framework/aCentralWin.h \
    aWin/Framework/aCtrlBar.h \
    aWin/Framework/aDockArea.h \
    aWin/Framework/aMainWin.h \
    aWin/Framework/aMdiArea.h \
    aWin/Framework/aMdiMainWin.h \
    aWin/Framework/aMdiWin.h \
    aWin/Framework/aPosition_i.h \
    aWin/Framework/aScrollWin.h \
    aWin/Framework/aStatusBar.h \
    aWin/Framework/aSysWin.h \
    aWin/Framework/aSysWin_i.h \
    aWin/Framework/aSysWin_qt.h \
    aWin/Framework/aTitleBar.h \
    aWin/Layout/aLayout.h \
    aWin/Layout/aLayoutCentralWin.h \
    aWin/Layout/aLayoutHoriVert.h \
    aWin/Layout/aLayoutMainWin.h \
    aWin/Layout/aLayoutObj.h \
    aWin/Style/aWinStyle.h \
    aWin/Style/aWinStyleFactory.h \
    aWin/Style/aWinStyleFactory_dark.h \
    aWin/Tool/aBorderResizeTool.h \
    aWin/Tool/aButtonTool.h \
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
    aGraphic/aFont_qt.cpp \
    aGraphic/aPainter_qt.cpp \
    aGraphic/aPen_qt.cpp \
    aGraphic/aPixmap_qt.cpp \
    aMath/Obj2D/aMathObj2D.cpp \
    aMath/Obj3D/aMathObj3D.cpp \
    aMath/aMathObj.cpp \
    aPic/aLayerStack.cpp \
    aPic/aLayerStack_qt.cpp \
    aPic/aLayer_i.cpp \
    aPic/aLayer_rgb8.cpp \
    aPic/aPicBuffer.cpp \
    aUtil/Cmds/aCmd.cpp \
    aUtil/Cmds/aCmdBase.cpp \
    aUtil/Cmds/aCmdMgr.cpp \
    aUtil/Cmds/aCmdStack.cpp \
    aUtil/Cmds/aCmdThread.cpp \
    aUtil/aArgument.cpp \
    aUtil/aColor.cpp \
    aUtil/aMargin.cpp \
    aUtil/aPath.cpp \
    aUtil/aProgressMgr_qt.cpp \
    aUtil/aProgress_cb.cpp \
    aUtil/aStopwatch.cpp \
    aUtil/aString.cpp \
    aUtil/aThread_cb.cpp \
    aUtil/aThread_qt.cpp \
    aUtil/aUrl_qt.cpp \
    aUtil/aVersionInfo.cpp \
    aWin/Ctrl/aButton.cpp \
    aWin/Ctrl/aCtrl.cpp \
    aWin/Ctrl/aCtrlMgr.cpp \
    aWin/Ctrl/aHoriSpacer.cpp \
    aWin/Ctrl/aLabel.cpp \
    aWin/Ctrl/aProgressCtrl.cpp \
    aWin/Ctrl/aScrollBar.cpp \
    aWin/Ctrl/aToolButton.cpp \
    aWin/DocView/aDoc.cpp \
    aWin/DocView/aView.cpp \
    aWin/Framework/aBaseWin.cpp \
    aWin/Framework/aBaseWin_handler.cpp \
    aWin/Framework/aCentralWin.cpp \
    aWin/Framework/aCtrlBar.cpp \
    aWin/Framework/aDockArea.cpp \
    aWin/Framework/aMainWin.cpp \
    aWin/Framework/aMdiArea.cpp \
    aWin/Framework/aMdiMainWin.cpp \
    aWin/Framework/aMdiWin.cpp \
    aWin/Framework/aPosition_i.cpp \
    aWin/Framework/aScrollWin.cpp \
    aWin/Framework/aStatusBar.cpp \
    aWin/Framework/aSysWin_qt.cpp \
    aLib.cpp \
    aWin/Framework/aTitleBar.cpp \
    aWin/Layout/aLayout.cpp \
    aWin/Layout/aLayoutCentralWin.cpp \
    aWin/Layout/aLayoutHoriVert.cpp \
    aWin/Layout/aLayoutMainWin.cpp \
    aWin/Layout/aLayoutObj.cpp \
    aWin/Style/aWinStyle.cpp \
    aWin/Style/aWinStyleFactory.cpp \
    aWin/Style/aWinStyleFactory_dark.cpp \
    aWin/Tool/aBorderResizeTool.cpp \
    aWin/Tool/aButtonTool.cpp \
    aWin/Tool/aParentControlTool.cpp \
    aWin/Tool/aToolBase.cpp \
    aWin/Tool/aToolMgr.cpp

DISTFILES +=
