QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

########################################################################
# defines
########################################################################
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += __NO_FRAME_main__
DEFINES += _USE_QT_


########################################################################
# QMAKE_LFLAGS
########################################################################
# stack size
QMAKE_LFLAGS += -Wl,--stack,8388608      # for MinGW
#QMAKE_LFLAGS += /F8388608                # for Visual Studio


########################################################################
# debug configuration
########################################################################
CONFIG(debug, debug|release) {
#        TARGET = qLightsd
        TARGET = sample1d
        windows {
                LIBS += ../../../../Apps/libaFramed.a
        }
        unix {
                LIBS += ../Apps/libaFramed.a
        }
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
#        TARGET = qLight
        TARGET = sample1
        windows {
                LIBS += ../../../../Apps/libaFrame.a
        }
        unix {
                LIBS += ../Apps/libaFrame.a
        }
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/qLights
MOC_DIR = ../../../../GeneratedFiles/qLights
DESTDIR = ../../../../Apps


########################################################################
# include pathes for aFrame
########################################################################
INCLUDEPATH += ../aFrame
INCLUDEPATH += ../aFrame/nlohmann_json/include

INCLUDEPATH += ../aFrame/aApp
INCLUDEPATH += ../aFrame/aApp/Qt

INCLUDEPATH += ../aFrame/aUtil
INCLUDEPATH += ../aFrame/aUtil/Cmds
INCLUDEPATH += ../aFrame/aUtil/Collection
INCLUDEPATH += ../aFrame/aUtil/Interface
INCLUDEPATH += ../aFrame/aUtil/Qt
INCLUDEPATH += ../aFrame/aUtil/VarPool

INCLUDEPATH += ../aFrame/aMath
INCLUDEPATH += ../aFrame/aMath/Obj2D
INCLUDEPATH += ../aFrame/aMath/Obj3D

INCLUDEPATH += ../aFrame/aGraphic
INCLUDEPATH += ../aFrame/aGraphic/Interface
INCLUDEPATH += ../aFrame/aGraphic/Qt
INCLUDEPATH += ../aFrame/aGraphic/Style

INCLUDEPATH += ../aFrame/aWin
INCLUDEPATH += ../aFrame/aWin/Ctrl
INCLUDEPATH += ../aFrame/aWin/Layout
INCLUDEPATH += ../aFrame/aWin/Qt
INCLUDEPATH += ../aFrame/aWin/Tools


########################################################################
# include PhotoLab
########################################################################
INCLUDEPATH += Classes
INCLUDEPATH += Dlg
INCLUDEPATH += Win


SOURCES += \
    Classes/channel.cpp \
    Classes/chase.cpp \
    Classes/controller.cpp \
    Classes/device.cpp \
    Classes/dmxData.cpp \
    Classes/fader.cpp \
    Classes/faderInfo.cpp \
    Classes/fixture.cpp \
    Classes/scene.cpp \
    Classes/scribbleStrip.cpp \
    Classes/universe.cpp \
    Dlg/dlgChannel.cpp \
    Dlg/dlgController.cpp \
    Dlg/dlgDevice.cpp \
    Dlg/dlgFixture.cpp \
    Dlg/dlgScene.cpp \
    Dlg/dlgUniverse.cpp \
    Win/bankButton.cpp \
    Win/chaseButton.cpp \
    Win/fixtureTable.cpp \
    Win/mainWin.cpp \
    Win/mainWin_handler.cpp \
    Win/mainWin_update.cpp \
    Win/masterButton.cpp \
    Win/sceneButton.cpp \
    main.cpp

HEADERS += \
    Classes/channel.h \
    Classes/chase.h \
    Classes/controller.h \
    Classes/device.h \
    Classes/dmxData.h \
    Classes/fader.h \
    Classes/faderInfo.h \
    Classes/fixture.h \
    Classes/scene.h \
    Classes/scribbleStrip.h \
    Classes/universe.h \
    Dlg/dlgChannel.h \
    Dlg/dlgController.h \
    Dlg/dlgDevice.h \
    Dlg/dlgFixture.h \
    Dlg/dlgScene.h \
    Dlg/dlgUniverse.h \
    Win/bankButton.h \
    Win/chaseButton.h \
    Win/fixtureTable.h \
    Win/mainWin.h \
    Win/masterButton.h \
    Win/sceneButton.h \
    qLights_def.h

FORMS += \
    Forms/dlgChannel.ui \
    Forms/dlgController.ui \
    Forms/dlgDevice.ui \
    Forms/dlgFixture.ui \
    Forms/dlgScene.ui \
    Forms/dlgUniverse.ui \
    Forms/mainWin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../aFrame/Resource/aFrame.qrc \
    Resource/qLights.qrc

DISTFILES += \
    Documents/qLights.json
