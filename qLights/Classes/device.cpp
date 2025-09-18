/*******************************************************************************
* \file Device.cpp
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
#include "Device.h"
#include "universe.h"

using namespace aFrame;


/*******************************************************************************
* Device::Device
*******************************************************************************/
Device::Device(const QString &_sName)
: m_sName(_sName)
{
} // Device::Device


/*******************************************************************************
* Device::~Device
*******************************************************************************/
Device::~Device()
{
} // Device::~Device


/*******************************************************************************
* Device::addUniverse
*******************************************************************************/
// void Device::addUniverse(u32 _u32Id)
// {
//     if (m_mapUniverse.size() < m_s32UniverseMax)
//     {
//         m_mapUniverse[_u32Id] = make_shared<Universe> (_u32Id, m_sIpAdr);
//     }
// } // Device::addUniverse


/*******************************************************************************
* Device::setDmxChannelValue
*******************************************************************************/
// void Device::setDmxChannelValue(s32      _s32UniverseId,
//                                     s32      _s32DmxChannelNr,
//                                     u8       _u8Value,
//                                     bool     _bSend)
// {
//     aMap<u32, shared_ptr<Universe>>::iterator it = m_mapUniverse.find(_s32UniverseId);

//     if (it != m_mapUniverse.end())
//     {
//         it->second->setDmxChannelValue(_s32DmxChannelNr, _u8Value, _bSend);
//     }
// } // Device::setDmxChannelValue


/*******************************************************************************
* Device::sendAllUniverses
*******************************************************************************/
// void Device::sendAllUniverses()
// {
//     for (auto me : m_mapUniverse)
//     {
//         me.second->sendValues2Device();
//     }
// } // Device::sendAllUniverses


// /*******************************************************************************
// * Device::universe
// *******************************************************************************/
// shared_ptr<Universe> Device::universe(u32 _u32Id)
// {
//     auto it = m_mapUniverse.find(_u32Id);

//     if (it != m_mapUniverse.end())
//     {
//         return it->second;
//     }

//     return nullptr;
// } // Device::universe


// /*******************************************************************************
// * Device::sendAllUniverses
// *******************************************************************************/
// void Device::sendAllUniverses()
// {
//     for (auto &mapEntry : m_mapUniverse)
//     {
//         mapEntry.second->sendUniverse();
//     }
// } // Device::sendAllUniverses
