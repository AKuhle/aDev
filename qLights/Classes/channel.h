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
#include "channelDevice.h"


class Universe;

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel : public ChannelDevice
{
    friend class Fixture;

    private:
        u8          m_u8Value       { 0 };

    public:
        Channel(s32             _s32Nr,
                const QString   &_sName,
                const QString   &_sPixmapName,
                bool            _bBright);

        ~Channel();

        u8                              channelValue() const        { return m_u8Value; }

    private:
        // can only be set via fixture
        void                            setChannelValue(u8 _value)  { m_u8Value = _value; }
}; // class Channel
