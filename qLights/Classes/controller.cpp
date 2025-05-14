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
#include "controller.h"
#include "universe.h"


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
* Controller::universe
*******************************************************************************/
shared_ptr<Universe> Controller::universe(u32 _u32Id)
{
    auto it = m_mapUniverse.find(_u32Id);

    if (it != m_mapUniverse.end())
    {
        return it->second;
    }

    return nullptr;
} // Controller::universe
