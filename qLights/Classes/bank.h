/*******************************************************************************
* \file bank.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aString.h"
#include "aMap.h"

using namespace std;
using namespace aLib;
using namespace aLib::aUtil;

class Fixture;


/*******************************************************************************
* class Bank
*******************************************************************************/
class Bank
{
    private:
        aString                         m_sName;
        aMap<s32, shared_ptr<Fixture>>  m_mapFixture;

    public:
        Bank(const aString &_sName);
        ~Bank();


        // properties
        const aString&                      name() const                    { return m_sName; }
        void                                setName(const aString &_s)      { m_sName = _s; }


        // fixture
        void                                assignFixture(shared_ptr<Fixture>  _pFixture,
                                                          s32                  _s32FixtureIdx);

        shared_ptr<Fixture>                 fixture(s32 _s32BankBtnIdx) const;

        // void                                add2Configuration(s32       _s32BankBtnIdx,
        //                        aJsonFile &_jf);

}; // class Bank
