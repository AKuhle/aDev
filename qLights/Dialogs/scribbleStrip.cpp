/*******************************************************************************
* \file ScribbleStrip.cpp
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
#include "qLights_defs.h"
#include "scribbleStrip.h"
#include "aPainter.h"

using namespace aLib::aGraphic;

aPixmap *ScribbleStrip::m_pixmapUnused     { nullptr };


/*******************************************************************************
* ScribbleStrip::ScribbleStrip
*******************************************************************************/
ScribbleStrip::ScribbleStrip(SysWin *_pParent /*= nullptr*/)
: aPlainWin(_pParent)
{
    if (!m_pixmapUnused)
    {
        m_pixmapUnused = new aPixmap(":/qLights/ChannelIcn/unused.png");
        m_pixmapUnused->scale(SCRIBBLE_STRIP_W, SCRIBBLE_STRIP_H);
    }
} // ScribbleStrip::ScribbleStrip


/*******************************************************************************
* ScribbleStrip::~ScribbleStrip
*******************************************************************************/
ScribbleStrip::~ScribbleStrip()
{
    DELETE0(m_pixmapUnused);
} // ScribbleStrip::~ScribbleStrip


/*******************************************************************************
* ScribbleStrip::setIcon
*******************************************************************************/
void ScribbleStrip::setIcon(const aString   &_sIcon)
{
    m_pixmap = aPixmap(_sIcon);

    if (m_pixmap.isValid())
    {
        m_pixmap.scale(SCRIBBLE_STRIP_W, SCRIBBLE_STRIP_H);
    }

    update();
} // ScribbleStrip::setIcon


/*******************************************************************************
* ScribbleStrip::onPaint
*******************************************************************************/
bool ScribbleStrip::onPaint()
{
    aRect2D<s32>    r2dContent = clientRect();
    aPainter        p(this);

    if (m_pixmap.isValid())
    {
        p.drawPixmap(m_pixmap, 0, 0);
    }
    else
    {
        p.drawPixmap(*m_pixmapUnused, 0, 0);
    }

    return true;
} // ScribbleStrip::onPaint
