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

#include "gamesDefs.h"
#include "qString16.h"
#include "qColor.h"
#include "gameInfo.h"


/*******************************************************************************
* class PointWidget
*******************************************************************************/
class PointWidget : public QWidget
{
    Q_OBJECT

    private:
        s32                         m_s32Team    { TEAM_NONE };
        std::shared_ptr<GameInfo>   m_pGameInfo;

    public:
        PointWidget(QWidget                     *_pParent,
                    s32                         _s32Team,
                    std::shared_ptr<GameInfo>   _pGameInfo);
        ~PointWidget();

    protected:
        virtual void        paintEvent(QPaintEvent *_pEvent) override;

}; // class PointWidget
