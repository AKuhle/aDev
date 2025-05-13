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
#include "qLights_defs.h"
#include "universe.h"

using namespace std;


/*******************************************************************************
* Universe::Universe
*******************************************************************************/
Universe::Universe(u32 _u32Id)
: m_u32Id(_u32Id),
  m_targetAddress("192.168.1.245"),
  m_dmxData(m_u32DmxDataSize, 0)
{
} // m_artnetPacket::Universe


/*******************************************************************************
* Universe::~Universe
*******************************************************************************/
Universe::~Universe()
{
} // Universe::~Universe


/*******************************************************************************
* Universe::bankCount
*******************************************************************************/
u32 Universe::bankCount() const
{
    return m_vBank.size();
} // Universe::bankCount


/*******************************************************************************
* Universe::addBank
*******************************************************************************/
void Universe::addBank(const aString &_sName)
{
    if (m_vBank.size() < (s32) BANK_COUNT)
    {
        m_vBank.push_back(make_shared<Bank> (_sName));
    }
} // Universe::addBank


/*******************************************************************************
* Universe::bank
*******************************************************************************/
shared_ptr<Bank> Universe::bank(u32 _u32Idx) const
{
    return (_u32Idx < (u32) m_vBank.size())?   m_vBank.at(_u32Idx) : nullptr;
} // Universe::bank


/*******************************************************************************
* Universe::setDmxChannel
*******************************************************************************/
void Universe::setDmxChannel(u32   _u32Channel,
                             char  _cValue)
{
    QUdpSocket      udpSocket;
    QByteArray      artnetPacket;
    u32             u32ChannelOs    = 17;
    u32             uChannel = u32ChannelOs + _u32Channel - 1;

    artnetPacket.append("Art-Net");               // Protokollkennung
    artnetPacket.append('\0');                    // Nullterminierung
    artnetPacket.append((char) 0x00);                    // OpCode (Low Byte)
    artnetPacket.append((char) 0x50);                    // OpCode (High Byte) -> ArtDMX
    artnetPacket.append((char) 0x00);                    // Protokollversion (High Byte)
    artnetPacket.append((char) 0x0E);                    // Protokollversion (Low Byte)
    artnetPacket.append((char) 0x00);                    // Sequence (0 = keine Synchronisation)
    artnetPacket.append((char) 0x00);                    // Physical (nicht verwendet)
    artnetPacket.append((char) (m_u32Id & 0xFF));         // Universum (Low Byte)
    artnetPacket.append((char) ((m_u32Id >> 8) & 0xFF));  // Universum (High Byte)
    artnetPacket.append((char) ((m_u32DmxDataSize >> 8) & 0xFF));                    // DMX-Datenlänge (High Byte)
    artnetPacket.append((char) m_u32DmxDataSize & 0xFF);                    // DMX-Datenlänge (Low Byte)

    // DMX-Daten (512 Kanäle, initialisiert mit 0)
    m_dmxData[uChannel - 1] = _cValue;
    cout << "channel:" << uChannel << ", value:" << _cValue << endl;

    // Füge DMX-Daten zum Paket hinzu
    artnetPacket.append(m_dmxData.left(m_u32DmxDataSize));

    // Senden des Pakets
    qint64 bytesSent = udpSocket.writeDatagram(artnetPacket, m_targetAddress, m_u16Port);

    if (bytesSent == -1) {
        std::cerr << "Fehler beim Senden des Pakets: " << udpSocket.errorString().toStdString() << std::endl;
    } else {
        std::cout << "Art-Net-Paket erfolgreich gesendet. Bytes gesendet: " << bytesSent << std::endl;
    }
} // Universe::setDmxChannel
