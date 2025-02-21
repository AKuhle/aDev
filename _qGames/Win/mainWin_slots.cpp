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
#include "qVec.h"

#include <QMessageBox>

#include "ui_mainWin.h"

#include "mainWin.h"
#include "gamesDefs.h"
#include "gameWin.h"
#include "qSysDlg.h"
#include "qJsonFile.h"
#include "qJsonValue.h"
#include "gameInfo.h"

using namespace qLib;
using namespace std;


/*******************************************************************************
* MainWin::SlotFigures1Clicked
*******************************************************************************/
void MainWin::SlotFigures1Clicked(bool /*_bChecked*/)
{
    m_pGameWin->SetPage(enumPages::PanelFigureTeam_1, nullptr);
} // MainWin::SlotFigures1Clicked


/*******************************************************************************
* MainWin::SlotFigures2Clicked
*******************************************************************************/
void MainWin::SlotFigures2Clicked(bool /*_bChecked*/)
{
    m_pGameWin->SetPage(enumPages::PanelFigureTeam_2, nullptr);
} // MainWin::SlotFigures2Clicked


/*******************************************************************************
* MainWin::SlotLoadSessionTriggered
*******************************************************************************/
void MainWin::SlotLoadSessionTriggered(bool /*_bChecked*/)
{
    static qPath    sPath       = GetJsonPath();

    qString16           sTitle { "Open Session" };
    qString16           sFilter;

    sFilter		=	"JSON - File (*.json)";
    sFilter		+=	";;All Files (*.*)";

    qString16 sFileName = qSysDlg::GetFileOpenName(sTitle, sPath.GetCanonicalPath(), sFilter);

    if (sFileName != "")
    {
        ReadSession(sFileName);

        UpdateCtrls();
        UpateGameTree();
        UpateRoundTree();
    }
} // MainWin::SlotLoadSessionTriggered


/*******************************************************************************
* MainWin::SlotRestoreSessionTriggered
*******************************************************************************/
void MainWin::SlotRestoreSessionTriggered(bool /*_bChecked*/)
{
    static qPath    sPath   = GetJsonPath() + FILENAME_CURRENT_SESSION;
    qJsonFile       f(sPath.GetCanonicalPath());

    // clear the session games
    m_vecSessionGames.clear();

    // read all entries
    f.ReadAllValues([this](qVec<qString16> &_vecKeys, const QJsonValue &_value)
    {
        this->RestoreSessionCallback(_vecKeys, _value);
    });

    // update
    UpdateCtrls();
    UpateGameTree();
    UpateRoundTree();

    OnSessionDataChanged();
} // MainWin::SlotRestoreSessionTriggered


/*******************************************************************************
* MainWin::SlotSetPrettyFontTriggered
*******************************************************************************/
void MainWin::SlotSetPrettyFontTriggered(bool /*_bChecked*/)
{
    bool bOk;

    QFont   f = QFontDialog::getFont(&bOk, m_prettyFont.ToQFont());

    if (bOk)
    {
        m_prettyFont.SetFont(f);
        OnSessionDataChanged();
    }
} // MainWin::SlotSetPrettyFontTriggered


/*******************************************************************************
* MainWin::SlotSetGameFontTriggered
*******************************************************************************/
void MainWin::SlotSetGameFontTriggered(bool /*_bChecked*/)
{
    bool bOk;

    QFont   f = QFontDialog::getFont(&bOk, m_prettyFont.ToQFont());

    if (bOk)
    {
        m_gameFont.SetFont(f);
        OnSessionDataChanged();
    }
} // MainWin::SlotSetGameFontTriggered


/*******************************************************************************
* MainWin::ReadAllGames
*******************************************************************************/
void MainWin::ReadAllGames()
{
    qPath       sPath   = GetJsonPath() + FILENAME_ALL_GAMES;
    qJsonFile   jFile(sPath.GetCanonicalPath());

    // delete previous content
    m_vecAllGames.clear();

    // read all entries
    jFile.ReadAllValues([this](qVec<qString16> &_vecKeys, const QJsonValue &_value) {
        this->ReaAllFilesCallback(_vecKeys, _value);
    });

    for (shared_ptr<GameInfo> &pGi : m_vecAllGames)
    {
        pGi->CalculateRoundInfos();
    }

    UpdateCtrls();
    UpateGameTree();
    UpateRoundTree();
} // MainWin::ReadAllGames


/*******************************************************************************
* MainWin::ReadSession
*******************************************************************************/
void MainWin::ReadSession(const qString16 &_sFileName)
{
    qJsonFile       jFile(_sFileName);

    // delete previous content
    m_vecSessionGames.clear();

    // read all entries
    jFile.ReadAllValues([this](qVec<qString16> &_vecKeys, const QJsonValue &_value) {
        this->ReadSessionCallback(_vecKeys, _value);
    });

    if (m_vecSessionGames.size() != GAME_COUNT)
    {
        m_vecSessionGames.clear();

        QMessageBox::warning(this, QString("Error"), QString("Session must have 16 games"));
    }

    OnSessionDataChanged();
} // MainWin::ReadSession


/*******************************************************************************
* MainWin::SlotAllGamesClicked
*******************************************************************************/
void MainWin::SlotAllGamesClicked(bool /*_bChecked*/)
{
    UpdateCtrls();
    UpateGameTree();
    UpateRoundTree();
} // MainWin::SlotAllGamesClicked


/*******************************************************************************
* MainWin::SlotStartRound
*******************************************************************************/
void MainWin::SlotStartRound(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    shared_ptr<GameInfo>    pGI         = m_pGameWin->GetCurrentGI();
    QListWidgetItem         *pCurrent   = m_pUI->m_pRoundList->currentItem();

    if (pGI != nullptr && pCurrent != nullptr)
    {

        shared_ptr<RoundInfo> pRI = pGI->FindRoundByName(qString16::FromQString(pCurrent->text()));

        m_pGameWin->SetRI(pRI);
        m_pGameWin->StartRound();
    }

    UpdateCtrls();
} // MainWin::SlotStartRound


/*******************************************************************************
* MainWin::SlotCloseRound
*******************************************************************************/
void MainWin::SlotCloseRound(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    m_pGameWin->CloseRound();

    UpdateCtrls();
} // MainWin::SlotCloseRound


/*******************************************************************************
* MainWin::SlotTeam1Plus
*******************************************************************************/
void MainWin::SlotTeam1Plus(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    std::shared_ptr<RoundInfo>  pRI = m_pGameWin->GetCurrentRI();
    CHECK_PRE_CONDITION_VOID(pRI != nullptr);

    pRI->AddWinner(TEAM_1);

    m_pGameWin->OnSessionDataChanged();
} // MainWin::SlotTeam1Plus


/*******************************************************************************
* MainWin::SlotTeam1Minus
*******************************************************************************/
void MainWin::SlotTeam1Minus(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    std::shared_ptr<RoundInfo>  pRI = m_pGameWin->GetCurrentRI();
    CHECK_PRE_CONDITION_VOID(pRI != nullptr);

    pRI->RemoveWinner(TEAM_1);

    m_pGameWin->OnSessionDataChanged();
} // MainWin::SlotTeam1Minus


/*******************************************************************************
* MainWin::SlotTeam2Plus
*******************************************************************************/
void MainWin::SlotTeam2Plus(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    std::shared_ptr<RoundInfo>  pRI = m_pGameWin->GetCurrentRI();
    CHECK_PRE_CONDITION_VOID(pRI != nullptr);

    pRI->AddWinner(TEAM_2);

    m_pGameWin->OnSessionDataChanged();
} // MainWin::SlotTeam1Plus


/*******************************************************************************
* MainWin::SlotTeam2Minus
*******************************************************************************/
void MainWin::SlotTeam2Minus(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    std::shared_ptr<RoundInfo>  pRI = m_pGameWin->GetCurrentRI();
    CHECK_PRE_CONDITION_VOID(pRI != nullptr);

    pRI->RemoveWinner(TEAM_2);

    m_pGameWin->OnSessionDataChanged();
} // MainWin::SlotTeam2Minus


/*******************************************************************************
* MainWin::SlotTeam1Won
*******************************************************************************/
void MainWin::SlotTeam1Won(bool /*_bChecked*/)
{
    std::shared_ptr<GameInfo>   pGI = m_pGameWin->GetCurrentGI();

    pGI->SetWinner(TEAM_1);

    m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);

    UpdateCtrls();

    SlotSaveSessionTriggered(false);
} // MainWin::SlotTeam1Won


/*******************************************************************************
* MainWin::SlotTeam2Won
*******************************************************************************/
void MainWin::SlotTeam2Won(bool /*_bChecked*/)
{
    std::shared_ptr<GameInfo>   pGI = m_pGameWin->GetCurrentGI();

    pGI->SetWinner(TEAM_2);

    m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);

    UpdateCtrls();

    SlotSaveSessionTriggered(false);
} // MainWin::SlotTeam2Won


/*******************************************************************************
* MainWin::SlotTeamBothWon
*******************************************************************************/
void MainWin::SlotTeamBothWon(bool /*_bChecked*/)
{
    std::shared_ptr<GameInfo>   pGI = m_pGameWin->GetCurrentGI();

    pGI->SetWinner(TEAM_BOTH);

    m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);

    UpdateCtrls();

    SlotSaveSessionTriggered(false);
} // MainWin::SlotTeamBothWon


/*******************************************************************************
* MainWin::SlotSessionGamesClicked
*******************************************************************************/
void MainWin::SlotSessionGamesClicked(bool /*_bChecked*/)
{
    UpdateCtrls();
    UpateGameTree();
    UpateRoundTree();
} // MainWin::SlotSessionGamesClicked


/*******************************************************************************
* MainWin::SlotCurrentRoundChanged
*******************************************************************************/
void MainWin::SlotCurrentRoundChanged(QListWidgetItem *_pCurrent,
                                      QListWidgetItem */*_pPrev*/)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    shared_ptr<GameInfo> pGI = m_pGameWin->GetCurrentGI();

    if (pGI != nullptr)
    {
        shared_ptr<RoundInfo> pRI = pGI->FindRoundByName(qString16::FromQString(_pCurrent->text()));
    }

    UpdateCtrls();
} // MainWin::SlotCurrentRoundChanged


/*******************************************************************************
* MainWin::ReaAllFilesCallback
*******************************************************************************/
void MainWin::ReaAllFilesCallback(qVec<qString16>    &_vecKeys,
                                  const QJsonValue   &_value)
{
    s32                                 s32KeyIdx = _vecKeys.size() - 1;   // last index

    // index == 2 => game type
    // index == 1 => game name
    // index == 0 => category (or comment which is not beeing parsed)
    const s32   idxCategory = 0;
    const s32   idxName     = 1;
    const s32   idxGameInfo = 2;

    if (s32KeyIdx == idxGameInfo)
    {
        // check, whether we have a new game
        if (m_vecAllGames.empty() || (m_vecAllGames.back()->GetName() != _vecKeys.at(idxName)))
        {
            std::shared_ptr<GameInfo> pGI = make_shared<GameInfo>();

            pGI->SetCategory(_vecKeys.at(idxCategory));
            pGI->SetName(_vecKeys.at(idxName));

            m_vecAllGames.push_back(pGI);
        }

        if (_vecKeys.at(idxGameInfo) == "type")
        {
            m_vecAllGames.back()->SetType(String2Type(qString16::FromQString(_value.toString())));
        }

        else if (_vecKeys.at(idxGameInfo) == "Points2Win")
        {
            m_vecAllGames.back()->SetPoints2Win(_value.toInteger());
        }

        else if (_vecKeys.at(idxGameInfo) == "buzzertimer_s")
        {
            m_vecAllGames.back()->SetBuzzerTimer_s(_value.toInteger());
        }

        else if (_vecKeys.at(idxGameInfo) == "example")
        {
            m_vecAllGames.back()->SetExample(qString16::FromQString(_value.toString()));
        }

        else if (_vecKeys.at(idxGameInfo).Left(4) == "item")
        {
            m_vecAllGames.back()->AddItem(qString16::FromQString(_value.toString()));
        }
    }
} // MainWin::ReaAllFilesCallback


/*******************************************************************************
* MainWin::ReadSessionCallback
*******************************************************************************/
void MainWin::ReadSessionCallback(qVec<qString16>    &_vecKeys,
                                  const QJsonValue   &_value)
{

    if (_vecKeys.size() == 1)
    {
        if (_vecKeys.at(0).Left(10) == "game-name_")
        {
            std::shared_ptr<GameInfo> pGI = FindGameByNameInAllGames(qString16::FromQString(_value.toString()));

            if (pGI != nullptr)
            {
                m_vecSessionGames.push_back(pGI);
            }
        }
    }
} // MainWin::ReaSessionCallback


/*******************************************************************************
* MainWin::SlotSaveSessionTriggered
*******************************************************************************/
void MainWin::SlotSaveSessionTriggered(bool /*_bChecked*/)
{
    CHECK_PRE_CONDITION_VOID(m_vecSessionGames.size() == GAME_COUNT);

    static qPath    sPath   = GetJsonPath() + FILENAME_CURRENT_SESSION;
    qJsonFile       f(sPath.GetCanonicalPath());

    // write team infos
    f.OpenLevel();
        f.Add(qJsonValue("team1", GetTeamInfo(TEAM_1).GetFigureFileName()));
        f.Add(qJsonValue("team2", GetTeamInfo(TEAM_2).GetFigureFileName()));
    f.CloseLevel("teamInfo");

    f.OpenLevel();
        for (s32 i = 0; i < GAME_COUNT; i++)
        {
            shared_ptr<GameInfo> p = m_vecSessionGames[i];

            f.OpenLevel();
                // game title
                f.Add(qJsonValue("winner", p->GetWinner()));
                f.Add(qJsonValue("gamepoints", p->GetGamePoints()));
                f.Add(qJsonValue("points2win", p->GetPoints2Win()));
            f.CloseLevel(qString16("game-") + ((i<10)? "0" : "") + qString16::FromValue(i)
                         + "-" + p->GetName());
        }
    f.CloseLevel("gameInfo");

    // write the file
    f.Write2File();
} // MainWin::SlotSaveSessionTriggered


/*******************************************************************************
* MainWin::RestoreSessionCallback
*******************************************************************************/
void MainWin::RestoreSessionCallback(qVec<qString16>  &_vecKeys,
                                     const QJsonValue &_value)
{
    if (_vecKeys.at(0) == "teamInfo")
    {
        if (_vecKeys.at(1) == "team1")
            GetTeamInfo(TEAM_1).SetFigureFileName(qString16::FromQString(_value.toString()));

        else if (_vecKeys.at(1) == "team2")
            GetTeamInfo(TEAM_2).SetFigureFileName(qString16::FromQString(_value.toString()));
    }

    else if (_vecKeys.at(0) == "gameInfo")
    {
        qString16               sName   = _vecKeys.at(1).Substr(8);
        shared_ptr<GameInfo>    pGI     = FindGameByNameInSessionGames(sName);

        // check whether the gameinfo is already in the session
        if (pGI == nullptr)
        {
            pGI = FindGameByNameInAllGames(sName);

            if (pGI != nullptr)
            {
                m_vecSessionGames.push_back(pGI);
            }
        }

        if (pGI != nullptr)
        {
            if (_vecKeys.at(2) == "winner")
                pGI->SetWinner(_value.toInt());

            if (_vecKeys.at(2) == "gamepoints")
                pGI->SetGamePoints(_value.toInt());

            if (_vecKeys.at(2) == "points2win")
                pGI->SetPoints2Win(_value.toInt());
        }

        // check if the game is already in the session games
//            shared_ptr<GameInfo> pGI = FindGameByNameInSessionGames(const qString16 &_sName);
    }
} // MainWin::RestoreSessionCallback
