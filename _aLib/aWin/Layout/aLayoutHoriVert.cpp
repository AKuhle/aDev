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
#include "aWin/Layout/aLayoutHoriVert.h"

#include "aUtil/aHelper.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aLayoutHoriVert::aLayoutHoriVert
*******************************************************************************/
aLayoutHoriVert::aLayoutHoriVert()
{
} // aLayoutHoriVert::aLayoutHoriVert


/*******************************************************************************
* aLayoutHoriVert::~aLayoutHoriVert
*******************************************************************************/
aLayoutHoriVert::~aLayoutHoriVert()
{
} // aLayoutHoriVert::~aLayoutHoriVert


/*******************************************************************************
* aLayoutHoriVert::addChild
*******************************************************************************/
void aLayoutHoriVert::addChild(aLayoutObj *_pChild)
{
    m_lstChilds.push_back(_pChild);
} // aLayoutHoriVert::addChild


/*******************************************************************************
* aLayoutHoriVert::setOrientation
*******************************************************************************/
void aLayoutHoriVert::setOrientation(enumOrientation  _eOrientation)
{
    m_eOrientation = _eOrientation;
} // aLayoutHoriVert::setOrientation


/*******************************************************************************
* aLayoutHoriVert::orientation
*******************************************************************************/
enumOrientation aLayoutHoriVert::orientation() const
{
    return m_eOrientation;
} // aLayoutHoriVert::orientation


/*******************************************************************************
* aLayoutHoriVert::minDimHori
*******************************************************************************/
aDimension2D<s32> aLayoutHoriVert::minDimHori() const
{
    aDimension2D<s32>   minDim;

    // arrange the top childs
    for (aLayoutObj *pLO : m_lstChilds)
    {
        if (pLO->isVisible())
        {
            minDim.w() += pLO->distance().w() + pLO->minDim().w();
            minDim.h() = aUtil::max<s32>(minDim.h(), pLO->distance().h() + pLO->minDim().h());
        }
    }

    return minDim;
} // aLayoutHoriVert::minDimHori


/*******************************************************************************
* aLayoutHoriVert::minDimVert
*******************************************************************************/
aDimension2D<s32> aLayoutHoriVert::minDimVert() const
{
    aDimension2D<s32>   minDim;

    // arrange the top childs
    for (aLayoutObj *pLO : m_lstChilds)
    {
        if (pLO->isVisible())
        {
            minDim.w() = aUtil::max<s32>(minDim.w(), pLO->distance().w() + pLO->minDim().w());
            minDim.h() += pLO->distance().h() + pLO->minDim().h();
        }
    }

    return minDim;
} // aLayoutHoriVert::minDimVert


/*******************************************************************************
* aLayoutHoriVert::arangeChildsHori
*******************************************************************************/
void aLayoutHoriVert::arangeChildsHori(aRect2D<s32> _r2dLayout)
{
    aDimension2D<s32>                   minDim      = minDimHori();
    s32                                 restSpace   = _r2dLayout.w() - minDim.w();
    s32                                 x           = _r2dLayout.x();

    s32                                 y;
    s32                                 w;
    s32                                 expandCount;
    s32                                 add;

    std::vector<shared_ptr<structDim>>  allItems;
    std::vector<shared_ptr<structDim>>  fixedItems;
    std::vector<shared_ptr<structDim>>  expandItems;

    // prepare the layout info
    for (aLayoutObj *pLO : m_lstChilds)
    {
        if (pLO->isVisible())
        {
            // multiple use of minDim => calculate just one time
            shared_ptr<structDim>   pDim = make_shared<structDim> (pLO, pLO->minDim());

            allItems.push_back(pDim);

            if (pLO->isHoriExpandable())
            {
                expandItems.push_back(pDim);
            }
            else
            {
                fixedItems.push_back(pDim);
            }
        }
    }

    // sort the expand list to the max size
    std::sort(expandItems.begin(), expandItems.end(), [] (const shared_ptr<structDim> &p1,
                                                          const shared_ptr<structDim> &p2)
              { return p1->pLO->maxDim().w() < p2->pLO->maxDim().w(); });


    // calculate the expandable childs
    // this is iterative, because the the remaining space per item
    // can be bigger than an items max-size, which changes the remaining space
    // per item for the other items
    expandCount = expandItems.size();
    for (shared_ptr<structDim> &pDim : expandItems)
    {
        add = (restSpace > 0)?   restSpace / expandCount : 0;
        w = pDim->minDim.w() + add;

        // set the size
        pDim->s32Size = aUtil::min<s32>(w, pDim->pLO->maxDim().w());

        // adjust the rest size and decrement the number of expandable items
        // pDim->minDim.w is already in minSizeHori() => substract it here (doubled else)
        restSpace -= pDim->s32Size - pDim->minDim.w();
        expandCount--;
    }

    // fixed size -> set the minSize
    for (shared_ptr<structDim> &pDim : fixedItems)
    {
        pDim->s32Size = pDim->minDim.w();
    } // for

    // finally set the childs to their positions
    for (shared_ptr<structDim> &pDim : allItems)
    {
        x += pDim->pLO->distance().l();
        y = _r2dLayout.y() + (minDim.h() - pDim->pLO->distance().h() - pDim->minDim.h()) / 2 + pDim->pLO->distance().t();

        pDim->pLO->setGeometry(x, y, pDim->s32Size, pDim->minDim.h());

        x += pDim->s32Size + pDim->pLO->distance().r();
    }
} // aLayoutHoriVert::arangeChildsHori


/*******************************************************************************
* aLayoutHoriVert::arangeChildsVert
*******************************************************************************/
void aLayoutHoriVert::arangeChildsVert(aRect2D<s32> _r2dLayout)
{
    aDimension2D<s32>                   minDim      = minDimVert();
    s32                                 restSpace   = _r2dLayout.h() - minDim.h();
    s32                                 y           = _r2dLayout.y();

    s32                                 x;
    s32                                 h;
    s32                                 expandCount;
    s32                                 add;

    std::vector<shared_ptr<structDim>>  allItems;
    std::vector<shared_ptr<structDim>>  fixedItems;
    std::vector<shared_ptr<structDim>>  expandItems;

    // prepare the layout info
    for (aLayoutObj *pLO : m_lstChilds)
    {
        if (pLO->isVisible())
        {
            // multiple use of minDim => calculate just one time
            shared_ptr<structDim>   pDim = make_shared<structDim> (pLO, pLO->minDim());

            allItems.push_back(pDim);

            if (pLO->isVertExpandable())
            {
                expandItems.push_back(pDim);
            }
            else
            {
                fixedItems.push_back(pDim);
            }
        }
    }

    // sort the expand list to the max size
    std::sort(expandItems.begin(), expandItems.end(), [] (const shared_ptr<structDim> &p1,
                                                          const shared_ptr<structDim> &p2)
              {return p1->pLO->maxDim().h() < p2->pLO->maxDim().h(); });


    // calculate the expandable childs
    // this is iterative, because the the remaining space per item
    // can be bigger than an items max-size, which changes the remaining space
    // per item for the other items
    expandCount = expandItems.size();
    for (shared_ptr<structDim> &pDim : expandItems)
    {
        add = (restSpace > 0)?   restSpace / expandCount : 0;
        h = pDim->minDim.h() + add;

        // set the size
        pDim->s32Size = aUtil::min<s32>(h, pDim->pLO->maxDim().h());

        // adjust the rest size and decrement the number of expandable items
        // pDim->minDim.h is already in minSizeVert() => substract it here (doubled else)
        restSpace -= pDim->s32Size - pDim->minDim.h();
        expandCount--;
    }

    // fixed size -> set the minSize
    for (shared_ptr<structDim> &pDim : fixedItems)
    {
        pDim->s32Size = pDim->minDim.h();
    } // for


    // finally set the childs to their positions
    for (shared_ptr<structDim> &pDim : allItems)
    {
        x = _r2dLayout.x() + (minDim.w() - pDim->pLO->distance().w() - pDim->minDim.h()) / 2 + pDim->pLO->distance().l();
        y += pDim->pLO->distance().t();

        pDim->pLO->setGeometry(x, y, pDim->minDim.w(), pDim->s32Size);

        y += pDim->s32Size + pDim->pLO->distance().b();
    }
} // aLayoutHoriVert::arangeChildsVert


/*******************************************************************************
* aLayoutHoriVert::calculateMinDim
*******************************************************************************/
aDimension2D<s32> aLayoutHoriVert::calculateMinDim() const
{
    if (orientation() == enumOrientation::Hori)
    {
        return minDimHori();
    }
    else
    {
        return minDimVert();
    }
} // aLayoutHoriVert::calculateMinDim


/*******************************************************************************
* aLayoutHoriVert::arrangeChilds
*******************************************************************************/
void aLayoutHoriVert::arrangeChilds(aRect2D<s32> _r2dLayout)
{
    if (orientation() == enumOrientation::Hori)
    {
        return arangeChildsHori(_r2dLayout);
    }
    else
    {
        return arangeChildsVert(_r2dLayout);
    }
} // aLayoutHoriVert::arrangeChilds


} // namespace aWin
} // namespace aLib
