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
#include "controller.h"
#include "universe.h"


/*******************************************************************************
* Channel::Channel
*******************************************************************************/
Channel::Channel(shared_ptr<Controller>  _pController,
                 s32                     _s32UniverseId,
                 s32                     _s32ChannelOs,
                 s32                     _s32ChannelNr,
                 aString                 _sIcon,
                 bool                    _bBrightness)
: m_pController(_pController),
  m_s32UniverseId(_s32UniverseId),
  m_s32ChannelOs(_s32ChannelOs),
  m_s32ChannelNr(_s32ChannelNr),
  m_sIcon(_sIcon),
  m_bBrightness(_bBrightness)
{
} // Channel::Channel


/*******************************************************************************
* Channel::~Channel
*******************************************************************************/
Channel::~Channel()
{
} // Channel::~Channel


/*******************************************************************************
* Channel::setValue
*******************************************************************************/
void Channel::setValue(u8    _u8Value)
{
    m_u8Value = _u8Value;
} // Channel::setValue


/*******************************************************************************
* Channel::updateDmxValue
*******************************************************************************/
void Channel::updateDmxValue(u8    _u8Value,
                             bool  _bSend)
{
    if (m_pController)
    {
        shared_ptr<Universe> pUni = m_pController->universe(m_s32UniverseId);

        if (pUni)
        {
            pUni->setDmxChannelValue(m_s32ChannelNr + m_s32ChannelOs - 1, _u8Value, _bSend);
        }
    }
} // Channel::updateDmxValue
