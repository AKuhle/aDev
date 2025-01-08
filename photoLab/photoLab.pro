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
# include pathes for aLLib
########################################################################
INCLUDEPATH += ../aLib

INCLUDEPATH += ../aLib/aApp

INCLUDEPATH += ../aLib/aUtil
INCLUDEPATH += ../aLib/Collection

INCLUDEPATH += ../aLib/aWin
INCLUDEPATH += ../aLib/aWin/Framework


########################################################################
# include PhotoLab
########################################################################
INCLUDEPATH += App
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/photoLabApp.h \
    Win/mainWin.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/photoLabApp.cpp \
    Win/mainWin.cpp
