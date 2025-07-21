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
#include "aWin_def.h"
#include "aProgressCb.h"
#include "aStatusBar.h"

using namespace aLib::aWin;


/*******************************************************************************
* class StatusBar
*******************************************************************************/
class StatusBar : public aStatusBar,
                  public aProgressCb
{
    private:
        aProgressBar    *m_pProgressBar     { nullptr };

    public:
        StatusBar(SysWin *pParent = nullptr);
        ~StatusBar();


    /*******************************************************************************
    * aProgressCb interface
    *******************************************************************************/
    public:
        void                onOpenProgressDisplay() override;
        void                onCloseProgressDisplay() override;
        void                onUpdateProgressDisplay(const aString &_sInfoText) override;
        void                onUpdateProgressDisplay(u16 _u16Progress_pml) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool        onCreateWin() override;

}; // class StatusBar
