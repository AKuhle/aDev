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

#include "mainWin.h"

using namespace aFrame;


/*******************************************************************************
* Fader::Fader
*******************************************************************************/
Fader::Fader(QWidget *_pParent)
: QSlider(_pParent)
{
    connect(this, &QSlider::valueChanged, this, &Fader::onSliderMoved);
} // Fader::Fader


/*******************************************************************************
* Fader::~Fader
*******************************************************************************/
Fader::~Fader()
{
} // Fader::~Fader


/*******************************************************************************
* Fader::init
*******************************************************************************/
void Fader::init(ScribbleStrip  *_pScribbleStrip,
                 FaderInfo      *_pFaderInfo,
                 QString        _sFaderNr)
{
    m_pScribbleStrip    = _pScribbleStrip;
    m_pFaderInfo        = _pFaderInfo;

    m_pFaderInfo->init(_sFaderNr);

    updateInfo();

    assignChannel(nullptr, nullptr);
} // Fader::init


/*******************************************************************************
* Fader::assignChannel
*******************************************************************************/
void Fader::assignChannel(shared_ptr<Fixture> _pFixture,
                          shared_ptr<Channel> _pChannel)
{
    m_pFixture = _pFixture;
    m_pChannel = _pChannel;

    update();
} // Fader::assignChannel


/*******************************************************************************
* Fader::update
*******************************************************************************/
void Fader::update()
{
    setFixedHeight(280);

    if (m_pChannel)
    {
        // channel assignes => fader enabled
        setEnabled(true);

        // scribble strip icon
        m_pScribbleStrip->setPixmap(m_pChannel->pixmap());

        // set the fader position
        setValue(m_pChannel->channelValue());
    }
    else if (m_bMasterFader)
    {
        u8 u8Val = MainWin::instance()->masterBrightness();

        setEnabled(true);
        m_pScribbleStrip->setPixmap(QPixmap(":/qLights/brightnessMasked.png"));
        setValue(u8Val);
    }
    else
    {
        setEnabled(false);
        m_pScribbleStrip->setPixmap(QPixmap(":/qLights/unused.png"));
        setValue(0);
    }

    updateInfo();
} // Fader::update


/*******************************************************************************
* Fader::updateInfo
*******************************************************************************/
void Fader::updateInfo()
{
    int     iVal = 0;

    if (m_pFixture && m_pChannel && m_pFixture->universe())
    {
        iVal = m_pChannel->channelValue();
    }

    m_pFaderInfo->setInfo(QString::number(iVal));
} // Fader::updateInfo


/*******************************************************************************
* Fader::onSliderMoved
*******************************************************************************/
void Fader::onSliderMoved(int _iValue)
{
    if (m_bMasterFader)
    {
        MainWin::instance()->setMasterBrightness((u8) _iValue, true);

        m_pScribbleStrip->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                      .arg(_iValue)
                                      .arg(_iValue)
                                      .arg(_iValue));
    }
    else
    {
        CHECK_PRE_CONDITION_VOID(m_pFixture);
        CHECK_PRE_CONDITION_VOID(m_pChannel);
        CHECK_PRE_CONDITION_VOID(m_pFixture->universe());

        // set the value in the universe
        m_pFixture->universe()->setChannelValue(m_pFixture->adress(),
                                                m_pChannel,
                                                (u8) _iValue,
                                                true);

        updateInfo();
    }
} // Fader::onSliderMoved
