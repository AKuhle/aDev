QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
#        TARGET = photoLabd
        TARGET = sample1d
        windows {
                LIBS += ../../../../Apps/libaLibd.a
        }
        unix {
                LIBS += ../Apps/libaLibd.a
        }
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
#        TARGET = qPhotoLab
        TARGET = sample1
        windows {
                LIBS += ../../../../Apps/libaLib.a
        }
        unix {
                LIBS += ../Apps/libaLib.a
        }
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/photoLab
MOC_DIR = ../../../../GeneratedFiles/photoLab
DESTDIR = ../../../../Apps


# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target


########################################################################
# include pathes for aLib
########################################################################
INCLUDEPATH += ../aLib

INCLUDEPATH += ../aLib/aApp
INCLUDEPATH += ../aLib/aApp/Qt

INCLUDEPATH += ../aLib/aCtrl
INCLUDEPATH += ../aLib/aCtrl/Interface
INCLUDEPATH += ../aLib/aCtrl/Qt

INCLUDEPATH += ../aLib/aGraphic
INCLUDEPATH += ../aLib/aGraphic/Interface
INCLUDEPATH += ../aLib/aGraphic/Qt

INCLUDEPATH += ../aLib/aUtil
INCLUDEPATH += ../aLib/aUtil/Cmds
INCLUDEPATH += ../aLib/aUtil/Collection
INCLUDEPATH += ../aLib/aUtil/Interface
INCLUDEPATH += ../aLib/aUtil/Qt
INCLUDEPATH += ../aLib/aUtil/Tool
INCLUDEPATH += ../aLib/aUtil/VarPool

INCLUDEPATH += ../aLib/aMath
INCLUDEPATH += ../aLib/aMath/Obj2D
INCLUDEPATH += ../aLib/aMath/Obj3D

INCLUDEPATH += ../aLib/aPic

INCLUDEPATH += ../aLib/aWin
INCLUDEPATH += ../aLib/aWin/DocView
INCLUDEPATH += ../aLib/aWin/Interface
INCLUDEPATH += ../aLib/aWin/Qt


########################################################################
# include PhotoLab
########################################################################
INCLUDEPATH += App
INCLUDEPATH += Classes
INCLUDEPATH += Cmds
INCLUDEPATH += Cmds/File_io
INCLUDEPATH += Cmds/Transform
INCLUDEPATH += DocView
INCLUDEPATH += Tool
INCLUDEPATH += ToolWin
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/photoLabApp.h \
    App/photoLab_defs.h \
    Classes/varPool.h \
    Cmds/File_io/cmdOpenFile.h \
    Cmds/Transform/cmdFlipHori.h \
    Cmds/Transform/cmdFlipVert.h \
    Cmds/Transform/cmdInvert.h \
    Cmds/Transform/cmdRotate180.h \
    Cmds/Transform/cmdRotateCCW.h \
    Cmds/cmdBase.h \
    Cmds/cmdBase4EqualTiles.h \
    Cmds/cmdBase4Tiles.h \
    Cmds/tile.h \
    DocView/document.h \
    DocView/editScrollWin.h \
    DocView/editView.h \
    DocView/fullView.h \
    DocView/layerStack.h \
    DocView/navigatorView.h \
    DocView/renderParams.h \
    DocView/viewBase.h \
    DocView/zoomSteps.h \
    Tool/toolBase.h \
    Tool/toolMove.h \
    ToolWin/navigatorToolWin.h \
    ToolWin/toolWinBase.h \
    Win/mainWin.h \
    Win/statusBar.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/photoLabApp.cpp \
    Classes/varPool.cpp \
    Cmds/File_io/cmdOpenFile.cpp \
    Cmds/Transform/cmdFlipHori.cpp \
    Cmds/Transform/cmdFlipVert.cpp \
    Cmds/Transform/cmdInvert.cpp \
    Cmds/Transform/cmdRotate180.cpp \
    Cmds/Transform/cmdRotateCCW.cpp \
    Cmds/Transform/cmdRotateCW.cpp \
    Cmds/cmdBase.cpp \
    Cmds/cmdBase4EqualTiles.cpp \
    Cmds/cmdBase4Tiles.cpp \
    Cmds/tile.cpp \
    DocView/document.cpp \
    DocView/editScrollWin.cpp \
    DocView/editView.cpp \
    DocView/fullView.cpp \
    DocView/layerStack.cpp \
    DocView/navigatorView.cpp \
    DocView/renderParams.cpp \
    DocView/viewBase.cpp \
    DocView/viewBase_coordinates.cpp \
    DocView/viewBase_tool.cpp \
    DocView/zoomSteps.cpp \
    Tool/toolBase.cpp \
    Tool/toolMove.cpp \
    ToolWin/navigatorToolWin.cpp \
    ToolWin/toolWinBase.cpp \
    Win/mainWin.cpp \
    Win/mainWin_ctrl.cpp \
    Win/mainWin_handler.cpp \
    Win/mainWin_io.cpp \
    Win/statusBar.cpp


########################################################################
# resources
########################################################################
RESOURCES += \
    Resource/Resource_Qt/photoLab.qrc

#DISTFILES += \
#    Resource/Resource_Qt/Masked/maximize.png \
#    Resource/Resource_Qt/Masked/minimize.png \
#    Resource/Resource_Qt/Masked/scrollBarDown.png \
#    Resource/Resource_Qt/Masked/scrollBarLeft.png \
#    Resource/Resource_Qt/Masked/scrollBarRight.png \
#    Resource/Resource_Qt/Masked/scrollBarUp.png


########################################################################
# forms
########################################################################
FORMS += \
    Forms/formMainWin.ui \
    Forms/formNavigator.ui
