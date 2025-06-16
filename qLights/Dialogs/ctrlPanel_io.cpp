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
                     m_vSceneBtnIoInfo);

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
                                 const aVector<sceneBtnIoInfo>          &_vSceneBtnIoInfo)
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
        aVector<channelValueTuple>  vValues;
        aString sSceneName  = std::get<0> (s);
        s32     s32BtnIdx   = std::get<1> (s);

        // create the new scene
        shared_ptr<Scene> pScene = make_shared<Scene> (sSceneName);

        // assign the scene to a scene button
        SceneTuple &sTuple = m_vSceneTuples.at(s32BtnIdx);
        std::get<1> (sTuple) = pScene;
    }

} // CtrlPanel::setConfiguration


/*******************************************************************************
* CtrlPanel::JsonValCallback
*******************************************************************************/
void CtrlPanel::JsonValCallback(const aVector<aString> &/*_vecKeys*/,
                                const aJsonValue       &/*_value*/)
{
    //s32     s32Size = _vecKeys.size();

    // parse controller
    // if (_vecKeys.at(0).left(10) == "controller" && s32Size == 1)
    // {
    //     cout << "controllerVal" << endl;
    // }
//         controllerIoInfo &ci = getControllerInfo(_vecKeys.at(0));

//         if (s32Size == 1)
//         {
//             // fixture name
//             if (_value.key() == "name")
//                 std::get<0> (ci) = _value.toString();

//             // ip adress
//             if (_value.key() == "adress")
//                 std::get<1> (ci) = _value.toString();

//             // universeMax of the controller
//             if (_value.key() == "universeMax")
//                 std::get<2> (ci) = _value.toDbl();
//         }

//         if (s32Size == 2)
//         {
//             universeIoInfo &ui = getUniverseInfo(ci, _vecKeys.at(0));

//             // fixture name
//             if (_value.key() == "id")
//                 std::get<0> (ui) = _value.toDbl();
//         }
//    }


//     // parse bank
//     if (_vecKeys.at(0).left(4) == "bank")
//     {
//         bankIoInfo &bi = getBankInfo(_vecKeys.at(0));

//         if (s32Size == 1)
//         {
//             // bank name
//             if (_value.key() == "name")
//                 std::get<0> (bi) = _value.toString();

//             // bankBtnIdx
//             if (_value.key() == "bankBtnIdx")
//                 std::get<1> (bi) = _value.toDbl();
//         }
//     }


//     // parse fixture
//     if (_vecKeys.at(0).left(7) == "fixture")
//     {
//         fixtureIoInfo &fi = getFixtureInfo(_vecKeys.at(0));

//         // read fixture data (name, controller, universeId, channelOs)
//         if (s32Size == 1)
//         {
//             // fixture name
//             if (_value.key() == "name")
//                 std::get<0> (fi) = _value.toString();

//             // fixture controller
//             if (_value.key() == "controller")
//                 std::get<1> (fi) = _value.toString();

//             // fixture universeId
//             if (_value.key() == "universeId")
//                 std::get<2> (fi) = _value.toDbl();

//             // fixture universeId
//             if (_value.key() == "channelOs")
//                 std::get<3> (fi) = static_cast<s32> (_value.toDbl());

//             // fixture controller
//             if (_value.key() == "bank")
//                 std::get<4> (fi) = _value.toString();

//             // fixture controller
//             if (_value.key() == "fixtureBtnIdx")
//                 std::get<5> (fi) = _value.toDbl();
//         }

//         // read fixture channel
//         if (s32Size == 2)
//         {
//             channelIoInfo &ci = getChannelInfo(fi, _vecKeys.at(1));

//             // channel controller
//             if (_value.key() == "controller")
//                 std::get<0> (ci) = _value.toString();

//             // channel channelNr
//             if (_value.key() == "channelNr")
//                 std::get<1> (ci) = _value.toDbl();

//             // channel icon
//             if (_value.key() == "icon")
//                 std::get<2> (ci) = _value.toString();

//             // channel brightness
//             if (_value.key() == "brightness")
//                 std::get<3> (ci) = _value.toBool();
//         }


//         // parse scene
//         if (_vecKeys.at(0).left(5) == "scene")
//         {
//             sceneIoInfo &si = getSceneInfo(_vecKeys.at(0));

//             if (s32Size == 1)
//             {
//                 // idx
//                 if (_value.key() == "idx")
//                     std::get<0> (si) = _value.toDbl();

//                 // sceneName
//                 if (_value.key() == "sceneName")
//                     std::get<1> (si) = _value.toString();

//                 // controllerName
//                 if (_value.key() == "controllerName")
//                     std::get<2> (si) = _value.toString();

//                 // universId
//                 if (_value.key() == "universId")
//                     std::get<3> (si) = _value.toDbl();

//                 // channelNr
//                 if (_value.key() == "channelNr")
//                     std::get<4> (si) = _value.toDbl();

//                 // channelOs
//                 if (_value.key() == "channelOs")
//                     std::get<5> (si) = _value.toDbl();

//                 // value
//                 if (_value.key() == "value")
//                     std::get<6> (si) = _value.toDbl();
//             }
//         }
//     }

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
    } // else if (s32Size == 2)

} // CtrlPanel::JsonObjCallback


// /*******************************************************************************
// * CtrlPanel::getBankInfo
// *******************************************************************************/
// bankIoInfo& CtrlPanel::getBankInfo(const aString &_sName)
// {
//     // create a new bankinfo, if it does not already exist
//     if (m_mapBankIoInfo.find(_sName) == m_mapBankIoInfo.end())
//     {
//         m_mapBankIoInfo[_sName] = std::make_tuple("", 0);
//     }

//     return m_mapBankIoInfo.find(_sName)->second;
// } // CtrlPanel::getBankInfo


// /*******************************************************************************
// * CtrlPanel::getFixtureInfo
// *******************************************************************************/
// fixtureIoInfo& CtrlPanel::getFixtureInfo(const aString &_sName)
// {
//     // create a new fixtureinfo, if it does not already exist
//     if (m_mapFixtureIoInfo.find(_sName) == m_mapFixtureIoInfo.end())
//     {
//         m_mapFixtureIoInfo[_sName] = std::make_tuple("", "", 0, 0, "", 0, aMap<aString, channelIoInfo>{});
//     }

//     return m_mapFixtureIoInfo.find(_sName)->second;
// } // CtrlPanel::getFixtureInfo


// /*******************************************************************************
// * CtrlPanel::getChannelInfo
// *******************************************************************************/
// channelIoInfo& CtrlPanel::getChannelInfo(fixtureIoInfo  &_fi,
//                                          const aString  &_sName)
// {
//     aMap<aString, channelIoInfo>  &mapChannelInfo = std::get<6> (_fi);

//     // create a new fixtureinfo, if it does not already exist
//     if (mapChannelInfo.find(_sName) == mapChannelInfo.end())
//     {
//         mapChannelInfo[_sName] = std::make_tuple("", 0, "", false);
//     }

//     return mapChannelInfo.find(_sName)->second;
// } // CtrlPanel::getChannelInfo


// /*******************************************************************************
// * CtrlPanel::getControllerInfo
// *******************************************************************************/
// controllerIoInfo& CtrlPanel::getControllerInfo(const aString &_sName)
// {
//     // create a new fixtureinfo, if it does not already exist
//     if (m_mapControllerIoInfo.find(_sName) == m_mapControllerIoInfo.end())
//     {
//         m_mapControllerIoInfo[_sName] = std::make_tuple("", "", 0, aMap<aString, universeIoInfo>{});
//     }

//     return m_mapControllerIoInfo.find(_sName)->second;
// } // CtrlPanel::getControllerInfo


// /*******************************************************************************
// * CtrlPanel::getUniverseInfo
// *******************************************************************************/
// universeIoInfo& CtrlPanel::getUniverseInfo(controllerIoInfo &_ci,
//                                            const aString    &_sName)
// {
//     aMap<aString, universeIoInfo>  &mapUniverseInfo = std::get<3> (_ci);

//     // create a new fixtureinfo, if it does not already exist
//     if (mapUniverseInfo.find(_sName) == mapUniverseInfo.end())
//     {
//         mapUniverseInfo[_sName] = std::make_tuple(0);
//     }

//     return mapUniverseInfo.find(_sName)->second;
// } // CtrlPanel::getUniverseInfo


// /*******************************************************************************
// * CtrlPanel::getSceneInfo
// *******************************************************************************/
// sceneIoInfo& CtrlPanel::getSceneInfo(const aString    &_sName)
// {
//     // create a new fixtureinfo, if it does not already exist
//     if (m_mapSceneIoInfo.find(_sName) == m_mapSceneIoInfo.end())
//     {
//         m_mapSceneIoInfo[_sName] = std::make_tuple(0, "", "", 0, 0, 0, 0);
//     }

//     return m_mapSceneIoInfo.find(_sName)->second;
// } // CtrlPanel::getSceneInfo
