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
# include pathes for aLib
########################################################################
INCLUDEPATH += aApp
INCLUDEPATH += aApp/Qt

INCLUDEPATH += aGraphic
INCLUDEPATH += aGraphic/Interface
INCLUDEPATH += aGraphic/Qt

INCLUDEPATH += aUtil
INCLUDEPATH += aUtil/Cmds
INCLUDEPATH += aUtil/Collection
INCLUDEPATH += aUtil/Interface
INCLUDEPATH += aUtil/Qt

INCLUDEPATH += aMath
INCLUDEPATH += aMath/Obj2D
INCLUDEPATH += aMath/Obj3D

INCLUDEPATH += aPic

INCLUDEPATH += aWin
INCLUDEPATH += aWin/DocView
INCLUDEPATH += aWin/Interface
INCLUDEPATH += aWin/Qt

INCLUDEPATH += aCtrl
INCLUDEPATH += aCtrl/Interface
INCLUDEPATH += aCtrl/Qt


########################################################################
# HEADERS
########################################################################
HEADERS += \
    aApp/Qt/aAppMainWin.h \
    aApp/aAppBase.h \
    aApp/aApp_def.h \
    aApp/main.h \
    aCtrl/Interface/aCtrlI.h \
    aCtrl/Interface/aToolButtonI.h \
    aCtrl/Qt/aCtrl.h \
    aCtrl/Qt/aCtrl.inl \
    aCtrl/Qt/aToolButton.h \
    aCtrl/aCtrlMgr.h \
    aCtrl/aCtrl_def.h \
    aGraphic/Interface/aBrush_sysi.h \
    aGraphic/Interface/aPainter_sysi.h \
    aGraphic/Interface/aPen_sysi.h \
    aGraphic/Qt/aBrush_sys.h \
    aGraphic/Qt/aPainter_sys.h \
    aGraphic/Qt/aPen_sys.h \
    aGraphic/aBrush.h \
    aGraphic/aGraphic_def.h \
    aGraphic/aPainter.h \
    aGraphic/aPen.h \
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
    aUtil/Interface/aProgressCb_i.h \
    aUtil/Interface/aProgressMgr_i.h \
    aUtil/Interface/aThreadCb_i.h \
    aUtil/Interface/aThread_i.h \
    aUtil/Interface/aUrl_sysi.h \
    aUtil/Qt/aProgressCb_qt.h \
    aUtil/Qt/aProgressMgr_qt.h \
    aUtil/Qt/aThread.h \
    aUtil/Qt/aUrl_sys.h \
    aUtil/aArgument.h \
    aUtil/aColor.h \
    aUtil/aHelper.h \
    aUtil/aHelper.inl \
    aUtil/aMargin.h \
    aUtil/aPath.h \
    aUtil/aStopwatch.h \
    aUtil/aString.h \
    aUtil/aSynchronize.h \
    aUtil/aUrl.h \
    aUtil/aUtil_def.h \
    aUtil/aVersionInfo.h \
    aLib.h \
    aLib_def.h \
    aWin/DocView/aDoc.h \
    aWin/DocView/aView.h \
    aWin/Interface/aBaseWinI.h \
    aWin/Interface/aMainWinI.h \
    aWin/Interface/aMainWinMdiI.h \
    aWin/Interface/aMdiAreaI.h \
    aWin/Interface/aMdiChildI.h \
    aWin/Interface/aPlainWinI.h \
    aWin/Interface/aScrollWinI.h \
    aWin/Qt/aBaseWin.h \
    aWin/Qt/aBaseWin.inl \
    aWin/Qt/aBaseWin_handler.inl \
    aWin/Qt/aMainWin.h \
    aWin/Qt/aMainWinMdi.h \
    aWin/Qt/aMdiArea.h \
    aWin/Qt/aMdiChild.h \
    aWin/Qt/aPlainWin.h \
    aWin/Qt/aScrollWin.h \
    aWin/aWin_def.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    aApp/Qt/aAppMainWin.cpp \
    aApp/aAppBase.cpp \
    aApp/main.cpp \
    aCtrl/aCtrlMgr.cpp \
    aGraphic/Qt/aBrush_sys.cpp \
    aGraphic/Qt/aPainter_sys.cpp \
    aGraphic/Qt/aPen_sys.cpp \
    aGraphic/aBrush.cpp \
    aGraphic/aPainter.cpp \
    aGraphic/aPen.cpp \
    aMath/Obj2D/aMathObj2D.cpp \
    aMath/Obj3D/aMathObj3D.cpp \
    aMath/aMathObj.cpp \
    aPic/Qt/aLayerStack_qt.cpp \
    aPic/aLayerStack.cpp \
    aPic/aLayer_i.cpp \
    aPic/aLayer_rgb8.cpp \
    aPic/aPicBuffer.cpp \
    aUtil/Cmds/aCmd.cpp \
    aUtil/Cmds/aCmdBase.cpp \
    aUtil/Cmds/aCmdMgr.cpp \
    aUtil/Cmds/aCmdStack.cpp \
    aUtil/Cmds/aCmdThread.cpp \
    aUtil/Qt/aProgressCb_qt.cpp \
    aUtil/Qt/aProgressMgr_qt.cpp \
    aUtil/Qt/aThread.cpp \
    aUtil/Qt/aUrl_sys.cpp \
    aUtil/aArgument.cpp \
    aUtil/aColor.cpp \
    aUtil/aHelper.cpp \
    aUtil/aMargin.cpp \
    aUtil/aPath.cpp \
    aUtil/aStopwatch.cpp \
    aUtil/aString.cpp \
    aUtil/aUrl.cpp \
    aUtil/aVersionInfo.cpp \
    aLib.cpp \
    aWin/DocView/aDoc.cpp \
    aWin/DocView/aView.cpp \
    aWin/Qt/aMainWin.cpp \
    aWin/Qt/aMainWinMdi.cpp \
    aWin/Qt/aMdiArea.cpp \
    aWin/Qt/aMdiChild.cpp \
    aWin/Qt/aPlainWin.cpp \
    aWin/Qt/aScrollWin.cpp

DISTFILES +=
