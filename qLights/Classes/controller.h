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
#include "aFrame_def.h"
#include "aString.h"
#include "aMap.h"


class Universe;

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* class Controller
*******************************************************************************/
class Controller
{
    private:
        aString                         m_sName;
        aString                         m_sIpAdr;

        //aMap<u32, shared_ptr<Universe>> m_mapUniverse;

    public:
        Controller(const aString &_sName,
                   const aString &_sIpAdr);
        ~Controller();

        const aString&                      name() const                        { return m_sName; }
        void                                setName(const aString &_sName)      { m_sName = _sName; }

        const aString&                      ipAdr() const                       { return m_sIpAdr; }
        void                                setIpAdr(const aString &_sIpAdr)    { m_sIpAdr = _sIpAdr; }

        //void                                addUniverse(u32 _u32Id);

        // void                                setDmxChannelValue(s32      _s32UniverseId,
        //                                                        s32      _s32DmxChannelNr,
        //                                                        u8       _u8Value,
        //                                                        bool     _bSend);

        //void                                sendAllUniverses();

        //shared_ptr<Universe>                universe(u32 _u32Id);

        //void                                resetAllUniverses();
}; // class Controller
