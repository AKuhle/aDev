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
        // channel assignes => fader enabled
        setEnabled(true);

        // scribble strip icon
        m_pScribbleStrip->setPixmap(_pChannel->pixmap());

        // set the fader position
        u8 u8Val = m_pFixture->universe()->channelValue(m_pFixture->adress(),
                                                        m_pChannel->nr());
        setValue(u8Val);
    }
    else
    {
        setEnabled(false);
        m_pScribbleStrip->setPixmap(QPixmap(":/qLights/unused.png"));
        setValue(0);
    }
} // Fader::assignChannel


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

    setInfo();

    assignChannel(nullptr, nullptr);
} // Fader::init


/*******************************************************************************
* Fader::updatePosition
*******************************************************************************/
void Fader::updatePosition()
{
    CHECK_PRE_CONDITION_VOID(m_pFixture);
    CHECK_PRE_CONDITION_VOID(m_pChannel);
    CHECK_PRE_CONDITION_VOID(m_pFixture->universe());

    u8 u8Val = m_pFixture->universe()->channelValue(m_pFixture->adress(),
                                                    m_pChannel->nr());
    setValue(u8Val);

    setInfo();
} // Fader::updatePosition


/*******************************************************************************
* Fader::setInfo
*******************************************************************************/
void Fader::setInfo()
{
    int     iVal = 0;

    if (m_pFixture && m_pChannel && m_pFixture->universe())
    {
        iVal = m_pFixture->universe()->channelValue(m_pFixture->adress(),
                                                    m_pChannel->nr());
    }

    m_pFaderInfo->setInfo(QString::number(iVal));
} // Fader::setInfo


/*******************************************************************************
* Fader::onSliderMoved
*******************************************************************************/
void Fader::onSliderMoved(int _iValue)
{
    cout << _iValue << endl;

    CHECK_PRE_CONDITION_VOID(m_pFixture);
    CHECK_PRE_CONDITION_VOID(m_pChannel);
    CHECK_PRE_CONDITION_VOID(m_pFixture->universe());

    // set the value in the universe
    m_pFixture->universe()->setChannelValue(m_pFixture->adress(),
                                            m_pChannel->nr(),
                                            (u8) _iValue,
                                            true);
    setInfo();

} // Fader::onSliderMoved
