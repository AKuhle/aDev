/*******************************************************************************
* \file Fader.cpp
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
#include "Fader.h"
#include "universe.h"

using namespace aFrame;


/*******************************************************************************
* Fader::Fader
*******************************************************************************/
Fader::Fader(QWidget *_pParent)
: QSlider(_pParent)
{
} // Fader::Fader


/*******************************************************************************
* Fader::~Fader
*******************************************************************************/
Fader::~Fader()
{
} // Fader::~Fader


/*******************************************************************************
* Fader::setChannel
*******************************************************************************/
void Fader::setChannel(shared_ptr<Channel> _pChannel)
{
    if (_pChannel)
    {
    }
    else
    {
        setEnabled(false);
        m_pScribbleStrip->setPixmap(QPixmap(":/qLights/unused.png"));
    }
} // Fader::setChannel


/*******************************************************************************
* Fader::init
*******************************************************************************/
void Fader::init(ScribbleStrip *_pScribbleStrip)
{
    m_pScribbleStrip = _pScribbleStrip;

    setChannel(nullptr);
} // Fader::init
