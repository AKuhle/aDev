/*******************************************************************************
* \file scene.cpp
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
#include "aJsonValue.h"

#include "channel.h"
#include "controller.h"
#include "scene.h"


/*******************************************************************************
* Scene::Scene
*******************************************************************************/
Scene::Scene(const aString                     &_sName,
             const aVector<channelValueTuple>  &_vValues)
: m_sName(_sName),
  m_vValues(_vValues)
{
} // Scene::Scene


/*******************************************************************************
* Scene::~Scene
*******************************************************************************/
Scene::~Scene()
{
} // Scene::~Scene


/*******************************************************************************
* Scene::add2Configuration
*******************************************************************************/
void Scene::add2Configuration(aJsonFile     &_jf,
                              s32           _idx) const
{
    _jf.openLevel();
    for (const channelValueTuple &t : m_vValues)
    {
        shared_ptr<Channel> pChannel    = std::get<0> (t);
        u8                  u8Value     = std::get<1> (t);

        _jf.openLevel();
            _jf.add(aJsonValue("idx", (dbl) _idx));
            _jf.add(aJsonValue("sceneName", m_sName));
            _jf.add(aJsonValue("controllerName", pChannel->controller()->name()));
            _jf.add(aJsonValue("universId", (dbl) pChannel->universeId()));
            _jf.add(aJsonValue("channelNr", (dbl) pChannel->channelNr()));
            _jf.add(aJsonValue("channelOs", (dbl) pChannel->channelOs()));
            _jf.add(aJsonValue("value", (dbl) u8Value));
        _jf.closeLevel(aString("channel") + "-" + aString::fromValue(pChannel->channelNr() +
                                                                     pChannel->channelOs()));
    }
    _jf.closeLevel(aString("scene") + "-" + m_sName);
} // Scene::add2Configuration
