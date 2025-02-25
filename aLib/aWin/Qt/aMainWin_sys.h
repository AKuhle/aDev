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
#include <QMainWindow>

#include "aWin_def.h"

#include "aMainWin_sysi.h"

#include "aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWin_sys
*******************************************************************************/
class aMainWin_sys : public aBaseWin<QMainWindow>,
                     private aMainWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin_sys(SysWinClass *_pParent = nullptr);
        virtual ~aMainWin_sys();


    /*******************************************************************************
    * aMainWin_sysi interface
    *******************************************************************************/
    protected:
        void            _setCentralWin(SysWinClass *_pWin) override;
        SysWinClass*    _centralWin() override;


}; // class aMainWin_sys


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
