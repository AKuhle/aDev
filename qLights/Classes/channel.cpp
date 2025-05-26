/*******************************************************************************
* \file Channel.cpp
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
#include "channel.h"


/*******************************************************************************
* Channel::Channel
*******************************************************************************/
Channel::Channel(s32         _s32ChannelNr,
                 s32         _s32ChannelOs,
                 s32         _s32ControllerIdx,
                 u32         _u32UniverseId,
                 bool        _bBrightness,
                 aString     _sIcon)
: m_s32ChannelNr(_s32ChannelNr),
  m_s32ChannelOs(_s32ChannelOs),
  m_s32ControllerIdx(_s32ControllerIdx),
  m_u32UniverseId(_u32UniverseId),
  m_bBrightness(_bBrightness),
  m_sIcon(_sIcon)
{
} // Channel::Channel


/*******************************************************************************
* Channel::~Channel
*******************************************************************************/
Channel::~Channel()
{
} // Channel::~Channel
