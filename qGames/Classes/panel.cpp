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
#include "qGuiDefs.h"

#include "mainWin.h"
#include "panel.h"
#include "qPainter.h"
#include "qPen.h"
#include "gameInfo.h"

using namespace qLib;


/*******************************************************************************
* Panel::Panel
*******************************************************************************/
Panel::Panel(QWidget    *_pParent,
             enumPages  _ePages)
: QWidget(_pParent),
  m_ePages(_ePages)
{
} // Panel::Panel


/*******************************************************************************
* Panel::~Panel
*******************************************************************************/
Panel::~Panel()
{
} // Panel::~Panel


/*******************************************************************************
* Panel::SetFrameColor
*******************************************************************************/
void Panel::SetFrameColor(const qColor  &_col)
{
    m_colFrame = _col;

    update();
} // Panel::SetFrameColor


/*******************************************************************************
* Panel::SetGameInfo
*******************************************************************************/
void Panel::SetGameInfo(std::shared_ptr<GameInfo> _pGameInfo)
{
    m_pGameInfo = _pGameInfo;

    repaint();
} // Panel::SetGameInfo


/*******************************************************************************
* Panel::SetFigure
*******************************************************************************/
void Panel::SetFigure(qString16 _sFigurePath)
{
    m_imgFigure.load(_sFigurePath.ToQString());

    if (!m_imgFigure.isNull())
    {
        m_imgFigureResized = m_imgFigure.scaled(width() - 10, height() - 10, Qt::KeepAspectRatio);
        m_sFigurePath = _sFigurePath;
    }
    else
    {
        m_sFigurePath = "";
    }

    update();
} // Panel::SetFigure


/*******************************************************************************
* Panel::resizeEvent
*******************************************************************************/
void Panel::resizeEvent(QResizeEvent */*_pEvent*/)
{
    if (!m_imgFigure.isNull())
    {
        m_imgFigureResized = m_imgFigure.scaled(width() - 10, height() - 10, Qt::KeepAspectRatio);
    }
} // Panel::resizeEvent


/*******************************************************************************
* Panel::paintEvent
*******************************************************************************/
void Panel::paintEvent(QPaintEvent */*_pEvent*/)
{
    MainWin         &mw = GetMainWin();
    qPainter        p(this);
    qPen            pen(m_colFrame, 3);
    qRect2D<s32>    r2dClient(0, 0, width(), height());

    p.DrawRoundedRect(0, 0, width(), height(), 10, 10, &pen);

    // shrink rect for content
    qRect2D<s32> r2dContent(5, 5, width() - 10, height() - 10);

    switch (m_ePages)
    {
        default:
            break;

        case enumPages::PanelFigureTeam_1:
        case enumPages::PanelFigureTeam_2:
        {
            if (!m_imgFigureResized.isNull())
            {
                p.DrawQImgCentered(m_imgFigureResized, r2dContent);
            }
            break;
        }

        case enumPages::PanelWinners:
        {
            const TeamInfo  &ti1 = mw.GetTeamInfo(TEAM_1);
            const TeamInfo  &ti2 = mw.GetTeamInfo(TEAM_2);

            if (m_pGameInfo != nullptr)
            {
                if (m_pGameInfo->GetWinner() == TEAM_BOTH)
                {
                    QPixmap pm1 = ti1.GetPixmap().scaled(width()/2 - 10, height()/2 - 10, Qt::KeepAspectRatio);
                    QPixmap pm2 = ti2.GetPixmap().scaled(width()/2 - 10, height()/2 - 10, Qt::KeepAspectRatio);

                    qRect2D<s32> r1(r2dContent.x, r2dContent.y, r2dContent.w/2, r2dContent.h/2);
                    qRect2D<s32> r2(r2dContent.x + r2dContent.w/2, r2dContent.y + r2dContent.h/2, r2dContent.w/2, r2dContent.h/2);

                    p.DrawQPixmapCentered(pm1, r1);
                    p.DrawQPixmapCentered(pm2, r2);
                }
                else if (m_pGameInfo->GetWinner() == TEAM_1)
                {
                    QPixmap pm = ti1.GetPixmap().scaled(r2dContent.w, r2dContent.h, Qt::KeepAspectRatio);
                    p.DrawQPixmapCentered(pm, r2dContent);
                }
                else if (m_pGameInfo->GetWinner() == TEAM_2)
                {
                    QPixmap pm = ti2.GetPixmap().scaled(r2dContent.w, r2dContent.h, Qt::KeepAspectRatio);
                    p.DrawQPixmapCentered(pm, r2dContent);
                }
                else
                {
                    p.DrawText(m_pGameInfo->GetCategory(), r2dClient, AlignCenter);
                }
            } // if (m_pGameInfo != nullptr)
            break;
        }
    } // switch (m_ePagePanelMode)
} // Panel::paintEvent


/*******************************************************************************
* Panel::mouseDoubleClickEvent
*******************************************************************************/
void Panel::mouseDoubleClickEvent(QMouseEvent *_pEvent)
{
    MainWin     &mw = GetMainWin();

    switch (m_ePages)
    {
        default:
            break;

        case enumPages::PanelFigureTeam_1:
        case enumPages::PanelFigureTeam_2:
            mw.OnFigureSelected(m_ePages, m_sFigurePath);
            break;

        case enumPages::PanelWinners:
            mw.OnGameSelected(m_pGameInfo);
            break;
    } // switch (m_ePagePanelMode)

    _pEvent->accept();
} // Panel::mouseDoubleClickEvent
