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
    private:
        s32         m_s32Nr         { -1 };
        QString     m_sName;
        QString     m_sPixmapName;
        QPixmap     m_pixmap;


    public:
        Channel(s32             _s32Nr,
                const QString   &_sName,
                const QString   &_sPixmapName);

        ~Channel();

        s32                             nr() const                  { return m_s32Nr; }

        QString                         name() const                { return m_sName; }

        const QString&                  pixmapName() const          { return m_sPixmapName; }
        const QPixmap&                  pixmap() const              { return m_pixmap; }

        virtual bool                    isBrightnessChannel() const { return false; }

        // void                            setValue(s32 _s32Value)     { m_s32Value = _s32Value; }
        // s32                             value() const               { return m_s32Value; }
}; // class Channel
