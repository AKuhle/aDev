/*******************************************************************************
* \file qLayoutMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayoutMainWin.h"
#include "qTitleBar.h"
#include "qStatusBar.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLayoutMainWin::qLayoutMainWin
    *******************************************************************************/
    qLayoutMainWin::qLayoutMainWin()
	{
    } // qLayoutMainWin::qLayoutMainWin


    /*******************************************************************************
    * qLayoutMainWin::~qLayoutMainWin
    *******************************************************************************/
    qLayoutMainWin::~qLayoutMainWin()
    {
    } // qLayoutMainWin::~qLayoutMainWin


    /*******************************************************************************
    * qLayoutMainWin::AddLeftChild
    *******************************************************************************/
    void qLayoutMainWin::AddLeftChild(qWin *_pChild)
    {
        m_lstLeftChilds.push_back(_pChild);
    } // qLayoutMainWin::AddLeftChild


    /*******************************************************************************
    * qLayoutMainWin::AddRightChild
    *******************************************************************************/
    void qLayoutMainWin::AddRightChild(qWin *_pChild)
    {
        m_lstRightChilds.push_back(_pChild);
    } // qLayoutMainWin::AddRightChild


    /*******************************************************************************
    * qLayoutMainWin::AddTopChild
    *******************************************************************************/
    void qLayoutMainWin::AddTopChild(qWin *_pChild)
    {
        m_lstTopChilds.push_back(_pChild);
    } // qLayoutMainWin::AddTopChild


    /*******************************************************************************
    * qLayoutMainWin::AddBottomChild
    *******************************************************************************/
    void qLayoutMainWin::AddBottomChild(qWin *_pChild)
    {
        m_lstBottomChilds.push_back(_pChild);
    } // qLayoutMainWin::AddBottomChild


    /*******************************************************************************
    * qLayoutMainWin::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qLayoutMainWin::GetMinSize() const
    {
        qDimension2D<s32>   minDim = qLayoutCenterWin::GetMinSize();

        // add the title bar
        if (GetTitleBar() != nullptr)
        {
            minDim.w = MU<s32>::Max(minDim.w, GetTitleBar()->GetMinSize().w);
            minDim.h += GetTitleBar()->GetMinSize().h;
        }

        // add the status bar
        if (GetStatusBar() != nullptr)
        {
            minDim.w = MU<s32>::Max(minDim.w, GetStatusBar()->GetMinSize().w);
            minDim.h += GetStatusBar()->GetMinSize().h;
        }

        // add the top childs
        for (qWin *pWin : m_lstTopChilds)
        {
            minDim.w = MU<s32>::Max(minDim.w, pWin->GetMinSize().w);
            minDim.h += pWin->GetMinSize().h;
        }

        // add the right childs
        for (qWin *pWin : m_lstRightChilds)
        {
            minDim.w += pWin->GetMinSize().w;
            minDim.h = MU<s32>::Max(minDim.h, pWin->GetMinSize().h);
        }

        return minDim;
    } // qLayoutMainWin::GetMinSize


    /*******************************************************************************
    * qLayoutMainWin::ArangeChilds
    *******************************************************************************/
    void qLayoutMainWin::ArangeChilds(const qRect2D<s32> &_parentRect)
    {
        qRect2D<s32>    centerRect = _parentRect;

        if (GetTitleBar() != nullptr)
        {
            s32 h = GetTitleBar()->GetMinSize().h;

            GetTitleBar()->SetGeometry(centerRect.l(), centerRect.t(),
                                     centerRect.w, h);

            centerRect.y += h;
            centerRect.h -= h;
        }

        if (GetStatusBar() != nullptr)
        {
            s32 h = GetStatusBar()->GetMinSize().h;

            GetStatusBar()->SetGeometry(centerRect.l(), centerRect.b() - h,
                                     centerRect.w, h);

            centerRect.h -= h;
        }

        // arrange the top childs
        for (qWin *pWin : m_lstTopChilds)
        {
            s32 h = pWin->GetMinSize().h;

            pWin->SetGeometry(centerRect.l(), centerRect.t(),
                              centerRect.w, h);

            centerRect.y += h;
            centerRect.h -= h;
        }

        // arrange the right childs
        for (qWin *pWin : m_lstRightChilds)
        {
            s32 w = pWin->GetMinSize().w;

            pWin->SetGeometry(centerRect.r() - w, centerRect.t(),
                              w, centerRect.h);

            centerRect.w -= w;
        }

        // finally set the size of the central win
        qLayoutCenterWin::ArangeChilds(centerRect);
    } // qLayoutMainWin::ArangeChilds

} // namespace qLib
