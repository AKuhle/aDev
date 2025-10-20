/*******************************************************************************
* \file ChannelBright.h
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
#include "channel.h"


class Universe;

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* class ChannelBright
*******************************************************************************/
class ChannelBright : public Channel
{
    private:

    public:
        ChannelBright(s32             _s32Nr,
                      const QString   &_sName,
                      const QString   &_sPixmapName);

        ~ChannelBright();

        bool                    isBrightnessChannel() const override    { return true; }
}; // class ChannelBright
