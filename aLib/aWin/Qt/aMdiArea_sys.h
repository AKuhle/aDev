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
#include <QMdiArea>

#include "aWin_def.h"

#include "aMdiArea_sysi.h"

#include "aSysWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiArea_sys
*******************************************************************************/
class aMdiArea_sys : public aSysWin<QMdiArea>,
                     public aMdiArea_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiArea_sys(SysWinClass *_pParent = nullptr);
        ~aMdiArea_sys();

}; // class aMdiArea_sys


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
