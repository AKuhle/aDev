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
    for (auto pChannel : vChannel)
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
* Fixture::updateBrightness
*******************************************************************************/
void Fixture::updateBrightness(bool _bSend)
{
    const vector<shared_ptr<Channel>>   &vChannel = m_pDevice->channel();

    for (shared_ptr<Channel> pC : vChannel)
    {
        if (pC->isBrightnessChannel())
        {

        }
    }

    if (_bSend)
    {
        m_pUniverse->sendDmxData();
    }
} // Fixture::updateBrightness


/*******************************************************************************
* Fixture::addUniverse
*******************************************************************************/
// void Fixture::addUniverse(u32 _u32Id)
// {
//     if (m_mapUniverse.size() < m_s32UniverseMax)
//     {
//         m_mapUniverse[_u32Id] = make_shared<Universe> (_u32Id, m_sIpAdr);
//     }
// } // Fixture::addUniverse


/*******************************************************************************
* Fixture::setDmxChannelValue
*******************************************************************************/
// void Fixture::setDmxChannelValue(s32      _s32UniverseId,
//                                     s32      _s32DmxChannelNr,
//                                     u8       _u8Value,
//                                     bool     _bSend)
// {
//     aMap<u32, shared_ptr<Universe>>::iterator it = m_mapUniverse.find(_s32UniverseId);

//     if (it != m_mapUniverse.end())
//     {
//         it->second->setDmxChannelValue(_s32DmxChannelNr, _u8Value, _bSend);
//     }
// } // Fixture::setDmxChannelValue


/*******************************************************************************
* Fixture::sendAllUniverses
*******************************************************************************/
// void Fixture::sendAllUniverses()
// {
//     for (auto me : m_mapUniverse)
//     {
//         me.second->sendValues2Fixture();
//     }
// } // Fixture::sendAllUniverses


// /*******************************************************************************
// * Fixture::universe
// *******************************************************************************/
// shared_ptr<Universe> Fixture::universe(u32 _u32Id)
// {
//     auto it = m_mapUniverse.find(_u32Id);

//     if (it != m_mapUniverse.end())
//     {
//         return it->second;
//     }

//     return nullptr;
// } // Fixture::universe


// /*******************************************************************************
// * Fixture::sendAllUniverses
// *******************************************************************************/
// void Fixture::sendAllUniverses()
// {
//     for (auto &mapEntry : m_mapUniverse)
//     {
//         mapEntry.second->sendUniverse();
//     }
// } // Fixture::sendAllUniverses
