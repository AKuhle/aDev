/*******************************************************************************
* \file bank.cpp
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
#include "qLights_defs.h"
#include "bank.h"
#include "fixture.h"


/*******************************************************************************
* Bank::Bank
*******************************************************************************/
Bank::Bank(const aString &_sName)
: m_sName(_sName)
{
} // Bank::Bank


/*******************************************************************************
* Bank::~Bank
*******************************************************************************/
Bank::~Bank()
{
} // Bank::~Bank


/*******************************************************************************
* Bank::addFixture
*******************************************************************************/
void Bank::addFixture(const aString   &_sName,
                      s32             _s32ControllerIdx,
                      s32             _s32UniverseId,
                      s32             _s32ChannelOs)
{
    if (m_vFixture.size() < FIXTURE_MAX)
    {
        m_vFixture.push_back (make_shared<Fixture> (_sName,
                                                    _s32ControllerIdx,
                                                    _s32UniverseId,
                                                    _s32ChannelOs));
    }
} // Bank::addFixture


/*******************************************************************************
* Bank::fixture
*******************************************************************************/
shared_ptr<Fixture> Bank::fixture(s32 _idx) const
{
    if (m_vFixture.size() > _idx)
    {
        return m_vFixture.at(_idx);
    }

    return nullptr;
} // Bank::fixture


/*******************************************************************************
* Bank::resetAll
*******************************************************************************/
void Bank::resetAll()
{
    for (shared_ptr<Fixture> &pFix : m_vFixture)
    {
        pFix->resetAll();
    }
} // Bank::resetAll
