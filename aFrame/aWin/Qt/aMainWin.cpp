/*******************************************************************************
* \file aMainWin.cpp
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

#include "aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWin::aMainWin
*******************************************************************************/
aMainWin::aMainWin(SysWin *_pParent)
: aMainWin_i(new QMainWindow(_pParent))
{
} // aMainWin::_isVisible


/*******************************************************************************
* aMainWin::~aMainWin
*******************************************************************************/
aMainWin::~aMainWin()
{
} // aMainWin::~aMainWin


// /*******************************************************************************
// * aMainWin::setCentralWin
// *******************************************************************************/
// void aMainWin::setCentralWin(SysWin *_pWin)
// {
//     QMainWindow::setCentralWidget(_pWin);
// } // aMainWin::setCentralWin


// /*******************************************************************************
// * aMainWin::centralWin
// *******************************************************************************/
// SysWin* aMainWin::centralWin()
// {
//     return QMainWindow::centralWidget();
// } // aMainWin::centralWin


// /*******************************************************************************
// * aMainWin::centralWin
// *******************************************************************************/
// SysWin* aMainWin::centralWin() const
// {
//     return QMainWindow::centralWidget();
// } // aMainWin::centralWin


// /*******************************************************************************
// * aMainWin::setStatusBar
// *******************************************************************************/
// void aMainWin::setStatusBar(aStatusBar *_pBar)
// {
//     QMainWindow::setStatusBar(_pBar);
// } // aMainWin::setStatusBar


// /*******************************************************************************
// * aMainWin::statusBar
// *******************************************************************************/
// aStatusBar* aMainWin::statusBar() const
// {
//     return dynamic_cast<aStatusBar *> (QMainWindow::statusBar());
// } // aMainWin::statusBar


// /*******************************************************************************
// * aMainWin::addDockWin
// *******************************************************************************/
// void aMainWin::addDockWin(const aString  &_sTile,
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
// } // aMainWin::addDockWin


// /*******************************************************************************
// * aMainWin::saveWinGeometry
// *******************************************************************************/
// void aMainWin::saveWinGeometry(const aString    &_sCompany,
//                                const aString    &_sApplication)
// {
//     QSettings settings(_sCompany.toQString(), _sApplication.toQString());
//     settings.setValue("geometry", saveGeometry());
//     settings.setValue("state", saveState());
// } // aMainWin::saveWinGeometry


// /*******************************************************************************
// * aMainWin::restoreWinGeometry
// *******************************************************************************/
// void aMainWin::restoreWinGeometry(const aString    &_sCompany,
//                                   const aString    &_sApplication)
// {
//     QSettings settings(_sCompany.toQString(), _sApplication.toQString());
//     restoreGeometry(settings.value("geometry").toByteArray());
//     restoreState(settings.value("state").toByteArray());
// } // aMainWin::restoreWinGeometry


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64 _u64Cmd)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              aDoc   *_pDoc)
// {
//     onUpdateCmd(_u64Cmd, _pDoc, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              aView  *_pView)
// {
//     onUpdateCmd(_u64Cmd, nullptr, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              aDoc   *_pDoc,
//                              aView  *_pView)
// {
//     onUpdateCmd(_u64Cmd, _pDoc, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              s64    _s64Param1)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64     _u64Cmd,
//                              s64     _s64Param1,
//                              s64     _s64Param2)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, _s64Param2, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              u64    _u64Param1)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


// /*******************************************************************************
// * aMainWin::sendUpdateCmd
// *******************************************************************************/
// void aMainWin::sendUpdateCmd(u64    _u64Cmd,
//                              u64    _u64Param1,
//                              u64    _u64Param2)
// {
//     onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, _u64Param2, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
// } // aMainWin::sendUpdateCmd


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
