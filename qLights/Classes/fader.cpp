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
#include "channel.h"
#include "fixture.h"

using namespace aFrame;


/*******************************************************************************
* Fader::Fader
*******************************************************************************/
Fader::Fader(QWidget *_pParent)
: QSlider(_pParent)
{
    connect(this, &QSlider::sliderMoved, this, &Fader::onSliderMoved);
} // Fader::Fader


/*******************************************************************************
* Fader::~Fader
*******************************************************************************/
Fader::~Fader()
{
} // Fader::~Fader


/*******************************************************************************
* Fader::assignChannel
*******************************************************************************/
void Fader::assignChannel(shared_ptr<Fixture> _pFixture,
                          shared_ptr<Channel> _pChannel)
{
    m_pFixture = _pFixture;
    m_pChannel = _pChannel;

    setFixedHeight(280);

    if (_pChannel)
    {
        setEnabled(true);
        m_pScribbleStrip->setPixmap(_pChannel->pixmap());
    }
    else
    {
        setEnabled(false);
        m_pScribbleStrip->setPixmap(QPixmap(":/qLights/unused.png"));
    }
} // Fader::assignChannel


/*******************************************************************************
* Fader::init
*******************************************************************************/
void Fader::init(ScribbleStrip *_pScribbleStrip)
{
    m_pScribbleStrip = _pScribbleStrip;

    assignChannel(nullptr, nullptr);
} // Fader::init


/*******************************************************************************
* Fader::onSliderMoved
*******************************************************************************/
void Fader::onSliderMoved(int value)
{
    CHECK_PRE_CONDITION_VOID(m_pFixture);
    CHECK_PRE_CONDITION_VOID(m_pChannel);
    CHECK_PRE_CONDITION_VOID(m_pFixture->universe());

    // set the value in the channel
    m_pChannel->setValue(value);

    // set the value in the universe
    m_pFixture->universe()->setChannelValue(m_pFixture->adress(),
                                            m_pChannel->nr(),
                                            (u8) value,
                                            true);
} // Fader::onSliderMoved
