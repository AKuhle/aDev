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

INCLUDEPATH += ../qLib/qBase
INCLUDEPATH += ../qLib/qBase/App
INCLUDEPATH += ../qLib/qBase/Classes
INCLUDEPATH += ../qLib/qBase/Classes/Qt
INCLUDEPATH += ../qLib/qBase/Cmds
INCLUDEPATH += ../qLib/qBase/File_io
INCLUDEPATH += ../qLib/qBase/Collection
INCLUDEPATH += ../qLib/qBase/VarPool
INCLUDEPATH += ../qLib/qBase/VarPool/Qt

INCLUDEPATH += ../qLib/qGui
INCLUDEPATH += ../qLib/qGui/App/Qt
INCLUDEPATH += ../qLib/qGui/Classes
INCLUDEPATH += ../qLib/qGui/Classes/Qt
INCLUDEPATH += ../qLib/qGui/Ctrls
INCLUDEPATH += ../qLib/qGui/Ctrls/Qt
INCLUDEPATH += ../qLib/qGui/DocView
INCLUDEPATH += ../qLib/qGui/Win
INCLUDEPATH += ../qLib/qGui/Tools
INCLUDEPATH += ../qLib/qGui/VarPool
INCLUDEPATH += ../qLib/qGui/Win/Qt

INCLUDEPATH += ../qLib/qMath
INCLUDEPATH += ../qLib/qMath/Classes
INCLUDEPATH += ../qLib/qMath/MathObj2D

INCLUDEPATH += ../qLib/qPic
INCLUDEPATH += ../qLib/qPic/Classes


########################################################################
# include pathes for qPhotoLab
########################################################################
INCLUDEPATH += App
INCLUDEPATH += Cmds
INCLUDEPATH += Cmds/File_io
INCLUDEPATH += Cmds/Transform
INCLUDEPATH += Dlg
INCLUDEPATH += DocView
INCLUDEPATH += Tools
INCLUDEPATH += Win
INCLUDEPATH += Win/Option


########################################################################
# SOURCES
########################################################################
SOURCES += \
    App/qPhotoLabApp.cpp \
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
    DocView/docPl.cpp \
    DocView/renderParams.cpp \
    DocView/viewBase.cpp \
    DocView/viewBase_coordinates.cpp \
    DocView/viewNavigator.cpp \
    DocView/viewStd.cpp \
    DocView/zoomSteps.cpp \
    Tools/toolBase.cpp \
    Tools/toolMove.cpp \
    Tools/toolNavigator.cpp \
    Tools/toolZoom.cpp \
    Win/Option/optionMoveWin.cpp \
    Win/Option/optionZoomWin.cpp \
    Win/mainWin.cpp \
    Win/mainWin_cmd.cpp \
    Win/mainWin_ctrls.cpp \
    Win/mainWin_handler.cpp \
    Win/mainWin_io.cpp \
    Win/mainWin_update.cpp \
    Win/navigatorToolWin.cpp \
    Win/protocolToolWin.cpp \
    Win/stdMdiWin.cpp \
    Win/stdScrollWin.cpp \
    Win/toolBoxToolWin.cpp \
    Win/toolWin.cpp \
    Win/varPoolPl.cpp


########################################################################
# HEADERS
########################################################################
HEADERS += \
    App/defsPl.h \
    App/qPhotoLabApp.h \
    Cmds/File_io/cmdOpenFile.h \
    Cmds/Transform/cmdFlipHori.h \
    Cmds/Transform/cmdFlipVert.h \
    Cmds/Transform/cmdInvert.h \
    Cmds/Transform/cmdRotate180.h \
    Cmds/Transform/cmdRotateCCW.h \
    Cmds/Transform/cmdRotateCW.h \
    Cmds/cmdBase.h \
    Cmds/cmdBase4EqualTiles.h \
    Cmds/cmdBase4Tiles.h \
    Cmds/tile.h \
    DocView/docPl.h \
    DocView/renderParams.h \
    DocView/viewBase.h \
    DocView/viewNavigator.h \
    DocView/viewStd.h \
    DocView/zoomSteps.h \
    Tools/toolBase.h \
    Tools/toolMove.h \
    Tools/toolNavigator.h \
    Tools/toolZoom.h \
    Win/Option/optionMoveWin.h \
    Win/Option/optionZoomWin.h \
    Win/mainWin.h \
    Win/navigatorToolWin.h \
    Win/protocolToolWin.h \
    Win/stdMdiWin.h \
    Win/stdScrollWin.h \
    Win/toolBoxToolWin.h \
    Win/toolWin.h \
    Win/varPoolPl.h


########################################################################
# FORMS
########################################################################
FORMS += \
    Resource_Qt/Forms/formMainWin.ui \
    Resource_Qt/Forms/formNavigator.ui \
    Resource_Qt/Forms/formOptionMove.ui \
    Resource_Qt/Forms/formOptionZoom.ui \
    Resource_Qt/Forms/formProtocol.ui \
    Resource_Qt/Forms/formToolBox.ui


########################################################################
# FORMS
########################################################################
#RESOURCES += \
#    Resource_Qt/Resource/qFsResource.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource_Qt/Resource/qFsResource.qrc

DISTFILES += \
    Docs/colors.txt
