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
#include "qVec.h"

#include "gamesDefs.h"
#include "panel.h"

using namespace qLib;


/*******************************************************************************
* class PagePanel
*******************************************************************************/
class PagePanel : public PageBase
{
    Q_OBJECT

    private:
        qVec<Panel *>       m_vPanel;

        QTimer              m_timerPanelFrame;

    public:
        PagePanel(enumPages _enumPage);
        ~PagePanel();

        virtual void        OnSessionDataChanged() override;

    /*******************************************************************************
    * interface of PageBase
    *******************************************************************************/
    protected:
        virtual void        OnStartRound() override;
        virtual void        OnCloseRound() override;

        virtual void        OnPaintStdItems(qRect2D<s32>    &_r2dClient,
                                            qPainter        &_p) override;

    protected:
        virtual void        OnResize(qRect2D<s32>   &_r2dClient) override;

    private slots:
        void                SlotPanelFrame();
}; // class PagePanel
