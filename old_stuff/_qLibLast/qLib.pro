QT += core
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
#win32:UI_DIR = ../../GeneratedFiles/qLib
#win32:MOC_DIR = ../../GeneratedFiles/qLib
#win32:DESTDIR = ../../Apps
UI_DIR = ../../../../GeneratedFiles/qLib
MOC_DIR = ../../../../GeneratedFiles/qLib
DESTDIR = ../../../../Apps


########################################################################
# Default rules for deployment.
########################################################################
#unix {
#    target.path = $$[QT_INSTALL_PLUGINS]/generic
#}
#!isEmpty(target.path): INSTALLS += target


########################################################################
# include pathes for qlLib
########################################################################
INCLUDEPATH += qBase
INCLUDEPATH += qBase/App
INCLUDEPATH += qBase/Classes
INCLUDEPATH += qBase/Classes/Qt
INCLUDEPATH += qBase/Cmds
INCLUDEPATH += qBase/Classes/Qt
INCLUDEPATH += qBase/Collection
INCLUDEPATH += qBase/VarPool
INCLUDEPATH += qBase/VarPool/Qt

INCLUDEPATH += qGui
INCLUDEPATH += qGui/App/Qt
INCLUDEPATH += qGui/Classes
INCLUDEPATH += qGui/Classes/Qt
INCLUDEPATH += qGui/Ctrls
INCLUDEPATH += qGui/Ctrls/Qt
INCLUDEPATH += qGui/DocView
INCLUDEPATH += qGui/Tools
INCLUDEPATH += qGui/VarPool
INCLUDEPATH += qGui/Win
INCLUDEPATH += qGui/Win/Qt

INCLUDEPATH += qMath
INCLUDEPATH += qMath/Classes
INCLUDEPATH += qMath/MathObj2D

INCLUDEPATH += qPic
INCLUDEPATH += qPic/Classes

SOURCES += \
    qBase/App/main.cpp \
    qBase/App/qApp_i.cpp \
    qBase/Classes/Qt/qFile_Qt.cpp \
    qBase/Classes/Qt/qJsonFile.cpp \
    qBase/Classes/Qt/qPath.cpp \
    qBase/Classes/Qt/qThread.cpp \
    qBase/Classes/Qt/qUrl.cpp \
    qBase/Classes/qFile.cpp \
    qBase/Classes/qIoDevice.cpp \
    qBase/Classes/qJsonValue.cpp \
    qBase/Classes/qLog.cpp \
    qBase/Classes/qProgress.cpp \
    qBase/Classes/qRgba.cpp \
    qBase/Classes/qString16.cpp \
    qBase/Classes/qThreadCb.cpp \
    qBase/Classes/qVersion.cpp \
    qBase/Cmds/qCmdMgr.cpp \
    qBase/Cmds/qCmdStack.cpp \
    qBase/Cmds/qCmdThread.cpp \
    qBase/Cmds/qCmd_i.cpp \
    qBase/VarPool/qBaseVarPool.cpp \
    qBase/VarPool/qPoolVarBool.cpp \
    qBase/VarPool/qPoolVarS32.cpp \
    qBase/qBaseDefs.cpp \
    qGui/App/Qt/qAppMainWin.cpp \
    qGui/Classes/Qt/qBrush.cpp \
    qGui/Classes/Qt/qContextMenu.cpp \
    qGui/Classes/Qt/qCursor.cpp \
    qGui/Classes/Qt/qFont.cpp \
    qGui/Classes/Qt/qGuiTools.cpp \
    qGui/Classes/Qt/qPainter.cpp \
    qGui/Classes/Qt/qPen.cpp \
    qGui/Classes/Qt/qSysDlg.cpp \
    qGui/Ctrls/Qt/qAction.cpp \
    qGui/Ctrls/Qt/qCtrlMgr.cpp \
    qGui/Ctrls/Qt/qListCtrl.cpp \
    qGui/Ctrls/Qt/qListCtrlItem.cpp \
    qGui/Ctrls/Qt/qScrollBar.cpp \
    qGui/Ctrls/Qt/qSlider.cpp \
    qGui/Ctrls/Qt/qToolButton.cpp \
    qGui/Ctrls/qCtrl_i.cpp \
    qGui/DocView/qDoc_i.cpp \
    qGui/DocView/qView_i.cpp \
    qGui/Tools/qTool.cpp \
    qGui/Tools/qToolMgr.cpp \
    qGui/VarPool/qGuiVarPool.cpp \
    qGui/Win/Qt/qDockWin.cpp \
    qGui/Win/Qt/qMainWin.cpp \
    qGui/Win/Qt/qMainWinMdi.cpp \
    qGui/Win/Qt/qMdiArea.cpp \
    qGui/Win/Qt/qMdiWin.cpp \
    qGui/Win/Qt/qScrollWin.cpp \
    qGui/Win/Qt/qToolBar.cpp \
    qGui/Win/Qt/qWin.cpp \
    qMath/Classes/qMathObj.cpp \
    qMath/MathObj2D/qMathObj2D.cpp \
    qPic/Classes/Qt/qLayerStack_Qt.cpp \
    qPic/Classes/qLayerStack.cpp \
    qPic/Classes/qLayer_i.cpp \
    qPic/Classes/qLayer_rgb8.cpp \
    qPic/Classes/qPicBuffer.cpp

HEADERS += \
    qBase/App/main.h \
    qBase/App/qApp_i.h \
    qBase/Classes/Qt/qJsonFile.h \
    qBase/Classes/Qt/qPath.h \
    qBase/Classes/Qt/qThread.h \
    qBase/Classes/Qt/qUrl.h \
    qBase/Classes/qFile.h \
    qBase/Classes/qIoDevice.h \
    qBase/Classes/qJsonValue.h \
    qBase/Classes/qLog.h \
    qBase/Classes/qMargin.h \
    qBase/Classes/qMargin.inl \
    qBase/Classes/qProgress.h \
    qBase/Classes/qRgba.h \
    qBase/Classes/qString16.h \
    qBase/Classes/qThreadCb.h \
    qBase/Classes/qVersion.h \
    qBase/Cmds/qCmdMgr.h \
    qBase/Cmds/qCmdStack.h \
    qBase/Cmds/qCmdThread.h \
    qBase/Cmds/qCmd_i.h \
    qBase/Collection/aDeque.h \
    qBase/Collection/aSpVector.h \
    qBase/Collection/aSpVector.inl \
    qBase/Collection/qList.h \
    qBase/Collection/qList.inl \
    qBase/Collection/qMap.h \
    qBase/Collection/qPtrList.h \
    qBase/Collection/qPtrList.inl \
    qBase/Collection/qSharedPtrDeque.h \
    qBase/Collection/qSharedPtrList.h \
    qBase/Collection/qSharedPtrList.inl \
    qBase/Collection/qUniquePtrDeque.h \
    qBase/Collection/qUniquePtrDeque.inl \
    qBase/Collection/qUniquePtrList.h \
    qBase/Collection/qUniquePtrList.inl \
    qBase/Collection/qUniquePtrVec.h \
    qBase/Collection/qUniquePtrVec.inl \
    qBase/Collection/qVec.h \
    qBase/Collection/qVec.inl \
    qBase/VarPool/qBaseVarPool.h \
    qBase/VarPool/qBaseVarPool.inl \
    qBase/VarPool/qPoolVarBool.h \
    qBase/VarPool/qPoolVarS32.h \
    qBase/VarPool/qPoolVar_I.h \
    qBase/qBase.h \
    qBase/qBaseDefs.h \
    qBase/qBaseDefs.inl \
    qGui/App/Qt/qAppMainWin.h \
    qGui/Classes/Qt/qBrush.h \
    qGui/Classes/Qt/qContextMenu.h \
    qGui/Classes/Qt/qCursor.h \
    qGui/Classes/Qt/qFont.h \
    qGui/Classes/Qt/qGuiTools.h \
    qGui/Classes/Qt/qPainter.h \
    qGui/Classes/Qt/qPen.h \
    qGui/Classes/Qt/qSysDlg.h \
    qGui/Ctrls/Qt/qAction.h \
    qGui/Ctrls/Qt/qButtonBase.h \
    qGui/Ctrls/Qt/qButtonBase.inl \
    qGui/Ctrls/Qt/qCtrlMgr.h \
    qGui/Ctrls/Qt/qListCtrl.h \
    qGui/Ctrls/Qt/qListCtrlItem.h \
    qGui/Ctrls/Qt/qScrollBar.h \
    qGui/Ctrls/Qt/qSlider.h \
    qGui/Ctrls/Qt/qToolButton.h \
    qGui/Ctrls/qCtrl_i.h \
    qGui/DocView/qDoc_i.h \
    qGui/DocView/qView_i.h \
    qGui/Tools/qTool.h \
    qGui/Tools/qToolMgr.h \
    qGui/VarPool/qGuiVarPool.h \
    qGui/Win/Qt/qDockWin.h \
    qGui/Win/Qt/qMainWin.h \
    qGui/Win/Qt/qMainWinMdi.h \
    qGui/Win/Qt/qMdiArea.h \
    qGui/Win/Qt/qMdiWin.h \
    qGui/Win/Qt/qScrollWin.h \
    qGui/Win/Qt/qSysWin.h \
    qGui/Win/Qt/qSysWin.inl \
    qGui/Win/Qt/qSysWin_handler.inl \
    qGui/Win/Qt/qToolBar.h \
    qGui/Win/Qt/qWin.h \
    qGui/qGui.h \
    qGui/qGuiDefs.h \
    qLib.h \
    qLibDefs.h \
    qMath/Classes/qMathObj.h \
    qMath/Classes/qTransform.h \
    qMath/Classes/qTransform.inl \
    qMath/MathObj2D/qDimension2D.h \
    qMath/MathObj2D/qDimension2D.inl \
    qMath/MathObj2D/qLine2D.h \
    qMath/MathObj2D/qLine2D.inl \
    qMath/MathObj2D/qMathObj2D.h \
    qMath/MathObj2D/qRect2D.h \
    qMath/MathObj2D/qRect2D.inl \
    qMath/MathObj2D/qVector2D.h \
    qMath/MathObj2D/qVector2D.inl \
    qMath/qMath.h \
    qMath/qMathDefs.h \
    qPic/Classes/qChannel.h \
    qPic/Classes/qChannel.inl \
    qPic/Classes/qLayerStack.h \
    qPic/Classes/qLayer_i.h \
    qPic/Classes/qLayer_rgb8.h \
    qPic/Classes/qPicBuffer.h \
    qPic/qPic.h \
    qPic/qPicDefs.h
