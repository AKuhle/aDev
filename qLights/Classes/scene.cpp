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
#include "channelDevice.h"
#include "mainWin.h"


/*******************************************************************************
* Scene::Scene
*******************************************************************************/
Scene::Scene(const QString  &_sName,
             bool          _bBlackStart)
: m_sName(_sName),
  m_bBlackStart(_bBlackStart)
{
} // Scene::Scene


/*******************************************************************************
* Scene::~Scene
*******************************************************************************/
Scene::~Scene()
{
} // Scene::~Scene


/*******************************************************************************
* Scene::addFixture
*******************************************************************************/
void Scene::addFixture(shared_ptr<Fixture>      _pFixture,
                       const mapChannelValue    &_channelValue)
{
    CHECK_PRE_CONDITION_VOID(_pFixture);

    m_vAffectedFixtures.push_back(_pFixture);

    m_mapFixtureValues[_pFixture] = _channelValue;
} // Scene::addFixture


/*******************************************************************************
* Scene::updateFixtures
*******************************************************************************/
void Scene::updateFixtures() const
{
    // iterate over all fixtures
    for (const shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
    {
        auto it = m_mapFixtureValues.find(pFix);

        if (it != m_mapFixtureValues.end())
        {
            pFix->setChannelValues(it->second);
        }
    }

    // update the faders, thei maybe have changed
    MainWin::instance()->updateFaders();
} // Scene::updateFixtures


/*******************************************************************************
* Scene::findChannelValues
*******************************************************************************/
const mapChannelValue* Scene::findChannelValues(const shared_ptr<Fixture> &_pFixture) const
{
    // Prüfe, ob Fixture bereits in der Map existiert
    auto it = m_mapFixtureValues.find(_pFixture);

    return (it != m_mapFixtureValues.end())?   &(it->second) : nullptr;
} // Scene::findChannelValues
