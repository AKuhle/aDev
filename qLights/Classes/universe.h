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
#include <QHostAddress>
#include <QTimer>

#include "aFrame_def.h"
#include "qLights_def.h"
#include "aSynchronize.h"

#include "controller.h"

class Channel;
class Fixture;

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace std;


/*******************************************************************************
* class Universe
*
* each universe sends periodically the DMX data, if they have changed.
* Therefor no update call is neccassary. Just set the channel values, and
* it will be updated (sended) within the next refresh (e.b´g. each 100ms)
*******************************************************************************/
class Universe : public QObject
{
    Q_OBJECT

    private:
        using SynchronizedDmxData = aSynchronized<QByteArray>;
        using ExclusiveDmxData = aExclusiveAccessor<SynchronizedDmxData>;
        using SharedDmxData = aSharedAccessor<SynchronizedDmxData>;

        using SynchronizedChangeFlag = aSynchronized<bool>;
        using ExclusiveChangeFlag = aExclusiveAccessor<SynchronizedChangeFlag>;
        using SharedChangeFlag = aSharedAccessor<SynchronizedChangeFlag>;

        QString                 m_sName;
        shared_ptr<Controller>  m_pController;
        u32                     m_u32Id;

        SynchronizedDmxData     m_dmxData;
        SynchronizedChangeFlag  m_SyncDataChaged;

        QTimer                  m_sendTimer;


        // artNet
        QHostAddress            m_hostAdr;
        const u16               m_u16Port           { 6454 };


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

        void                    setDmxValue(s32 _s32FixtureAdress,
                                            s32 _32ChannelNr,
                                            u8  _u8Value);


        QByteArray              dmxDataValue() const;

        void                    setDmxData(const QByteArray &_arData);

        void                    reset();


    private:
        void                    sendValues2Controller() const;

        void                    setDmxChangeFlag(bool _bChanged);
        bool                    isDmxChangeFlag() const;


    private slots:
        void                    onSendTimer();
}; // class Universe
