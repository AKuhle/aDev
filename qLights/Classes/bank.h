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
        aString                     m_sName;
        aSharedPtrVector<Fixture>   m_vFixture;

    public:
        Bank(const aString &_sName);
        ~Bank();

        const aString&                      name() const                    { return m_sName; }
        void                                setName(const aString &_s)      { m_sName = _s; }

        void                                addFixture(const aString   &_sName,
                                                       s32             _s32ControllerIdx,
                                                       s32             _s32UniverseId,
                                                       s32             _s32ChannelOs);

        const aSharedPtrVector<Fixture>&    fixtures() const { return m_vFixture; }
        shared_ptr<Fixture>                 fixture(s32 _idx) const;

        void                                resetAll();
}; // class Bank
