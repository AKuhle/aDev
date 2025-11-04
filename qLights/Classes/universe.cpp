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
#include "channel.h"
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
* Universe::attachFixture
*******************************************************************************/
void Universe::attachFixture(shared_ptr<Fixture> _pFixture)
{
    shared_ptr<Device>                  pDevice = _pFixture->device();
    CHECK_PRE_CONDITION_VOID(pDevice);

    vector<shared_ptr<Channel>>   vChannel = pDevice->channel();

    for (shared_ptr<Channel> &c : vChannel)
    {
        setChannelValue(_pFixture->adress(), c, 0);
    }
} // Universe::attachFixture


/*******************************************************************************
* Universe::setChannelValue
*******************************************************************************/
void Universe::setChannelValue(s32                  _s32FixtureAdress,
                               shared_ptr<Channel>  _pChannel,
                               u8                   _u8Value)
{
    s32     dmxIdx = _s32FixtureAdress + _pChannel->nr() - 2;
    bool    bBright = _pChannel->isBrightnessChannel();

    // set the new channel value
    _pChannel->setChannelValue(_u8Value);

    // set the value in the dmx-arrays
    {
        ExclusiveDmxData dmxData(m_dmxData);

        dmxData->setValue(dmxIdx, _u8Value, bBright);

        // dmx data ere beeing changed
        setDmxChangeFlag(true);
    }

} // Universe::setChannelValue


/*******************************************************************************
* Universe::channelValue
*******************************************************************************/
u8 Universe::channelValue(s32    _s32FixtureAdress,
                          s32    _s32ChannelNr) const
{
    s32     dmxIdx = _s32FixtureAdress +_s32ChannelNr - 2;
    u8      u8Value;

    {
        SharedDmxData dmxData(m_dmxData);
        u8Value = dmxData->value(dmxIdx);
    }

    return u8Value;
} // Universe::channelValue


/*******************************************************************************
* Universe::dmxDataValue
*******************************************************************************/
QByteArray Universe::dmxDataValue() const
{
    SharedDmxData dmxData(m_dmxData);

    return dmxData->dmxDataValue();
} // Universe::dmxDataValue


/*******************************************************************************
* Universe::setDmxData
*******************************************************************************/
void Universe::setDmxData(const QByteArray  &_arData)
{
    ExclusiveDmxData dmxData(m_dmxData);

    dmxData->setDmxData(_arData);

    // dmx data ere beeing changed
    setDmxChangeFlag(true);
} // Universe::setDmxData


/*******************************************************************************
* Universe::reset
*******************************************************************************/
void Universe::reset()
{
    ExclusiveDmxData dmxData(m_dmxData);

    dmxData->reset();

    // dmx data ere beeing changed
    setDmxChangeFlag(true);
} // Universe::reset


/*******************************************************************************
* Universe::updateBrightness
*******************************************************************************/
void Universe::updateBrightness()
{
    ExclusiveDmxData dmxData(m_dmxData);

    dmxData->updateBrightness();

    // dmx data ere beeing changed
    setDmxChangeFlag(true);
} // Universe::updateBrightness


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

            artnetPacket.append(dmxData->dmxDataSend().left(DMX_DATA_SIZE));
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
