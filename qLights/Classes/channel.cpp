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
// #include "aJsonFile.h"
// #include "aJsonValue.h"

#include "channel.h"
#include "fixture.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* Channel::Channel
*******************************************************************************/
Channel::Channel(Fixture             *_pFixture,
                 s32                 _s32ChannelNr,
                 aString             _sIcon,
                 bool                _bBrightness)
: m_pFixture(_pFixture),
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
void Channel::setValue(u8   _u8Value,
                       bool _bSend)
{
    CHECK_PRE_CONDITION_VOID(m_pFixture);

    m_u8Value = _u8Value;
    m_pFixture->setChannelValue(m_s32ChannelNr, _u8Value, _bSend);
} // Channel::setValue


// /*******************************************************************************
// * Channel::add2Configuration
// *******************************************************************************/
// void Channel::add2Configuration(aJsonFile &_jf)
// {
//     _jf.openLevel();
//         _jf.add(aJsonValue("controller", m_pController->name()));
//         _jf.add(aJsonValue("channelNr", (dbl) m_s32ChannelNr));
//         _jf.add(aJsonValue("icon", m_sIcon));
//         _jf.add(aJsonValue("brightness", m_bBrightness));
//     _jf.closeLevel(aString("channel") + "-" + aString::fromValue(m_s32ChannelNr));

// } // Channel::add2Configuration


// /*******************************************************************************
// * Channel::updateDmxValue
// *******************************************************************************/
// void Channel::updateDmxValue(u8    _u8Value,
//                              bool  _bSend)
// {
//     if (m_pController)
//     {
//         shared_ptr<Universe> pUni = m_pController->universe(m_s32UniverseId);

//         if (pUni)
//         {
//             pUni->setDmxChannelValue(m_s32ChannelNr + m_s32ChannelOs - 1, _u8Value, _bSend);
//         }
//     }
// } // Channel::updateDmxValue
