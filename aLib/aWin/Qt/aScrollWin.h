/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "QAbstractScrollArea"

#include "aWin_def.h"
#include "aScrollWinI.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin
*******************************************************************************/
class aScrollWin : public aBaseWin<QAbstractScrollArea>,
                   public aScrollWinI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aScrollWin(SysWin *_pParent = nullptr);
        ~aScrollWin();

    public:
        void                setCentralWin(SysWin *_pWin) override;
        SysWin*             centralWin() override;


        // policy for both scrollbars
        virtual void        setScrollBarPolicy(ScrollBarPolicy _Ppolicy) override; // for both scrollbars


        // policy for hori scrollbars
        void                setHoriScrollBarPolicy(ScrollBarPolicy _policy) override;


        // policy for vert scrollbars
        void                setVertScrollBarPolicy(ScrollBarPolicy _policy) override;

}; // class aScrollWin


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
