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

#include "aFrame_def.h"
#include "controller.h"
#include "dmxData.h"

class Channel;
class Fixture;

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
        DmxData                 m_dmxData;

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

        void                    attachFixture(shared_ptr<Fixture> _pFixture);

        void                    setChannelValue(s32                 _s32FixtureAdress,
                                                shared_ptr<Channel> _pChannel,
                                                u8                  _u8Value,
                                                bool                _bSend);

        const QByteArray&       dmxDataValue() const                        { return m_dmxData.dmxDataValue(); }

        // void                    dmxData(vector<u8> &_vData,
        //                                 vector<u8> &_vBright) const;

        void                    setDmxData(const QByteArray &_arData,
                                           bool             _bSend);

        void                    sendDmxData() const;

        void                    reset(bool _bSend);

        void                    updateBrightness(bool _bSend);

    private:
        void                    sendValues2Controller() const;
}; // class Universe
