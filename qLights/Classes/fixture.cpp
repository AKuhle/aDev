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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "controller.h"
#include "fixture.h"
#include "channel.h"
#include "bank.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* Fixture::Fixture
*******************************************************************************/
Fixture::Fixture(const aString          &_sName,
                 shared_ptr<Controller> _pConroller,
                 s32                    _s32UniverseId,
                 s32                    _s32ChannelOs)
: m_sName(_sName),
  m_pConroller(_pConroller),
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
* Fixture::add2Configuration
*******************************************************************************/
void Fixture::add2Configuration(aJsonFile           &_jf,
                                shared_ptr<Bank>    _pBank,
                                s32                 _s32FixtureBtnIdx)
{
    _jf.openLevel();
        _jf.add(aJsonValue("name", m_sName));
        _jf.add(aJsonValue("controller", m_pConroller->name()));
        _jf.add(aJsonValue("universeId", (dbl) m_s32UniverseId));
        _jf.add(aJsonValue("channelOs", (dbl) m_s32ChannelOs));
        _jf.add(aJsonValue("bank", _pBank->name()));
        _jf.add(aJsonValue("fixtureBtnIdx", (dbl) _s32FixtureBtnIdx));

        // add the channels
        for (auto &c : m_mapChannel)
        {
            c.second->add2Configuration(_jf);
        }
    _jf.closeLevel(aString("fixture") + "-" + m_sName);

} // Fixture::add2Configuration


/*******************************************************************************
* Fixture::createChannel
*******************************************************************************/
shared_ptr<Channel> Fixture::createChannel(s32      _s32ChannelNr,
                                           aString  _sIcon,
                                           bool     _bBrightness)
{
    m_mapChannel[_s32ChannelNr] = make_shared<Channel> (m_pConroller,
                                                        m_s32UniverseId,
                                                        m_s32ChannelOs,
                                                        _s32ChannelNr,
                                                        _sIcon,
                                                        _bBrightness);

    return m_mapChannel[_s32ChannelNr];
} // Fixture::createChannel


/*******************************************************************************
* Fixture::channel
*******************************************************************************/
shared_ptr<Channel> Fixture::channel(s32 _s32ChannelNr) const
{
    auto it = m_mapChannel.find(_s32ChannelNr);

    if (it != m_mapChannel.end())
    {
        return it->second;
    }

    return nullptr;
} // Fixture::channel


/*******************************************************************************
* Fixture::allChannelValues
*******************************************************************************/
void Fixture::allChannelValues(aVector<channelValueTuple> &vValues) const
{
    for (auto &me : m_mapChannel)
    {
        channelValueTuple t = std::make_tuple(me.second, me.second->value());

        vValues.push_back(t);
    }
} // Fixture::allChannelValues


/*******************************************************************************
* Fixture::allChannels
*******************************************************************************/
void Fixture::allChannels(aVector<shared_ptr<Channel>> &_vChannel) const
{
    for (auto &me : m_mapChannel)
    {
        _vChannel.push_back(me.second);
    }
} // Fixture::allChannels
