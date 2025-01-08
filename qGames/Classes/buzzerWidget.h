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
* class BuzzerWidget
*******************************************************************************/
class BuzzerWidget : public QWidget
{
    Q_OBJECT

    private:
        s32     m_s32Team           { TEAM_NONE };
        s32     m_s32StartTime_s    { 0 };
        s32     m_s32CurrentTime_s  { 0 };

        bool    m_bBuzzerRunning    { false };

    public:
        BuzzerWidget(QWidget *_pParent);
        ~BuzzerWidget();

        void                StartBuzzer(s32 _s32Team,
                                        s32 _s32StartTime_s);

        void                DecreaseBuzzer(s32 _s32Time_s);

        void                StopBuzzer();

        s32                 GetRemainingTime()  { return m_s32CurrentTime_s; }

    protected:
        virtual void        paintEvent(QPaintEvent *_pEvent) override;

}; // class BuzzerWidget
