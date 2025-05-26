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
void Bank::addFixture(s32                  _s32FixtureBtnIdx,
                      shared_ptr<Fixture>  _pFixture)
{
    m_mapFixture[_s32FixtureBtnIdx] = _pFixture;
} // Bank::addFixture


/*******************************************************************************
* Bank::fixture
*******************************************************************************/
shared_ptr<Fixture> Bank::fixture(s32 _s32FixtureBtnIdx) const
{
    aMap<s32, shared_ptr<Fixture>>::const_iterator it = m_mapFixture.find(_s32FixtureBtnIdx);

    return (it != m_mapFixture.end())?   it->second : nullptr;
} // Bank::fixture
