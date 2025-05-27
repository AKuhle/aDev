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
#include "aSharedPtrVector.h"
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

        void                                add2Configuration(aJsonFile &_jf);

        const aString&                      name() const                    { return m_sName; }
        void                                setName(const aString &_s)      { m_sName = _s; }

        void                                addFixture(s32                  _s32BankBtnIdx,
                                                       shared_ptr<Fixture>  _pFixture);

        shared_ptr<Fixture>                 fixture(s32 _s32BankBtnIdx) const;

}; // class Bank
