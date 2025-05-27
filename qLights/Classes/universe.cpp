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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "qLights_defs.h"
#include "universe.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* Universe::Universe
*******************************************************************************/
Universe::Universe(u32              _u32Id,
                   const aString    &_sIpAdr)
: m_u32Id(_u32Id),
  m_ipAdr(_sIpAdr.toQString()),
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
* Universe::add2Configuration
*******************************************************************************/
void Universe::add2Configuration(aJsonFile &_jf)
{
    _jf.openLevel();
        // add univers info
        _jf.add(aJsonValue("id", (dbl) m_u32Id));

        // add dmxdata
        _jf.openLevel();
            for (s32 i = 0; i < 512; i++)
            {
                _jf.add(aJsonValue(aString::fromValue(i), (dbl) m_dmxData.at(i)));
            }
        _jf.closeLevel("dmxdata");

    _jf.closeLevel(aString("universe") + "-" + aString::fromValue(m_u32Id));
} // Universe::add2Configuration


/*******************************************************************************
* Universe::setDmxChannelValue
*******************************************************************************/
void Universe::setDmxChannelValue(u32   _u32Channel,
                                  u8    _u8Value,
                                  bool  _bSend)
{
    // set the new channel value
    m_dmxData[_u32Channel - 1] = _u8Value;

    if (_bSend)
    {
        sendDmxValues();
    } // if (_bSend)

} // Universe::setDmxChannelValue


/*******************************************************************************
* Universe::resetUniverse
*******************************************************************************/
void Universe::resetUniverse()
{
    m_dmxData.fill(0);

    sendDmxValues();

} // Universe::resetUniverse


/*******************************************************************************
* Universe::sendDmxValues
*******************************************************************************/
void Universe::sendDmxValues()
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
    artnetPacket.append((char) ((m_u32DmxDataSize >> 8) & 0xFF));   // DMX-Datenlänge (High Byte)
    artnetPacket.append((char) m_u32DmxDataSize & 0xFF);            // DMX-Datenlänge (Low Byte)

    // Füge DMX-Daten zum Paket hinzu
    artnetPacket.append(m_dmxData.left(m_u32DmxDataSize));

    // Senden des Pakets
    qint64 bytesSent = udpSocket.writeDatagram(artnetPacket, m_ipAdr, m_u16Port);

    if (bytesSent == -1)
    {
        //std::cerr << "Fehler beim Senden des Pakets: " << udpSocket.errorString().toStdString() << std::endl;
    }
    else
    {
        //std::cout << "Art-Net-Paket erfolgreich gesendet. Bytes gesendet: " << bytesSent << std::endl;
    }
} // Universe::sendDmxValues


/*******************************************************************************
* Universe::dmxChannelValue
*******************************************************************************/
// u8 Universe::dmxChannelValue(u32   _u32ChannelOs,
//                              u32   _u32Channel)
// {
//     // set the new channel value
//     u32 uChannel = _u32ChannelOs + _u32Channel - 1;
//     return m_dmxData[uChannel - 1];
// } // Universe::dmxChannelValue
