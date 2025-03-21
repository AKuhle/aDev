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
    * mdi win management
    *******************************************************************************/
    protected:
        aMdiArea*           mdiArea();
        void                addMdiChild(aMdiChild *_pMdiChild);


    /*******************************************************************************
    * aSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        onSysCreate();

}; // class aMainWinMdi


} // namespace aWin
} // namespace aLib
