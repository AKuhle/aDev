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

#include "gamesDefs.h"
#include "mainWin.h"
#include "pageBase.h"

using namespace qLib;


/*******************************************************************************
* PageBase::PageBase
*******************************************************************************/
PageBase::PageBase()
{
    setAttribute(Qt::WA_DeleteOnClose);
} // PageBase::PageBase


/*******************************************************************************
* PageBase::~PageBase
*******************************************************************************/
PageBase::~PageBase()
{
} // PageBase::~PageBase


/*******************************************************************************
* PageBase::OnSessionDataChanged
*******************************************************************************/
void PageBase::OnSessionDataChanged()
{
    repaint();
} // PageBase::OnSessionDataChanged


/*******************************************************************************
* PageBase::BuzzerPressed
*******************************************************************************/
void PageBase::BuzzerPressed(s32 /*_s32Team*/)
{
} // PageBase::BuzzerPressed


/*******************************************************************************
* PageBase::StartRound
*******************************************************************************/
void PageBase::StartRound(std::shared_ptr<GameInfo>    _pGameInfo,
                          std::shared_ptr<RoundInfo>   _pRoundInfo)
{
    m_pGameInfo     = _pGameInfo;
    m_pRoundInfo    = _pRoundInfo;

    OnStartRound();
} // PageBase::StartRound


/*******************************************************************************
* PageBase::CloseRound
*******************************************************************************/
void PageBase::CloseRound()
{
    m_pGameInfo     = nullptr;
    m_pRoundInfo    = nullptr;

    OnCloseRound();
} // PageBase::CloseRound


/*******************************************************************************
* PageBase::OnResize
*******************************************************************************/
void PageBase::OnResize(qRect2D<s32>   &/*_r2dClient*/)
{
} // PageBase::OnResize


/*******************************************************************************
* PageBase::resizeEvent
*******************************************************************************/
void PageBase::resizeEvent(QResizeEvent */*_pEvent*/)
{
    qRect2D<s32>    r2dClient(0, 0, width(), height());

    OnResize(r2dClient);
} // PageBase::resizeEvent


/*******************************************************************************
* PageBase::OnPaintStdItems
*******************************************************************************/
void PageBase::OnPaintStdItems(qRect2D<s32>    &/*_r2dClient*/,
                               qPainter        &/*_p*/)
{
} // PageBase::OnPaintStdItems


/*******************************************************************************
* PageBase::OnPaintGameStuff
*******************************************************************************/
void PageBase::OnPaintGameStuff(const qRect2D<s32> &/*_r2dGame*/,
                                qPainter           &/*_p*/)
{
} // PageBase::OnPaintGameStuff


/*******************************************************************************
* PageBase::paintEvent
*******************************************************************************/
void PageBase::paintEvent(QPaintEvent */*_pEvent*/)
{
    GamesVarPool    vp = GetVarPool();
    qPainter        p(this);
    qRect2D<s32>    r2dClient(0, 0, width(), height());
    const qColor    &col1 = vp.GetColor(ID_VP_GAME_BG_1);
    const qColor    &col2 = vp.GetColor(ID_VP_GAME_BG_2);


    // draw the gradient
    p.DrawGradientRect(r2dClient,
                       qVector2D<s32> (0, height()),
                       qVector2D<s32> (0, 0),
                       col1, col2);

    OnPaintStdItems(r2dClient, p);
    OnPaintGameStuff(r2dClient, p);
} // PageBase::paintEvent
