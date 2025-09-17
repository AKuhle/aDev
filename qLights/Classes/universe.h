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

#include "aFrame_def.h"
#include "aString.h"
#include "controller.h"

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace std;


/*******************************************************************************
* class Universe
*******************************************************************************/
class Universe
{
    private:
        aString                 m_sName;
        u32                     m_u32Id;
        weak_ptr<Controller>    m_pController;

        // artNet
        QHostAddress            m_hostAdr;
        const u16               m_u16Port           { 6454 };
        const u32               m_u32DmxDataSize    { 512 };
        QByteArray              m_dmxData           { m_u32DmxDataSize, 0 };

    public:
        Universe(aString                m_sName,
                 u32                    _u32Id,
                 weak_ptr<Controller>   _pController);
        ~Universe();

        const aString&      name() const                        { return m_sName; }
        void                setName(const aString &_sName)      { m_sName = _sName; }

        u32                 id() const                          { return m_u32Id; }

        const Controller*   controller() const                  { return m_pController.lock().get(); }

        void                setDmxChannelValue(s32      _s32DmxChannelNr,
                                               u8       _u8Value,
                                               bool     _bSend);

        void                sendValues2Controller();

        // void                setDmxValues(const QByteArray    &_values,
        //                                  bool                _bSend);

        // u8                  dmxChannelValue(u32   _u32ChannelOs,
        //                                     u32   _u32Channel);
}; // class Universe
