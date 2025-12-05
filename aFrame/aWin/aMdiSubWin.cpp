/*******************************************************************************
* \file aMdiSubWin.cpp
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

#include "aMdiSubWin.h"
#include "aLayoutMainWin.h"
#include "aLayoutHoriVert.h"
#include "aTitleBar.h"
#include "aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMdiSubWin::aMdiSubWin
*******************************************************************************/
aMdiSubWin::aMdiSubWin(aBaseWin *_pParent)
: aBaseWin(_pParent)
{
} // aMdiSubWin::_isVisible


/*******************************************************************************
* aMdiSubWin::~aMdiSubWin
*******************************************************************************/
aMdiSubWin::~aMdiSubWin()
{
} // aMdiSubWin::~aMdiSubWin


/*******************************************************************************
* aMdiSubWin::titleBar
*******************************************************************************/
const aTitleBar* aMdiSubWin::titleBar() const
{
    const aLayoutMainWin *pLayout = dynamic_cast<const aLayoutMainWin *> (layout());
    CHECK_PRE_CONDITION(pLayout, nullptr);

    return pLayout->titleBar();
} // aMdiSubWin::titleBar


/*******************************************************************************
* aMdiSubWin::titleBar
*******************************************************************************/
aTitleBar* aMdiSubWin::titleBar()
{
    aLayoutMainWin *pLayout = dynamic_cast<aLayoutMainWin *> (layout());
    CHECK_PRE_CONDITION(pLayout, nullptr);

    return pLayout->titleBar();
} // aMdiSubWin::titleBar


/*******************************************************************************
* aMdiSubWin::onSysCreateWin
*******************************************************************************/
bool aMdiSubWin::onSysCreateWin()
{
    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    // #ifdef _USE_QT_
    //     // Titelleiste entfernen (for top level windows)
    //     asSysWin()->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // #endif // _USE_QT_

    // create the layout
    unique_ptr<aLayoutMainWin>  pLayout = make_unique<aLayoutMainWin> ();

    unique_ptr<aTitleBar> pTitleBar = make_unique<aTitleBar> (this);
    pTitleBar->createWin();

    // move the items
    pLayout->setTitleBar(std::move(pTitleBar));
    setLayout(std::move(pLayout));

    // add the aBorderResizeTool
    addTool(make_unique<aBorderResizeTool> (this));

    return true;
} // aMdiSubWin::onSysCreateWin


} // namespace aWin
} // namespace aFrame
