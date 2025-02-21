/*******************************************************************************
* \file RoundInfo.h
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

#include "gamesDefs.h"
#include "qString16.h"
#include "qPath.h"

using namespace qLib;


/*******************************************************************************
* class RoundInfo
*******************************************************************************/
class RoundInfo
{
    private:
        qString16       m_sName;
        qPath           m_sGameDataPath;
        qString16       m_sSolution;
        QImage          m_img;
        s32             m_s32Winner         { TEAM_NONE };

    public:
        RoundInfo(const qPath &_sGameDataPath);
        ~RoundInfo();

        void            SetName(const qString16 &_sName)            { m_sName = _sName; }
        qString16       GetName() const                             { return m_sName; }

        void            SetSolution(const qString16 &_sSolution)    { m_sSolution = _sSolution; }
        qString16       GetSolution() const                         { return m_sSolution; }

        void            SetImage(const qString16 &_sImage);
        const QImage&   GetImage() const                            { return m_img; }

        // mutabla members (during the game is beeing played)
        void            AddWinner(s32 _s32Winner)                   { m_s32Winner |= _s32Winner; }
        void            RemoveWinner(s32 _s32Winner)                { m_s32Winner &= ~_s32Winner; }
        s32             GetWinner() const                           { return m_s32Winner; }
}; // class RoundInfo
