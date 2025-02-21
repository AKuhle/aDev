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
#include "qBrush.h"

#include "pageMosaic.h"
#include "mainWin.h"

#include "roundInfo.h"


using namespace qLib;


/*******************************************************************************
* constants
*******************************************************************************/
#define PANEL_SPACE         8
#define TOP_SPACE           25
#define BOTTOM_SPACE        300


/*******************************************************************************
* PageMosaic::PageMosaic
*******************************************************************************/
PageMosaic::PageMosaic(std::shared_ptr<GameInfo> _pGameInfo)
: PageStd(_pGameInfo)
{
    EnableBuzzer();
} // PageMosaic::PageMosaic


/*******************************************************************************
* PageMosaic::~PageMosaic
*******************************************************************************/
PageMosaic::~PageMosaic()
{
} // PageMosaic::~PageMosaic


/*******************************************************************************
* PageMosaic::OnStartRound
*******************************************************************************/
void PageMosaic::OnStartRound()
{
    // set flag to create the new blocks
    m_bCreateBlocks = true;

    for (stBlocks &block : m_vBlocks)
    {
        block.col = qColor::RandomColor(0.3);
    }

    StartSingleShotTimer(m_s32BlockIntervall_ms);

    update();
} // PageMosaic::OnStartRound


/*******************************************************************************
* PageMosaic::OnCloseRound
*******************************************************************************/
void PageMosaic::OnCloseRound()
{
    StopSingleShotTimer();

    update();
} // PageMosaic::OnCloseRound


/*******************************************************************************
* PageMosaic::CreateBlocks
*******************************************************************************/
void PageMosaic::CreateBlocks(const qRect2D<s32>   &_r2dImg)
{
    if (m_bCreateBlocks)
    {
        // erase the old blocks
        m_vBlocks.clear();

        s32     s32BlockW       = _r2dImg.w / m_s32BlocksPerRow;
        s32     s32BlockRestW   = _r2dImg.w  - s32BlockW * (m_s32BlocksPerRow - 1);
        s32     s32BlockH       = _r2dImg.h / m_s32BlocksPerRow;
        s32     s32BlockRestH   = _r2dImg.h  - s32BlockH * (m_s32BlocksPerRow - 1);

        for (s32 y = 0; y < m_s32BlocksPerRow; y++)
        {
            for (s32 x = 0; x < m_s32BlocksPerRow; x++)
            {
                stBlocks st;

                st.rect.Set(_r2dImg.x + x * s32BlockW,
                            _r2dImg.y + y * s32BlockH,
                               (x == m_s32BlocksPerRow-1)?   s32BlockRestW : s32BlockW,
                               (y == m_s32BlocksPerRow-1)?   s32BlockRestH : s32BlockH);

                m_vBlocks.push_back(st);
            }
        }

        m_vBlocks.Shuffle();

        m_bCreateBlocks = false;
    }
} // PageMosaic::CreateBlocks


/*******************************************************************************
* PageMosaic::OnBuzzer
*******************************************************************************/
void PageMosaic::OnBuzzer(s32 /*_s32Team*/)
{
    StopSingleShotTimer();
} // PageMosaic::OnBuzzer


/*******************************************************************************
* PageMosaic::OnSingleShotTimer
*******************************************************************************/
void PageMosaic::OnSingleShotTimer()
{
    m_vBlocks.pop_front();

    if (!m_vBlocks.empty())
    {
        StartSingleShotTimer(m_s32BlockIntervall_ms);
    }

    update();
} // PageMosaic::OnSingleShotTimer


/*******************************************************************************
* PageMosaic::OnPaintGameStuff
*******************************************************************************/
void PageMosaic::OnPaintGameStuff(const qRect2D<s32>   &_r2dGame,
                                  qPainter             &_p)
{
    CHECK_PRE_CONDITION_VOID(m_pRoundInfo != nullptr);

    if (!m_pRoundInfo->GetImage().isNull())
    {
        qRect2D<s32> r2dImg = _p.DrawQImgMaximizedCentered(m_pRoundInfo->GetImage(), _r2dGame);

        // the blocks depends on the img size
        if (m_bCreateBlocks)
        {
            CreateBlocks(r2dImg);
        }
    }


    for (const stBlocks &b : m_vBlocks)
    {
        _p.SetBrush(qBrush(b.col));
        _p.DrawFilledRect(b.rect);
    }
} // PageMosaic::OnPaintGameStuff
