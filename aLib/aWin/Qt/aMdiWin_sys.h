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

#include "aSysWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiWin_sys
*******************************************************************************/
class aMdiWin_sys : public aSysWin<QMdiSubWindow>,
                    public aMdiWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiWin_sys(SysWinClass *_pParent = nullptr);
        ~aMdiWin_sys();

}; // class aMdiWin_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
