/*******************************************************************************
* \file Fixture.cpp
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
#include "universe.h"
#include "device.h"
#include "mainWin.h"

using namespace aFrame;


/*******************************************************************************
* Fixture::Fixture
*******************************************************************************/
Fixture::Fixture(const QString          &_sName,
                 shared_ptr<Device>     _pDevice,
                 shared_ptr<Universe>   _pUniverse,
                 s32                    _s32Adress)
: m_sName(_sName),
  m_pDevice(_pDevice),
  m_pUniverse(_pUniverse),
  m_s32Adress(_s32Adress)
{
    // create channels which are conform to the device channels
    const vector<shared_ptr<ChannelDevice>> &vChannelDevice = m_pDevice->channel();
    for (shared_ptr<ChannelDevice> pChannelDevice : vChannelDevice)
    {
        shared_ptr<Channel> pC = make_shared<Channel> (pChannelDevice->nr(),
                                                       pChannelDevice->name(),
                                                       pChannelDevice->pixmapName(),
                                                       pChannelDevice->isBrightnessChannel());

        // save the master brightness for this fixture separate for efficiency
        if (pC->isBrightnessChannel())
        {
            m_pChannelBright = pC;
        }

        m_vChannel.push_back(pC);
    }

} // Fixture::Fixture


/*******************************************************************************
* Fixture::~Fixture
*******************************************************************************/
Fixture::~Fixture()
{
} // Fixture::~Fixture


/*******************************************************************************
* Fixture::findChannel
*******************************************************************************/
shared_ptr<Channel> Fixture::findChannel(s32 _s32ChannelNr) const
{
    auto it = std::find_if(m_vChannel.begin(),
                           m_vChannel.end(),
                           [_s32ChannelNr](const shared_ptr<Channel> &ch)
                           {
                               return ch->nr() == _s32ChannelNr;
                           });

    if (it != m_vChannel.end())
    {
        // Channel found
        return *it;
    }

    return nullptr;
} // Fixture::findChannel


/*******************************************************************************
* Fixture::setChannelValue
*******************************************************************************/
void Fixture::setChannelValue(shared_ptr<Channel>   _pChannel,
                              u8                    _u8Value)
{
    CHECK_PRE_CONDITION_VOID(m_pUniverse);

    // set the value in the channel
    _pChannel->setChannelValue(_u8Value);

    // set the value in the universe
    dbl dValue  = static_cast<dbl> (_u8Value);

    if (_pChannel->isBrightnessChannel())
    {
        if (m_bSwitchedOff)
        {
            dValue = 0;
        }
        else
        {
            // brightness channel => take master brightness into account
            dbl dMaster = static_cast<dbl> (MainWin::instance()->masterBrightness());
            dValue *= dMaster / 255.;
        }
    }

    m_pUniverse->setDmxValue(m_s32Adress, _pChannel->nr(), static_cast<u8> (dValue));
} // Fixture::setChannelValue


/*******************************************************************************
* Fixture::channelValue
*******************************************************************************/
u8 Fixture::channelValue(s32 _s32ChannelNr) const
{
    shared_ptr<Channel>pChannel = findChannel(_s32ChannelNr);

    return (pChannel)?   pChannel->channelValue() : 0;
} // Fixture::channelValue


/*******************************************************************************
* Fixture::switchOn
*******************************************************************************/
void Fixture::switchOn()
{
    // set the off flag and and set the channel value of the brightness channel
    // again. This set the universe value to correct brightness value
    if (m_pChannelBright)
    {
        m_bSwitchedOff = false;

        setChannelValue(m_pChannelBright, m_pChannelBright->channelValue());
    }
} // Fixture::switchOn


/*******************************************************************************
* Fixture::switchOff
*******************************************************************************/
void Fixture::switchOff()
{
    // set the off flag and and set the channel value of the brightness channel
    // again. This set the universe value to 0
    if (m_pChannelBright)
    {
        m_bSwitchedOff = true;

        setChannelValue(m_pChannelBright, m_pChannelBright->channelValue());
    }
} // Fixture::switchOff


/*******************************************************************************
* Fixture::setBrightness0
*******************************************************************************/
void Fixture::setBrightness0()
{
    CHECK_PRE_CONDITION_VOID(m_pChannelBright);

    setChannelValue(m_pChannelBright, 0);

} // Fixture::setBrightness0


/*******************************************************************************
* Fixture::channelValues
*******************************************************************************/
mapChannelValue Fixture::channelValues() const
{
    std::map<int, u8>   mapValues;

    for (const shared_ptr<Channel> &pChannel : m_vChannel)
    {
        mapValues[pChannel->nr()] = pChannel->channelValue();
    }


    return mapValues;
} // Fixture::channelValues


/*******************************************************************************
* Fixture::setChannelValues
*******************************************************************************/
void Fixture::setChannelValues(const mapChannelValue &_channelValues)
{
    for (const auto& [key, value] : _channelValues)
    {
        auto it = std::find_if(m_vChannel.begin(), m_vChannel.end(),
            [key](const shared_ptr<Channel> &pChannel) {
                return pChannel->nr() == key;
            });

        if (it != m_vChannel.end())
        {
            // found channel
            setChannelValue(*it, value);
        }
    }

} // Fixture::setChannelValues


/*******************************************************************************
* Fixture::updateMasterBrightness
*******************************************************************************/
void Fixture::updateMasterBrightness()
{
    CHECK_PRE_CONDITION_VOID(m_pChannelBright);

    setChannelValue(m_pChannelBright, m_pChannelBright->channelValue());

} // Fixture::updateMasterBrightness


/*******************************************************************************
* Fixture::resetFixture
*******************************************************************************/
void Fixture::resetFixture()
{
    // set all channel values to 0
    for (auto &pChannel : m_vChannel)
    {
        // set the value in the universe
        m_pUniverse->setDmxValue(m_s32Adress, pChannel->nr(), (u8) 0);
    }

} // Fixture::resetFixture
