/*******************************************************************************
* \file aLayoutHoriVert.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayoutHoriVert.h"
#include "aBaseWin.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aLayoutHoriVert::aLayoutHoriVert
*******************************************************************************/
aLayoutHoriVert::aLayoutHoriVert()
{
} // aLayoutHoriVert::_isVisible


/*******************************************************************************
* aLayoutHoriVert::~aLayoutHoriVert
*******************************************************************************/
aLayoutHoriVert::~aLayoutHoriVert()
{
} // aLayoutHoriVert::~aLayoutHoriVert


/*******************************************************************************
* aLayoutHoriVert::addChild
*******************************************************************************/
void aLayoutHoriVert::addChild(aBaseWin *_pWin)
{
    m_lstChilds.push_back(_pWin);
} // aLayoutHoriVert::addChild


/*******************************************************************************
* aLayoutHoriVert::layoutDemand
*******************************************************************************/
aDimension aLayoutHoriVert::layoutDemand() const
{
    if (m_eOrientation == enumOrientation::Hori)
    {
        return layoutDemandHori();
    }
    else
    {
        return layoutDemandVert();
    }
} // aLayoutHoriVert::layoutDemand


/*******************************************************************************
* aLayoutHoriVert::arrange
*******************************************************************************/
void aLayoutHoriVert::arrange(const aRect &_r)
{
    if (m_eOrientation == enumOrientation::Hori)
    {
        arrangeHori(_r);
    }
    else
    {
        arrangeVert(_r);
    }
} // aLayoutHoriVert::arrange


/*******************************************************************************
* aLayoutHoriVert::layoutDemandHori
*******************************************************************************/
aDimension aLayoutHoriVert::layoutDemandHori() const
{
    aDimension   dimDemand;
    aDimension   dimChild;

    for (const aBaseWin *pChild : m_lstChilds)
    {
        dimChild = layoutDemandOfChild(pChild);

        dimDemand.w() += dimChild.w();
        dimDemand.h() =aUtil::max(dimChild.h(), dimDemand.h());
    }

    return dimDemand;
} // aLayoutHoriVert::layoutDemandHori


/*******************************************************************************
* aLayoutHoriVert::layoutDemandVert
*******************************************************************************/
aDimension aLayoutHoriVert::layoutDemandVert() const
{
    aDimension   dimDemand;

    // for (const aBaseWin *pChild : m_lstChilds)
    // {
    // }

    return dimDemand;
} // aLayoutHoriVert::layoutDemandVert


/*******************************************************************************
* aLayoutHoriVert::arrangeHori
*******************************************************************************/
void aLayoutHoriVert::arrangeHori(const aRect &_r)
{
    aDimension demand   = aLayoutHoriVert::layoutDemand();

    s32         l       = _r.l();

    s32         y;

    for (aBaseWin *pChild : m_lstChilds)
    {
        s32     s32ChildW   = pChild->minW();
        s32     s32ChildH   = pChild->minH();

        y = (demand.h() - s32ChildH) / 2;

        // set the child geometry
        pChild->setGeometry(l, y, s32ChildW, s32ChildH);

        l += s32ChildW;
    }
} // aLayoutHoriVert::arrangeHori


/*******************************************************************************
* aLayoutHoriVert::arrangeVert
*******************************************************************************/
void aLayoutHoriVert::arrangeVert(const aRect &/*_r*/)
{
    // for (aBaseWin *pChild : m_lstChilds)
    // {
    // }
} // aLayoutHoriVert::arrangeVert


} // namespace aWin
} // namespace aFrame
