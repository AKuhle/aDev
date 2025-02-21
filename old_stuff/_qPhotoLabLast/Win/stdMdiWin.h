/*******************************************************************************
* \file StdMdiWin.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "qLib.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class StdScrollWin;
class ViewStd;


/*******************************************************************************
* class StdMdiWin
*******************************************************************************/
class StdMdiWin : public qMdiWin
{
    public:
        StdMdiWin(SysWin_t  *_pParent = nullptr);
        ~StdMdiWin();

        void                SetView(ViewStd *_pView);
        ViewStd*            StdView() const;

    private:
        StdScrollWin*       ScrollWin() const;

    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        OnCreate() override;
}; // class StdMdiWin
