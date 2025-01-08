/*******************************************************************************
* \file qLayoutScrollWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayoutScrollWin.h"
#include "qScrollBar.h"


using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLayoutScrollWin::qLayoutScrollWin
    *******************************************************************************/
    qLayoutScrollWin::qLayoutScrollWin()
	{
    } // qLayoutScrollWin::qLayoutScrollWin


    /*******************************************************************************
    * qLayoutScrollWin::~qLayoutScrollWin
    *******************************************************************************/
    qLayoutScrollWin::~qLayoutScrollWin()
    {
    } // qLayoutScrollWin::~qLayoutScrollWin


    /*******************************************************************************
    * qLayoutScrollWin::GetItemSize
    *******************************************************************************/
    s32 qLayoutScrollWin::GetItemSize() const
    {
        bool                bH          = (m_pHoriSb->IsVisible());
        bool                bV          = (m_pVertSb->IsVisible());
        bool                bC          = (m_pCornerWin != nullptr && m_pCornerWin->IsVisible());

        s32                 s32Size     = 0;

        // the size of the element is beeing determined by the biggest item
        s32Size = MU<s32>::Max((bH)?    m_pHoriSb->GetMinSize().h : 0,
                               (bV)?    m_pVertSb->GetMinSize().w : 0,
                               (bC)?    m_pCornerWin->GetMinSize().w : 0,
                               (bC)?    m_pCornerWin->GetMinSize().h : 0);

        return s32Size;
    } // qLayoutScrollWin::GetItemSize


    /*******************************************************************************
    * qLayoutScrollWin::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qLayoutScrollWin::GetMinSize() const
    {
        bool                bH      = (m_pHoriSb->IsVisible());
        bool                bV      = (m_pVertSb->IsVisible());
        bool                bC      = (m_pCornerWin != nullptr && m_pCornerWin->IsVisible());
        s32                 s32Size = GetItemSize();

        return qDimension2D<s32> (((bH)?   m_pHoriSb->GetMinSize().w : 0) + ((bV || bC)?   s32Size : 0),
                                  ((bV)?   m_pVertSb->GetMinSize().h : 0) + ((bH || bC)?   s32Size : 0));
    } // qLayoutScrollWin::GetMinSize


    /*******************************************************************************
    * qLayoutScrollWin::ArangeChilds
    *******************************************************************************/
    void qLayoutScrollWin::ArangeChilds(const qRect2D<s32> &_parentRect)
    {
        qRect2D<s32>    centerRect  = _parentRect;

        bool            bH      = (m_pHoriSb->IsVisible());
        bool            bV      = (m_pVertSb->IsVisible());
        bool            bC      = (m_pCornerWin != nullptr && m_pCornerWin->IsVisible());
        s32             s32Size = GetItemSize();

        // Hori Sb
        if (bH)
        {
            m_pHoriSb->SetGeometry(_parentRect.l(),
                                   _parentRect.b() - s32Size,
                                   _parentRect.w - ((bV || bC)?   s32Size : 0),
                                   s32Size);
        }

        // Vert Sb
        if (bV)
        {
            m_pVertSb->SetGeometry(_parentRect.r() - s32Size,
                                   _parentRect.t(),
                                   s32Size,
                                   _parentRect.h - ((bH || bC)?   s32Size : 0));
        }

        // corner win
        if (bC)
        {
            m_pCornerWin->SetGeometry(_parentRect.r() - s32Size,
                                      _parentRect.b() - s32Size,
                                      s32Size,
                                      s32Size);
        }

        // calculate the central win area
        if (bH || bC)
        {
            centerRect.h -= s32Size;
        }
        if (bV || bC)
        {
            centerRect.w -= s32Size;
        }

        // finally set the size of the central win
        qLayoutCenterWin::ArangeChilds(centerRect);
    } // qLayoutScrollWin::ArangeChilds

} // namespace qLib
