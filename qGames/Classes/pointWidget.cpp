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
#include "qPen.h"

#include "mainWin.h"
#include "pointWidget.h"
#include "gameInfo.h"

using namespace qLib;


/*******************************************************************************
* PointWidget::PointWidget
*******************************************************************************/
PointWidget::PointWidget(QWidget                *_pParent,
                         s32                    _s32Team,
                         shared_ptr<GameInfo>   _pGameInfo)
: QWidget(_pParent),
  m_s32Team(_s32Team),
  m_pGameInfo(_pGameInfo)
{
} // PointWidget::PointWidget


/*******************************************************************************
* PointWidget::~PointWidget
*******************************************************************************/
PointWidget::~PointWidget()
{
} // PointWidget::~PointWidget


/*******************************************************************************
* PointWidget::paintEvent
*******************************************************************************/
void PointWidget::paintEvent(QPaintEvent */*_pEvent*/)
{
    CHECK_PRE_CONDITION_VOID(m_s32Team == TEAM_1 || m_s32Team == TEAM_2);
    CHECK_PRE_CONDITION_VOID(m_pGameInfo != nullptr);

    MainWin         &mw = GetMainWin();
    qPainter        p(this);

    qPen            penCircle(colGold);
    qColor          colCircleFilled = colDarkOrange;

    const TeamInfo  &ti = mw.GetTeamInfo(m_s32Team);

    qRect2D<s32>    r2dImg;
    const s32       s32ImgW         = height() * 2 / 3;
    const s32       s32ImgH         = height();

    if (m_s32Team == TEAM_1)
    {
        r2dImg.Set(0, 0, s32ImgW, s32ImgH);
    }
    else
    {
        r2dImg.Set(width() - s32ImgW, 0, s32ImgW, s32ImgH);
    }
    qPen ppp(colLightGreen);
    p.DrawRect(r2dImg, &ppp);

    // draw the team image
    p.DrawQPixmapMaximizedCentered(ti.GetPixmap(), r2dImg);

    // draw the points
    s32 s32PointN   = m_pGameInfo->GetPoints2Win();
    s32 s32RoundWon = m_pGameInfo->GetRoundWinnerCount(m_s32Team);

    if (s32PointN > 0)
    {
        s32             s32PointD   = 5;
        s32             s32PointR   = ((width() - s32ImgW - (s32PointN - 1) * s32PointD) / s32PointN) / 2 - 1;  // radius
        s32             s32PointX   = ((m_s32Team == TEAM_1)?  s32ImgW + s32PointR :  width() - s32ImgW - s32PointR);
        s32             s32PointY   = height() / 2;

        for (s32 i = 0; i < s32PointN; i++)
        {
            // draw the outlined circle
            p.DrawCircle(s32PointX, s32PointY,
                         s32PointR, &penCircle);

            // fill it if the round has been won
            if (i < s32RoundWon)
            {
                p.DrawFilledCircle(s32PointX, s32PointY,
                                   s32PointR - 4, &colCircleFilled);
            }

            if (m_s32Team == TEAM_1)
            {
                s32PointX += 2*s32PointR + s32PointD;
            }
            else
            {
                s32PointX -= 2*s32PointR + s32PointD;
            }
        }
    } // if (s32Points > 0)

} // PointWidget::paintEvent
