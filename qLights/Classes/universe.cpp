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
  m_u32Id(_u32Id),
  m_dmxData(m_u32DmxDataSize, 0)
{
    shared_ptr<Controller> pC = _pController.lock();

    if (pC)
    {
        m_hostAdr.setAddress(pC->ipAdr());
    }
} // m_artnetPacket::Universe


/*******************************************************************************
* Universe::~Universe
*******************************************************************************/
Universe::~Universe()
{
} // Universe::~Universe


/*******************************************************************************
* Universe::channelValue
*******************************************************************************/
u8 Universe::channelValue(s32  _s32FixtureAdress,
                          s32  _s32ChannelNr) const
{
    // get the channel value
    return m_dmxData[_s32FixtureAdress + _s32ChannelNr-2];
} // Universe::channelValue


/*******************************************************************************
* Universe::setChannelValue
*******************************************************************************/
void Universe::setChannelValue(s32  _s32FixtureAdress,
                               s32  _s32ChannelNr,
                               u8   _u8Value,
                               bool _bSend)
{
    // set the new channel value
    m_dmxData[_s32FixtureAdress + _s32ChannelNr-2] = _u8Value;

    if (_bSend)
    {
        sendValues2Controller();
    } // if (_bSend)
} // Universe::setChannelValue


/*******************************************************************************
* Universe::dmxData
*******************************************************************************/
vector<u8> Universe::dmxData() const
{
    // Anzahl der Elemente berechnen
    size_t count = m_dmxData.size() / sizeof(u8);

    // Vektor mit den Daten füllen
    std::vector<u8> vec(reinterpret_cast<const u8*> (m_dmxData.constData()),
                        reinterpret_cast<const u8*> (m_dmxData.constData()) + count);

    return vec;
} // Universe::dmxData


/*******************************************************************************
* Universe::setDmxData
*******************************************************************************/
void Universe::setDmxData(const vector<u8> &_data,
                          bool             _bSend)
{
    m_dmxData = QByteArray (reinterpret_cast<const char *> (_data.data()), _data.size() * sizeof(u8));

    if (_bSend)
    {
        sendValues2Controller();
    } // if (_bSend)
} // Universe::setDmxData


/*******************************************************************************
* Universe::sendDmxData
*******************************************************************************/
void Universe::sendDmxData() const
{
    sendValues2Controller();
} // Universe::sendDmxData


/*******************************************************************************
* Universe::sendValues2Controller
*******************************************************************************/
void Universe::sendValues2Controller() const
{
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
        artnetPacket.append((char) ((m_u32DmxDataSize >> 8) & 0xFF));   // DMX-Datenlänge (High Byte)
        artnetPacket.append((char) m_u32DmxDataSize & 0xFF);            // DMX-Datenlänge (Low Byte)

        // Füge DMX-Daten zum Paket hinzu
        artnetPacket.append(m_dmxData.left(m_u32DmxDataSize));

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


// /*******************************************************************************
// * Universe::setDmxValues
// *******************************************************************************/
// // void Universe::setDmxValues(const QByteArray &_values,
// //                             bool             _bSend)
// // {
// //     // set the new channel value
// //     m_dmxData = _values;

// //     if (_bSend)
// //     {
// //         sendDmxValues();
// //     } // if (_bSend)
// // } // Universe::setDmxValues


// /*******************************************************************************
// * Universe::sendUniverse
// *******************************************************************************/
// void Universe::sendUniverse()
// {
//     sendDmxValues();

// } // Universe::sendUniverse


// /*******************************************************************************
// * Universe::dmxChannelValue
// *******************************************************************************/
// // u8 Universe::dmxChannelValue(u32   _u32ChannelOs,
// //                              u32   _u32Channel)
// // {
// //     // set the new channel value
// //     u32 uChannel = _u32ChannelOs + _u32Channel - 1;
// //     return m_dmxData[uChannel - 1];
// // } // Universe::dmxChannelValue
