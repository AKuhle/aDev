QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


########################################################################
# debug configuration
########################################################################
CONFIG(debug, debug|release) {
        TARGET = qGamesd
        windows {
#                LIBS += ../../../../Apps/libqLibd.a
        }
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
        TARGET = qGames
        windows {
#                LIBS += ../../../../Apps/libqLib.a
        }
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/qPhotoLab
MOC_DIR = ../../../../GeneratedFiles/qPhotoLab
DESTDIR = ../../../../Apps


########################################################################
# SOURCES
########################################################################
SOURCES += \
    qLib/Application/main.cpp \
    qLib/Application/qAppBase.cpp


########################################################################
# HEADERS
########################################################################
HEADERS += \
    qLib/Application/main.h \
    qLib/Application/qAppBase.h


########################################################################
# Forms
########################################################################
FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
