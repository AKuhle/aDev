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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "qLights_defs.h"
#include "bank.h"
#include "fixture.h"

using namespace std;
using namespace aLib::aUtil;


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
* Bank::add2Configuration
*******************************************************************************/
void Bank::add2Configuration(s32        _s32BankBtnIdx,
                             aJsonFile  &_jf)
{
    _jf.openLevel();
        // add controller info
        _jf.add(aJsonValue("bankBtnIdx", (dbl) _s32BankBtnIdx));
        _jf.add(aJsonValue("name", m_sName));

    _jf.closeLevel(aString("bank") + "-" + m_sName);
} // Bank::add2Configuration


/*******************************************************************************
* Bank::addFixture
*******************************************************************************/
void Bank::addFixture(s32                  _s32BankBtnIdx,
                      shared_ptr<Fixture>  _pFixture)
{
    m_mapFixture[_s32BankBtnIdx] = _pFixture;
} // Bank::addFixture


/*******************************************************************************
* Bank::fixture
*******************************************************************************/
shared_ptr<Fixture> Bank::fixture(s32 _s32BankBtnIdx) const
{
    aMap<s32, shared_ptr<Fixture>>::const_iterator it = m_mapFixture.find(_s32BankBtnIdx);

    return (it != m_mapFixture.end())?   it->second : nullptr;
} // Bank::fixture
