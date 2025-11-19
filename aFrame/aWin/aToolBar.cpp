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
#include "aPainter.h"
#include "aStyleItemBorder.h"


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
* aToolBar::setAllowedDockPosition
*******************************************************************************/
void aToolBar::setAllowedDockPosition(u32 _u32AllowedDockPos)
{
    m_u32AllowedDockPos = _u32AllowedDockPos;
} // aToolBar::setAllowedDockPosition


/*******************************************************************************
* aToolBar::allowedDockPosition
*******************************************************************************/
u32 aToolBar::allowedDockPosition() const
{
    return m_u32AllowedDockPos;
} // aToolBar::allowedDockPosition


/*******************************************************************************
* aToolBar::setDockPosition
*******************************************************************************/
void aToolBar::setDockPosition(u32 _u32DockPos)
{
    m_u32DockPos = _u32DockPos;
} // aToolBar::setDockPosition


/*******************************************************************************
* aToolBar::dockPosition
*******************************************************************************/
u32 aToolBar::dockPosition() const
{
    return m_u32DockPos;
} // aToolBar::dockPosition


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


/*******************************************************************************
* aToolBar::borderMarginFromPosition
* a Toolbar has the border only on the edge where it is attached
*******************************************************************************/
aMargin aToolBar::borderMarginFromPosition() const
{
    aMargin m;

    if (borderStyle() != nullptr)
    {
        aMargin marginOri = borderStyle()->margin();

        // draw only the border according to the position
        switch (m_u32DockPos)
        {
            default:
                m = marginOri;
                break;

            case DOCK_POS_T:
                m.set(0, 0, marginOri.t(), 0);
                break;

            case DOCK_POS_B:
                m.set(0, 0, 0, marginOri.b());
                break;

            case DOCK_POS_L:
                m.set(marginOri.l(), 0, 0, 0);
                break;

            case DOCK_POS_R:
                m.set(0, marginOri.r(), 0, 0);
                break;
        } // switch
    }

    return m;
} // aToolBar::borderMarginFromPosition


/*******************************************************************************
* aToolBar::onPaintBorder
* a Toolbar has the border only on the edge where it is attached
*******************************************************************************/
void aToolBar::onPaintBorder()
{
    if (borderStyle() != nullptr)
    {
        aRect                           r = borderRect();
        aPainter                        p(this);

        shared_ptr<aStyleItemBorder>    pStyle      = borderStyle();
        aMargin                         marginOri   = pStyle->margin();
        aMargin                         marginDraw  = borderMarginFromPosition();

        // draw the border
        pStyle->setMargin(marginDraw);
        pStyle->draw(p, r);

        // restore the original border
        pStyle->setMargin(marginOri);
    }
} // aToolBar::onPaintBorder


/*******************************************************************************
* aToolBar::paddingRect
* a Toolbar has the border only on the edge where it is attached
*******************************************************************************/
aRect aToolBar::paddingRect() const
{
    aRect    r = borderRect();

    // no border => padding rect == border rect
    if (borderStyle())
    {
        r -= borderMarginFromPosition();
    }

    return r;
} // aToolBar::paddingRect


} // namespace aWin
} // namespace aFrame
