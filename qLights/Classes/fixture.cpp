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
Fixture::Fixture(const aString   &_sName,
                 s32             _s32ControllerIdx,
                 s32             _s32UniverseId,
                 s32             _s32ChannelOs)
: m_sName(_sName),
  m_s32ControllerIdx(_s32ControllerIdx),
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
void Fixture::addChannel(s32        _s32ChannelNr,
                         s32        _s32FaderIdx,
                         aString    _sChannelIcon)
{
    m_mapChannel[_s32FaderIdx] = make_shared<Channel> (_s32ChannelNr);
    m_mapChannel[_s32FaderIdx]->setChannelIcon(_sChannelIcon);
} // Fixture::addChannel


/*******************************************************************************
* Fixture::channel
*******************************************************************************/
shared_ptr<Channel> Fixture::channel(s32 _s32FaderIdx) const
{
    auto it = m_mapChannel.find(_s32FaderIdx);

    if (it != m_mapChannel.end())
    {
        return it->second;
    }

    return nullptr;
} // Fixture::channel
