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
    // win, idx, newW
    using SizeTuple = std::tuple<aBaseWin *, s32, s32>;

    aDimension          demand  = aLayoutHoriVert::layoutDemand();
    s32                 space   = _r.w() - demand.w();
    s32                 l       = _r.l();
    s32                 y;
    vector<SizeTuple>   vTup;

    s32 idx = 0;
    for (auto pChild : m_lstChilds)
    {
        SizeTuple t = std::make_tuple(pChild, idx++, 0);
        vTup.push_back(t);
    }

    // 1. sort the childs to their max width, lowest first
    std::sort(vTup.begin(), vTup.end(), [](const SizeTuple& a, const SizeTuple& b) {
         return std::get<0>(a)->maxW() < std::get<0>(b)->maxW();
    });

    // 2. set the size of all fixed childs
    for (auto &tup : vTup)
    {
        if (std::get<0>(tup)->isFixW())
        {
            s32 w = std::get<0>(tup)->minW();

            std::get<2>(tup) = w;
            space -= w;
        }
    }

    // 3. set the size of all variable childs
    for (auto &tup : vTup)
    {
        if (!std::get<0>(tup)->isFixW())
        {
            cout << "mima:" << std::get<0>(tup)->minW() << " - " << std::get<0>(tup)->maxW() << endl;
        }
    }

    // 4. sort the childs back to their index
    std::sort(vTup.begin(), vTup.end(), [](const SizeTuple& a, const SizeTuple& b) {
         return std::get<1>(a) < std::get<1>(b);
    });

    // 5. set thr new width and position of the childs
    for (auto tup : vTup)
    {
        aBaseWin    *pChild     = std::get<0>(tup);
        s32         s32ChildW   = std::get<2>(tup);
        s32         s32ChildH   = pChild->minH();


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
