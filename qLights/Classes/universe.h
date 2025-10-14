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
#include <QString>

#include "aFrame_def.h"
#include "controller.h"

using namespace aFrame;
using namespace std;


/*******************************************************************************
* class Universe
*******************************************************************************/
class Universe
{
    private:
        QString                 m_sName;
        shared_ptr<Controller>  m_pController;
        u32                     m_u32Id;

        // artNet
        QHostAddress            m_hostAdr;
        const u16               m_u16Port           { 6454 };
        const u32               m_u32DmxDataSize    { 512 };
        QByteArray              m_dmxData           { m_u32DmxDataSize, 0 };

    public:
        Universe(QString                _sName,
                 weak_ptr<Controller>   _pController,
                 u32                    _u32Id);
        ~Universe();

        const QString&          name() const                                { return m_sName; }
        void                    setName(const QString &_sName)              { m_sName = _sName; }

        shared_ptr<Controller>  controller()                                { return m_pController; }
        void                    setController(shared_ptr<Controller> _pC)   { m_pController = _pC; }

        u32                     id() const                                  { return m_u32Id; }
        void                    setId(u32 _u32Id)                           { m_u32Id = _u32Id; }

        u8                      channelValue(s32      _s32FixtureAdress,
                                             s32      _s32ChannelNr) const;

        void                    setChannelValue(s32      _s32FixtureAdress,
                                                s32      _s32ChannelNr,
                                                u8       _u8Value,
                                                bool     _bSend);

        vector<u8>              dmxData() const;
        void                    setDmxData(const vector<u8> &_data,
                                           bool             _bSend);

        void                    sendDmxData() const;

    private:
        void                    sendValues2Controller() const;

        // void                setDmxValues(const QByteArray    &_values,
        //                                  bool                _bSend);

        // u8                  dmxChannelValue(u32   _u32ChannelOs,
        //                                     u32   _u32Channel);
}; // class Universe
