/*******************************************************************************
* \file ctrlPanel.h
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

#include "ui_formCtrlPanel.h"

#include "aVector.h"

#include "aPlainWin.h"
#include "bank.h"
#include "fader.h"


using namespace aLib;
using namespace aLib::aWin;
using namespace aLib::aUtil;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewNavigator;
class Universe;


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class CtrlPanel
*******************************************************************************/
class CtrlPanel : public aPlainWin,
                  public aCtrlMgr
{
    private:
        Ui::FormCtrlPanel           *m_pUi              { nullptr };

        shared_ptr<Universe>        m_pUniverse;

        aVector<aPushButton *>      m_vBankBtn;
        aPushButton                 *m_pActiveBankBtn   { nullptr };

        aVector<Fader *>            m_vFader;

    public:
        CtrlPanel(SysWin *_pParent = nullptr);
        ~CtrlPanel();

        // universe member
        shared_ptr<Universe>    activeUniverse() const;

        // bank member
        void                    addBank();
        u32                     bankCount() const;
        shared_ptr<Bank>        bank(u32 _u32Idx) const;

        void                    addFixture();

        void                    updateGui();

    private:
        void                    updateBanks();
        void                    updateFixtures();
        void                    updateScenes();
        void                    updateFaders();

        void                    onFaderMoved(s32    _s32SliderIdx,
                                             s32    _s32Value);


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        void                    onRegisterCtrl() override;
        void                    onUpdateCtrl(aCtrlI *_pCtrl) override;

    protected:
        void                    onCtrlClicked(aCtrlI *_pCtrl) override;

        void                    onCtrlValueChanged(aCtrlI   *_pCtrl,
                                                   s32      _s32Value) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                    onCreateWin() override;

}; // class CtrlPanel
