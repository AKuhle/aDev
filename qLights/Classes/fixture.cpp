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
        // brightness channel => take master brightness into account
        dbl dMaster = static_cast<dbl> (MainWin::instance()->masterBrightness());
        dValue *= dMaster / 255.;

    }

    m_pUniverse->setDmxValue(m_s32Adress, _pChannel->nr(), static_cast<u8> (dValue));
} // Fixture::setChannelValue


/*******************************************************************************
* Fixture::channelValues
*******************************************************************************/
std::map<int, u8> Fixture::channelValues() const
{
    std::map<int, u8>   mapValues;

    for (const shared_ptr<Channel> &pChannel : m_vChannel)
    {
        mapValues[pChannel->nr()] = pChannel->channelValue();
    }


    return mapValues;
} // Fixture::channelValues


/*******************************************************************************
* Fixture::updateMasterBrightness
*******************************************************************************/
void Fixture::updateMasterBrightness()
{
    CHECK_PRE_CONDITION_VOID(m_pChannelBright);

    setChannelValue(m_pChannelBright, m_pChannelBright->channelValue());

} // Fixture::updateMasterBrightness


/*******************************************************************************
* Fixture::overrideBrightness
*******************************************************************************/
// void Fixture::overrideBrightness(u8 _u8Brightness)
// {
//     // just one override
//     if (!m_bOverrideBrightness)
//     {
//         const vector<shared_ptr<Channel>> &vChannels = m_pDevice->channel();

//         for (shared_ptr<Channel> pChannel : vChannels)
//         {
//             // there should be just one brightness channel per fixture
//             if (pChannel->isBrightnessChannel())
//             {
//                 m_u8LastBrightness = pChannel->channelValue();
//                 m_pUniverse->setChannelValue(m_s32Adress, pChannel, _u8Brightness);
//                 break;
//             }
//         }

//         m_bOverrideBrightness = true;
//     }
// } // Fixture::overrideBrightness


// /*******************************************************************************
// * Fixture::restoreBrightness
// *******************************************************************************/
// void Fixture::restoreBrightness()
// {
//     // restore only, if overridden
//     if (m_bOverrideBrightness)
//     {
//         const vector<shared_ptr<Channel>> &vChannels = m_pDevice->channel();

//         for (shared_ptr<Channel> pChannel : vChannels)
//         {
//             // there should be just one brightness channel per fixture
//             if (pChannel->isBrightnessChannel())
//             {
//                 m_u8LastBrightness = pChannel->channelValue();
//                 m_pUniverse->setChannelValue(m_s32Adress, pChannel, m_u8LastBrightness);
//                 break;
//             }
//         }

//         m_bOverrideBrightness = false;
//     }
// } // Fixture::restoreBrightness


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


/*******************************************************************************
* Fixture::updateAllChannelValuesFromUniverse
*******************************************************************************/
// void Fixture::updateAllChannelValuesFromUniverse()
// {
//     const vector<shared_ptr<Channel>>   &vChannel = m_pDevice->channel();

//     // set all channel values to 0
//     for (auto &pChannel : vChannel)
//     {
//         // set the value in the universe
//         m_pUniverse->setChannelValue(m_s32Adress,
//                                      pChannel,
//                                      m_pUniverse->channelValue(m_s32Adress, pChannel->nr()));
//     }
// } // Fixture::updateAllChannelValuesFromUniverse
