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
#include "aUtil_def.h"
#include "aLib_def.h"
#include "aString.h"


using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel
{
    private:
        s32             m_s32ChannelNr          { -1 };
        s32             m_s32ChannelOs          { -1 };
        s32             m_s32ControllerIdx      { -1 };
        u32             m_u32UniverseId         { 0 };
        bool            m_bBrightness           { false };
        aString         m_sIcon;
        u8              m_u8Value               { 0 };

    public:
        Channel(s32         _s32ChannelNr,
                s32         _s32ChannelOs,
                s32         _s32ControllerIdx,
                u32         _u32UniverseId,
                bool        _bBrightness,
                aString     _sIcon);

        ~Channel();

        void            setChannelNr(s32 _s32ChannelNr)         { m_s32ChannelNr = _s32ChannelNr; }
        s32             channelNr() const                       { return m_s32ChannelNr; }

        void            setChannelOs(s32 _s32ChannelOs)         { m_s32ChannelOs = _s32ChannelOs; }
        s32             channelOs() const                       { return m_s32ChannelOs; }

        void            setControllerIdx(s32 &_controllerIdx)   { m_s32ControllerIdx = _controllerIdx; }
        s32             controllerIdx() const                   { return m_s32ControllerIdx; }

        void            setUniverseId(u32 &_u32UniverseId)      { m_u32UniverseId = _u32UniverseId; }
        u32             universeId() const                      { return m_u32UniverseId; }

        void            setBrightness(bool _bBrightness)        { m_bBrightness = _bBrightness; }
        bool            isBrightness()                          { return m_bBrightness; }

        void            setChannelIcon(const aString &_sIcon)   { m_sIcon = _sIcon; }
        aString         channelIcon()                           { return m_sIcon; }

        void            setValue(u8 _u8Value)                   { m_u8Value = _u8Value; }
        u8              value()                                 { return m_u8Value; }
}; // class Channel
