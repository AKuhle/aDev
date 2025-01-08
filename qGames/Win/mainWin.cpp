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
#include "ui_mainWin.h"

#include "qFile.h"
#include "qPath.h"
#include "qString16.h"

#include "gamesDefs.h"
#include "mainWin.h"
#include "gameWin.h"
#include "gameInfo.h"
#include "roundInfo.h"


using namespace qLib;
using namespace std;


/*******************************************************************************
* statics
*******************************************************************************/
MainWin *MainWin::m_pMainWin    { nullptr };
qFont   MainWin::m_prettyFont   {"Gigi"};
qFont   MainWin::m_gameFont     {"Lucida Calligraphy"};


/*******************************************************************************
* GetMainWin
*******************************************************************************/
MainWin& GetMainWin()
{
    return MainWin::GetMainWin();
} // GetMainWin


/*******************************************************************************
* GetVarPool
*******************************************************************************/
GamesVarPool& GetVarPool()
{
    MainWin &mw = GetMainWin();

    return mw.GetVarPool();
} // GetVarPool


/*******************************************************************************
* GetPrettyFont
*******************************************************************************/
const qFont& GetPrettyFont()
{
    MainWin &mw = GetMainWin();

    return mw.GetPrettyFont();
} // GetPrettyFont


/*******************************************************************************
* GetGameFont
*******************************************************************************/
const qFont& GetGameFont()
{
    MainWin &mw = GetMainWin();

    return mw.GetGameFont();
} // GetGameFont


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin(QWidget *_pParent)
: QMainWindow(_pParent),
  m_pUI(new Ui::MainWin)
{
    m_pMainWin = this;

    m_pUI->setupUi(this);

    InitData();

    InitCtrls();

    // create the game win
    m_pGameWin = new GameWin;
    m_pGameWin->show();
    m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    delete m_pUI;
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::closeEvent
*******************************************************************************/
void MainWin::closeEvent(QCloseEvent *_pEvent)
{
    GamesVarPool    &vp = GetVarPool();

    // write the var pool
    qPath   sPath = GetAppPath() + PATH_JSON + FILENAME_VAR_POOL;
    vp.WriteToJsonFile(sPath.GetCanonicalPath());

    // close the game win
    m_pGameWin->close();

    _pEvent->accept();
} // MainWin::closeEvent


/*******************************************************************************
* MainWin::keyPressEvent
*******************************************************************************/
void MainWin::keyPressEvent(QKeyEvent *_pEvent)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    switch (_pEvent->key())
    {
        default:
            break;

        case Qt::Key_1:
            m_pGameWin->BuzzerPressed(TEAM_1);
            break;

        case Qt::Key_2:
            m_pGameWin->BuzzerPressed(TEAM_2);
            break;
    }

    _pEvent->accept();
} // MainWin::keyPressEvent


/*******************************************************************************
* MainWin::InitData
*******************************************************************************/
void MainWin::InitData()
{
    // array for game type iterations
    m_vecGameTypes.push_back(enumGameType::LetterSum);
    m_vecGameTypes.push_back(enumGameType::Mosaic);
} // MainWin::InitData


/*******************************************************************************
* MainWin::InitCtrls
*******************************************************************************/
void MainWin::InitCtrls()
{
    // session menu
    connect(m_pUI->m_pActionLoadSession, SIGNAL(triggered(bool)), this, SLOT(SlotLoadSessionTriggered(bool)));
    connect(m_pUI->m_pActionSaveSession, SIGNAL(triggered(bool)), this, SLOT(SlotSaveSessionTriggered(bool)));
    connect(m_pUI->m_pActionRestoreSession, SIGNAL(triggered(bool)), this, SLOT(SlotRestoreSessionTriggered(bool)));

    // settings menu
    connect(m_pUI->m_pActionSetPrettyFont, SIGNAL(triggered(bool)), this, SLOT(SlotSetPrettyFontTriggered(bool)));
    connect(m_pUI->m_pActionSetGameFont, SIGNAL(triggered(bool)), this, SLOT(SlotSetGameFontTriggered(bool)));

    // figures and load session
    connect(m_pUI->m_pBtnFigures1, SIGNAL(clicked(bool)), this, SLOT(SlotFigures1Clicked(bool)));
    connect(m_pUI->m_pBtnRestoreSession, SIGNAL(clicked(bool)), this, SLOT(SlotRestoreSessionTriggered(bool)));
    connect(m_pUI->m_pBtnFigures2, SIGNAL(clicked(bool)), this, SLOT(SlotFigures2Clicked(bool)));

    // tree mode: all games / session games
    connect(m_pUI->m_pBtnAllGames, SIGNAL(clicked(bool)), this, SLOT(SlotAllGamesClicked(bool)));
    connect(m_pUI->m_pBtnSessionGames, SIGNAL(clicked(bool)), this, SLOT(SlotSessionGamesClicked(bool)));

    // round tree
    connect(m_pUI->m_pRoundList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
                                        this, SLOT(SlotCurrentRoundChanged(QListWidgetItem*,QListWidgetItem*)));

    // buttons
    connect(m_pUI->m_pBtnStartRound, SIGNAL(clicked(bool)), this, SLOT(SlotStartRound(bool)));
    connect(m_pUI->m_pBtnCloseRound, SIGNAL(clicked(bool)), this, SLOT(SlotCloseRound(bool)));

    connect(m_pUI->m_pBtnTeam1Plus, SIGNAL(clicked(bool)), this, SLOT(SlotTeam1Plus(bool)));
    connect(m_pUI->m_pBtnTeam1Minus, SIGNAL(clicked(bool)), this, SLOT(SlotTeam1Minus(bool)));
    connect(m_pUI->m_pBtnTeam2Plus, SIGNAL(clicked(bool)), this, SLOT(SlotTeam2Plus(bool)));
    connect(m_pUI->m_pBtnTeam2Minus, SIGNAL(clicked(bool)), this, SLOT(SlotTeam2Minus(bool)));

    connect(m_pUI->m_pBtnTeam1Won, SIGNAL(clicked(bool)), this, SLOT(SlotTeam1Won(bool)));
    connect(m_pUI->m_pBtnTeam2Won, SIGNAL(clicked(bool)), this, SLOT(SlotTeam2Won(bool)));
    connect(m_pUI->m_pBtnBothWon, SIGNAL(clicked(bool)), this, SLOT(SlotTeamBothWon(bool)));
} // MainWin::InitCtrls


/*******************************************************************************
* MainWin::UpdateCtrls
*******************************************************************************/
void MainWin::UpdateCtrls()
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    bool    bGame   = (m_pGameWin->GetCurrentGI() != nullptr);
    bool    bRound  = (m_pGameWin->GetCurrentRI() != nullptr);

    // team info
    const TeamInfo  &t1 = GetTeamInfo(TEAM_1);
    const TeamInfo  &t2 = GetTeamInfo(TEAM_2);

    m_pUI->m_pImageTeam1->setPixmap(t1.GetPixmap().scaled(50, 50, Qt::KeepAspectRatio));
    m_pUI->m_pNameTeam1->setText(t1.GetName().ToQString());

    m_pUI->m_pImageTeam2->setPixmap(t2.GetPixmap().scaled(50, 50, Qt::KeepAspectRatio));
    m_pUI->m_pNameTeam2->setText(t2.GetName().ToQString());

    // update the game tree mode
    m_pUI->m_pBtnAllGames->setEnabled(!bGame);
    m_pUI->m_pBtnSessionGames->setEnabled(!bGame);

    // update the game tree
    m_pUI->m_pGameTree->setEnabled(!bGame);

    // update the round list
    m_pUI->m_pRoundList->setEnabled(bGame && !bRound);

    // update the buttons
    m_pUI->m_pBtnStartRound->setEnabled(bGame && !bRound);
    m_pUI->m_pBtnCloseRound->setEnabled(bGame && bRound);

    m_pUI->m_pBtnTeam1Plus->setEnabled(bGame && bRound);
    m_pUI->m_pBtnTeam1Minus->setEnabled(bGame && bRound);
    m_pUI->m_pBtnTeam2Plus->setEnabled(bGame && bRound);
    m_pUI->m_pBtnTeam2Minus->setEnabled(bGame && bRound);

    if (GetTeamInfo(TEAM_1).GetName() != "")
    {
        m_pUI->m_pBtnTeam1Plus->setText(QString("+ ") + GetTeamInfo(TEAM_1).GetName().ToQString());
        m_pUI->m_pBtnTeam1Minus->setText(QString("- ") + GetTeamInfo(TEAM_1).GetName().ToQString());
    }

    if (GetTeamInfo(TEAM_2).GetName() != "")
    {
        m_pUI->m_pBtnTeam2Plus->setText(QString("+ ") + GetTeamInfo(TEAM_2).GetName().ToQString());
        m_pUI->m_pBtnTeam2Minus->setText(QString("- ") + GetTeamInfo(TEAM_2).GetName().ToQString());
    }

    m_pUI->m_pBtnTeam1Won->setEnabled(bGame && !bRound);
    m_pUI->m_pBtnTeam2Won->setEnabled(bGame&& !bRound);
    m_pUI->m_pBtnBothWon->setEnabled(bGame&& !bRound);
} // MainWin::UpdateCtrls


/*******************************************************************************
* MainWin::UpateGameTree
*******************************************************************************/
void MainWin::UpateGameTree()
{
    // delete previous content
    m_pUI->m_pGameTree->clear();

    if (m_pUI->m_pBtnAllGames->isChecked())
    {
        UpateGameTreeAll();
    }
    else
    {
        UpateGameTreeSession();
    }
} // MainWin::UpateGameTree


/*******************************************************************************
* MainWin::UpateGameTreeAll
*******************************************************************************/
void MainWin::UpateGameTreeAll()
{
    QStringList lstHeader;
    QIcon       iconDice(":/Icon/dice.png");

    // column count
    m_pUI->m_pGameTree->setColumnCount(3);

    // set the header
    lstHeader << "Type" << "Name" << "Category";
    m_pUI->m_pGameTree->setHeaderLabels(lstHeader);

    // iterate over all game types
    for (enumGameType eGT : m_vecGameTypes)
    {
        QTreeWidgetItem *pTopLevel = new QTreeWidgetItem();
        pTopLevel->setText(0, GameInfo::GetTypeString(eGT).ToQString());
        pTopLevel->setIcon(0, iconDice);

        // iterate over all games
        for (shared_ptr<GameInfo> &pGame : m_vecAllGames)
        {
            if (pGame->GetType() == eGT)
            {
                QTreeWidgetItem *pChild = new QTreeWidgetItem();
                pChild->setText(1, pGame->GetName().ToQString());
                pChild->setText(2, pGame->GetCategory().ToQString());

                pTopLevel->addChild(pChild);
            }
        }

        m_pUI->m_pGameTree->addTopLevelItem(pTopLevel);
    }

} // MainWin::UpateGameTreeAll


/*******************************************************************************
* MainWin::UpateGameTreeSession
*******************************************************************************/
void MainWin::UpateGameTreeSession()
{
    QStringList lstHeader;

    // column count
    m_pUI->m_pGameTree->setColumnCount(3);

    // set the header
    lstHeader << "Category" << "Name" << "Type";
    m_pUI->m_pGameTree->setHeaderLabels(lstHeader);

    // iterate over session games
    for (shared_ptr<GameInfo> pGI : m_vecSessionGames)
    {
        QTreeWidgetItem *pTopLevel = new QTreeWidgetItem();
        pTopLevel->setText(0, pGI->GetCategory().ToQString());
        pTopLevel->setText(1, pGI->GetName().ToQString());
        pTopLevel->setText(2, GameInfo::GetTypeString(pGI->GetType()).ToQString());

        m_pUI->m_pGameTree->addTopLevelItem(pTopLevel);
    }
} // MainWin::UpateGameTreeSession


/*******************************************************************************
* MainWin::UpateRoundTree
*******************************************************************************/
void MainWin::UpateRoundTree()
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    shared_ptr<GameInfo>    pGI = m_pGameWin->GetCurrentGI();
    qColor                  colExample = qColor::FromU8(230, 251, 197);

    m_pUI->m_pRoundList->clear();

    if (pGI != nullptr)
    {
        const qSharedPtrList<RoundInfo> &ri = pGI->GetRoundInfo();

        // example at the top
        if (pGI->GetExample() != nullptr)
        {
            QListWidgetItem *pLWI = new QListWidgetItem(pGI->GetExample()->GetName().ToQString());
            pLWI->setBackground(QBrush(colExample.ToQColor()));
            m_pUI->m_pRoundList->addItem(pLWI);
        }

        for (const shared_ptr<RoundInfo> &pRI : ri)
        {
            QListWidgetItem *pLWI = new QListWidgetItem(pRI->GetName().ToQString());
            pLWI->setBackground(QBrush(colGrey90.ToQColor()));
            m_pUI->m_pRoundList->addItem(pLWI);
        }
    }
} // MainWin::UpateRoundTree


/*******************************************************************************
* MainWin::GetSelectedRound
*******************************************************************************/
qString16 MainWin::GetSelectedRound() const
{
    qString16           sRound;
    QListWidgetItem     *pLWI = m_pUI->m_pRoundList->currentItem();

    if (pLWI != nullptr)
    {
        sRound = qString16::FromQString(pLWI->text());
    }

    return sRound;
} // MainWin::GetSelectedRound


/*******************************************************************************
* MainWin::CalculatePointsForNextGame
*******************************************************************************/
s32 MainWin::CalculatePointsForNextGame() const
{
    s32 s32Points = 1;

    for (const shared_ptr<GameInfo> &pGI : m_vecSessionGames)
    {
        // each finished game increases the points for the next game
        if (pGI->GetGamePoints() > 0)
        {
            s32Points++;
        }
    }

    return s32Points;
} // MainWin::CalculatePointsForNextGame


/*******************************************************************************
* MainWin::GetMainWin
*******************************************************************************/
MainWin& MainWin::GetMainWin()
{
    return *m_pMainWin;
} // MainWin::GetMainWin


/*******************************************************************************
* MainWin::GetVarPool
*******************************************************************************/
GamesVarPool& MainWin::GetVarPool()
{
    return m_varPool;
} // MainWin::GetVarPool


/*******************************************************************************
* MainWin::ParseArgs
*******************************************************************************/
void MainWin::ParseArgs(int     /*_argc*/,
                        char    *_argv[])
{
    qString16       sArgv0(_argv[0]);
    qString16       sExt;

    // save the program name
   qFile::SplitPath(sArgv0, m_sProgramPath, m_sProgramName, sExt, m_sProgramFullName);

    ReadAllGames();

   UpdateCtrls();
} // MainWin::ParseArgs


/*******************************************************************************
* MainWin::GetAppPath
*******************************************************************************/
qPath MainWin::GetAppPath() const
{
    return m_sProgramPath;
} // MainWin::GetAppPath


/*******************************************************************************
* MainWin::GetJsonPath
*******************************************************************************/
qPath MainWin::GetJsonPath() const
{
    qPath p = GetAppPath() + PATH_JSON;

    return p.GetCanonicalPath();
} // MainWin::GetJsonPath


/*******************************************************************************
* MainWin::GetGameDataPath
*******************************************************************************/
qPath MainWin::GetGameDataPath() const
{
    qPath p = GetAppPath() + PATH_GAME_DATA;

    return p.GetCanonicalPath();
} // MainWin::GetGameDataPath


/*******************************************************************************
* MainWin::GetFiguresPath
*******************************************************************************/
qPath MainWin::GetFiguresPath() const
{
    qPath p = GetAppPath() + PATH_GAME_DATA;

    return p.GetCanonicalPath();
} // MainWin::GetFiguresPath


/*******************************************************************************
* MainWin::GetTeamInfo
*******************************************************************************/
const TeamInfo& MainWin::GetTeamInfo(s32 _s32Team) const
{
    return m_teamInfo[_s32Team - 1];
} // MainWin::GetTeamInfo


/*******************************************************************************
* MainWin::GetTeamInfo
*******************************************************************************/
TeamInfo& MainWin::GetTeamInfo(s32 _s32Team)
{
    return m_teamInfo[_s32Team - 1];
} // MainWin::GetTeamInfo


/*******************************************************************************
* MainWin::FindGameByNameInAllGames
*******************************************************************************/
shared_ptr<GameInfo> MainWin::FindGameByNameInAllGames(const qString16 &_sName)
{
    shared_ptr<GameInfo>    pGame;

    for (shared_ptr<GameInfo> &p : m_vecAllGames)
    {
        if (p->GetName() == _sName)
        {
            pGame = p;
            break;
        }
    } // for

    return pGame;
} // MainWin::FindGameByNameInAllGames


/*******************************************************************************
* MainWin::FindGameByNameInSessionGames
*******************************************************************************/
shared_ptr<GameInfo> MainWin::FindGameByNameInSessionGames(const qString16 &_sName)
{
    shared_ptr<GameInfo>    pGame;

    for (shared_ptr<GameInfo> &p : m_vecSessionGames)
    {
        if (p->GetName() == _sName)
        {
            pGame = p;
            break;
        }
    } // for

    return pGame;
} // MainWin::FindGameByNameInSessionGames


/*******************************************************************************
* MainWin::OnSessionDataChanged
*******************************************************************************/
void MainWin::OnSessionDataChanged()
{
    if (m_pGameWin != nullptr)
    {
        m_pGameWin->OnSessionDataChanged();
    }
} // MainWin::OnSessionDataChanged


/*******************************************************************************
* MainWin::OnFigureSelected
*******************************************************************************/
void MainWin::OnFigureSelected(enumPages    _ePages,
                               qString16    _sFigurePath)
{
    switch (_ePages)
    {
        default:
            break;

        case enumPages::PanelFigureTeam_1:
        {
            GetTeamInfo(TEAM_1).SetFigureFileName(_sFigurePath);
            m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);
            break;
        }

        case enumPages::PanelFigureTeam_2:
        {
            GetTeamInfo(TEAM_2).SetFigureFileName(_sFigurePath);
            m_pGameWin->SetPage(enumPages::PanelWinners, nullptr);
            break;
        }
    } // switch (m_ePagePanelMode)

    UpdateCtrls();
} // MainWin::OnFigureSelected


/*******************************************************************************
* MainWin::OnGameSelected
*******************************************************************************/
void MainWin::OnGameSelected(std::shared_ptr<GameInfo> _pGameInfo)
{
    // if the game info already has points => nothing will be changed
    _pGameInfo->SetGamePoints(CalculatePointsForNextGame());

    StartGame(_pGameInfo);
} // MainWin::OnGameSelected


/*******************************************************************************
* MainWin::StartGame
*******************************************************************************/
void MainWin::StartGame(std::shared_ptr<GameInfo> _pGameInfo)
{
    CHECK_PRE_CONDITION_VOID(m_pGameWin != nullptr);

    switch (_pGameInfo->GetType())
    {
        default:
            break;

        case enumGameType::Mosaic:
            m_pGameWin->SetPage(enumPages::Mosaic, _pGameInfo);
            break;
    }

    // update the controls
    UpdateCtrls();
    UpateGameTree();
    UpateRoundTree();
} // MainWin::StartGame


/*******************************************************************************
* MainWin::String2Type
*******************************************************************************/
enumGameType MainWin::String2Type(const qString16 &_sType) const
{
    if (_sType == "LETTER_SUM")
        return enumGameType::LetterSum;

    if (_sType == "MOSAIC")
        return enumGameType::Mosaic;

    return enumGameType::Undefined;
} // MainWin::String2Type
