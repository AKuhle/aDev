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
#include "aScrollWin_sysi.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin_sys
*******************************************************************************/
class aScrollWin_sys : public aBaseWin<QAbstractScrollArea>,
                       private aScrollWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aScrollWin_sys(SysWinClass *_pParent = nullptr);
        ~aScrollWin_sys();

        void                setCentralWin(SysWinClass *_pWin) override;
        SysWinClass*        centralWin() override;

        // policy
        void                setHoriScrollBarPolicy(ScrollBarPolicy _policy) override;
        void                setVertScrollBarPolicy(ScrollBarPolicy _policy) override;

}; // class aScrollWin_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
