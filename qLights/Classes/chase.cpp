/*******************************************************************************
* \file Chase.cpp
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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "chase.h"


/*******************************************************************************
* Chase::Chase
*******************************************************************************/
Chase::Chase(const aString                     &_sName)
: m_sName(_sName)
{
} // Chase::Chase


/*******************************************************************************
* Chase::~Chase
*******************************************************************************/
Chase::~Chase()
{
} // Chase::~Chase


/*******************************************************************************
* Chase::add2Configuration
*******************************************************************************/
void Chase::add2Configuration(aJsonFile     &/*_jf*/,
                              s32           /*_idx*/) const
{
    // _jf.openLevel();
    //     // add Chase info
    //     _jf.add(aJsonValue("idx", (dbl) _idx));
    //     _jf.add(aJsonValue("ChaseName", m_sName));

    //     // add the channels
    //     for (const channelValueTuple &t : m_vValues)
    //     {
    //         shared_ptr<Channel> pChannel        = std::get<0> (t);
    //         u8                  u8Value         = std::get<1> (t);

    //         aString             sFixName        = pChannel->fixture()->name();
    //         s32                 s32ChannelNr    = pChannel->channelNr();

    //         _jf.openLevel();
    //             _jf.add(aJsonValue("ChaseName", m_sName));
    //             _jf.add(aJsonValue("fixtureName", sFixName));
    //             _jf.add(aJsonValue("channelNr", (dbl) s32ChannelNr));
    //             _jf.add(aJsonValue("value", (dbl) u8Value));
    //         _jf.closeLevel(aString("channel") + "-" + sFixName + "-" + aString::fromValue(s32ChannelNr));
    //     }
    // _jf.closeLevel(aString("Chase") + "-" + m_sName);
} // Chase::add2Configuration
