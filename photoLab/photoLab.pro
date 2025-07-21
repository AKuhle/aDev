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
#        TARGET = qPhotoLab
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
UI_DIR = ../../../../GeneratedFiles/photoLab
MOC_DIR = ../../../../GeneratedFiles/photoLab
DESTDIR = ../../../../Apps


# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target


########################################################################
# include pathes for aFrame
########################################################################
INCLUDEPATH += ../aFrame

INCLUDEPATH += ../aFrame/aApp
INCLUDEPATH += ../aFrame/aApp/Qt

INCLUDEPATH += ../aFrame/aUtil
INCLUDEPATH += ../aFrame/aUtil/Cmds
INCLUDEPATH += ../aFrame/aUtil/Collection
INCLUDEPATH += ../aFrame/aUtil/Interface
INCLUDEPATH += ../aFrame/aUtil/Qt
INCLUDEPATH += ../aFrame/aUtil/Tool
INCLUDEPATH += ../aFrame/aUtil/VarPool

INCLUDEPATH += ../aFrame/aMath
INCLUDEPATH += ../aFrame/aMath/Obj2D
INCLUDEPATH += ../aFrame/aMath/Obj3D

INCLUDEPATH += ../aFrame/aGraphic
INCLUDEPATH += ../aFrame/aGraphic/Interface
INCLUDEPATH += ../aFrame/aGraphic/Qt

INCLUDEPATH += ../aFrame/aWin
INCLUDEPATH += ../aFrame/aWin/Interface
INCLUDEPATH += ../aFrame/aWin/Qt


########################################################################
# include PhotoLab
########################################################################
INCLUDEPATH += App
# INCLUDEPATH += Classes
# INCLUDEPATH += Cmds
# INCLUDEPATH += Cmds/File_io
# INCLUDEPATH += Cmds/Transform
# INCLUDEPATH += DocView
# INCLUDEPATH += Tool
# INCLUDEPATH += ToolWin
INCLUDEPATH += Win


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/photoLabApp.h \
    App/photoLab_defs.h \
    Win/mainWin.h


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/photoLabApp.cpp \
    Win/mainWin.cpp


########################################################################
# resources
########################################################################
#RESOURCES += \
#    Resource/Resource_Qt/photoLab.qrc

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
#FORMS += \
#    Forms/formMainWin.ui \
#    Forms/formNavigator.ui
