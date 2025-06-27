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

#include "aLib_def.h"
#include "aWin_def.h"
#include "aCtrl_def.h"
#include "aUtil_def.h"

#include "aPlainWin.h"

#include "aVector.h"
#include "aMap.h"
#include "aSharedPtrVector.h"

#include "ui_formCtrlPanel.h"

using namespace aLib;
using namespace aLib::aUtil;
using namespace aLib::aWin;


/*******************************************************************************
* forwards
*******************************************************************************/
class Bank;
class Fixture;
class Scene;
class Controller;
class Channel;
class Chase;


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class CtrlPanel
*******************************************************************************/
class CtrlPanel : public aPlainWin,
                  public aCtrlMgr
{
    using BankTuple     = std::tuple<aPushButton *, shared_ptr<Bank>>;
    using FixtureTuple  = std::tuple<aPushButton *, shared_ptr<Fixture>>;
    using SceneTuple    = std::tuple<aPushButton *, shared_ptr<Scene>>;
    using ChaseTuple    = std::tuple<aPushButton *, shared_ptr<Chase>>;

    private:
        using controllerIoInfo = std::tuple<aString, s32>;                  // controllerIoInfo: name, maxUnivers
        using universeIoInfo = std::tuple<s32>;                             // universeIoInfo: id
        using fixtureIoInfo = std::tuple<aString, s32, s32>;                // fixtureIoInfo: controll, id, os
        using sceneIoInfo = std::tuple<aString, aString, s32, bool>;        // sceneIoInfo: fixture, icon, channelNr, brightness
        using bankIoInfo = std::tuple<s32>;                                 // bankIoInfo: bankBtnIdx
        using bankFixtureIoInfo = std::tuple<aString, aString, s32>;        // bankFixtureIoInfo: bankName, fixtureName, fixtureBtnIdx
        using sceneBtnIoInfo = std::tuple<aString, s32>;                    // sceneBtnIoInfo: sceneName, sceneBtnIdx
        using sceneChannelIoInfo = std::tuple<aString, aString, s32, u8>;   // sceneBtnIoInfo: sceneName, fixtureName, channelNr, value

        Ui::FormCtrlPanel               *m_pUi                  { nullptr };

        // controller
        aSharedPtrVector<Controller>    m_vController;

        // banks (10)r
        aSharedPtrVector<Bank>          m_vBanks;
        aVector<BankTuple>              m_vBankTuples;
        shared_ptr<Bank>                m_pActiveBank;

        // fixtures (10)
        aSharedPtrVector<Fixture>       m_vFixtures;
        aVector<FixtureTuple>           m_vFixtureTuples;
        shared_ptr<Fixture>             m_pActiveFixture;

        // scenes (30)
        aVector<SceneTuple>             m_vSceneTuples;
        aColor                          m_colButtonBg;

        // chases (10)
        aVector<ChaseTuple>             m_vChaseTuples;

        // faders (24)
        aVector<Fader *>                m_vFaders;

        // master fader
        dbl                             m_dMasterBrightness     { 1.0 };
        shared_ptr<Channel>             m_pMasterChannel;

        // io-member
        aMap<aString, controllerIoInfo> m_mapControllerIoInfo;      // controllerName -> bankIoInfo
        aMap<aString, universeIoInfo>   m_mapUniverseIoInfo;
        aMap<aString, fixtureIoInfo>    m_mapFixtureIoInfo;         // fixtureName -> fixtureIoInfo
        aVector<sceneIoInfo>            m_vSceneIoInfo;
        aMap<aString, bankIoInfo>       m_mapBankIoInfo;              // bankName -> bankIoInfo
        aVector<bankFixtureIoInfo>      m_vBankFixtureIoInfo;
        aVector<sceneBtnIoInfo>         m_vSceneBtnIoInfo;
        aVector<sceneChannelIoInfo>     m_vSceneChannelIoInfo;

    public:
        CtrlPanel(SysWin *_pParent = nullptr);
        ~CtrlPanel();

        void                            resetAllChannels();
        dbl                             getMasterBrightness() const     { return m_dMasterBrightness; }

        shared_ptr<Scene>               findScene(const aString  &_sName);
        void                            loadScene(s32 _s32SceneBtnIdx);


    private:
        void                            createSetup();

        shared_ptr<Controller>          createController(const aString  &_sName,
                                                         const aString  &_sIpAdr,
                                                         s32            _s32UniverseMax);

        // bank member
        shared_ptr<Bank>                createBank(const aString    &_sName);

        void                            assignBank(shared_ptr<Bank>      _pBank,
                                                   s32                   _s32BankIdx);


        // fixtur member
        shared_ptr<Fixture>             createFixture(const aString             &_sName,
                                                      shared_ptr<Controller>    _pConroller,
                                                      s32                       _s32UniverseId,
                                                      s32                       _s32ChannelOs);

        void                            assignFixture(shared_ptr<Bank>      _pBank,
                                                      shared_ptr<Fixture>   _pFixture,
                                                      s32                   _s32FixtureIdx);

        shared_ptr<Controller>          findController(const aString  &_sName);
        shared_ptr<Fixture>             findFixture(const aString  &_sName);
        shared_ptr<Bank>                findBank(const aString  &_sName);

        void                            updateBrightnessChannels() const;


    /*******************************************************************************
    * CtrlPanel - io
    *******************************************************************************/
    public:
        void                            writeConfiguration(const aPath &_path) const;
        void                            readConfiguration(const aPath &_path);

    private:
        void                            resetConfiguration();
        void                            setConfiguration(const aMap<aString, controllerIoInfo>  &_mapControllerIoInfo,
                                                         const aMap<aString, universeIoInfo>    &_mapUniverseIoInfo,
                                                         const aMap<aString, fixtureIoInfo>     &_mapFixtureIoInfo,
                                                         const aVector<sceneIoInfo>             &_vSceneIoInfo,
                                                         const aMap<aString, bankIoInfo>        &_mapBankIoInfo,
                                                         const aVector<bankFixtureIoInfo>       &_vBankFixtureIoInfo,
                                                         const aVector<sceneBtnIoInfo>          &_vSceneBtnIoInfo,
                                                         const aVector<sceneChannelIoInfo>      &_vSceneChannelIoInfo);

        void                            saveScene(s32       _s32SceneBtnIdx,
                                                  aString   _sSceneName);

        void                            JsonValCallback(const aVector<aString> &_vecKeys,
                                                        const aJsonValue       &_value);

        void                            JsonObjCallback(const aVector<aString> &_vecKeys,
                                                        const aJsonObj         &_obj);


    /*******************************************************************************
    * CtrlPanel - chase
    *******************************************************************************/
    private:
        void                            saveChase(s32       _s32ChaseBtnIdx,
                                                  aString   _sChaseName);


    /*******************************************************************************
    * update gui
    *******************************************************************************/
    public:
        void                            updateGui();

    private:
        void                            initBanks();
        void                            initFixtures();
        void                            initScenes();
        void                            initChases();
        void                            initFaders();

        void                            updateBanks();
        void                            updateFixtures();
        void                            updateScenes();
        void                            updateChases();
        void                            updateFaders();
        void                            updateBlackoutButton();


    /*******************************************************************************
    * user action
    *******************************************************************************/
    private:
        void                            onBankSelected(s32 _s32BankBtnIdx);

        void                            onFixtureSelected(s32 _s32FixtureBtnIdx);

        void                            onSceneSelected(s32 _s32SceneBtnIdx);

        void                            onChaseSelected(s32 _s32ChaseBtnIdx);

        void                            onFaderMoved(s32    s32FaderIdx,
                                                     s32    _s32Value);

        void                            onMasterFaderMoved(s32    _s32Value);

        void                            onBlackoutClicked();


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    protected:
        void                            onRegisterCtrl() override;
        void                            onUpdateCtrl(aCtrlI *_pCtrl) override;


    protected:
        void                            onCtrlClicked(aCtrlI *_pCtrl) override;

        void                            onCtrlValueChanged(aCtrlI   *_pCtrl,
                                                           s32      _s32Value) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                            onCreateWin() override;

}; // class CtrlPanel
