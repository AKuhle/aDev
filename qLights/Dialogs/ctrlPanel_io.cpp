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
    aVector<channelValueTuple>      vValues;

    auto    pSceneBtn   = std::get<0> (m_vSceneTuples.at(_s32SceneBtnIdx));
    auto    &pScene     = std::get<1> (m_vSceneTuples.at(_s32SceneBtnIdx));

    // set the scene name
    pSceneBtn->setText(_sSceneName);

    // collect all channels
    for (auto pFixture : m_vFixtures)
    {
        pFixture->collectScenes(vValues);
    }

    // create an d save the scene
    pScene = make_shared<Scene> (_sSceneName, vValues);
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

//     // add scenes
//     for (s32 idx = 0; idx < SCENE_MAX; idx++)
//     {
//         sceneTuple          &st     = m_vSceneCtrl.at(idx);
//         shared_ptr<Scene>   pScene  = std::get<1> (st);

//         if (pScene)
//         {
//             pScene->add2Configuration(jf, idx);
//         }
//     }

    // write the json file
    jf.write2File();
} // CtrlPanel::writeConfiguration


/*******************************************************************************
* CtrlPanel::readConfiguration
*******************************************************************************/
void CtrlPanel::readConfiguration(const aPath &_path)
{
    // delete previous configuration
//     m_mapControllerIoInfo.clear();
//     m_mapBankIoInfo.clear();
//     m_mapFixtureIoInfo.clear();

     aJsonFile   jFile(_path);

    // read all entries
    // jFile.readAllValues([this](const aVector<aString> &_vecKeys, const aJsonValue &_value) {
    //                     this->JsonCallback(_vecKeys, _value);
    // });

//     // set the configuration
//     setConfiguration(m_mapControllerIoInfo,
//                      m_mapBankIoInfo,
//                      m_mapFixtureIoInfo,
//                      m_mapSceneIoInfo);
} // CtrlPanel::readConfiguration


/*******************************************************************************
* CtrlPanel::JsonCallback
*******************************************************************************/
void CtrlPanel::JsonCallback(const aVector<aString> &_vecKeys,
                             const aJsonValue       &_value)
{
//     s32     s32Size = _vecKeys.size();

//     // parse controller
//     if (_vecKeys.at(0).left(10) == "controller")
//     {
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
//     }


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

} // CtrlPanel::JsonCallback


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
