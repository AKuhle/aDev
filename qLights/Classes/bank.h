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

using namespace aLib::aUtil;


/*******************************************************************************
* class Bank
*******************************************************************************/
class Bank
{
    private:
        aString         m_sName;

    public:
        Bank(const aString &_sName);
        ~Bank();

        const aString&      name() const                    { return m_sName; }
        void                setName(const aString &_s)      { m_sName = _s; }

}; // class Bank
