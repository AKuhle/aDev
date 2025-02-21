/*******************************************************************************
* \file StatusBar.h
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
#include "aLib_def.h"
#include "aStatusBar.h"
#include "aProgressCtrl.h"
#include "aProgress_cb.h"
#include "aLabel.h"

using namespace aLib;
using namespace aLib::aWin;


/*******************************************************************************
* class StatusBar
*******************************************************************************/
class StatusBar : public aStatusBar,
                  public aProgressCb
{
    private:
        aProgressCtrl   *m_pProgressCtrl        { nullptr };
        aLabel          *m_pCoordinatesLabel    { nullptr };

    public:
        StatusBar(aBaseWin *_pParent   = nullptr);
        ~StatusBar();

        void                        clearCoordinates() const;
        void                        updateCoordinates(s32   _x,
                                                      s32   _y) const;


    /*******************************************************************************
    * qCtrlMgr interface
    *******************************************************************************/
    protected:
        virtual void                onRegisterCtrl() override;
        virtual void                onUpdateCtrl(aCtrl *_pCtrl) override;
        virtual void                onCtrlClicked(aCtrl *_pCtrl) override;


    /*******************************************************************************
    * aProgressCb interface
    *******************************************************************************/
    public:
        void                        onOpenProgressDisplay() override;
        void                        onCloseProgressDisplay() override;
        void                        onUpdateProgressDisplay(const aString &_sInfoText) override;
        void                        onUpdateProgressDisplay(u16 _u16Progress_pml) override;

}; // class StatusBar
