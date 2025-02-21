/*******************************************************************************
* \file qColor.h
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
#include "qBaseDefs.h"
#include "qGuiDefs.h"

#include "qPainter.h"
#include "qBrush.h"
#include "qPen.h"

#include "buzzerWidget.h"

using namespace qLib;


/*******************************************************************************
* BuzzerWidget::BuzzerWidget
*******************************************************************************/
BuzzerWidget::BuzzerWidget(QWidget *_pParent)
: QWidget(_pParent)
{
} // BuzzerWidget::BuzzerWidget


/*******************************************************************************
* BuzzerWidget::~BuzzerWidget
*******************************************************************************/
BuzzerWidget::~BuzzerWidget()
{
} // BuzzerWidget::~BuzzerWidget


/*******************************************************************************
* BuzzerWidget::StartBuzzer
*******************************************************************************/
void BuzzerWidget::StartBuzzer(s32 _s32Team,
                               s32 _s32StartTime_s)
{
    m_s32Team           = _s32Team;
    m_s32StartTime_s    = _s32StartTime_s;
    m_s32CurrentTime_s  = _s32StartTime_s;
    m_bBuzzerRunning    = true;

    repaint();
} // BuzzerWidget::StartBuzzer


/*******************************************************************************
* BuzzerWidget::DecreaseBuzzer
*******************************************************************************/
void BuzzerWidget::DecreaseBuzzer(s32 _s32Time_s)
{
    m_s32CurrentTime_s  = MU<s32>::Max(0, m_s32CurrentTime_s - _s32Time_s);

    repaint();
} // BuzzerWidget::DecreaseBuzzer


/*******************************************************************************
* BuzzerWidget::StopBuzzer
*******************************************************************************/
void BuzzerWidget::StopBuzzer()
{
    m_s32Team           = TEAM_NONE;
    m_s32StartTime_s    = 0;
    m_s32CurrentTime_s  = 0;
    m_bBuzzerRunning    = false;

    repaint();
} // BuzzerWidget::StopBuzzer


/*******************************************************************************
* BuzzerWidget::paintEvent
*******************************************************************************/
void BuzzerWidget::paintEvent(QPaintEvent */*_pEvent*/)
{
    if (m_bBuzzerRunning)
    {
        qPainter        p(this);
        qPen            penFrame(colLightCyan);
        qBrush          brush(colCyan);
        qRect2D<s32>    r2dClient(0, 0, width()-1, height()-1);
        s32             w = (width()-2) * m_s32CurrentTime_s / m_s32StartTime_s;

        // draw the frame
        p.DrawRect(r2dClient, &penFrame);

        // draw the rect
        if (m_s32Team == TEAM_1)
        {
            p.DrawFilledRect(1, 1, w, height()-2, &brush);
        }
        else
        {
            p.DrawFilledRect(width() - 2 - w, 1, w, height()-2, &brush);
        }
    }
} // BuzzerWidget::paintEvent
