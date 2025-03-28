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
#include "QMdiSubWindow"

#include "aWin_def.h"
#include "aMdiChild_sysi.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiChild_sys
*******************************************************************************/
class aMdiChild_sys : public aBaseWin<QMdiSubWindow>,
                      private aMdiChild_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiChild_sys(SysWinClass *_pParent = nullptr);
        ~aMdiChild_sys();


    /*******************************************************************************
    * aMdiArea_sysi interface
    *******************************************************************************/
    protected:
        void            setCentralWin(SysWinClass *_pWin) override;
        SysWinClass*    centralWin() override;

}; // class aMdiChild_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
