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
class Fixture;


using namespace std;
using namespace aFrame;



/*******************************************************************************
* class Fader
*******************************************************************************/
class Fader  :public QSlider
{
    Q_OBJECT

    private:
        ScribbleStrip           *m_pScribbleStrip;
        shared_ptr<Fixture>     m_pFixture;
        shared_ptr<Channel>     m_pChannel;

    public:
        Fader(QWidget *_pParent);

        ~Fader();

        void                init(ScribbleStrip *_pScribbleStrip);

        void                assignChannel(shared_ptr<Fixture> _pFixture,
                                          shared_ptr<Channel> _pChannel);

    private slots:
        void                onSliderMoved(int value);

}; // class Fader
