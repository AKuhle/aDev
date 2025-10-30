/*******************************************************************************
* \file Channel.h
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
#include "aString.h"
#include <QPixmap>


class Universe;

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


/*******************************************************************************
* class Channel
*******************************************************************************/
class Channel
{
    friend class Universe;

    private:
        s32         m_s32Nr         { -1 };
        QString     m_sName;
        QString     m_sPixmapName;
        QPixmap     m_pixmap;
        u8          m_u8Value       { 0 };
        bool        m_bBright       { false };

    public:
        Channel(s32             _s32Nr,
                const QString   &_sName,
                const QString   &_sPixmapName,
                bool            _bBright);

        ~Channel();

        s32                             nr() const                  { return m_s32Nr; }

        QString                         name() const                { return m_sName; }

        u8                              channelValue() const        { return m_u8Value; }

        const QString&                  pixmapName() const          { return m_sPixmapName; }
        const QPixmap&                  pixmap() const              { return m_pixmap; }

        bool                            isBrightnessChannel() const { return m_bBright; }


    private:
        // channel value can only be set via universe
        void                            setChannelValue(u8 _value)  { m_u8Value = _value; }
}; // class Channel
