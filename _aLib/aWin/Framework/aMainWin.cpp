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
#include "aWin/Framework/aMainWin.h"
#include "aWin/Framework/aTitleBar.h"
#include "aWin/Framework/aDockArea.h"

#include "aWin/Layout/aLayoutMainWin.h"

#include "aWin/Tool/aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMainWin::aMainWin
*******************************************************************************/
aMainWin::aMainWin(aBaseWin  *_pParent  /* = nullptr */)
: aCentralWin(_pParent)
{
} // aMainWin::aMainWin


/*******************************************************************************
* aMainWin::~aMainWin
*******************************************************************************/
aMainWin::~aMainWin()
{
} // aMainWin::aMainWin


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


/*******************************************************************************
* aMainWin::onSysCreate
*******************************************************************************/
bool aMainWin::onSysCreate()
{
    unique_ptr<aLayoutMainWin> pLayout = make_unique<aLayoutMainWin> ();

    aTitleBar   *pTitleBar = new aTitleBar(this);
    pTitleBar->create();
    pLayout->setTitleBar(pTitleBar);

    // add the dock areas
    aDockArea   *pDA = new aDockArea(this);    // the top one
    pDA->create();
    pLayout->addTopWin(pDA);

    pDA = new aDockArea(this);    // the bottom one
    pDA->create();
    pLayout->addBottomWin(pDA);

    pDA = new aDockArea(this);    // the left one
    pDA->create();
    pLayout->addLeftWin(pDA);

    pDA = new aDockArea(this);    // the right one
    pDA->create();
    pLayout->addRightWin(pDA);

    // move the layout
    setLayout(std::move (pLayout));

    // start the border resize tool
    unique_ptr<aBorderResizeTool> pTool = make_unique<aBorderResizeTool> (this);
    setTool(std::move(pTool));

    // enable mouse tracking to set the resize cursor
    setMouseTracking(true);

    return true;
} // aMainWin::onSysCreate


/*******************************************************************************
* aMainWin::onSysCreate
*******************************************************************************/
bool aMainWin::onSysCreate()
{
    return true;
} // aMainWin::onSysCreate


} // namespace aWin
} // namespace aLib
