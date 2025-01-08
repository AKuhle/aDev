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
        TARGET = qGamesd
        windows {
                LIBS += ../../../../Apps/libqLibd.a
        }
}


########################################################################
# release configuration
########################################################################
CONFIG(release, debug|release) {
        TARGET = qGames
        windows {
                LIBS += ../../../../Apps/libqLib.a
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
INCLUDEPATH += ../qLib/qBase/Collections
INCLUDEPATH += ../qLib/qBase/VarPool

INCLUDEPATH += ../qLib/qGui
INCLUDEPATH += ../qLib/qGui/App
INCLUDEPATH += ../qLib/qGui/App/Qt
INCLUDEPATH += ../qLib/qGui/Classes
INCLUDEPATH += ../qLib/qGui/Classes/Qt
INCLUDEPATH += ../qLib/qGui/Ctrls
INCLUDEPATH += ../qLib/qGui/Dlg
INCLUDEPATH += ../qLib/qGui/Dlg/Qt
INCLUDEPATH += ../qLib/qGui/DocView
INCLUDEPATH += ../qLib/qGui/Layouts
INCLUDEPATH += ../qLib/qGui/Painting
INCLUDEPATH += ../qLib/qGui/Painting/Qt
INCLUDEPATH += ../qLib/qGui/Tools
INCLUDEPATH += ../qLib/qGui/VarPool
INCLUDEPATH += ../qLib/qGui/Win
INCLUDEPATH += ../qLib/qGui/Win/CtrlBars
INCLUDEPATH += ../qLib/qGui/Win/Qt
INCLUDEPATH += ../qLib/qGui/Win/WinStyle

INCLUDEPATH += ../qLib/qMath
INCLUDEPATH += ../qLib/qMath/Classes
INCLUDEPATH += ../qLib/qMath/MathObj2D
INCLUDEPATH += ../qLib/qMath/MathObj3D

INCLUDEPATH += ../qLib/qPic
INCLUDEPATH += ../qLib/qPic/Classes
INCLUDEPATH += ../qLib/qPic/Classes/Qt


########################################################################
# include pathes for qGames
########################################################################
INCLUDEPATH += App
INCLUDEPATH += VarPool
INCLUDEPATH += Win
INCLUDEPATH += Win/CtrlBars


SOURCES += \
    App/qGames.cpp \
    VarPool/varPool.cpp \
    Win/CtrlBars/stdBar.cpp \
    Win/ctrlWin.cpp \
    Win/ctrlWin_ctrlMgr.cpp \
    Win/gameWin.cpp \
    Win/gameWin_ctrlMgr.cpp \
    Win/gameWin_handler.cpp \
    Win/mainWin.cpp \
    Win/mainWin_ctrlMgr.cpp \
    Win/mainWin_handler.cpp \
    Win/mainWin_io.cpp

HEADERS += \
    App/qGames.h \
    App/qGamesDefs.h \
    VarPool/varPool.h \
    Win/CtrlBars/stdBar.h \
    Win/ctrlWin.h \
    Win/gameWin.h \
    Win/mainWin.h

FORMS +=

TRANSLATIONS +=
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/Resource_Qt/qGames.qrc
