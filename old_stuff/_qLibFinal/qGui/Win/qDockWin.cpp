/*******************************************************************************
* \file qDockWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qDockWin.h"
#include "qStyleBorderBase.h"
#include "qLayoutCenterWin.h"


namespace qLib
{
    /*******************************************************************************
    * qDockWin::qDockWin
    *******************************************************************************/
    qDockWin::qDockWin(qWin  *_pParent  /* = nullptr */)
    : qWin(_pParent)
    {
    } // qDockWin::qDockWin


    /*******************************************************************************
    * qDockWin::~qDockWin
    *******************************************************************************/
    qDockWin::~qDockWin()
    {
    } // qDockWin::~qDockWin


    /*******************************************************************************
    * qDockWin::SetAllowedDockPositions
    *******************************************************************************/
    void qDockWin::SetAllowedDockPositions(s32 _dockPos)
    {
        m_s32AllowedDockPos = _dockPos;
    } // qDockWin::SetAllowedDockPositions


    /*******************************************************************************
    * qDockWin::SetDockPosition
    *******************************************************************************/
    void qDockWin::SetDockPosition(s32 _dockPos)
    {
        // check if the position is allowed
        if (MU<s32>::AreBitsSet(m_s32AllowedDockPos, _dockPos) &&
            m_s32DockPos != _dockPos)
        {
            // set the new dock position
            m_s32DockPos = _dockPos;

            qLayoutBase *pLayout = GetLayout();

            switch (m_s32DockPos)
            {
                case DOCK_POS_L:
                    GetBorderEdges().Set(GetBorderSize(), 0, 0, 0);
                    if (pLayout != nullptr)
                    {
                        pLayout->SetOrientation(enumOrientation::Vert);
                    }
                    break;

                case DOCK_POS_R:
                    GetBorderEdges().Set(0, GetBorderSize(), 0, 0);
                    if (pLayout != nullptr)
                    {
                        pLayout->SetOrientation(enumOrientation::Vert);
                    }
                    break;

                case DOCK_POS_T:
                    GetBorderEdges().Set(0, 0, GetBorderSize(),  0);
                    if (pLayout != nullptr)
                    {
                        pLayout->SetOrientation(enumOrientation::Hori);
                    }
                    break;

                case DOCK_POS_B:
                    GetBorderEdges().Set(0, 0, 0, GetBorderSize());
                    if (pLayout != nullptr)
                    {
                        pLayout->SetOrientation(enumOrientation::Hori);
                    }
                    break;
            } // switch
        }

    } // qDockWin::SetDockPosition


    /*******************************************************************************
    * qDockWin::GetCenterWin
    *******************************************************************************/
    qWin* qDockWin::GetCenterWin() const
    {
        qLayoutCenterWin  *pLayout = dynamic_cast<qLayoutCenterWin *> (GetLayout());
        CHECK_PRE_CONDITION(pLayout != nullptr, nullptr);

        return pLayout->GetCenterWin();
    } // qDockWin::GetCenterWin


    /*******************************************************************************
    * qDockWin::SetCenterWin
    *******************************************************************************/
    void qDockWin::SetCenterWin(qWin *_pWin)
    {
        qLayoutCenterWin  *pLayout = dynamic_cast<qLayoutCenterWin *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        _pWin->SetParent(this);

        pLayout->SetCenterWin(_pWin);
    } // qDockWin::SetCenterWin

    /*******************************************************************************
    * qDockWin::OnCreate
    *******************************************************************************/
    bool qDockWin::OnCreate()
    {
        // create the layout
        unique_ptr<qLayoutCenterWin> pLayout = make_unique<qLayoutCenterWin> ();
        SetLayout(std::move(pLayout));

        return true;
    } // qDockWin::OnCreate


} // namespace qLib
