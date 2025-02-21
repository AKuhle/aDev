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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QtWidgets>

#include "qString16.h"
#include "qVec.h"
#include "qSharedPtrList.h"
#include "qPath.h"

#include "gamesDefs.h"
#include "gamesVarPool.h"
#include "teamInfo.h"
#include "gameInfo.h"
#include "qFont.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE


/*******************************************************************************
* forwards
*******************************************************************************/
class MainWin;
class GameWin;
class GameInfo;


/*******************************************************************************
* global function
*******************************************************************************/
MainWin&            GetMainWin();
GamesVarPool&       GetVarPool();

const qFont&        GetPrettyFont();
const qFont&        GetGameFont();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWin                     *m_pUI          { nullptr };
        static MainWin*                 m_pMainWin;
        GameWin                         *m_pGameWin     { nullptr };

        static qFont                    m_prettyFont;
        static qFont                    m_gameFont;

        qLib::qString16                 m_sProgramPath;
        qLib::qString16                 m_sProgramName;
        qLib::qString16                 m_sProgramFullName;

        GamesVarPool                    m_varPool;

        TeamInfo                        m_teamInfo[2];
        qVec<std::shared_ptr<GameInfo>> m_vecAllGames;
        qVec<std::shared_ptr<GameInfo>> m_vecSessionGames;

        // arrays for iteration
        qVec<enumGameType>              m_vecGameTypes;

    public:
        MainWin(QWidget *_pParent = nullptr);
        ~MainWin();

        static MainWin&                         GetMainWin();
        GamesVarPool&                           GetVarPool();

        static const qFont&                     GetPrettyFont()     { return m_prettyFont; }
        static const qFont&                     GetGameFont()       { return m_gameFont; }

        void                                    ParseArgs(int   _argc,
                                                          char  *_argv[]);

        // team info
        const TeamInfo&                         GetTeamInfo(s32 _s32Team) const;
        TeamInfo&                               GetTeamInfo(s32 _s32Team);

        qLib::qPath                             GetGameDataPath() const;

        // all games: game info
        std::shared_ptr<GameInfo>               FindGameByNameInAllGames(const qString16 &_sName);

        // session games: game info
        const qVec<std::shared_ptr<GameInfo>>&  GetSessionGames() const { return m_vecSessionGames; }
        std::shared_ptr<GameInfo>               FindGameByNameInSessionGames(const qString16 &_sName);

        std::shared_ptr<RoundInfo>              FindRoundByName(std::shared_ptr<GameInfo> _pGI,
                                                                const qString16           &_sName);

        void                                    OnSessionDataChanged();

        // handler
        void                                    OnFigureSelected(enumPages          _ePages,
                                                                 qLib::qString16    _sFigurePath);

        void                                    OnGameSelected(std::shared_ptr<GameInfo> _pGameInfo);


        qLib::qPath                             GetAppPath() const;

    private:
        qLib::qPath                             GetJsonPath() const;
        qLib::qPath                             GetFiguresPath() const;

        void                                    InitData();
        void                                    InitCtrls();
        void                                    UpdateCtrls();

        void                                    StartGame(std::shared_ptr<GameInfo> _pGameInfo);

        void                                    UpateGameTree();
        void                                    UpateGameTreeAll();
        void                                    UpateGameTreeSession();

        void                                    UpateRoundTree();
        qString16                               GetSelectedRound() const;

        s32                                     CalculatePointsForNextGame() const;

        enumGameType                            String2Type(const qString16 &_sType) const;

        void                                    ReadAllGames();
        void                                    ReadSession(const qString16 &_sFileName);

        void                                    ReaAllFilesCallback(qVec<qString16>     &_vecKeys,
                                                                    const QJsonValue    &_value);

        void                                    ReadSessionCallback(qVec<qString16>     &_vecKeys,
                                                                    const QJsonValue    &_value);

        void                                    RestoreSessionCallback(qVec<qString16>  &_vecKeys,
                                                                       const QJsonValue &_value);

    protected:
        virtual void                            closeEvent(QCloseEvent *_pEvent) override;
        virtual void                            keyPressEvent(QKeyEvent *_pEvent) override;

    private slots:
        // session menu
        void                                    SlotLoadSessionTriggered(bool _bChecked);
        void                                    SlotSaveSessionTriggered(bool _bChecked);
        void                                    SlotRestoreSessionTriggered(bool _bChecked);

        // setting menu
        void                                    SlotSetPrettyFontTriggered(bool _bChecked);
        void                                    SlotSetGameFontTriggered(bool _bChecked);

        void                                    SlotFigures1Clicked(bool _bChecked);
        void                                    SlotFigures2Clicked(bool _bChecked);

        // game area
        void                                    SlotAllGamesClicked(bool _bChecked);
        void                                    SlotSessionGamesClicked(bool _bChecked);

        void                                    SlotCurrentRoundChanged(QListWidgetItem *_pCurrent,
                                                                        QListWidgetItem *_pPrev);

        // button area
        void                                    SlotStartRound(bool _bChecked);
        void                                    SlotCloseRound(bool _bChecked);

        void                                    SlotTeam1Plus(bool _bChecked);
        void                                    SlotTeam1Minus(bool _bChecked);
        void                                    SlotTeam2Plus(bool _bChecked);
        void                                    SlotTeam2Minus(bool _bChecked);

        void                                    SlotTeam1Won(bool _bChecked);
        void                                    SlotTeam2Won(bool _bChecked);
        void                                    SlotTeamBothWon(bool _bChecked);
}; // class MainWin

