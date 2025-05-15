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
        s32             m_s32ChannelNr      { -1 };
        aString         m_sIcon;

    public:
        Channel(s32 _s32ChannelNr);
        ~Channel();

        s32             channelNr() const                       { return m_s32ChannelNr; }
        void            setChannelNr(s32 _s32ChannelNr)         { m_s32ChannelNr = _s32ChannelNr; }

        void            setChannelIcon(const aString &_sIcon)   { m_sIcon = _sIcon; }
        aString         channelIcon()                           { return m_sIcon; }
}; // class Channel
