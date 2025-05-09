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
#        TARGET = qGamesd
        TARGET = sample2
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
#        TARGET = qGames
        TARGET = sample2
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
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target


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
# include qGames
########################################################################
#INCLUDEPATH += App
#INCLUDEPATH += Classes
#INCLUDEPATH += Cmds
#INCLUDEPATH += Cmds/File_io
#INCLUDEPATH += Cmds/Transform
#INCLUDEPATH += DocView
#INCLUDEPATH += Tool
#INCLUDEPATH += ToolWin
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    mainwindow.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    main.cpp \
    mainwindow.cpp


########################################################################
# resources
########################################################################
RESOURCES += \
    Resource/Resource_Qt/photoLab.qrc


########################################################################
# forms
########################################################################
FORMS += \
    mainwindow.ui
