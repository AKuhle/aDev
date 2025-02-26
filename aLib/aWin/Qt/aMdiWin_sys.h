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

#include "aMdiWin_sysi.h"

#include "aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiWin_sys
*******************************************************************************/
class aMdiWin_sys : public aBaseWin<QMdiSubWindow>,
                    private aMdiWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiWin_sys(SysWinClass *_pParent = nullptr);
        ~aMdiWin_sys();

        virtual void            _setCentralWin(SysWinClass   *_pWin) override;
        virtual SysWinClass*    _centralWin() const override;
}; // class aMdiWin_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
