/*******************************************************************************
* \file teamInfo.h
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

#include "qString16.h"

using namespace qLib;


/*******************************************************************************
* class TeamInfo
*******************************************************************************/
class TeamInfo
{
    private:
        qString16       m_sName;
        qString16       m_sFigureFileName;
        QPixmap         m_pixmap;

    public:
        TeamInfo();
        ~TeamInfo();

        qString16       GetName() const                             { return m_sName; }

        void            SetFigureFileName(const qString16 &_sFile);
        qString16       GetFigureFileName() const                   { return m_sFigureFileName; }

        const QPixmap&  GetPixmap() const                           { return m_pixmap; }

        //void            SetPixmapg(const QPixmap &_pixmap)      { m_pixmap = _pixmap; }
        //const QPixmap&  GetPixmap() const                       { return m_pixmap; }
}; // class TeamInfo
