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

#include "scene.h"
#include "channel.h"
#include "fixture.h"


/*******************************************************************************
* Scene::Scene
*******************************************************************************/
Scene::Scene(const aString                     &_sName)
: m_sName(_sName)
{
} // Scene::Scene


/*******************************************************************************
* Scene::~Scene
*******************************************************************************/
Scene::~Scene()
{
} // Scene::~Scene


/*******************************************************************************
* Scene::addChannel
*******************************************************************************/
void Scene::addChannel(shared_ptr<Channel>  _pChannel,
                       u8                   _u8Value)
{
    m_vValues.push_back(std::make_tuple(_pChannel, _u8Value));
} // Scene::addChannel


/*******************************************************************************
* Scene::findCorrespondingChannelValueTuple
*******************************************************************************/
const channelValueTuple* Scene::findCorrespondingChannelValueTuple(const channelValueTuple &_template) const
{
    const channelValueTuple   *pFound = nullptr;

    for (const channelValueTuple &v : m_vValues)
    {
        if (std::get<0> (v) == std::get<0> (_template))
        {
            pFound = &v;
        }
    }

    return pFound;
} // Scene::findCorrespondingChannelValueTuple


/*******************************************************************************
* Scene::add2Configuration
*******************************************************************************/
void Scene::add2Configuration(aJsonFile     &_jf,
                              s32           _idx) const
{
    _jf.openLevel();
        // add scene info
        _jf.add(aJsonValue("idx", (dbl) _idx));
        _jf.add(aJsonValue("sceneName", m_sName));

        // add the channels
        for (const channelValueTuple &t : m_vValues)
        {
            shared_ptr<Channel> pChannel        = std::get<0> (t);
            u8                  u8Value         = std::get<1> (t);

            aString             sFixName        = pChannel->fixture()->name();
            s32                 s32ChannelNr    = pChannel->channelNr();

            _jf.openLevel();
                _jf.add(aJsonValue("sceneName", m_sName));
                _jf.add(aJsonValue("fixtureName", sFixName));
                _jf.add(aJsonValue("channelNr", (dbl) s32ChannelNr));
                _jf.add(aJsonValue("value", (dbl) u8Value));
            _jf.closeLevel(aString("channel") + "-" + sFixName + "-" + aString::fromValue(s32ChannelNr));
        }
    _jf.closeLevel(aString("scene") + "-" + m_sName);
} // Scene::add2Configuration
