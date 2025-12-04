/*******************************************************************************
* \file universe.cpp
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
#include "universe.h"
#include "aString.h"
#include "channelDevice.h"
#include "mainWin.h"
#include "fixture.h"

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* Universe::Universe
*******************************************************************************/
Universe::Universe(QString                _sName,
                   weak_ptr<Controller>   _pController,
                   u32                    _u32Id)
: m_sName(_sName),
  m_pController(_pController),
  m_u32Id(_u32Id)
{
    shared_ptr<Controller> pC = _pController.lock();

    if (pC)
    {
        m_hostAdr.setAddress(pC->ipAdr());
    }

    // initialize the byte array
    {
        ExclusiveDmxData dmxData(m_dmxData);
        dmxData->fill(0, DMX_DATA_SIZE);
    }


    // set the data changed flag to false
    setDmxChangeFlag(false);

    // start the send timer
    connect(&m_sendTimer, &QTimer::timeout, this, &Universe::onSendTimer);
    m_sendTimer.start(UNIVERSE_UPDATE_TIME_MS);
} // m_artnetPacket::Universe


/*******************************************************************************
* Universe::~Universe
*******************************************************************************/
Universe::~Universe()
{
} // Universe::~Universe


/*******************************************************************************
* Universe::setDmxValue
*******************************************************************************/
void Universe::setDmxValue(s32  _s32FixtureAdress,
                           s32  _32ChannelNr,
                           u8   _u8Value)
{
    s32     dmxIdx = _s32FixtureAdress + _32ChannelNr - 2;

    // set the value in the dmx-arrays
    {
        ExclusiveDmxData dmxData(m_dmxData);
        (*dmxData)[dmxIdx] = _u8Value;

        // dmx data ere beeing changed
        setDmxChangeFlag(true);
    }

} // Universe::setDmxValue


/*******************************************************************************
* Universe::dmxDataValue
*******************************************************************************/
QByteArray Universe::dmxDataValue() const
{
    SharedDmxData dmxData(m_dmxData);

    return *dmxData;
} // Universe::dmxDataValue


/*******************************************************************************
* Universe::setDmxData
*******************************************************************************/
void Universe::setDmxData(const QByteArray  &_arData)
{
    ExclusiveDmxData dmxData(m_dmxData);

    *dmxData = _arData;

    // dmx data ere beeing changed
    setDmxChangeFlag(true);
} // Universe::setDmxData


/*******************************************************************************
* Universe::reset
*******************************************************************************/
void Universe::reset()
{
    ExclusiveDmxData dmxData(m_dmxData);

    dmxData->fill(0);

    // dmx data ere beeing changed
    setDmxChangeFlag(true);
} // Universe::reset


/*******************************************************************************
* Universe::sendValues2Controller
*******************************************************************************/
void Universe::sendValues2Controller() const
{
    return;

    if (!m_hostAdr.isNull())
    {
        QUdpSocket      udpSocket;
        QByteArray      artnetPacket;

        artnetPacket.append("Art-Net");                                 // Protokollkennung
        artnetPacket.append('\0');                                      // Nullterminierung
        artnetPacket.append((char) 0x00);                               // OpCode (Low Byte)
        artnetPacket.append((char) 0x50);                               // OpCode (High Byte) -> ArtDMX
        artnetPacket.append((char) 0x00);                               // Protokollversion (High Byte)
        artnetPacket.append((char) 0x0E);                               // Protokollversion (Low Byte)
        artnetPacket.append((char) 0x00);                               // Sequence (0 = keine Synchronisation)
        artnetPacket.append((char) 0x00);                               // Physical (nicht verwendet)
        artnetPacket.append((char) (m_u32Id & 0xFF));                   // Universum (Low Byte)
        artnetPacket.append((char) ((m_u32Id >> 8) & 0xFF));            // Universum (High Byte)
        artnetPacket.append((char) ((DMX_DATA_SIZE >> 8) & 0xFF));      // DMX-Datenlänge (High Byte)
        artnetPacket.append((char) DMX_DATA_SIZE & 0xFF);               // DMX-Datenlänge (Low Byte)

        // Füge DMX-Daten zum Paket hinzu
        {
            SharedDmxData dmxData(m_dmxData);

            artnetPacket.append(dmxData->left(DMX_DATA_SIZE));
        }

        // Senden des Pakets
        qint64 bytesSent = udpSocket.writeDatagram(artnetPacket, m_hostAdr, m_u16Port);

        if (bytesSent == -1)
        {
            std::cerr << "Fehler beim Senden des Pakets: " << udpSocket.errorString().toStdString() << std::endl;
        }
        else
        {
           //std::cout << "Art-Net-Paket erfolgreich gesendet. Bytes gesendet: " << bytesSent << std::endl;
        }

    } // if...

} // Universe::sendValues2Controller


/*******************************************************************************
* Universe::setDmxChangeFlag
*******************************************************************************/
void Universe::setDmxChangeFlag(bool _bChanged)
{
    // reset the changed flag
    {
        ExclusiveChangeFlag bSync(m_SyncDataChaged);
        *bSync = _bChanged;
    }
} // Universe::setDmxChangeFlag


/*******************************************************************************
* Universe::isDmxChangeFlag
*******************************************************************************/
bool Universe::isDmxChangeFlag() const
{
    SharedChangeFlag bSync(m_SyncDataChaged);

    return bSync.get();
} // Universe::isDmxChangeFlag


/*******************************************************************************
* Universe::onSendTimer
*******************************************************************************/
void Universe::onSendTimer()
{
    if (isDmxChangeFlag())
    {
        sendValues2Controller();

        // reset the changed flag
        setDmxChangeFlag(false);
    }
} // Universe::onSendTimer
