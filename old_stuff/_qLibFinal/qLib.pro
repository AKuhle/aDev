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
DEFINES += _QLIB_MAIN_


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
INCLUDEPATH += qBase/Collections
INCLUDEPATH += qBase/VarPool

INCLUDEPATH += qGui
INCLUDEPATH += qGui/App
INCLUDEPATH += qGui/App/Qt
INCLUDEPATH += qGui/Classes
INCLUDEPATH += qGui/Classes/Qt
INCLUDEPATH += qGui/Ctrls
INCLUDEPATH += qGui/Dlg
INCLUDEPATH += qGui/Dlg/Qt
INCLUDEPATH += qGui/DocView
INCLUDEPATH += qGui/Layouts
INCLUDEPATH += qGui/Painting
INCLUDEPATH += qGui/Painting/Qt
INCLUDEPATH += qGui/Tools
INCLUDEPATH += qGui/VarPool
INCLUDEPATH += qGui/Win
INCLUDEPATH += qGui/Win/CtrlBars
INCLUDEPATH += qGui/Win/Qt
INCLUDEPATH += qGui/Win/WinStyle

INCLUDEPATH += qMath
INCLUDEPATH += qMath/Classes
INCLUDEPATH += qMath/MathObj2D
INCLUDEPATH += qMath/MathObj3D

INCLUDEPATH += qPic
INCLUDEPATH += qPic/Classes
INCLUDEPATH += qPic/Classes/Qt


SOURCES += \
    qBase/App/main.cpp \
    qBase/App/qAppBase.cpp \
    qBase/Classes/Qt/qFile_Qt.cpp \
    qBase/Classes/Qt/qJsonFile.cpp \
    qBase/Classes/Qt/qThread.cpp \
    qBase/Classes/Qt/qUrl.cpp \
    qBase/Classes/qColor.cpp \
    qBase/Classes/qFile.cpp \
    qBase/Classes/qIoDevice.cpp \
    qBase/Classes/qJsonValue.cpp \
    qBase/Classes/qLog.cpp \
    qBase/Classes/qPath.cpp \
    qBase/Classes/qProgress.cpp \
    qBase/Classes/qString16.cpp \
    qBase/Classes/qThreadCb.cpp \
    qBase/Cmds/qCmd.cpp \
    qBase/Cmds/qCmdBase.cpp \
    qBase/Cmds/qCmdMgr.cpp \
    qBase/Cmds/qCmdStack.cpp \
    qBase/Cmds/qCmdThread.cpp \
    qBase/VarPool/qBaseVarPool.cpp \
    qBase/VarPool/qPoolVarBool.cpp \
    qBase/VarPool/qPoolVarColor.cpp \
    qBase/VarPool/qPoolVarDbl.cpp \
    qBase/VarPool/qPoolVarS32.cpp \
    qGui/App/Qt/qAppMainWin.cpp \
    qGui/Classes/Qt/qCursor.cpp \
    qGui/Classes/Qt/qFont.cpp \
    qGui/Classes/Qt/qPixmap.cpp \
    qGui/Ctrls/qButtonBase.cpp \
    qGui/Ctrls/qCtrlBase.cpp \
    qGui/Ctrls/qCtrlMgr.cpp \
    qGui/Ctrls/qLabel.cpp \
    qGui/Ctrls/qScrollBar.cpp \
    qGui/Ctrls/qSpacer.cpp \
    qGui/Ctrls/qToolButton.cpp \
    qGui/Dlg/Qt/qSysDlg.cpp \
    qGui/DocView/qDocBase.cpp \
    qGui/DocView/qViewBase.cpp \
    qGui/Layouts/qLayoutCenterWin.cpp \
    qGui/Layouts/qLayoutHoriVert.cpp \
    qGui/Layouts/qLayoutMainWin.cpp \
    qGui/Layouts/qLayoutObj.cpp \
    qGui/Layouts/qLayoutScrollWin.cpp \
    qGui/Painting/Qt/qBrush.cpp \
    qGui/Painting/Qt/qPainter.cpp \
    qGui/Painting/Qt/qPen.cpp \
    qGui/Tools/qBorderResizeTool.cpp \
    qGui/Tools/qButtonTool.cpp \
    qGui/Tools/qParentControlTool.cpp \
    qGui/Tools/qScrollBarTool.cpp \
    qGui/Tools/qToolBase.cpp \
    qGui/Tools/qToolMgr.cpp \
    qGui/VarPool/qGuiVarPool.cpp \
    qGui/Win/CtrlBars/qCtrlBar.cpp \
    qGui/Win/CtrlBars/qCtrlBarBase.cpp \
    qGui/Win/CtrlBars/qStatusBar.cpp \
    qGui/Win/CtrlBars/qTitleBar.cpp \
    qGui/Win/Qt/qSysWin.cpp \
    qGui/Win/WinStyle/qStyleBorderBase.cpp \
    qGui/Win/WinStyle/qStyleBorderSolid.cpp \
    qGui/Win/WinStyle/qStyleFillBase.cpp \
    qGui/Win/WinStyle/qStyleFillGradient.cpp \
    qGui/Win/WinStyle/qStyleFillSolid.cpp \
    qGui/Win/WinStyle/qStyleItemBase.cpp \
    qGui/Win/WinStyle/qWinStyle.cpp \
    qGui/Win/WinStyle/qWinStyleFactoryBase.cpp \
    qGui/Win/WinStyle/qWinStyleFactory_dark.cpp \
    qGui/Win/qDockWin.cpp \
    qGui/Win/qMainWin.cpp \
    qGui/Win/qMainWinMdi.cpp \
    qGui/Win/qMainWinSdi.cpp \
    qGui/Win/qMdiChild.cpp \
    qGui/Win/qMdiWin.cpp \
    qGui/Win/qScrollWin.cpp \
    qGui/Win/qWin.cpp \
    qMath/Classes/qEdges.cpp \
    qMath/Classes/qMathObjBase.cpp \
    qMath/MathObj2D/qMathObjBase2D.cpp \
    qMath/MathObj3D/qMathObjBase3D.cpp \
    qPic/Classes/Qt/qLayerStack_Qt.cpp \
    qPic/Classes/qLayerBase.cpp \
    qPic/Classes/qLayerStack.cpp \
    qPic/Classes/qLayer_rgb8.cpp \
    qPic/Classes/qPicBuffer.cpp

HEADERS += \
    qBase/App/main.h \
    qBase/App/qAppBase.h \
    qBase/Classes/Qt/qJsonFile.h \
    qBase/Classes/Qt/qThread.h \
    qBase/Classes/Qt/qUrl.h \
    qBase/Classes/qColor.h \
    qBase/Classes/qFile.h \
    qBase/Classes/qIoDevice.h \
    qBase/Classes/qJsonValue.h \
    qBase/Classes/qLog.h \
    qBase/Classes/qPath.h \
    qBase/Classes/qProgress.h \
    qBase/Classes/qString16.h \
    qBase/Classes/qThreadCb.h \
    qBase/Cmds/qCmd.h \
    qBase/Cmds/qCmdBase.h \
    qBase/Cmds/qCmdMgr.h \
    qBase/Cmds/qCmdStack.h \
    qBase/Cmds/qCmdThread.h \
    qBase/Collections/qList.h \
    qBase/Collections/qList.inl \
    qBase/Collections/qMap.h \
    qBase/Collections/qPtrList.h \
    qBase/Collections/qPtrList.inl \
    qBase/Collections/qSharedPtrDeque.h \
    qBase/Collections/qSharedPtrList.h \
    qBase/Collections/qSharedPtrList.inl \
    qBase/Collections/qUniquePtrDeque.h \
    qBase/Collections/qUniquePtrDeque.inl \
    qBase/Collections/qUniquePtrList.h \
    qBase/Collections/qUniquePtrList.inl \
    qBase/Collections/qUniquePtrVec.h \
    qBase/Collections/qUniquePtrVec.inl \
    qBase/Collections/qVec.h \
    qBase/Collections/qVec.inl \
    qBase/VarPool/qBaseVarPool.h \
    qBase/VarPool/qBaseVarPool.inl \
    qBase/VarPool/qPoolVarBool.h \
    qBase/VarPool/qPoolVarColor.h \
    qBase/VarPool/qPoolVarDbl.h \
    qBase/VarPool/qPoolVarS32.h \
    qBase/VarPool/qPoolVar_i.h \
    qBase/qBase.h \
    qBase/qBaseDefs.h \
    qGui/App/Qt/qAppMainWin.h \
    qGui/Classes/Qt/qCursor.h \
    qGui/Classes/Qt/qFont.h \
    qGui/Classes/Qt/qPixmap.h \
    qGui/Ctrls/qButtonBase.h \
    qGui/Ctrls/qCtrlBase.h \
    qGui/Ctrls/qCtrlMgr.h \
    qGui/Ctrls/qLabel.h \
    qGui/Ctrls/qScrollBar.h \
    qGui/Ctrls/qSpacer.h \
    qGui/Ctrls/qToolButton.h \
    qGui/Dlg/Qt/qSysDlg.h \
    qGui/DocView/qDocBase.h \
    qGui/DocView/qViewBase.h \
    qGui/Layouts/qLayoutCenterWin.h \
    qGui/Layouts/qLayoutHoriVert.h \
    qGui/Layouts/qLayoutMainWin.h \
    qGui/Layouts/qLayoutObj.h \
    qGui/Layouts/qLayoutScrollWin.h \
    qGui/Painting/Qt/qBrush.h \
    qGui/Painting/Qt/qPainter.h \
    qGui/Painting/Qt/qPen.h \
    qGui/Tools/qBorderResizeTool.h \
    qGui/Tools/qButtonTool.h \
    qGui/Tools/qParentControlTool.h \
    qGui/Tools/qScrollBarTool.h \
    qGui/Tools/qToolBase.h \
    qGui/Tools/qToolMgr.h \
    qGui/VarPool/qGuiVarPool.h \
    qGui/Win/CtrlBars/qCtrlBar.h \
    qGui/Win/CtrlBars/qCtrlBarBase.h \
    qGui/Win/CtrlBars/qStatusBar.h \
    qGui/Win/CtrlBars/qTitleBar.h \
    qGui/Win/Qt/qSysWin.h \
    qGui/Win/WinStyle/qStyleBorderBase.h \
    qGui/Win/WinStyle/qStyleBorderSolid.h \
    qGui/Win/WinStyle/qStyleFillBase.h \
    qGui/Win/WinStyle/qStyleFillGradient.h \
    qGui/Win/WinStyle/qStyleFillSolid.h \
    qGui/Win/WinStyle/qStyleItemBase.h \
    qGui/Win/WinStyle/qWinStyle.h \
    qGui/Win/WinStyle/qWinStyleFactoryBase.h \
    qGui/Win/WinStyle/qWinStyleFactory_dark.h \
    qGui/Win/qDockWin.h \
    qGui/Win/qMainWin.h \
    qGui/Win/qMainWinMdi.h \
    qGui/Win/qMainWinSdi.h \
    qGui/Win/qMdiChild.h \
    qGui/Win/qMdiWin.h \
    qGui/Win/qScrollWin.h \
    qGui/Win/qWin.h \
    qGui/qGui.h \
    qGui/qGuiDefs.h \
    qLib.h \
    qLibDefs.h \
    qMath/Classes/qEdges.h \
    qMath/Classes/qMathObjBase.h \
    qMath/Classes/qMathUtil.h \
    qMath/Classes/qMathUtil.inl \
    qMath/Classes/qTransform.h \
    qMath/Classes/qTransform.inl \
    qMath/MathObj2D/qDimension2D.h \
    qMath/MathObj2D/qDimension2D.inl \
    qMath/MathObj2D/qInterval2D.h \
    qMath/MathObj2D/qInterval2D.inl \
    qMath/MathObj2D/qMathObjBase2D.h \
    qMath/MathObj2D/qRect2D.h \
    qMath/MathObj2D/qRect2D.inl \
    qMath/MathObj2D/qVector2D.h \
    qMath/MathObj2D/qVector2D.inl \
    qMath/MathObj3D/qMathObjBase3D.h \
    qMath/qMath.h \
    qMath/qMathDefs.h \
    qPic/Classes/qChannel.h \
    qPic/Classes/qChannel.inl \
    qPic/Classes/qLayerBase.h \
    qPic/Classes/qLayerStack.h \
    qPic/Classes/qLayer_rgb8.h \
    qPic/Classes/qPicBuffer.h \
    qPic/qPic.h \
    qPic/qPicDefs.h
