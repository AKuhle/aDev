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
        QPixmap     m_pixmap;
        bool        m_bBrightness   { false };

        s32         m_s32Value      { 0 };


    public:
        Channel(s32             _s32Nr,
                const QString   &_sName,
                const QPixmap   &_pixmap,
                bool            _bBrightness);

        ~Channel();

        s32                             nr() const                  { return m_s32Nr; }

        QString                         name() const                { return m_sName; }

        const QPixmap&                  pixmap() const              { return m_pixmap; }

        bool                            isBrightness() const        { return m_bBrightness; }

        void                            setValue(s32 _s32Value)     { m_s32Value = _s32Value; }
        s32                             value() const               { return m_s32Value; }
}; // class Channel
