/*******************************************************************************
* \file DmxData.cpp
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
#include "mainWin.h"
#include "dmxData.h"



/*******************************************************************************
* DmxData::DmxData
*******************************************************************************/
DmxData::DmxData()
{
} // DmxData::DmxData


/*******************************************************************************
* DmxData::~DmxData
*******************************************************************************/
DmxData::~DmxData()
{
} // DmxData::~DmxDataV


/*******************************************************************************
* DmxData::setValue
*******************************************************************************/
void DmxData::setValue(s32      _s32DmxIdx,
                       u8       _u8Value,
                       bool     _bBright)
{
    // set the value
    m_arValue[_s32DmxIdx] = _u8Value;

    // set the brightness flag
    m_arBrightFlag[_s32DmxIdx] = (_bBright)?   1 : 0;

    // set the send value
    updateSendValue(_s32DmxIdx);
} // DmxData::setValue


/*******************************************************************************
* DmxData::reset
*******************************************************************************/
void DmxData::reset()
{
    m_arValue.fill(0);
    m_arSend.fill(0);
} // DmxData::reset


/*******************************************************************************
* DmxData::updateBrightness
*******************************************************************************/
void DmxData::updateBrightness()
{
    u32 i;

    for (i = 0; i < DMX_DATA_SIZE; ++i)
    {
        if (m_arBrightFlag.at(i) == 1)
        {
            updateSendValue(i);
        }
    }
} // DmxData::updateBrightness


/*******************************************************************************
* DmxData::setDmxData
*******************************************************************************/
void DmxData::setDmxData(const QByteArray &_arValue)
{
    u32 i;

    m_arValue = _arValue;

    // set all send values
    for (i = 0; i < DMX_DATA_SIZE; ++i)
    {
        updateSendValue(i);
    }
} // DmxData::setDmxData


/*******************************************************************************
* DmxData::updateSendValue
*******************************************************************************/
void DmxData::updateSendValue(s32 _dmxIdx)
{
    // set the send value
    if (m_arBrightFlag.at(_dmxIdx) == 1)
    {
        // brightness channel => send value depends on master brighness
        float   fFactor = static_cast<float> (MainWin::masterBrightness()) / 255.f;
        u8      u8Val   = static_cast<u8> (fFactor * m_arValue.at(_dmxIdx));

        m_arSend[_dmxIdx] = u8Val;
    }
    else
    {
        // no brightness channel => send value == channel value
        m_arSend[_dmxIdx] = m_arValue[_dmxIdx];
    }
} // DmxData::updateSendValue
