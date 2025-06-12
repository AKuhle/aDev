/*******************************************************************************
* \file fader.h
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
#include "aScrollBar.h"
#include "scribbleStrip.h"

class Channel;

using namespace aLib::aWin;


/*******************************************************************************
* class Fader
*******************************************************************************/
class Fader : public aScrollBar
{
    private:
        ScribbleStrip           *m_pScribbleStrip   { nullptr };
        aLabel                  *m_pLabel           { nullptr };
        shared_ptr<Channel>     m_pChannel          { nullptr };

    public:
        Fader(SysWin *_pParent = nullptr);
        ~Fader();

        void                        setControls(ScribbleStrip   *_pScribbleStrip,
                                                aLabel          *_pLabel);

        void                        updateState();

        shared_ptr<Channel>         channel()           { return m_pChannel; }
        void                        setChannel(shared_ptr<Channel> _pChannel);
        bool                        hasChannel() const;
}; // class Fader
