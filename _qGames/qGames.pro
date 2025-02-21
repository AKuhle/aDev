QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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
# include path
########################################################################
INCLUDEPATH += Classes
INCLUDEPATH += Collections
INCLUDEPATH += Form
INCLUDEPATH += Pages
INCLUDEPATH += qLib
INCLUDEPATH += VarPool
INCLUDEPATH += Win


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/buzzerWidget.cpp \
    Classes/gameInfo.cpp \
    Classes/main.cpp \
    Classes/panel.cpp \
    Classes/pointWidget.cpp \
    Classes/roundInfo.cpp \
    Classes/teamInfo.cpp \
    Pages/pageBase.cpp \
    Pages/pageMosaic.cpp \
    Pages/pagePanel.cpp \
    Pages/pageStd.cpp \
    Win/mainWin_slots.cpp \
    qLib/qBrush.cpp \
    qLib/qColor.cpp \
    qLib/qFile.cpp \
    qLib/qFont.cpp \
    qLib/qIoDevice.cpp \
    qLib/qJsonFile.cpp \
    qLib/qJsonValue.cpp \
    qLib/qMathObjBase.cpp \
    qLib/qMathObjBase2D.cpp \
    qLib/qPainter.cpp \
    qLib/qPath.cpp \
    qLib/qPen.cpp \
    qLib/qPixmap.cpp \
    qLib/qString16.cpp \
    VarPool/gamesVarPool.cpp \
    VarPool/qPoolVarBool.cpp \
    VarPool/qPoolVarColor.cpp \
    VarPool/qPoolVarDbl.cpp \
    VarPool/qPoolVarS32.cpp \
    VarPool/qVarPool.cpp \
    Win/gameWin.cpp \
    Win/mainWin.cpp \
    qLib/qSysDlg.cpp

HEADERS += \
    Classes/buzzerWidget.h \
    Classes/gameInfo.h \
    Classes/gamesDefs.h \
    Classes/panel.h \
    Classes/pointWidget.h \
    Classes/roundInfo.h \
    Classes/teamInfo.h \
    Pages/pageBase.h \
    Pages/pageMosaic.h \
    Pages/pagePanel.h \
    Pages/pageStd.h \
    qLib/qBaseDefs.h \
    qLib/qBrush.h \
    qLib/qColor.h \
    qLib/qDimension2D.h \
    qLib/qDimension2D.inl \
    qLib/qFile.h \
    qLib/qFont.h \
    qLib/qGuiDefs.h \
    qLib/qIoDevice.h \
    qLib/qJsonFile.h \
    qLib/qJsonValue.h \
    qLib/qMathObjBase.h \
    qLib/qMathObjBase2D.h \
    qLib/qMathUtil.h \
    qLib/qMathUtil.inl \
    qLib/qPainter.h \
    qLib/qPath.h \
    qLib/qPen.h \
    qLib/qPixmap.h \
    qLib/qRect2D.h \
    qLib/qRect2D.inl \
    qLib/qString16.h \
    Collections/qList.h \
    Collections/qList.inl \
    Collections/qMap.h \
    Collections/qPtrList.h \
    Collections/qPtrList.inl \
    Collections/qSharedPtrDeque.h \
    Collections/qSharedPtrList.h \
    Collections/qSharedPtrList.inl \
    Collections/qUniquePtrDeque.h \
    Collections/qUniquePtrDeque.inl \
    Collections/qUniquePtrList.h \
    Collections/qUniquePtrList.inl \
    Collections/qUniquePtrVec.h \
    Collections/qUniquePtrVec.inl \
    Collections/qVec.h \
    Collections/qVec.inl \
    VarPool/gamesVarPool.h \
    VarPool/qPoolVarBool.h \
    VarPool/qPoolVarColor.h \
    VarPool/qPoolVarDbl.h \
    VarPool/qPoolVarS32.h \
    VarPool/qPoolVar_i.h \
    VarPool/qVarPool.h \
    VarPool/qVarPool.inl \
    Win/gameWin.h \
    Win/mainWin.h \
    qLib/qSysDlg.h \
    qLib/qVector2D.h \
    qLib/qVector2D.inl

FORMS += \
    Form/mainWin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/qGames.qrc
