/*******************************************************************************
* \file DmxData.h
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
#include "aFrame_def.h"
#include "qLights_def.h"

using namespace std;
using namespace aFrame;


/*******************************************************************************
* class DmxData
*******************************************************************************/
class DmxData
{
    private:
        QByteArray              m_arValue       { DMX_DATA_SIZE, 0 };
        QByteArray              m_arSend        { DMX_DATA_SIZE, 0 };
        QByteArray              m_arBrightFlag  { DMX_DATA_SIZE, 0 };

    public:
        DmxData();
        ~DmxData();

        void                        setValue(s32    _s32DmxIdx,
                                             u8     _u8Value,
                                             bool   _bBright);

        void                        reset();

        void                        updateBrightness();

        const QByteArray&           dmxDataValue() const    { return  m_arValue; }
        const QByteArray&           dmxDataSend() const     { return  m_arSend; }

        void                        setDmxData(const QByteArray &_arValue);

    private:
        void                        updateSendValue(s32 _dmxIdx);

}; // class DmxData
