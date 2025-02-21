/*******************************************************************************
* \file qDockWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qWin.h"

namespace qLib
{
    /*******************************************************************************
    * class qDockWin
    *******************************************************************************/
    class qDockWin : public qWin
    {
        DeclareTypeProperty(s32, s32, BorderSize, 0)

        private:
            s32     m_s32AllowedDockPos     { DOCK_POS_NONE };
            s32     m_s32DockPos            { DOCK_POS_NONE };

        public:
            qDockWin(qWin  *_pParent = nullptr);
            ~qDockWin();

            void                        SetAllowedDockPositions(s32 _dockPos);
            void                        SetDockPosition(s32 _dockPos);

            qWin*                       GetCenterWin() const;
            void                        SetCenterWin(qWin *_pWin);

        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool                OnCreate() override;

    }; // class qDockWin

} // namespace aLib
