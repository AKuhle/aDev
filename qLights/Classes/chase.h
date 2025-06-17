/*******************************************************************************
* \file Chase.h
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
#include "aVector.h"

#include "qLights_defs.h"

class Universe;

using namespace aLib::aUtil;


/*******************************************************************************
* class Chase
*******************************************************************************/
class Chase
{
    private:
        aString                     m_sName;
        aVector<channelValueTuple>  m_vValues;

    public:
        Chase(const aString &_sName);
        ~Chase();

        const aString&                      name() const                    { return m_sName; }

        void                                setName(const aString &_sName)  { m_sName = _sName; }

        void                                add2Configuration(aJsonFile &_jf,
                                                              s32       _idx) const;
}; // class Chase
