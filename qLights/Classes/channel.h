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

using namespace aLib;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel
{
    private:
        s32            m_s32ChannelNr   { -1 };

    public:
        Channel(s32 _s32ChannelNr);
        ~Channel();

        s32             channelNr() const               { return m_s32ChannelNr; }
        void            setChannelNr(s32 _s32ChannelNr) { m_s32ChannelNr = _s32ChannelNr; }

}; // class Channel
