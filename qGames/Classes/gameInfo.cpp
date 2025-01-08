/*******************************************************************************
* \file GameInfo.cpp
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
#include "gameInfo.h"
#include "roundInfo.h"
#include "mainWin.h"

using namespace std;
using namespace qLib;


/*******************************************************************************
* GameInfo::GameInfo
*******************************************************************************/
GameInfo::GameInfo()
{
} // GameInfo::GameInfo


/*******************************************************************************
* GameInfo::~GameInfo
*******************************************************************************/
GameInfo::~GameInfo()
{
} // GameInfo::~GameInfo


/*******************************************************************************
* GameInfo::SetGamePoints
*******************************************************************************/
void GameInfo::SetGamePoints(s32 _s32GamePoints)
{
    if (m_s32GamePoints == 0)
    {
        m_s32GamePoints = _s32GamePoints;
    }
} // GameInfo::SetGamePoints


/*******************************************************************************
* GameInfo::GetTypeString
*******************************************************************************/
qString16 GameInfo::GetTypeString() const
{
    return GetTypeString (m_eType);
} // GameInfo::GetTypeString


/*******************************************************************************
* GameInfo::GetTypeString
*******************************************************************************/
qString16 GameInfo::GetTypeString(enumGameType _eType)
{
    switch (_eType)
    {
        case enumGameType::Undefined:       return "?";
        case enumGameType::LetterSum:       return "Letter Sum";
        case enumGameType::Mosaic:          return "Mosaic";
    }

    return "?";
} // GameInfo::GetTypeString


/*******************************************************************************
* GameInfo::SetExample
*******************************************************************************/
void GameInfo::SetExample(const qString16 &_sExample)
{
    m_sExample = _sExample;
} // GameInfo::SetExample


/*******************************************************************************
* GameInfo::Additem
*******************************************************************************/
void GameInfo::AddItem(const qString16 &_sItem)
{
    m_vecItem.push_back(_sItem);
} // GameInfo::Additem


/*******************************************************************************
* GameInfo::GetGamePath
*******************************************************************************/
qLib::qPath GameInfo::GetGamePath() const
{
    MainWin     &mw = GetMainWin();
    qPath       p = mw.GetAppPath() + PATH_GAME_DATA;

    // add the category
    p += "/";
    p += GetTypeString();

    // add the game name
    p += "/";
    p += GetName();

    return p.GetCanonicalPath();
} // GameInfo::GetGamePath


/*******************************************************************************
* GameInfo::GetRoundWinnerCount
*******************************************************************************/
s32 GameInfo::GetRoundWinnerCount(s32   _s32Team)
{
    s32     s32Count = 0;

    for (shared_ptr<RoundInfo> &pRI : m_lstRoundInfo)
    {
        // team won if winner is TEAM_x or TEAM_BOTH
        if ((pRI->GetWinner() & _s32Team) != 0)
        {
            s32Count++;
        }
    }

    return s32Count;
} // GameInfo::GetRoundWinnerCount


/*******************************************************************************
* GameInfo::CalculateRoundInfos
*******************************************************************************/
void GameInfo::CalculateRoundInfos()
{
    m_pExample = Item2RoundInfo(m_sExample);

    for (qString16 &sItem : m_vecItem)
    {
        m_lstRoundInfo.push_back(Item2RoundInfo(sItem));
    }
} // GameInfo::CalculateRoundInfos


/*******************************************************************************
* GameInfo::FindRoundByName
*******************************************************************************/
shared_ptr<RoundInfo> GameInfo::FindRoundByName(const qString16 &_sName)
{
    if (m_pExample != nullptr && m_pExample->GetName() == _sName)
    {
        return m_pExample;
    }

    for (shared_ptr<RoundInfo> &p : m_lstRoundInfo)
    {
        if (p->GetName() == _sName)
        {
            return p;
        }
    } // for

    return nullptr;
} // GameInfo::FindRoundByName


/*******************************************************************************
* GameInfo::Item2RoundInfo
*******************************************************************************/
std::shared_ptr<RoundInfo> GameInfo::Item2RoundInfo(const qString16 &_sItem)
{
    std::shared_ptr<RoundInfo>  pRI;
    qVec<qString16>             vecToken;

    // create the new round info
    pRI = std::make_shared<RoundInfo> (GetGamePath());

    switch (m_eType)
    {
        case enumGameType::Undefined:
            break;

        case enumGameType::LetterSum:
        {
            // split the string
            _sItem.SplitString("#",vecToken, true);

            // set the round info
            for (const qString16 &s : vecToken)
            {
                // round name, e.g. Alaaf
                pRI->SetName(s);
                // solution is the sum of the letters
                QString sQ = s.ToQString().toUpper();
                s32     sum = 0;
                for (QChar c : sQ)
                {
                    sum += c.toLatin1() - QChar('A').toLatin1() + 1;
                }
                pRI->SetSolution(qString16::FromValue(sum));
            }

            m_lstRoundInfo.push_back(pRI);
            break;
        }

        case enumGameType::Mosaic:
        {
            // split the string
            _sItem.SplitString("#", vecToken, true);

            if (vecToken.size() == 2)
            {
                pRI->SetImage(vecToken.at(0));
                pRI->SetName(vecToken.at(1));
                pRI->SetSolution(vecToken.at(1));
            }
        }
    }

    return pRI;
} // GameInfo::Item2RoundInfo
