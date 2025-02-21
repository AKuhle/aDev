QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


########################################################################
# defines
########################################################################
DEFINES += _USE_QT_

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


########################################################################
# debug configuration
########################################################################
CONFIG(debug, debug|release) {
        TARGET = qPhotoLabd
        windows {
                LIBS += ../../../../Apps/libqLibd.a
        }
        unix {
                LIBS += ../Apps/libqLibd.a
        }
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
        TARGET = qPhotoLab
        windows {
                LIBS += ../../../../Apps/libqLib.a
        }
        unix {
                LIBS += ../Apps/libqLib.a
        }
}


########################################################################
# windows configuration
########################################################################
UI_DIR = ../../../../GeneratedFiles/qPhotoLab
MOC_DIR = ../../../../GeneratedFiles/qPhotoLab
DESTDIR = ../../../../Apps


########################################################################
# include pathes for qlLib
########################################################################
INCLUDEPATH += ../qLib/


########################################################################
# include pathes for qPhotoLab
########################################################################
INCLUDEPATH += Application
INCLUDEPATH += Win


########################################################################
# SOURCES
########################################################################
SOURCES += \
    Application/qPhotoLab.cpp \
    Win/mainWin.cpp


########################################################################
# HEADERS
########################################################################
HEADERS += \
    Application/qPhotoLab.h \
    Win/mainWin.h


########################################################################
# resources
########################################################################
#RESOURCES += \
#    Resource_Qt/Resource/qFsResource.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#RESOURCES +=
#    Resource/Resource_Qt/qLib.qrc

#DISTFILES += \
#    Docs/colors.txt
