/*******************************************************************************
* \file Channel.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "Channel.h"
#include "universe.h"

using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* Channel::Channel
*******************************************************************************/
Channel::Channel(s32            _s32Nr,
                 const QString  &_sName,
                 const QString  &_sPixmapName,
                 bool           _bBright)
: ChannelDevice(_s32Nr, _sName, _sPixmapName, _bBright)
{
} // Channel::Channel


/*******************************************************************************
* Channel::~Channel
*******************************************************************************/
Channel::~Channel()
{
} // Channel::~ChannelV
