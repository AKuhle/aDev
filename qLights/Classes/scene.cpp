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
