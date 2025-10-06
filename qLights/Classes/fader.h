/*******************************************************************************
* \file Fader.h
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
#include <QSlider>
#include <QString>
#include "scribbleStrip.h"
#include "aFrame_def.h"

class Channel;


using namespace std;
using namespace aFrame;



/*******************************************************************************
* class Fader
*******************************************************************************/
class Fader  :public QSlider
{
    private:
        ScribbleStrip           *m_pScribbleStrip;
        shared_ptr<Channel>     m_pChannel;

    public:
        Fader(QWidget *_pParent);

        ~Fader();

        void                init(ScribbleStrip *_pScribbleStrip);

        void                setChannel(shared_ptr<Channel> _pChannel);


        //void                                addUniverse(u32 _u32Id);

        // void                                setDmxChannelValue(s32      _s32UniverseId,
        //                                                        s32      _s32DmxChannelNr,
        //                                                        u8       _u8Value,
        //                                                        bool     _bSend);

        //void                                sendAllUniverses();

        //shared_ptr<Universe>                universe(u32 _u32Id);

        //void                                resetAllUniverses();
}; // class Fader
