/*******************************************************************************
* \file fixture.cpp
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
#include "aVector.h"

#include "fixture.h"
#include "channel.h"
#include "controller.h"

#include "qLights_defs.h"

#include "aJsonFile.h"
#include "aJsonValue.h"


using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* Fixture::Fixture
*******************************************************************************/
Fixture::Fixture(const aString          &_sName,
                 shared_ptr<Controller> _pController,
                 s32                    _s32UniverseId,
                 s32                    _s32ChannelOs)
: m_sName(_sName),
  m_pController(_pController),
  m_s32UniverseId(_s32UniverseId),
  m_s32ChannelOs(_s32ChannelOs)
{
} // Fixture::Fixture


/*******************************************************************************
* Fixture::~Fixture
*******************************************************************************/
Fixture::~Fixture()
{
} // Fixture::~Fixture


/*******************************************************************************
* Fixture::addChannel
*******************************************************************************/
void Fixture::addChannel(s32      _s32ChannelNr,
                         aString  _sIcon,
                         bool     _bBrightness)
{
    m_mapAllChannel[_s32ChannelNr] = make_shared<Channel> (this,
                                                           _s32ChannelNr,
                                                           _sIcon,
                                                           _bBrightness);

    if (_bBrightness)
    {
        m_vBrightnessChannel.push_back(m_mapAllChannel[_s32ChannelNr]);
    }
} // Fixture::addChannel


/*******************************************************************************
* Fixture::channel
*******************************************************************************/
shared_ptr<Channel> Fixture::channel(s32 _s32ChannelNr) const
{
    auto it = m_mapAllChannel.find(_s32ChannelNr);

    if (it != m_mapAllChannel.end())
    {
        return it->second;
    }

    return nullptr;
} // Fixture::channel


/*******************************************************************************
* Fixture::setChannelValue
*******************************************************************************/
void Fixture::setChannelValue(s32   _s32ChannelNr,
                              u8    _u8Value,
                              bool  _bSend)
{
    CHECK_PRE_CONDITION_VOID(m_pController);

    m_pController->setDmxChannelValue(m_s32ChannelOs + _s32ChannelNr - 2,
                                      m_s32UniverseId, _u8Value, _bSend);
} // Fixture::setChannelValue


/*******************************************************************************
* Fixture::resetAllChannels
*******************************************************************************/
void Fixture::resetAllChannels()
{
    CHECK_PRE_CONDITION_VOID(m_pController);

    for (auto me  : m_mapAllChannel)
    {
        me.second->setValue(0, false);
    }
} // Fixture::resetAllChannels


/*******************************************************************************
* Fixture::updateBrightnessChannels
*******************************************************************************/
void Fixture::updateBrightnessChannels(bool   _bSend) const
{
    for (auto &pC : m_vBrightnessChannel)
    {
        pC->updateBrightness(_bSend);
    }
} // Fixture::updateBrightnessChannels


/*******************************************************************************
* Fixture::collectChannels
*******************************************************************************/
void Fixture::collectChannels(aVector<shared_ptr<Channel>> &_vChannel)
{
    for (auto me : m_mapAllChannel)
    {
        _vChannel.push_back(me.second);
    }
} // Fixture::collectChannels


/*******************************************************************************
* Fixture::add2Configuration
*******************************************************************************/
void Fixture::add2Configuration(aJsonFile &_jf) const
{
    _jf.openLevel();
        _jf.add(aJsonValue("name", m_sName));
        _jf.add(aJsonValue("controller", m_pController->name()));
        _jf.add(aJsonValue("universeId", (dbl) m_s32UniverseId));
        _jf.add(aJsonValue("channelOs", (dbl) m_s32ChannelOs));

        // add the channels
        for (auto &c : m_mapAllChannel)
        {
            c.second->add2Configuration(_jf);
        }
    _jf.closeLevel(aString("fixture") + "-" + m_sName);

} // Fixture::add2Configuration
