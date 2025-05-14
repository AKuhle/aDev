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
#include "aSharedPtrVector.h"
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
class Controller;
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
    using bankTuple = std::tuple<aPushButton *, shared_ptr<Bank>>;

    private:
        Ui::FormCtrlPanel               *m_pUi                  { nullptr };

        aSharedPtrVector<Controller>    m_vController;

        // banks
        aVector<bankTuple>              m_vBank;
        bankTuple*                      m_pActiveBank           { nullptr };

        // fixtures
        aVector<aPushButton *>          m_vFixtureBtn;
        aPushButton *                   m_pActiveFixtureBtn     { nullptr };
        shared_ptr<Fixture>             m_pActiveFixture;

        aVector<Fader *>                m_vFader;

    public:
        CtrlPanel(SysWin *_pParent = nullptr);
        ~CtrlPanel();

        shared_ptr<Controller>              controller(s32 _idx) const;

        // bank member
        void                                addBank(const aString &_sName);
        aPushButton*                        activeBankBtn()const ;
        aPushButton*                        bankBtn(s32 _idx) const;

        shared_ptr<Bank>                    activeBank() const;
        shared_ptr<Bank>                    bank(s32 _idx) const;


        // fixture member
        aPushButton*                        activeFixtureBtn()const ;
        aPushButton*                        fixtureBtn(s32 _idx) const;
        shared_ptr<Fixture>                 activeFixture() const;


        void                                updateGui();

    private:
        void                                createSetup();

        void                                addController(const aString &_sName,
                                                          const aString &_sIpAdr,
                                                          s32           _s32UniverseMax);


        void                                updateBanks();
        void                                updateFixtures();
        void                                updateScenes();
        void                                updateFaders();

        void                                onFaderMoved(s32    _s32SliderIdx,
                                                         s32    _s32Value);

        void                                onBankSeleted(s32 _s32BankIdx);
        void                                onFixtureSeleted(s32 _s32FixtureIdx);


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        void                                onRegisterCtrl() override;
        void                                onUpdateCtrl(aCtrlI *_pCtrl) override;

    protected:
        void                                onCtrlClicked(aCtrlI *_pCtrl) override;

        void                                onCtrlValueChanged(aCtrlI   *_pCtrl,
                                                               s32      _s32Value) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                                onCreateWin() override;

}; // class CtrlPanel
