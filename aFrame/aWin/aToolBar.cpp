/*******************************************************************************
* \file aToolBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aWin_def.h"

#include "aToolBar.h"
#include "aLayoutHoriVert.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolBar::aToolBar
*******************************************************************************/
aToolBar::aToolBar(aBaseWin *_pParent /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aToolBar::aToolBar


/*******************************************************************************
* aToolBar::~aToolBar
*******************************************************************************/
aToolBar::~aToolBar()
{
} // aToolBar::~aToolBar


/*******************************************************************************
* aToolBar::addChild
*******************************************************************************/
void aToolBar::addChild(aBaseWin *_pWin)
{
    aLayoutHoriVert *pLayout = dynamic_cast<aLayoutHoriVert *> (layout());
    CHECK_PRE_CONDITION_VOID(pLayout);

    pLayout->addChild(_pWin);
} // aToolBar::addChild


/*******************************************************************************
* aToolBar::onSysCreateWin
*******************************************************************************/
bool aToolBar::onSysCreateWin()
{
    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    // create the layout
    unique_ptr<aLayoutHoriVert>  pLayout = make_unique<aLayoutHoriVert> ();
    setLayout(std::move(pLayout));

    return true;
} // namespace aFrame


} // namespace aWin
} // namespace aFrame
