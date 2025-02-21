/*******************************************************************************
* \file aMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>

#include "aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWin::aMainWin
*******************************************************************************/
aMainWin::aMainWin(SysWinClass *_pParent /*= nullptr*/)
: aMainWin_sys(_pParent)
{
} // aMainWin::aMainWin


/*******************************************************************************
* aMainWin::~aMainWin
*******************************************************************************/
aMainWin::~aMainWin()
{
} // aMainWin::aMainWin


/*******************************************************************************
* aMainWin::setCentralWin
*******************************************************************************/
void aMainWin::setCentralWin(SysWinClass *_pWin)
{
    _setCentralWin(_pWin);
} // aMainWin::setCentralWin


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64 _u64Cmd)
{
    onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             aDoc   *_pDoc)
{
    onUpdateCmd(_u64Cmd, _pDoc, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             aView  *_pView)
{
    onUpdateCmd(_u64Cmd, nullptr, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             aDoc   *_pDoc,
                             aView  *_pView)
{
    onUpdateCmd(_u64Cmd, _pDoc, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             s64    _s64Param1)
{
    onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64     _u64Cmd,
                                s64     _s64Param1,
                                s64     _s64Param2)
{
    onUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, _s64Param2, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             u64    _u64Param1)
{
    onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd


/*******************************************************************************
* aMainWin::sendUpdateCmd
*******************************************************************************/
void aMainWin::sendUpdateCmd(u64    _u64Cmd,
                             u64    _u64Param1,
                             u64    _u64Param2)
{
    onUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, _u64Param2, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
} // aMainWin::sendUpdateCmd



} // namespace aWin
} // namespace aLib
