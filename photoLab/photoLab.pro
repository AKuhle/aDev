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
        TARGET = photoLabd
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
        TARGET = qPhotoLab
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

INCLUDEPATH += ../aLib/aGraphic
INCLUDEPATH += ../aLib/aGraphic/Interface
INCLUDEPATH += ../aLib/aGraphic/Qt

INCLUDEPATH += ../aLib/aUtil
INCLUDEPATH += ../aLib/aUtil/Cmds
INCLUDEPATH += ../aLib/aUtil/Collection
INCLUDEPATH += ../aLib/aUtil/Interface
INCLUDEPATH += ../aLib/aUtil/Qt

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
INCLUDEPATH += Cmds
INCLUDEPATH += Cmds/File_io
INCLUDEPATH += DocView
INCLUDEPATH += Tool
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/photoLabApp.h \
    App/photoLab_defs.h \
    Cmds/File_io/cmdOpenFile.h \
    Cmds/cmdBase.h \
    Cmds/cmdBase4EqualTiles.h \
    Cmds/cmdBase4Tiles.h \
    Cmds/tile.h \
    DocView/document.h \
    DocView/editScrollWin.h \
    DocView/editView.h \
    DocView/renderParams.h \
    DocView/viewBase.h \
    DocView/zoomSteps.h \
    Win/mainWin.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/photoLabApp.cpp \
    Cmds/File_io/cmdOpenFile.cpp \
    Cmds/cmdBase.cpp \
    Cmds/cmdBase4EqualTiles.cpp \
    Cmds/cmdBase4Tiles.cpp \
    Cmds/tile.cpp \
    DocView/document.cpp \
    DocView/editScrollWin.cpp \
    DocView/editView.cpp \
    DocView/renderParams.cpp \
    DocView/viewBase.cpp \
    DocView/viewBase_coordinates.cpp \
    DocView/zoomSteps.cpp \
    Win/mainWin.cpp \
    Win/mainWin_handler.cpp


########################################################################
# resources
########################################################################
RESOURCES += \
    Resource/Resource_Qt/qLib.qrc

DISTFILES += \
    Resource/Resource_Qt/Masked/close.png \
    Resource/Resource_Qt/Masked/file_open.png \
    Resource/Resource_Qt/Masked/maximize.png \
    Resource/Resource_Qt/Masked/minimize.png \
    Resource/Resource_Qt/Masked/scrollBarDown.png \
    Resource/Resource_Qt/Masked/scrollBarLeft.png \
    Resource/Resource_Qt/Masked/scrollBarRight.png \
    Resource/Resource_Qt/Masked/scrollBarUp.png
