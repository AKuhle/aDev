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
#include "aMap.h"
#include "aString.h"
#include "aColor.h"

#include "aPlainWin.h"


using namespace aLib;
using namespace aLib::aWin;
using namespace aLib::aUtil;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewNavigator;
class Controller;
class Universe;
class Bank;
class Fixture;
class Scene;
class Channel;
class Fader;


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
    using fixtureTuple = std::tuple<aPushButton *, shared_ptr<Fixture>>;
    using sceneTuple = std::tuple<aPushButton *, shared_ptr<Scene>>;
    using faderTuple = std::tuple<ScribbleStrip*, Fader *, aLabel *, shared_ptr<Channel>>;

    private:
        Ui::FormCtrlPanel               *m_pUi                  { nullptr };
        aColor                          m_colButtonBg;

        // controller
        aSharedPtrVector<Controller>    m_vController;

        // banks (10)
        aSharedPtrVector<Bank>          m_vBank;
        aVector<bankTuple>              m_vBankCtrl;
        bankTuple*                      m_pActiveBank           { nullptr };

        // fixtures (10)
        aSharedPtrVector<Fixture>       m_vFixture;
        aVector<fixtureTuple>           m_vFixtureCtrl;
        fixtureTuple*                   m_pActiveFixture        { nullptr };

        // scenes (30)
        aVector<sceneTuple>             m_vScene;

        // faders (24)
        aVector<faderTuple>             m_vFader;

        // master fader
        faderTuple                      m_masterFader;
        dbl                             m_dMasterBrightness     { 1.0 };
        aSharedPtrVector<Channel>       m_vMasterChannel;


    public:
        CtrlPanel(SysWin *_pParent = nullptr);
        ~CtrlPanel();


    private:
        void                            createSetup();


        // controller members
        shared_ptr<Controller>          createController(const aString  &_sName,
                                                         const aString  &_sIpAdr,
                                                         s32            _s32UniverseMax);


        // bank members
        shared_ptr<Bank>                createBank(const aString &_sName);

        void                            assignBank(shared_ptr<Bank> _pBank,
                                                   s32              _s32BankBtnIdx);

        void                            updateBankCtrls();

        void                            onBankSeleted(s32 _s32BankBtnIdx);


        // fixture mambers
        shared_ptr<Fixture>             createFixture(const aString             &_sName,
                                                      shared_ptr<Controller>    _pConroller,
                                                      s32                       _s32UniverseId,
                                                      s32                       _s32ChannelOs);

        void                            assignFixture(shared_ptr<Fixture>   _pFixture,
                                                      shared_ptr<Bank>      _pBank,
                                                      s32                   _s32FixtureBtnIdx);

        void                            updateFixtureCtrls();


        // scene mambers
        void                            updateSceneCtrls();


        // fader mambers
        void                            updateFaderCtrls();


    public:
        // fixture member
        aPushButton*                        activeFixtureBtn()const ;
        aPushButton*                        fixtureBtn(s32 _idx) const;
        shared_ptr<Fixture>                 activeFixture() const;

        void                                updateGui();

        void                                resetAll();


    private:
        void                                updateScenes();
        void                                updateFaders();

        void                                onFaderMoved(s32    s32FaderIdx,
                                                         s32    _s32Value);

        void                                onMasterFaderMoved(s32    _s32Value);

        void                                onFixtureSeleted(s32 _s32FixtureIdx);

        void                                onSceneClicked(const sceneTuple &_sceneTuple);

        void                                updateDmxValue(shared_ptr<Channel>  _pChannel,
                                                           bool                 _bSend);

        void                                updateBlackoutButton();

        void                                onBlackoutClicked();

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
