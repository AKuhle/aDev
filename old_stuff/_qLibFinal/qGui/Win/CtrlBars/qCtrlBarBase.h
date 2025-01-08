/*******************************************************************************
* \file qCtrlBarBase.h
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
#include "qCtrlMgr.h"


namespace qLib
{
    /*******************************************************************************
    * class qCtrlBarBase
    *******************************************************************************/
    class qCtrlBarBase : public qWin,
                         public qCtrlMgr
    {
        DeclareTypeProperty(enumOrientation, e, Orientation, enumOrientation::Hori)

        public:
            qCtrlBarBase(qWin  *_pParent = nullptr);
            ~qCtrlBarBase();

    }; // class qCtrlBarBase

} // namespace aLib
