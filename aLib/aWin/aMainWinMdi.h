/*******************************************************************************
* \file qWin.h
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
#include "aWin_def.h"
#include "aMainWinMdi_sysi.h"
#include "aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWinMdi
*******************************************************************************/
class aMainWinMdi : public aMainWin
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWinMdi(SysWinClass *_pParent = nullptr);
        ~aMainWinMdi();


    /*******************************************************************************
    * aSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        onSysCreate();

}; // class aMainWinMdi


} // namespace aWin
} // namespace aLib
