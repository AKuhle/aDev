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
#include "qPainter.h"
#include "qList.h"
#include "qFile.h"

#include "PagePanel.h"
#include "mainWin.h"

using namespace qLib;


/*******************************************************************************
* constants
*******************************************************************************/
#define PANEL_SPACE         8
#define TOP_SPACE           25
#define BOTTOM_SPACE        300


/*******************************************************************************
* PagePanel::PagePanel
*******************************************************************************/
PagePanel::PagePanel(enumPages _enumPage)
{
    MainWin             &mw         = GetMainWin();
    bool                bFigure     = _enumPage == enumPages::PanelFigureTeam_1 ||
                                      _enumPage == enumPages::PanelFigureTeam_2;
    qVec<qString16>     vecFiles;

    if (bFigure)
    {
        qPath               pathFigures = mw.GetGameDataPath() + PATH_FIGURES;
        qList<qString16>    lstPattern;

        lstPattern.push_back("*.png");

        qFile::GetFilesInDirectory(pathFigures.GetCanonicalPath(), lstPattern, vecFiles, true);

        if (vecFiles.size() != GAME_COUNT)
        {
            QMessageBox::warning(this, QString("Error"), QString("figure folder must have 16 figures"));
        }
    }

    for (s32 i = 0; i < GAME_COUNT; i++)
    {
        Panel *pPanel = new Panel(this, _enumPage);

        if (bFigure && i < vecFiles.size())
        {
            pPanel->SetFigure(vecFiles.at(i));
        }

        m_vPanel.push_back(pPanel);
    }

    // timer for frame color animation
    connect(&m_timerPanelFrame, SIGNAL(timeout()),
            this, SLOT(SlotPanelFrame()));
    m_timerPanelFrame.setInterval(100);
    m_timerPanelFrame.start();
} // PagePanel::PagePanel


/*******************************************************************************
* PagePanel::~PagePanel
*******************************************************************************/
PagePanel::~PagePanel()
{
} // PagePanel::~PagePanel


/*******************************************************************************
* PagePanel::OnSessionDataChanged
*******************************************************************************/
void PagePanel::OnSessionDataChanged()
{
    MainWin                                 &mw         = GetMainWin();
    const qVec<std::shared_ptr<GameInfo>>   &vecGames   = mw.GetSessionGames();

    repaint();

    for (s32 i = 0; i < GAME_COUNT; i++)
    {
        m_vPanel[i]->SetGameInfo((vecGames.size() > i)?   vecGames[i] : nullptr);

        m_vPanel[i]->repaint();
    }

} // PagePanel::OnSessionDataChanged


/*******************************************************************************
* PagePanel::OnStartRound
*******************************************************************************/
void PagePanel::OnStartRound()
{
    // panel view is a info view => can't start a round
} // PagePanel::OnStartRound


/*******************************************************************************
* PagePanel::OnCloseRound
*******************************************************************************/
void PagePanel::OnCloseRound()
{
    // panel view is a info view => can't close a round
} // PagePanel::OnCloseRound


/*******************************************************************************
* PagePanel::OnPaintGameStuff
*******************************************************************************/
void PagePanel::OnPaintStdItems(qRect2D<s32>    &/*_r2dClient*/,
                                qPainter        &/*_p*/)
{
} // PagePanel::OnPaintGameStuff


/*******************************************************************************
* PagePanel::OnResize
*******************************************************************************/
void PagePanel::OnResize(qRect2D<s32>   &/*_r2dClient*/)
{
    s32 w       = width();
    s32 h       = height() - TOP_SPACE - BOTTOM_SPACE;

    s32 size = (std::min(w, h - 3 * PANEL_SPACE) / 4);
    s32 row, col;

    s32 xOs = (w - 3*PANEL_SPACE - 4*size) / 2;
    s32 yOs = TOP_SPACE + (h - 3*PANEL_SPACE - 4*size) / 2;

    for (s32 i = 0; i < GAME_COUNT; i++)
    {
        col = i % 4;
        row = i / 4;

        m_vPanel[i]->setGeometry(xOs + col * (PANEL_SPACE + size),
                                 yOs + row * (PANEL_SPACE + size),
                                 size, size);

    }
} // PagePanel::OnResize


/*******************************************************************************
* PagePanel::SlotPanelFrame
*******************************************************************************/
void PagePanel::SlotPanelFrame()
{
    static qColor   colDark     = qColor::FromU8(205, 254, 255);
    static qColor   colBright   = qColor::FromU8(30, 135, 170);

    static s32      val     = 0;    // %
    static s32      step    = 2;    // %

    if (val+step > 100)
    {
        val = 100;
        step = -2;
    }
    else if (val+step < 0)
    {
        val = 0;
        step = 02;
    }
    else
    {
        val += step;
    }

    qColor  col = colDark.GetColorInBetween(colBright, ((float) val) / 100);

    for (s32 i = 0; i < GAME_COUNT; i++)
    {
        m_vPanel[i]->SetFrameColor(col);
    }

} // PagePanel::SlotPanelFrame
