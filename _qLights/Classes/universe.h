/*******************************************************************************
* \file universe.h
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
#include <QtNetwork/QUdpSocket>
#include <QByteArray>
#include <QHostAddress>

#include "aLib_def.h"
#include "aString.h"

using namespace aLib;
using namespace aLib::aUtil;
using namespace std;


/*******************************************************************************
* class Universe
*******************************************************************************/
class Universe
{
    private:
        u32                     m_u32Id;

        // artNet
        QHostAddress            m_ipAdr;
        const u16               m_u16Port           { 6454 };
        const u32               m_u32DmxDataSize    { 512 };
        QByteArray              m_dmxData           { m_u32DmxDataSize, 0 };

    public:
        Universe(u32            _u32Id,
                 const aString  &_sIpAdr);
        ~Universe();

        u32                 id() const              { return m_u32Id; }

        void                setDmxChannelValue(s32      _s32DmxChannelNr,
                                               u8       _u8Value,
                                               bool     _bSend);

        void                sendValues2Controller();

        // void                setDmxValues(const QByteArray    &_values,
        //                                  bool                _bSend);

        // u8                  dmxChannelValue(u32   _u32ChannelOs,
        //                                     u32   _u32Channel);
}; // class Universe
