/*******************************************************************************
* \file Scene.cpp
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
#include "scene.h"
#include "universe.h"
#include "fixture.h"
#include "device.h"
#include "channel.h"


/*******************************************************************************
* Scene::Scene
*******************************************************************************/
Scene::Scene(const QString  &_sName,
             u8             _u8MasterBrighness)
: m_sName(_sName),
  m_u8MasterBrighness(_u8MasterBrighness)
{
} // Scene::Scene


/*******************************************************************************
* Scene::~Scene
*******************************************************************************/
Scene::~Scene()
{
} // Scene::~Scene


/*******************************************************************************
* Scene::addUniverses
*******************************************************************************/
void Scene::addUniverses(const list<shared_ptr<Universe>>  &_lstUniverse)
{
    for (auto pUniverse : _lstUniverse)
    {
        stUniverseInfo uInfo { pUniverse, pUniverse->dmxDataValue() };
        m_lstUniverse.push_back(uInfo);
    }
} // Scene::addUniverses


/*******************************************************************************
* Scene::channelValue
*******************************************************************************/
u8 Scene::channelValue(const shared_ptr<Universe>   _pUniverse,
                       s32                          _s32FixtureAdress,
                       s32                          _s32ChannelNr) const
{
    for (const stUniverseInfo &stU : m_lstUniverse)
    {
        if (stU.pUniverse == _pUniverse)
        {
            s32     dmxIdx = _s32FixtureAdress +_s32ChannelNr - 2;

            return static_cast<u8>(static_cast<unsigned char>(stU.data.at(dmxIdx)));
        }
    }

    cout << "!!!!! ERROR: no channel value found in Scene::channelValue" << endl;
    return 0;
} // Scene::channelValue


/*******************************************************************************
* Scene::applySceneData2Fixture
*******************************************************************************/
void Scene::applySceneData2Fixture(shared_ptr<Fixture>  _pFix) const
{
    const vector<shared_ptr<Channel>> &vChannel = _pFix->device()->channel();
    shared_ptr<Universe>              pUniverse = _pFix->universe();
    s32                               s32Adress = _pFix->adress();

    for (const shared_ptr<Channel> &pChannel : vChannel)
    {
        u8 u8ChannelValue = channelValue(pUniverse, s32Adress, pChannel->nr());

        pUniverse->setChannelValue(s32Adress, pChannel, u8ChannelValue);
    }
} // Scene::applySceneData2Fixture
