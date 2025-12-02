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
#include <QTimer>

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
* Scene::hasFixture
*******************************************************************************/
bool Scene::hasFixture(shared_ptr<Fixture> _pFixture) const
{
    return std::find(m_vAffectedFixtures.begin(),
                     m_vAffectedFixtures.end(),
                     _pFixture) != m_vAffectedFixtures.end();
} // Scene::hasFixture


/*******************************************************************************
* Scene::showScene
*******************************************************************************/
void Scene::showScene(bool _bIgnoreBlackStart) const
{
    // iterate over all fixtures
    for (const shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
    {
        // black start -> switch fixture off
        if (!_bIgnoreBlackStart && isBlackStart())
        {
            pFix->switchOff();
        }

        auto it = m_mapFixtureValues.find(pFix);

        if (it != m_mapFixtureValues.end())
        {
            pFix->setChannelValues(it->second);
        }
    }

    // update the faders, they maybe have changed
    MainWin::instance()->updateFaders();

    // black start -> switch fixture on after BLACK_START_TIME_MS (2 seconds)
    if (!_bIgnoreBlackStart && isBlackStart())
    {
        QTimer::singleShot(BLACK_START_TIME_MS, this, SLOT(switchFixturesOn()));
    }
} // Scene::showScene


/*******************************************************************************
* Scene::switchAllFixturesOff
*******************************************************************************/
void Scene::switchAllFixturesOff() const
{
    // iterate over all fixtures
    for (const shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
    {
        pFix->switchOff();
    }

    // update the faders, they maybe have changed
    MainWin::instance()->updateFaders();

} // Scene::switchAllFixturesOff


/*******************************************************************************
* Scene::switchAllFixturesOn
*******************************************************************************/
void Scene::switchAllFixturesOn() const
{
    // iterate over all fixtures
    for (const shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
    {
        pFix->switchOn();
    }

    // update the faders, they maybe have changed
    MainWin::instance()->updateFaders();

} // Scene::switchAllFixturesOn


/*******************************************************************************
* Scene::channelValue
*******************************************************************************/
u8 Scene::channelValue(shared_ptr<Fixture>    _pFixture,
                       s32                    _s32ChannelNr) const
{
    // find the map entry
    auto itMap = m_mapFixtureValues.find(_pFixture);

    if (itMap != m_mapFixtureValues.end())
    {
        // Entry found
        const mapChannelValue &values = itMap->second;

        // find the channel
        auto itChannel = values.find(_s32ChannelNr);

        if (itChannel != values.end())
        {
            return itChannel->second;
        }
    }

    return 0;
} // Scene::channelValue


/*******************************************************************************
* Scene::findChannelValues
*******************************************************************************/
const mapChannelValue* Scene::findChannelValues(const shared_ptr<Fixture> &_pFixture) const
{
    // Prüfe, ob Fixture bereits in der Map existiert
    auto it = m_mapFixtureValues.find(_pFixture);

    return (it != m_mapFixtureValues.end())?   &(it->second) : nullptr;
} // Scene::findChannelValues


/*******************************************************************************
* Scene::switchFixturesOn
*******************************************************************************/
void Scene::switchFixturesOn() const
{
    // iterate over all fixtures
    for (const shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
    {
        pFix->switchOn();
    }
} // Scene::switchFixturesOn
