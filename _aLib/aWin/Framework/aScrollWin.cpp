/*******************************************************************************
* \file aScrollWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aScrollWin.h"

#include "aWin/Layout/aLayoutCentralWin.h"

#include "aWin/Ctrl/aScrollBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollWin::aScrollWin
*******************************************************************************/
aScrollWin::aScrollWin(aBaseWin  *_pParent  /* = nullptr */)
: aCentralWin(_pParent)
{
} // aScrollWin::aScrollWin


/*******************************************************************************
* aScrollWin::~aScrollWin
*******************************************************************************/
aScrollWin::~aScrollWin()
{
} // aScrollWin::aScrollWin


/*******************************************************************************
* aScrollWin::onSysCreate
*******************************************************************************/
bool aScrollWin::onSysCreate()
{
    unique_ptr<aLayoutCentralWin> pLayout = make_unique<aLayoutCentralWin> ();

    // create the horizontal scrollbar
    m_pHoriSb = new aScrollBar(this, CTRL_ID_HORI_SCROLLBAR);
    m_pHoriSb->create();
    pLayout->addBottomWin(m_pHoriSb);

    // create the vertical scrollbar
    m_pVertSb = new aScrollBar(this, CTRL_ID_VERT_SCROLLBAR);
    m_pVertSb->create();
    pLayout->addRightWin(m_pVertSb);

    // move the layout
    setLayout(std::move (pLayout));

    return true;
} // aScrollWin::onSysCreate


/*******************************************************************************
* aScrollWin::contentRect
*******************************************************************************/
// aRect2D<s32> aScrollWin::contentRect() const
// {
//     aRect2D<s32>    r = aBaseWin::contentRect();

//     // take dockareas into account

//     return r;
// } // aScrollWin::contentRect




} // namespace aWin
} // namespace aLib
