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
#include "pageStd.h"
#include "mainWin.h"
#include "qPen.h"
#include "qColor.h"
#include "qBrush.h"
#include "gameInfo.h"

using namespace qLib;


/*******************************************************************************
* constants
*******************************************************************************/


/*******************************************************************************
* PageStd::PageStd
*******************************************************************************/
PageStd::PageStd(std::shared_ptr<GameInfo> _pGameInfo)
: m_pGameInfo(_pGameInfo),
  m_pointWidget1(this, TEAM_1, _pGameInfo),
  m_pointWidget2(this, TEAM_2, _pGameInfo),
  m_buzzerWidget(this)
{
    // connect single shot timer
    m_timerSingleShot.setSingleShot(true);
    m_timerBuzzer.setSingleShot(true);

    connect(&m_timerSingleShot, SIGNAL(timeout()), this, SLOT(SlotSingleShot()));
    connect(&m_timerBuzzer, SIGNAL(timeout()), this, SLOT(SlotBuzzer()));
} // PageStd::PageStd


/*******************************************************************************
* PageStd::~PageStd
*******************************************************************************/
PageStd::~PageStd()
{
} // PageStd::~PageStd


/*******************************************************************************
* PageStd::BuzzerPressed
*******************************************************************************/
void PageStd::BuzzerPressed(s32 _s32Team)
{
    if (m_bBuzzerEnabled)
    {
        OnBuzzer(_s32Team);
    }

    if (m_pGameInfo->GetBuzzerTimer_s() > 0)
    {
        m_buzzerWidget.StartBuzzer(_s32Team, m_pGameInfo->GetBuzzerTimer_s());
        m_timerBuzzer.start(1000);
    }
} // PageStd::BuzzerPressed


/*******************************************************************************
* PageStd::OnBuzzer
*******************************************************************************/
void PageStd::OnBuzzer(s32 /*_s32Team*/)
{
} // PageStd::OnBuzzer


/*******************************************************************************
* PageStd::StartSingleShotTimer
*******************************************************************************/
void PageStd::StartSingleShotTimer(s32    s32Time_ms)
{
    m_timerSingleShot.start(s32Time_ms);
} // PageStd::StartSingleShotTimer


/*******************************************************************************
* PageStd::StopSingleShotTimer
*******************************************************************************/
void PageStd::StopSingleShotTimer()
{
    m_timerSingleShot.stop();
} // PageStd::StopSingleShotTimer


/*******************************************************************************
* PageStd::OnSingleShotTimer
*******************************************************************************/
void PageStd::OnSingleShotTimer()
{
} // PageStd::OnSingleShotTimer


/*******************************************************************************
* PageStd::SlotSingleShot
*******************************************************************************/
void PageStd::SlotSingleShot()
{
    OnSingleShotTimer();
} // PageStd::SlotSingleShot


/*******************************************************************************
* PageStd::SlotBuzzer
*******************************************************************************/
void PageStd::SlotBuzzer()
{
    if (m_buzzerWidget.GetRemainingTime() > 1)
    {
        m_buzzerWidget.DecreaseBuzzer(1);
        m_timerBuzzer.start(1000);
    }
    else
    {
        m_buzzerWidget.StopBuzzer();

    }
} // PageStd::SlotBuzzer


/*******************************************************************************
* PageStd::OnPaintStdItems
*******************************************************************************/
void PageStd::OnPaintStdItems(qRect2D<s32>    &_r2dClient,
                              qPainter        &_p)
{
    CHECK_PRE_CONDITION_VOID(m_pGameInfo != nullptr);

    const qFont     &fntPretty  = GetPrettyFont();

    GameInfo        &gi = GetGameInfo();

    // paint the game points
    qString16       sPoints = qString16::FromValue(m_pGameInfo->GetGamePoints());
    qPen            penPoints(colDarkGoldenRod, 3);
    // left points
    qRect2D<s32>    r2dPointsL(_r2dClient.x, _r2dClient.y, StdTitleH, StdTitleH);
    _p.DrawTextMaximizedCentered(sPoints, r2dPointsL, 5, &fntPretty, &penPoints);
    // right points
    qRect2D<s32>    r2dPointsR(_r2dClient.r1() - StdTitleH, _r2dClient.y, StdTitleH, StdTitleH);
    _p.DrawTextMaximizedCentered(sPoints, r2dPointsR, 5, &fntPretty, &penPoints);


    // paint the name of the game
    qRect2D<s32>    r2dTitle(_r2dClient.x, _r2dClient.y, _r2dClient.w, StdTitleH);
    qPen            penText(colGold, 3);

    _p.DrawTextMaximizedCentered(gi.GetName(), r2dTitle, 5, &fntPretty, &penText);
    _r2dClient.y += StdTitleH;
    _r2dClient.h -= StdTitleH;

    // remove the point widgets from the game rect
    _r2dClient.h -= m_s32PointWidgetH + m_s32WidgetMargin;

} // PageStd::OnPaintStdItems


/*******************************************************************************
* PageStd::OnResize
*******************************************************************************/
void PageStd::OnResize(qRect2D<s32>   &_r2dClient)
{
    // left point widget
    m_pointWidget1.setGeometry(_r2dClient.x + m_s32WidgetMargin,
                               _r2dClient.b() - m_s32PointWidgetH - m_s32WidgetMargin,
                               m_s32PointWidgetW, m_s32PointWidgetH);

    // right point widget
    m_pointWidget2.setGeometry(_r2dClient.r1() - m_s32WidgetMargin - m_s32PointWidgetW,
                               _r2dClient.b() - m_s32PointWidgetH - m_s32WidgetMargin,
                               m_s32PointWidgetW, m_s32PointWidgetH);

    // buzzer widget
    m_buzzerWidget.setGeometry(_r2dClient.CenterPoint().x - m_s32BuzzerWidgetW / 2,
                               _r2dClient.b() - m_s32BuzzerWidgetH - m_s32WidgetMargin,
                               m_s32BuzzerWidgetW, m_s32BuzzerWidgetH);
} // PageStd::OnResize
