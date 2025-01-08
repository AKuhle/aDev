/*******************************************************************************
* \file qLayoutHoriVert.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayoutHoriVert.h"
#include "qWin.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLayoutHoriVert::qLayoutHoriVert
    *******************************************************************************/
    qLayoutHoriVert::qLayoutHoriVert()
	{
    } // qLayoutHoriVert::qLayoutHoriVert


    /*******************************************************************************
    * qLayoutHoriVert::~qLayoutHoriVert
    *******************************************************************************/
    qLayoutHoriVert::~qLayoutHoriVert()
    {
    } // qLayoutHoriVert::~qLayoutHoriVert


    /*******************************************************************************
    * qLayoutHoriVert::AddChild
    *******************************************************************************/
    void qLayoutHoriVert::AddChild(qLayoutObj *_pChild)
    {
        m_lstChilds.push_back(_pChild);
    } // qLayoutHoriVert::AddChild


    /*******************************************************************************
    * qLayoutHoriVert::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qLayoutHoriVert::GetMinSize() const
    {
        if (GetOrientation() == enumOrientation::Hori)
        {
            return GetMinSizeHori();
        }
        else
        {
            return GetMinSizeVert();
        }
    } // qLayoutHoriVert::GetMinSize


    /*******************************************************************************
    * qLayoutHoriVert::GetMinSizeHori
    *******************************************************************************/
    qDimension2D<s32> qLayoutHoriVert::GetMinSizeHori() const
    {
        qDimension2D<s32>   minDim;

        // arrange the top childs
        for (qLayoutObj *pLO : m_lstChilds)
        {
            minDim.w += pLO->GetDistanceEdges().w() + pLO->GetMinSize().w;
            minDim.h = MU<s32>::Max(minDim.h, pLO->GetDistanceEdges().h() + pLO->GetMinSize().h);
        }

        return minDim;
    } // qLayoutHoriVert::GetMinSizeHori


    /*******************************************************************************
    * qLayoutHoriVert::GetMinSizeVert
    *******************************************************************************/
    qDimension2D<s32> qLayoutHoriVert::GetMinSizeVert() const
    {
        qDimension2D<s32>   minDim;

        // arrange the top childs
        for (qLayoutObj *pLO : m_lstChilds)
        {
            minDim.w = MU<s32>::Max(minDim.w, pLO->GetDistanceEdges().w() + pLO->GetMinSize().w);
            minDim.h += pLO->GetDistanceEdges().h() + pLO->GetMinSize().h;
        }

        return minDim;
    } // qLayoutHoriVert::GetMinSizeVert


    /*******************************************************************************
    * qLayoutHoriVert::ArangeChilds
    *******************************************************************************/
    void qLayoutHoriVert::ArangeChilds(const qRect2D<s32> &_parentRect)
    {
        if (GetOrientation() == enumOrientation::Hori)
        {
            return ArangeChildsHori(_parentRect);
        }
        else
        {
            return ArangeChildsVert(_parentRect);
        }
    } // qLayoutHoriVert::ArangeChilds


    /*******************************************************************************
    * qLayoutHoriVert::ArangeChildsHori
    *******************************************************************************/
    void qLayoutHoriVert::ArangeChildsHori(qRect2D<s32> _parentRect)
    {
        qDimension2D<s32>                   minDim      = GetMinSizeHori();
        s32                                 restSpace   = _parentRect.w - minDim.w;
        s32                                 x           = _parentRect.x;

        s32                                 y;
        s32                                 w;
        s32                                 itemSize;
        s32                                 expandCount;
        s32                                 add;

        std::vector<shared_ptr<structDim>>  allItems;
        std::vector<shared_ptr<structDim>>  fixedItems;
        std::vector<shared_ptr<structDim>>  expandItems;

        // prepare the layout info
        for (qLayoutObj *pLO : m_lstChilds)
        {
            // multiple use of minDim => calculate just one time
            shared_ptr<structDim>   pDim = make_shared<structDim> (pLO, pLO->GetMinSize());

            allItems.push_back(pDim);

            if (pLO->IsHoriExpandable())
            {
                expandItems.push_back(pDim);
            }
            else
            {
                fixedItems.push_back(pDim);
            }
        }

        // sort the expand list to the max size
        std::sort(expandItems.begin(), expandItems.end(), [] (const shared_ptr<structDim> &p1,
                                                              const shared_ptr<structDim> &p2)
                  {return p1->pLO->GetMaxSize().w < p2->pLO->GetMaxSize().w; });


        // calculate the expandable childs
        // this is iterative, because the the remaining space per item
        // can be bigger than an items max-size, which changes the remaining space
        // per item for the other items
        expandCount = expandItems.size();
        for (shared_ptr<structDim> &pDim : expandItems)
        {
            add = (restSpace > 0)?   restSpace / expandCount : 0;
            w = pDim->minDim.w + add;
            itemSize    = MU<s32>::Min(w, pDim->pLO->GetMaxSize().w);

            // set the size
            pDim->s32Size = itemSize;

            // adjust the rest size and decrement the number of expandable items
            restSpace -= itemSize - pDim->minDim.w;
            expandCount--;
        }

        // fixed size -> set the minSize
        for (shared_ptr<structDim> &pDim : fixedItems)
        {
            pDim->s32Size = pDim->minDim.w;
        } // for


        // finally set the childs to their positions
        for (shared_ptr<structDim> &pDim : allItems)
        {
            x += pDim->pLO->GetDistanceEdges().l;
            y = _parentRect.y + (minDim.h - pDim->minDim.h) / 2 + pDim->pLO->GetDistanceEdges().t;

            pDim->pLO->SetGeometry(x, y, pDim->s32Size, pDim->minDim.h);

            x += pDim->s32Size + pDim->pLO->GetDistanceEdges().r;
        }
    } // qLayoutHoriVert::ArangeChildsHori


    /*******************************************************************************
    * qLayoutHoriVert::ArangeChildsVert
    *******************************************************************************/
    void qLayoutHoriVert::ArangeChildsVert(qRect2D<s32> _parentRect)
    {
        qDimension2D<s32>                   minDim      = GetMinSizeVert();
        s32                                 restSpace   = _parentRect.h - minDim.h;
        s32                                 y           = _parentRect.y;

        s32                                 x;
        s32                                 h;
        s32                                 itemSize;
        s32                                 expandCount;
        s32                                 add;

        std::vector<shared_ptr<structDim>>  allItems;
        std::vector<shared_ptr<structDim>>  fixedItems;
        std::vector<shared_ptr<structDim>>  expandItems;

        // prepare the layout info
        for (qWin *pWin : m_lstChilds)
        {
            // multiple use of minDim => calculate just one time
            shared_ptr<structDim>   pDim = make_shared<structDim> (pWin, pWin->GetMinSize());

            allItems.push_back(pDim);

            if (pWin->IsVertExpandable())
            {
                expandItems.push_back(pDim);
            }
            else
            {
                fixedItems.push_back(pDim);
            }
        }

        // sort the expand list to the max size
        std::sort(expandItems.begin(), expandItems.end(), [] (const shared_ptr<structDim> &p1,
                                                              const shared_ptr<structDim> &p2)
                  {return p1->pWin->GetMaxSize().h < p2->pWin->GetMaxSize().h; });


        // calculate the expandable childs
        // this is iterative, because the the remaining space per item
        // can be bigger than an items max-size, which changes the remaining space
        // per item for the other items
        expandCount = expandItems.size();
        for (shared_ptr<structDim> &pDim : expandItems)
        {
            add = (restSpace > 0)?   restSpace / expandCount : 0;
            h = pDim->minDim.h + add;
            itemSize    = MU<s32>::Min(h, pDim->pWin->GetMaxSize().h);

            // set the size
            pDim->s32Size = itemSize;

            // adjust the rest size and decrement the number of expandable items
            restSpace -= itemSize - pDim->minDim.h;
            expandCount--;
        }

        // fixed size -> set the minSize
        for (shared_ptr<structDim> &pDim : fixedItems)
        {
            pDim->s32Size = pDim->minDim.h;
        } // for


        // finally set the childs to their positions
        for (shared_ptr<structDim> &pDim : allItems)
        {
            x = _parentRect.x + (minDim.w - pDim->minDim.w) / 2 + pDim->pWin->GetDistanceEdges().l;
            y += pDim->pWin->GetDistanceEdges().t;

            pDim->pWin->SetGeometry(x, y, pDim->minDim.w, pDim->s32Size);

            y += pDim->s32Size + pDim->pWin->GetDistanceEdges().b;
        }
    } // qLayoutHoriVert::ArangeChildsVert

} // namespace qLib
