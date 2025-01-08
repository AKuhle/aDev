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
#include "pageBase.h"
#include "gameInfo.h"
#include "pointWidget.h"
#include "buzzerWidget.h"

using namespace qLib;


/*******************************************************************************
* class PageStd
*******************************************************************************/
class PageStd : public PageBase
{
    Q_OBJECT

    private:
        std::shared_ptr<GameInfo>   m_pGameInfo;

        // all widgets
        const s32       m_s32WidgetMargin   { 20 };

        // point widgets
        const s32       m_s32PointWidgetW   { 300 };
        const s32       m_s32PointWidgetH   { 150 };
        PointWidget     m_pointWidget1;
        PointWidget     m_pointWidget2;

        // buzzer widget
        const s32       m_s32BuzzerWidgetW  { 300 };
        const s32       m_s32BuzzerWidgetH  { 30 };
        BuzzerWidget    m_buzzerWidget;

        QTimer          m_timerSingleShot;
        QTimer          m_timerBuzzer;

        bool            m_bBuzzerEnabled    { false };

    public:
        PageStd(std::shared_ptr<GameInfo> _pGameInfo);
        ~PageStd();

        virtual void        BuzzerPressed(s32 _s32Team);

        GameInfo&           GetGameInfo(){ return *m_pGameInfo; }

    protected:
        void                EnableBuzzer()      { m_bBuzzerEnabled = true; }

        virtual void        OnBuzzer(s32 _s32Team);

        void                StartSingleShotTimer(s32    s32Time_ms);
        void                StopSingleShotTimer();
        virtual void        OnSingleShotTimer();

    private:
        virtual void        OnPaintStdItems(qRect2D<s32>    &_r2dClient,
                                            qPainter        &_p);

    private slots:
        void                SlotSingleShot();
        void                SlotBuzzer();


    /*******************************************************************************
    * interface of PageBase
    *******************************************************************************/
    protected:
        virtual void        OnResize(qRect2D<s32>   &_r2dClient);

}; // class PageStd
