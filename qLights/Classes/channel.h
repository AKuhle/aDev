/*******************************************************************************
* \file Channel.h
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
#include "aUtil_def.h"
#include "aLib_def.h"
#include "aString.h"

class Controller;

using namespace std;
using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel
{
    private:
        shared_ptr<Controller>  m_pController;
        s32                     m_s32UniverseId         { 0 };
        s32                     m_s32ChannelOs          { -1 };
        s32                     m_s32ChannelNr          { -1 };
        aString                 m_sIcon;
        bool                    m_bBrightness           { false };

        u8                      m_u8Value               { 0 };


    public:
        Channel(shared_ptr<Controller>  _pController,
                s32                     _u32UniverseId,
                s32                     _s32ChannelOs,
                s32                     _s32ChannelNr,
                aString                 _sIcon,
                bool                    _bBrightness);

        ~Channel();

        void                    add2Configuration(aJsonFile &_jf);

        void                    setController(shared_ptr<Controller> _pController)  { m_pController = _pController; }
        shared_ptr<Controller>  controllerIdx() const                               { return m_pController; }

        void                    setUniverseId(s32 &_s32UniverseId)                  { m_s32UniverseId = _s32UniverseId; }
        s32                     universeId() const                                  { return m_s32UniverseId; }

        void                    setChannelOs(s32 _s32ChannelOs)                     { m_s32ChannelOs = _s32ChannelOs; }
        s32                     channelOs() const                                   { return m_s32ChannelOs; }

        void                    setChannelNr(s32 _s32ChannelNr)                     { m_s32ChannelNr = _s32ChannelNr; }
        s32                     channelNr() const                                   { return m_s32ChannelNr; }

        void                    setChannelIcon(const aString &_sIcon)               { m_sIcon = _sIcon; }
        aString                 channelIcon()                                       { return m_sIcon; }

        void                    setBrightness(bool _bBrightness)                    { m_bBrightness = _bBrightness; }
        bool                    isBrightness()                                      { return m_bBrightness; }

        void                    setValue(u8     _u8Value);
        u8                      value()                                             { return m_u8Value; }

        void                    updateDmxValue(u8     _u8Value,
                                               bool   _bSend);

}; // class Channel
