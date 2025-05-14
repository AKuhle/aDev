/*******************************************************************************
* \file Controller.h
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
#include "aLib_def.h"
#include "aSharedPtrVector.h"
#include "aString.h"
#include "aMap.h"

class Universe;

using namespace std;
using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* class Controller
*******************************************************************************/
class Controller
{
    private:
        aString                         m_sName;
        aString                         m_sIpAdr;
        s32                             m_s32UniverseMax;

        aMap<u32, shared_ptr<Universe>> m_mapUniverse;
        s32                             m_s32ActiveUniverseIdx  { -1 };

    public:
        Controller(const aString &_sName,
                   const aString &_sIpAdr,
                   s32           _s32UniverseMax);
        ~Controller();

        const aString&                      name() const                        { return m_sName; }
        void                                setName(const aString &_sName)      { m_sName = _sName; }

        const aString&                      ipAdr() const                       { return m_sIpAdr; }
        void                                setIpAdr(const aString &_sIpAdr)    { m_sIpAdr = _sIpAdr; }

        void                                addUniverse(u32 _u32Id);
        shared_ptr<Universe>                universe(u32 _u32Id);

}; // class Controller
