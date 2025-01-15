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
: aBaseWin(_pParent)
{
} // aMainWin::aMainWin


/*******************************************************************************
* aMainWin::~aMainWin
*******************************************************************************/
aMainWin::~aMainWin()
{
} // aMainWin::aMainWin


/*******************************************************************************
* aMainWin::onSysCreate
*******************************************************************************/
bool aMainWin::onSysCreate()
{
    unique_ptr<aLayoutMainWin> pLayout = make_unique<aLayoutMainWin> ();

    aTitleBar   *pTitleBar = new aTitleBar(this);
    pTitleBar->create();
    pLayout->setTitleBar(pTitleBar);

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
* aMainWin::contentRect
*******************************************************************************/
aRect2D<s32> aMainWin::contentRect() const
{
    aRect2D<s32>    r = aBaseWin::contentRect();

    // take dockareas into account

    return r;
} // aMainWin::contentRect


/*******************************************************************************
* aMainWin::layoutRect
*******************************************************************************/
aRect2D<s32> aMainWin::layoutRect() const
{
    return aBaseWin::contentRect();
 } // aMainWin::layoutRect



} // namespace aWin
} // namespace aLib
