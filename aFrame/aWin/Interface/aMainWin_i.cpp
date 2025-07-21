/*******************************************************************************
* \file aMainWin_i.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>
//#include <QSettings>

#include "aMainWin_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWin_i::aMainWin_i
*******************************************************************************/
aMainWin_i::aMainWin_i(SysWin *_pWin)
: aBaseWin(_pWin)
{
} // aMainWin_i::_isVisible


/*******************************************************************************
* aMainWin_i::~aMainWin_i
*******************************************************************************/
aMainWin_i::~aMainWin_i()
{
} // aMainWin_i::~aMainWin_i


// /*******************************************************************************
// * aMainWin_i::setCentralWin
// *******************************************************************************/
// void aMainWin_i::setCentralWin(SysWin *_pWin)
// {
//     QMainWindow::setCentralWidget(_pWin);
// } // aMainWin_i::setCentralWin


// /*******************************************************************************
// * aMainWin_i::centralWin
// *******************************************************************************/
// SysWin* aMainWin_i::centralWin()
// {
//     return QMainWindow::centralWidget();
// } // aMainWin_i::centralWin


// /*******************************************************************************
// * aMainWin_i::centralWin
// *******************************************************************************/
// SysWin* aMainWin_i::centralWin() const
// {
//     return QMainWindow::centralWidget();
// } // aMainWin_i::centralWin


// /*******************************************************************************
// * aMainWin_i::setStatusBar
// *******************************************************************************/
// void aMainWin_i::setStatusBar(aStatusBar *_pBar)
// {
//     QMainWindow::setStatusBar(_pBar);
// } // aMainWin_i::setStatusBar


// /*******************************************************************************
// * aMainWin_i::statusBar
// *******************************************************************************/
// aStatusBar* aMainWin_i::statusBar() const
// {
//     return dynamic_cast<aStatusBar *> (QMainWindow::statusBar());
// } // aMainWin_i::statusBar


// /*******************************************************************************
// * aMainWin_i::addDockWin
// *******************************************************************************/
// void aMainWin_i::addDockWin(const aString  &_sTile,
//                           aDockWin       *_pDockWin,
//                           u16            _u16Area)
// {
//     Qt::DockWidgetArea area = Qt::NoDockWidgetArea;

//     if (isBitsSet<u16>(_u16Area, DOCK_POS_L))
//         area = Qt::LeftDockWidgetArea;
//     else if (isBitsSet<u16>(_u16Area, DOCK_POS_R))
//         area = Qt::RightDockWidgetArea;
//     else if (isBitsSet<u16>(_u16Area, DOCK_POS_T))
//         area = Qt::TopDockWidgetArea;
//     else if (isBitsSet<u16>(_u16Area, DOCK_POS_B))
//         area = Qt::BottomDockWidgetArea;

//     QMainWindow::addDockWidget(area, _pDockWin);

//     // set the title and object name
//     _pDockWin->setObjectName(_sTile);
//     _pDockWin->setWindowTitle(_sTile);
// } // aMainWin_i::addDockWin


// /*******************************************************************************
// * aMainWin_i::saveWinGeometry
// *******************************************************************************/
// void aMainWin_i::saveWinGeometry(const aString    &_sCompany,
//                                const aString    &_sApplication)
// {
//     QSettings settings(_sCompany.toQString(), _sApplication.toQString());
//     settings.setValue("geometry", saveGeometry());
//     settings.setValue("state", saveState());
// } // aMainWin_i::saveWinGeometry


// /*******************************************************************************
// * aMainWin_i::restoreWinGeometry
// *******************************************************************************/
// void aMainWin_i::restoreWinGeometry(const aString    &_sCompany,
//                                   const aString    &_sApplication)
// {
//     QSettings settings(_sCompany.toQString(), _sApplication.toQString());
//     restoreGeometry(settings.value("geometry").toByteArray());
//     restoreState(settings.value("state").toByteArray());
// } // aMainWin_i::restoreWinGeometry


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64 _u64Cmd)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              aDoc   *_pDoc)
// {
//     onUpdateCmd(_u64Cmd, _pDoc, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              aView  *_pView)
// {
//     onUpdateCmd(_u64Cmd, nullptr, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              aDoc   *_pDoc,
//                              aView  *_pView)
// {
//     onUpdateCmd(_u64Cmd, _pDoc, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              s64    _s64Param1)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64     _u64Cmd,
//                              s64     _s64Param1,
//                              s64     _s64Param2)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, _s64Param2, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              u64    _u64Param1)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


// /*******************************************************************************
// * aMainWin_i::sendUpdateCmd
// *******************************************************************************/
// void aMainWin_i::sendUpdateCmd(u64    _u64Cmd,
//                              u64    _u64Param1,
//                              u64    _u64Param2)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, _u64Param2, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin_i::sendUpdateCmd


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
