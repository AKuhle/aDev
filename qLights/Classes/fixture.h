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
#include "aSharedPtrVector.h"

#include "qLights_defs.h"


class Controller;
class Universe;
class Channel;
class Bank;

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
        shared_ptr<Controller>          m_pController;
        s32                             m_s32UniverseId     { -1 };
        s32                             m_s32ChannelOs      { -1 };

        aMap<s32, shared_ptr<Channel>>  m_mapAllChannel;
        aSharedPtrVector<Channel>       m_vBrightnessChannel;

    public:
        Fixture(const aString           &_sName,
                shared_ptr<Controller>  _pController,
                s32                     _s32UniverseId,
                s32                     _s32ChannelOs);

        ~Fixture();

        const aString&          name() const                    { return m_sName; }
        shared_ptr<Controller>  controller() const              { return m_pController; }
        s32                     universeId() const              { return m_s32UniverseId; }
        s32                     channelOs() const               { return m_s32ChannelOs; }

        void                    addChannel(s32      _s32ChannelNr,
                                           aString  _sIcon,
                                           bool     _bBrightness);

        shared_ptr<Channel>     channel(s32 _s32ChannelNr) const;

        void                    setChannelValue(s32     _s32ChannelNr,
                                                u8      _u8Value,
                                                bool    _bSend);

        void                    resetAllChannels();

        void                    collectChannels(aVector<shared_ptr<Channel>> &_vChannel);

        // void                    allChannelValues(aVector<channelValueTuple> &vValues) const;
        // void                    allChannels(aVector<shared_ptr<Channel>> &_vChannel) const;

        void                    add2Configuration(aJsonFile &_jf) const;

}; // class Fixture
