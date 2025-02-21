/*******************************************************************************
* \file GameInfo.h
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
#include <QPixmap>

#include "qVec.h"
#include "qString16.h"
#include "qSharedPtrList.h"
#include "qPath.h"

#include "gamesDefs.h"
#include "roundInfo.h"

using namespace qLib;


/*******************************************************************************
* class GameInfo
*******************************************************************************/
class GameInfo
{
    private:
        qString16                   m_sCategory;
        qString16                   m_sName;
        enumGameType                m_eType             { enumGameType::Undefined };
        s32                         m_s32Winner         { TEAM_NONE };
        s32                         m_s32GamePoints     { 0 };

        s32                         m_s32Points2Win     { 0 };
        s32                         m_s32BuzzerTimer_s  { 5 };

        qString16                   m_sExample;
        qVec<qString16>             m_vecItem;

        std::shared_ptr<RoundInfo>  m_pExample;
        qSharedPtrList<RoundInfo>   m_lstRoundInfo;


    public:
        GameInfo();
        ~GameInfo();

        // non mutabla members
        void                                SetCategory(const qString16 &_sCategory)    { m_sCategory = _sCategory; }
        qString16                           GetCategory() const                         { return m_sCategory; }

        void                                SetName(const qString16 &_sName)            { m_sName = _sName; }
        qString16                           GetName() const                             { return m_sName; }

        void                                SetType(const enumGameType _eType)          { m_eType = _eType; }
        enumGameType                        GetType() const                             { return m_eType; }
        qString16                           GetTypeString() const;
        static qString16                    GetTypeString(enumGameType _eType);

        void                                SetExample(const qString16 &_sExample);
        void                                AddItem(const qString16 &_sItem);

        // mutabla members (during the game is beeing played)
        void                                SetWinner(s32 _s32Winner)                   { m_s32Winner = _s32Winner; }
        s32                                 GetWinner() const                           { return m_s32Winner; }

        void                                SetGamePoints(s32 _s32GamePoints);
        s32                                 GetGamePoints() const                       { return m_s32GamePoints; }

        void                                SetPoints2Win(s32 _s32Points2Win)           { m_s32Points2Win = _s32Points2Win; }
        s32                                 GetPoints2Win() const                       { return m_s32Points2Win; }

        void                                SetBuzzerTimer_s(s32 _s32BuzzerTimer_s)     { m_s32BuzzerTimer_s = _s32BuzzerTimer_s; }
        s32                                 GetBuzzerTimer_s() const                    { return m_s32BuzzerTimer_s; }

        s32                                 GetRoundWinnerCount(s32 _s32Team);

        // can be called after all infos are loaded, because the
        // order of json-item are not defined
        void                                CalculateRoundInfos();

        qLib::qPath                         GetGamePath() const;

        const std::shared_ptr<RoundInfo>    GetExample() const                          { return m_pExample; }
        const qSharedPtrList<RoundInfo>&    GetRoundInfo() const                        { return m_lstRoundInfo; }

        std::shared_ptr<RoundInfo>          FindRoundByName(const qString16 &_sName);

    private:
        std::shared_ptr<RoundInfo>          Item2RoundInfo(const qString16 &_sItem);
}; // class GameInfo

