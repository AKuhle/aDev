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
#include "Fixture.h"
#include "universe.h"
#include "device.h"

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
} // Fixture::Fixture


/*******************************************************************************
* Fixture::~Fixture
*******************************************************************************/
Fixture::~Fixture()
{
} // Fixture::~Fixture


/*******************************************************************************
* Fixture::resetFixture
*******************************************************************************/
void Fixture::resetFixture(bool _bSend)
{
    const vector<shared_ptr<Channel>>   &vChannel = m_pDevice->channel();

    // set all channel values to 0
    for (auto &pChannel : vChannel)
    {
        // set the value in the universe
        m_pUniverse->setChannelValue(m_s32Adress,
                                     pChannel,
                                     (u8) 0,
                                     false);
    }

    if (_bSend)
    {
        m_pUniverse->sendDmxData();
    }

} // Fixture::resetFixture


/*******************************************************************************
* Fixture::updateAllChannelValuesFromUniverse
*******************************************************************************/
void Fixture::updateAllChannelValuesFromUniverse()
{
    const vector<shared_ptr<Channel>>   &vChannel = m_pDevice->channel();

    // set all channel values to 0
    for (auto &pChannel : vChannel)
    {
        // set the value in the universe
        m_pUniverse->setChannelValue(m_s32Adress,
                                     pChannel,
                                     m_pUniverse->channelValue(m_s32Adress, pChannel->nr()),
                                     false);
    }
} // Fixture::updateAllChannelValuesFromUniverse
