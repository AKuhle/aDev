/*******************************************************************************
* \file fixture.h
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

class Controller;
class Universe;
class Channel;

using namespace std;
using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* class Fixture
*******************************************************************************/
class Fixture
{
    private:
        aString                         m_sName;
        s32                             m_s32ControllerIdx  { -1 };
        s32                             m_s32UniverseId     { -1 };
        s32                             m_s32ChannelOs      { -1 };

        aMap<s32, shared_ptr<Channel>>  m_mapChannel;

    public:
        Fixture(const aString   &_sName,
                s32             _s32ControllerIdx,
                s32             _s32UniverseId,
                s32             _s32ChannelOs);
        ~Fixture();

        const aString&          name() const                    { return m_sName; }
        void                    setName(const aString &_sName)  { m_sName = _sName; }

        void                    addChannel(s32      _s32ChannelNr,
                                           s32      _s32FaderIdx,
                                           aString  _sChannelIcon);

        shared_ptr<Channel>     channel(s32 _s32FaderIdx) const;

        s32                     controllerIdx() const           { return m_s32ControllerIdx; }
        s32                     universeId() const              { return m_s32UniverseId; }
        s32                     channelOs() const               { return m_s32ChannelOs; }
}; // class Fixture
