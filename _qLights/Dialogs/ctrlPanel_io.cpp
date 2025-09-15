/*******************************************************************************
* \file CtrlPanel.cpp
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
#include "aJsonFile.h"
#include "aJsonObj.h"

#include "qLights_defs.h"
#include "ctrlPanel.h"
#include "fixture.h"
#include "scene.h"
#include "channel.h"
#include "controller.h"
#include "bank.h"
#include "chase.h"


/*******************************************************************************
* CtrlPanel::loadScene
*******************************************************************************/
void CtrlPanel::loadScene(s32 _s32SceneBtnIdx)
{
    auto    pScene      = std::get<1> (m_vSceneTuples.at(_s32SceneBtnIdx));
    CHECK_PRE_CONDITION_VOID(pScene);

    const aVector<channelValueTuple>    &vChannels = pScene->channelValues();

    // set all channel values
    for (auto &c : vChannels)
    {
        std::get<0> (c)->setValue( std::get<1> (c), false);
    }

    // send all universes
    for (auto &pCtrl : m_vController)
    {
        pCtrl->sendAllUniverses();
    }
} // CtrlPanel::loadScene


/*******************************************************************************
* CtrlPanel::saveScene
*******************************************************************************/
void CtrlPanel::saveScene(s32       _s32SceneBtnIdx,
                          aString   _sSceneName)
{
    aVector<shared_ptr<Channel>>  vChannel;

    auto    pSceneBtn   = std::get<0> (m_vSceneTuples.at(_s32SceneBtnIdx));
    auto    &pScene     = std::get<1> (m_vSceneTuples.at(_s32SceneBtnIdx));

    // set the scene name
    pSceneBtn->setText(_sSceneName);

    // collect all channels
    for (auto pFixture : m_vFixtures)
    {
        pFixture->collectChannels(vChannel);
    }

    // create the scene
    pScene = make_shared<Scene> (_sSceneName);

    // add channels to scene
    for (auto pChannel : vChannel)
    {
        pScene->addChannel(pChannel, pChannel->value());
    }
} // CtrlPanel::saveScene


/*******************************************************************************
* CtrlPanel::setChase
*******************************************************************************/
void CtrlPanel::setChase(s32                _s32ChaseBtnIdx,
                         shared_ptr<Chase>  _pChase)
{
    auto        pChaseBtn   = std::get<0> (m_vChaseTuples.at(_s32ChaseBtnIdx));
    auto        &pChase     = std::get<1> (m_vChaseTuples.at(_s32ChaseBtnIdx));

    pChaseBtn->setText(_pChase->name());
    pChase = _pChase;

} // CtrlPanel::setChase


/*******************************************************************************
* CtrlPanel::writeConfiguration
*******************************************************************************/
void CtrlPanel::writeConfiguration(const aPath &_path) const
{
    aJsonFile   jf(_path);

    // add controller and universes
    for (const shared_ptr<Controller> &pController : m_vController)
    {
        pController->add2Configuration(jf);
    }

    // add fixtures
    for (const shared_ptr<Fixture> &pFix : m_vFixtures)
    {
        pFix->add2Configuration(jf);
    }

    // add banks
    for (s32 idx = 0; idx < BANK_MAX; idx++)
    {
        const BankTuple     &t      = m_vBankTuples.at(idx);
        shared_ptr<Bank>    pBank   = std::get<1> (t);

        if (pBank)
        {
            pBank->add2Configuration(jf, idx);
        }
   }

    // add scenes
    for (s32 idx = 0; idx < SCENE_MAX; idx++)
    {
        const SceneTuple    &st     = m_vSceneTuples.at(idx);
        shared_ptr<Scene>   pScene  = std::get<1> (st);

        if (pScene)
        {
            pScene->add2Configuration(jf, idx);
        }
    }

    // write the json file
    jf.write2File();
} // CtrlPanel::writeConfiguration


/*******************************************************************************
* CtrlPanel::readConfiguration
*******************************************************************************/
void CtrlPanel::readConfiguration(const aPath &_path)
{
    aJsonFile   jFile(_path);

    // delete previous configuration
    resetConfiguration();

    // read all entries
    jFile.readAllValues([this](const aVector<aString> &_vecKeys, const aJsonValue &_value) { this->JsonValCallback(_vecKeys, _value);},
                        [this](const aVector<aString> &_vecKeys, const aJsonObj &_obj) { this->JsonObjCallback(_vecKeys, _obj);}
    );

    // set the configuration
    setConfiguration(m_mapControllerIoInfo,
                     m_mapUniverseIoInfo,
                     m_mapFixtureIoInfo,
                     m_vSceneIoInfo,
                     m_mapBankIoInfo,
                     m_vBankFixtureIoInfo,
                     m_vSceneBtnIoInfo,
                     m_vSceneChannelIoInfo);

     initBanks();
     initFixtures();
     initScenes();
     initFaders();
} // CtrlPanel::readConfiguration


/*******************************************************************************
* CtrlPanel::resetConfiguration
*******************************************************************************/
void CtrlPanel::resetConfiguration()
{
    // delete all io-infos
    m_mapControllerIoInfo.clear();
    m_mapUniverseIoInfo.clear();
    m_mapFixtureIoInfo.clear();
    m_vSceneIoInfo.clear();
    m_mapBankIoInfo.clear();
    m_vBankFixtureIoInfo.clear();
    m_vSceneBtnIoInfo.clear();

    // delete controllers
    m_vController.clear();

    // delete banks
    m_vBanks.clear();
    for (BankTuple &b : m_vBankTuples)
    {
        std::get<1> (b) = nullptr;
    }
    m_pActiveBank = nullptr;

    // delete fixtures
    m_vFixtures.clear();
    for (FixtureTuple &f : m_vFixtureTuples)
    {
        std::get<1> (f) = nullptr;
    }
    m_pActiveBank = nullptr;

    // delete scenes
    for (SceneTuple &s : m_vSceneTuples)
    {
        std::get<1> (s) = nullptr;
    }
} // CtrlPanel::resetConfiguration


/*******************************************************************************
* CtrlPanel::setConfiguration
*******************************************************************************/
void CtrlPanel::setConfiguration(const aMap<aString, controllerIoInfo>  &_mapControllerIoInfo,
                                 const aMap<aString, universeIoInfo>    &_mapUniverseIoInfo,
                                 const aMap<aString, fixtureIoInfo>     &_mapFixtureIoInfo,
                                 const aVector<sceneIoInfo>             &_vSceneIoInfo,
                                 const aMap<aString, bankIoInfo>        &_mapBankIoInfo,
                                 const aVector<bankFixtureIoInfo>       &_vBankFixtureIoInfo,
                                 const aVector<sceneBtnIoInfo>          &_vSceneBtnIoInfo,
                                 const aVector<sceneChannelIoInfo>      &_vSceneChannelIoInfo)
{
    // create the controller
    for (const auto &me : _mapControllerIoInfo)
    {
        createController(me.first, std::get<0> (me.second), std::get<1> (me.second));
    }

    // create the universes
    for (const auto &me : _mapUniverseIoInfo)
    {
        shared_ptr<Controller>  pCtrl = findController(me.first);

        if (pCtrl)
        {
            pCtrl->addUniverse(std::get<0> (me.second));
        }
        else
        {
            cout << "setConfiguration - controller not found for universe: " << me.first << endl;
        }
    }

    // create the fixtures
    for (const auto &me : _mapFixtureIoInfo)
    {
        shared_ptr<Controller>  pCtrl = findController(std::get<0> (me.second));
        s32                     s32Id = std::get<1> (me.second);
        s32                     s32Os = std::get<2> (me.second);

        if (pCtrl)
        {
            createFixture(me.first, pCtrl, s32Id, s32Os);
        }
        else
        {
            cout << "setConfiguration - controller not found for fixture: " << me.first << endl;
        }
    }

    // create the scenes
    for (const auto &si : _vSceneIoInfo)
    {
        shared_ptr<Fixture> pFix = findFixture(std::get<0> (si));

        if (pFix)
        {
            aString sIcon   = std::get<1> (si);
            s32     s32Nr   = std::get<2> (si);
            bool    bBright = std::get<3> (si);

            pFix->addChannel(s32Nr, sIcon, bBright);
        }
        else
        {
            cout << "setConfiguration - fixture not found for scene: " << pFix->name() << endl;
        }
    }

    // create the banks
    for (const auto &me : _mapBankIoInfo)
    {
        aString sBankName   = me.first;
        s32     s32Nr       = std::get<0> (me.second);

        shared_ptr<Bank> pBank = createBank(sBankName);
        assignBank(pBank, s32Nr);
    }

    // add fixtures to the banks
    for (const auto &bfi : _vBankFixtureIoInfo)
    {
        aString sBankName   = std::get<0> (bfi);
        aString sFixName    = std::get<1> (bfi);
        s32     s32BtnIdx   = std::get<2> (bfi);

        shared_ptr<Bank> pBank = findBank(sBankName);
        shared_ptr<Fixture> pFix = findFixture(sFixName);

        if (pBank == nullptr)
        {
            cout << "setConfiguration - bank not found for fixture2bank-assign: "<< endl;
        }
        else if (pFix == nullptr)
        {
            cout << "setConfiguration - fixture not found for fixture2bank-assign: " << endl;
        }
        else
        {
            assignFixture(pBank, pFix, s32BtnIdx);
        }

    }

    // create the scenes
    for (const auto &s : _vSceneBtnIoInfo)
    {
        aString sSceneName  = std::get<0> (s);
        s32     s32BtnIdx   = std::get<1> (s);

        // create the new scene
        shared_ptr<Scene> pScene = make_shared<Scene> (sSceneName);

        // assign the scene to a scene button
        SceneTuple &sTuple = m_vSceneTuples.at(s32BtnIdx);
        std::get<1> (sTuple) = pScene;
    }

    // add channels to the scene
    for (const auto &s : _vSceneChannelIoInfo)
    {
        aString sScene          =   std::get<0> (s);
        aString sFixture        =   std::get<1> (s);
        s32     s32ChannelNr    =   std::get<2> (s);
        u8      u8Value         =   std::get<3> (s);

        // find the new scene
        shared_ptr<Scene> pScene = findScene(sScene);
        if (!pScene)
        {
            cout << "scene not found in scene-channels: " << sScene << endl;
        }
        else
        {
            shared_ptr<Fixture> pFixture = findFixture(sFixture);
            if (!pFixture)
            {
                cout << "fixture not found in scene-channels: " << sFixture << endl;
            }
            else
            {
                shared_ptr<Channel> pChannel = pFixture->channel(s32ChannelNr);

                if (!pChannel)
                {
                    cout << "channel not found in scene-channels: " << s32ChannelNr << endl;
                }
                else
                {
                    pScene->addChannel(pChannel, u8Value);
                }
            }
        }
    }

} // CtrlPanel::setConfiguration


/*******************************************************************************
* CtrlPanel::JsonValCallback
*******************************************************************************/
void CtrlPanel::JsonValCallback(const aVector<aString> &/*_vecKeys*/,
                                const aJsonValue       &/*_value*/)
{
} // CtrlPanel::JsonValCallback


/*******************************************************************************
* CtrlPanel::JsonObjCallback
*******************************************************************************/
void CtrlPanel::JsonObjCallback(const aVector<aString> &_vecKeys,
                                const aJsonObj       &_obj)
{
    s32     s32Size = _vecKeys.size();

    if (s32Size == 1)
    {
        // parse controller
        if (_vecKeys.at(0).left(10) == "controller")
        {
            aString     sName           = _obj.findString("name");
            aString     sAdress         = _obj.findString("adress");
            s32         s32UniverseMax  = _obj.findS32("universeMax");

            m_mapControllerIoInfo[sName] = make_tuple(sAdress, s32UniverseMax);
        }

        // parse universe
        if (_vecKeys.at(0).left(8) == "universe")
        {
            aString     sName   = _obj.findString("name");
            s32         id      = _obj.findS32("id");

            m_mapUniverseIoInfo[sName] = make_tuple(id);
        }

        // parse fixture
        if (_vecKeys.at(0).left(7) == "fixture")
        {
            aString     sName   = _obj.findString("name");
            aString     sCtrl   = _obj.findString("controller");
            s32         id      = _obj.findS32("universeId");
            s32         os      = _obj.findS32("channelOs");

            m_mapFixtureIoInfo[sName] = make_tuple(sCtrl, id, os);
        }

        // parse bank
        if (_vecKeys.at(0).left(4) == "bank")
        {
            aString     sName   = _obj.findString("name");
            s32         idx     = _obj.findS32("bankBtnIdx");

            m_mapBankIoInfo[sName] = make_tuple(idx);
        }

        // parse scene
        if (_vecKeys.at(0).left(5) == "scene")
        {
            aString     sName   = _obj.findString("sceneName");
            s32         idx     = _obj.findS32("idx");

            m_vSceneBtnIoInfo.push_back(make_tuple(sName, idx));
        }
    } // if (s32Size == 1)

    else if (s32Size == 2)
    {
        // parse fixture channel
        if (_vecKeys.at(0).left(7) == "fixture" &&
            _vecKeys.at(1).left(7) == "channel")
        {
            aString     sFixture    = _obj.findString("fixture");
            aString     sIcon       = _obj.findString("icon");
            s32         nr          = _obj.findS32("channelNr");
            bool        bBright     = _obj.findBool("brightness");

            m_vSceneIoInfo.push_back(make_tuple(sFixture, sIcon, nr, bBright));
        }

        // parse bank/fixture
        if (_vecKeys.at(0).left(4) == "bank" &&
            _vecKeys.at(1).left(7) == "fixture")
        {
            aString     sBank       = _obj.findString("bankName");
            aString     sFixture    = _obj.findString("fixtureName");
            s32         idx         = _obj.findS32("fixtureBtnIdx");

            m_vBankFixtureIoInfo.push_back(make_tuple(sBank, sFixture, idx));
        }

        // parse scene channel
        if (_vecKeys.at(0).left(5) == "scene" &&
            _vecKeys.at(1).left(7) == "channel")
        {
            aString     sScene      = _obj.findString("sceneName");
            aString     sFixture    = _obj.findString("fixtureName");
            s32         nr          = _obj.findS32("channelNr");
            u8          u8Value     = static_cast<u8> (_obj.findS32("value"));

            m_vSceneChannelIoInfo.push_back(make_tuple(sScene, sFixture, nr, u8Value));
        }
    } // else if (s32Size == 2)

} // CtrlPanel::JsonObjCallback
