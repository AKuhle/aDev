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
* Bank::assignFixture
*******************************************************************************/
void Bank::assignFixture(shared_ptr<Fixture>  _pFixture,
                         s32                  _s32FixtureIdx)
{
    m_mapFixture[_s32FixtureIdx] = _pFixture;
} // Bank::assignFixture


/*******************************************************************************
* Bank::fixture
*******************************************************************************/
shared_ptr<Fixture> Bank::fixture(s32 _s32FixtureIdx) const
{
    aMap<s32, shared_ptr<Fixture>>::const_iterator it = m_mapFixture.find(_s32FixtureIdx);

    return (it != m_mapFixture.end())?   it->second : nullptr;
} // Bank::fixture


/*******************************************************************************
* Bank::add2Configuration
*******************************************************************************/
void Bank::add2Configuration(aJsonFile  &_jf,
                             s32        _s32BankBtnIdx) const
{
    _jf.openLevel();
        // add bank info
        _jf.add(aJsonValue("name", m_sName));
        _jf.add(aJsonValue("bankBtnIdx", (dbl) _s32BankBtnIdx));

        // add the fixures
        for (const auto &me : m_mapFixture)
        {
            _jf.openLevel();
                _jf.add(aJsonValue("bankName", m_sName));
                _jf.add(aJsonValue("fixtureName", me.second->name()));
                _jf.add(aJsonValue("fixtureBtnIdx", (double) me.first));
            _jf.closeLevel(aString("fixture") + "-" + me.second->name());
        }

    _jf.closeLevel(aString("bank") + "-" + m_sName);
} // Bank::add2Configuration
