/*******************************************************************************
* \file BaseApp.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aScrollWin.h"

using namespace aLib::aWin;



/*******************************************************************************
* class EditScrollWin
*******************************************************************************/
class EditScrollWin : public aScrollWin
{
    public:
        EditScrollWin(SysWinClass *_pParent = nullptr);
        ~EditScrollWin();


    /*******************************************************************************
    * BaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                onCreate();

}; // class EditScrollWin
