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

class Fixture;

using namespace std;
using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel
{
    private:
        Fixture                 *m_pFixture;
        s32                     m_s32ChannelNr          { -1 };
        aString                 m_sIcon;
        bool                    m_bBrightness           { false };

        u8                      m_u8Value               { 0 };


    public:
        Channel(Fixture     *_pFixture,
                s32         _s32ChannelNr,
                aString     _sIcon,
                bool        _bBrightness);

        ~Channel();

        bool                    isBrightness()              { return m_bBrightness; }

        aString                 icon()                      { return m_sIcon; }

        void                    setValue(u8     _u8Value,
                                         bool   _bSend);

        s32                     channelNr() const           { return m_s32ChannelNr; }
        u8                      value()                     { return m_u8Value; }

        // void                    setChannelNr(s32 _s32ChannelNr)                     { m_s32ChannelNr = _s32ChannelNr; }

        // void                    setChannelIcon(const aString &_sIcon)               { m_sIcon = _sIcon; }
        // aString                 channelIcon()                                       { return m_sIcon; }

        // void                    setBrightness(bool _bBrightness)                    { m_bBrightness = _bBrightness; }

        // void                    updateDmxValue(u8     _u8Value,
                                               // bool   _bSend);

        // void                    add2Configuration(aJsonFile &_jf);

}; // class Channel
