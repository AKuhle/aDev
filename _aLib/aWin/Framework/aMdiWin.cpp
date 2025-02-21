/*******************************************************************************
* \file aMdiWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aGraphic/GraphicObj/aFillSolid.h"

#include "aWin/Framework/aMdiWin.h"
#include "aWin/Framework/aMdiArea.h"
#include "aWin/Framework/aTitleBar.h"

#include "aWin/Layout/aLayoutMainWin.h"

#include "aWin/Tool/aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aMdiWin::aMdiWin
*******************************************************************************/
aMdiWin::aMdiWin(aBaseWin  *_pParent  /* = nullptr */)
: aCentralWin(_pParent)
{
} // aMdiWin::aMdiWin


/*******************************************************************************
* aMdiWin::~aMdiWin
*******************************************************************************/
aMdiWin::~aMdiWin()
{
} // aMdiWin::aMdiWin


/*******************************************************************************
* aMdiWin::onSysCreate
*******************************************************************************/
bool aMdiWin::onSysCreate()
{
    unique_ptr<aLayoutMainWin> pLayout = make_unique<aLayoutMainWin> ();

    m_pTitleBar = new aTitleBar(this);
    m_pTitleBar->create();
    pLayout->setTitleBar(m_pTitleBar);

    // move the layout
    setLayout(std::move (pLayout));

    // start the border resize tool
    unique_ptr<aBorderResizeTool> pTool = make_unique<aBorderResizeTool> (this);
    setTool(std::move(pTool));

    // enable mouse tracking to set the resize cursor
    setMouseTracking(true);

    setFocusPolicy(enumFocusPolicy::StrongFocus);

    return true;
} // aMdiWin::onSysCreate


/*******************************************************************************
* aMdiWin::mdiArea
*******************************************************************************/
aMdiArea* aMdiWin::mdiArea()
{
    return dynamic_cast<aMdiArea *> (parent());
} // aMdiWin::mdiArea


/*******************************************************************************
* aMdiWin::onFocusIn
*******************************************************************************/
void aMdiWin::onFocusIn(enumFocusReason /*_eReason*/)
{
    // bring the window to the top of the z-order
    raise();

    // inform the mdi area about the new focus window
    if (mdiArea() != nullptr)
    {
        mdiArea()->mdiChildRaised(this);
    }

    // set the background of the titlebar
    m_pTitleBar->setContentObj(make_unique<aFillSolid> (activeColor()));
    m_pTitleBar->update();
} // aMdiWin::onFocusIn


/*******************************************************************************
* aMdiWin::onFocusOut
*******************************************************************************/
void aMdiWin::onFocusOut(enumFocusReason /*_eReason*/)
{
    // set the background of the titlebar
    m_pTitleBar->setContentObj(make_unique<aFillSolid> (bgColor()));
    m_pTitleBar->update();
} // aMdiWin::onFocusOut

} // namespace aWin
} // namespace aLib
