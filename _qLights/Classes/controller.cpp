/*******************************************************************************
* \file Controller.cpp
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
#include "aJsonFile.h"
#include "aJsonValue.h"
#include "controller.h"

#include "universe.h"

using namespace aLib::aUtil;


/*******************************************************************************
* Controller::Controller
*******************************************************************************/
Controller::Controller(const aString &_sName,
                       const aString &_sIpAdr,
                       s32           _s32UniverseMax)
: m_sName(_sName),
  m_sIpAdr(_sIpAdr),
  m_s32UniverseMax(_s32UniverseMax)
{
} // Controller::Controller


/*******************************************************************************
* Controller::~Controller
*******************************************************************************/
Controller::~Controller()
{
} // Controller::~Controller


/*******************************************************************************
* Controller::addUniverse
*******************************************************************************/
void Controller::addUniverse(u32 _u32Id)
{
    if (m_mapUniverse.size() < m_s32UniverseMax)
    {
        m_mapUniverse[_u32Id] = make_shared<Universe> (_u32Id, m_sIpAdr);
    }
} // Controller::addUniverse


/*******************************************************************************
* Controller::setDmxChannelValue
*******************************************************************************/
void Controller::setDmxChannelValue(s32      _s32DmxChannelNr,
                                    s32      _s32UniverseId,
                                    u8       _u8Value,
                                    bool     _bSend)
{
    aMap<u32, shared_ptr<Universe>>::iterator it = m_mapUniverse.find(_s32UniverseId);

    if (it != m_mapUniverse.end())
    {
        it->second->setDmxChannelValue(_s32DmxChannelNr, _u8Value, _bSend);
    }
} // Controller::setDmxChannelValue


/*******************************************************************************
* Controller::sendAllUniverses
*******************************************************************************/
void Controller::sendAllUniverses()
{
    for (auto me : m_mapUniverse)
    {
        me.second->sendValues2Controller();
    }
} // Controller::sendAllUniverses


/*******************************************************************************
* Controller::add2Configuration
*******************************************************************************/
void Controller::add2Configuration(aJsonFile &_jf) const
{
    _jf.openLevel();
        // add controller info
        _jf.add(aJsonValue("name", m_sName));
        _jf.add(aJsonValue("adress", m_sIpAdr));
        _jf.add(aJsonValue("universeMax", (dbl) m_s32UniverseMax));
    _jf.closeLevel(aString("controller") + "-" + m_sName);

    // add universes
    for (auto u : m_mapUniverse)
    {
        u32     u32Id = u.second->id();

        _jf.openLevel();
            _jf.add(aJsonValue("name", m_sName));
            _jf.add(aJsonValue("id", (double) u32Id));
        _jf.closeLevel(aString("universe") + "-" + m_sName + "-" + aString::fromValue(u32Id));
    }
} // Controller::add2Configuration


// /*******************************************************************************
// * Controller::universe
// *******************************************************************************/
// shared_ptr<Universe> Controller::universe(u32 _u32Id)
// {
//     auto it = m_mapUniverse.find(_u32Id);

//     if (it != m_mapUniverse.end())
//     {
//         return it->second;
//     }

//     return nullptr;
// } // Controller::universe


// /*******************************************************************************
// * Controller::sendAllUniverses
// *******************************************************************************/
// void Controller::sendAllUniverses()
// {
//     for (auto &mapEntry : m_mapUniverse)
//     {
//         mapEntry.second->sendUniverse();
//     }
// } // Controller::sendAllUniverses
