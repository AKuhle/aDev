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
#include "aMdiChildI.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiChild
*******************************************************************************/
class aMdiChild : public aBaseWin<QMdiSubWindow>,
                  public aMdiChildI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiChild(SysWin *_pParent = nullptr);
        ~aMdiChild();


    /*******************************************************************************
    * aMdiChildI interface
    *******************************************************************************/
    protected:
        void            setCentralWin(SysWin *_pWin) override;
        SysWin*         centralWin() override;

}; // class aMdiChild


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
