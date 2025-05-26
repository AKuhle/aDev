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
#include "fixture.h"
#include "channel.h"


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
