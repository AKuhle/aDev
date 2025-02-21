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
#include "gamesDefs.h"
#include "mainWin.h"
#include "gameWin.h"
#include "qPainter.h"

#include "pagePanel.h"
#include "pageMosaic.h"

using namespace qLib;


/*******************************************************************************
* GameWin::GameWin
*******************************************************************************/
GameWin::GameWin(QWidget *_pParent)
: QWidget(_pParent)
{
} // GameWin::GameWin


/*******************************************************************************
* GameWin::~GameWin
*******************************************************************************/
GameWin::~GameWin()
{
} // GameWin::~GameWin


/*******************************************************************************
* GameWin::SetPage
*******************************************************************************/
void GameWin::SetPage(enumPages                 _enumPage,
                      std::shared_ptr<GameInfo> _pGameInfo) // can be nullptr
{
    m_pGameInfo = _pGameInfo;

    // close the previous page
    if (m_pPage != nullptr)
    {
        m_pPage->close();
        m_pPage = nullptr;
    }

    // create the new page
    switch (_enumPage)
    {
        default:
            break;

        case enumPages::PanelFigureTeam_1:
        case enumPages::PanelFigureTeam_2:
        case enumPages::PanelWinners:
            m_pPage = new PagePanel(_enumPage);
            break;

        case enumPages::Mosaic:
            m_pPage = new PageMosaic(m_pGameInfo);
            break;
    } // switch

    if (m_pPage != nullptr)
    {
        m_pPage->setParent(this);
        m_pPage->show();
    }

    ResizePage();
    OnSessionDataChanged();
} // GameWin::SetPage


/*******************************************************************************
* GameWin::mouseDoubleClickEvent
*******************************************************************************/
void GameWin::mouseDoubleClickEvent(QMouseEvent */*_pEvent*/)
{
    if (isMaximized())
    {
        setWindowFlags(windowFlags() & ~Qt::FramelessWindowHint);
        showNormal();
    }
    else
    {
        setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
        showMaximized();
    }
} // GameWin::mouseDoubleClickEvent


/*******************************************************************************
* GameWin::OnSessionDataChanged
*******************************************************************************/
void GameWin::OnSessionDataChanged()
{
    CHECK_PRE_CONDITION_VOID(m_pPage != nullptr);

    // set to parent size
    m_pPage->OnSessionDataChanged();
} // GameWin::OnSessionDataChanged


/*******************************************************************************
* GameWin::BuzzerPressed
*******************************************************************************/
void GameWin::BuzzerPressed(s32 _s32Team)
{
    CHECK_PRE_CONDITION_VOID(m_pPage != nullptr);

    // set to parent size
    m_pPage->BuzzerPressed(_s32Team);
} // GameWin::BuzzerPressed


/*******************************************************************************
* GameWin::SetRI
*******************************************************************************/
void GameWin::SetRI(std::shared_ptr<RoundInfo> _pRI)
{
    m_pRoundInfo = _pRI;
} // GameWin::SetRI


/*******************************************************************************
* GameWin::StartRound
*******************************************************************************/
void GameWin::StartRound()
{
    CHECK_PRE_CONDITION_VOID(m_pPage != nullptr);
    CHECK_PRE_CONDITION_VOID(m_pGameInfo != nullptr);
    CHECK_PRE_CONDITION_VOID(m_pRoundInfo != nullptr);

    m_pPage->StartRound(m_pGameInfo, m_pRoundInfo);
} // GameWin::StartRound


/*******************************************************************************
* GameWin::CloseRound
*******************************************************************************/
void GameWin::CloseRound()
{
    CHECK_PRE_CONDITION_VOID(m_pPage != nullptr);
    CHECK_PRE_CONDITION_VOID(m_pGameInfo != nullptr);
    CHECK_PRE_CONDITION_VOID(m_pRoundInfo != nullptr);

    m_pRoundInfo = nullptr;

    m_pPage->CloseRound();
} // GameWin::CloseRound


/*******************************************************************************
* GameWin::ResizePage
*******************************************************************************/
void GameWin::ResizePage()
{
    CHECK_PRE_CONDITION_VOID(m_pPage != nullptr);

    // set to parent size
    m_pPage->setGeometry(0, 0, width(), height());
} // GameWin::ResizePage


/*******************************************************************************
* GameWin::resizeEvent
*******************************************************************************/
void GameWin::resizeEvent(QResizeEvent */*_pEvent*/)
{
    ResizePage();
} // GameWin::resizeEvent
