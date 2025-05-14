QT       += core gui network

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
#        TARGET = qLightsd
        TARGET = sample2d
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
#        TARGET = qLights
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
UI_DIR = ../../../../GeneratedFiles/qLights
MOC_DIR = ../../../../GeneratedFiles/qLights
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
# include qLights
########################################################################
INCLUDEPATH += App
INCLUDEPATH += Classes
INCLUDEPATH += Dialogs
INCLUDEPATH += Forms
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/qLightsApp.h \
    App/qLights_defs.h \
    Classes/bank.h \
    Classes/channel.h \
    Classes/controller.h \
    Classes/fader.h \
    Classes/fixture.h \
    Classes/scene.h \
    Classes/universe.h \
    Dialogs/ctrlPanel.h \
    Dialogs/dlgAddBank.h \
    Win/mainWin.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/qLightsApp.cpp \
    Classes/bank.cpp \
    Classes/channel.cpp \
    Classes/controller.cpp \
    Classes/fader.cpp \
    Classes/fixture.cpp \
    Classes/scene.cpp \
    Classes/universe.cpp \
    Dialogs/ctrlPanel.cpp \
    Dialogs/dlgAddBank.cpp \
    Win/mainWin.cpp \
    Win/mainWin_ctrls.cpp \
    Win/mainWin_handler.cpp


########################################################################
# resources
########################################################################
#RESOURCES += \
#    Resource/Resource_Qt/photoLab.qrc


########################################################################
# forms
########################################################################
FORMS += \
    Forms/dlgAddBank.ui \
    Forms/formCtrlPanel.ui \
    Forms/formMainWin.ui

RESOURCES += \
    Resource/Resource_Qt/photoLab.qrc \
    Resource/Resource_Qt/qLights.qrc
