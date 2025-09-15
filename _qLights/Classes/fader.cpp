/*******************************************************************************
* \file fader.cpp
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
#include "fader.h"
#include "aLabel.h"
#include "Channel.h"


/*******************************************************************************
* Fader::Fader
*******************************************************************************/
Fader::Fader(SysWin *_pParent /*= nullptr*/)
: aScrollBar(_pParent)
{
} // Fader::Fader


/*******************************************************************************
* Fader::~Fader
*******************************************************************************/
Fader::~Fader()
{
} // Fader::~Fader


/*******************************************************************************
* Fader::setControls
*******************************************************************************/
void Fader::setControls(ScribbleStrip   *_pScribbleStrip,
                        aLabel          *_pLabel)
{
    m_pScribbleStrip    = _pScribbleStrip;
    m_pLabel            = _pLabel;
} // Fader::setControls


/*******************************************************************************
* Fader::updateState
*******************************************************************************/
void Fader::updateState()
{
    if (hasChannel())
    {
        setEnabled(true);
        setTracking(false);
        setPosition(m_pChannel->value());
        setTracking(true);

        m_pScribbleStrip->setIcon(m_pChannel->icon());
    }
    else
    {
        setEnabled(false);
        setTracking(false);
        setPosition(0);
        setTracking(true);

        m_pScribbleStrip->setIcon("");
        m_pLabel->setText(aString(""));
    }
} // Fader::updateState


/*******************************************************************************
* Fader::setChannel
*******************************************************************************/
void Fader::setChannel(shared_ptr<Channel> _pChannel)
{
    m_pChannel = _pChannel;

    updateState();
} // Fader::setChannel


/*******************************************************************************
* Fader::hasChannel
*******************************************************************************/
bool Fader::hasChannel() const
{
    return (m_pChannel != nullptr);
} // Fader::hasChannel
