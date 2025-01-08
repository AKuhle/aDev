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

#include "qRect2D.h"
#include "qPainter.h"
#include "qFont.h"

using namespace qLib;

class GameInfo;
class RoundInfo;


/*******************************************************************************
* class PageBase
*******************************************************************************/
class PageBase : public QWidget
{
    Q_OBJECT

    protected:
        std::shared_ptr<GameInfo>   m_pGameInfo;
        std::shared_ptr<RoundInfo>  m_pRoundInfo;

    public:
        PageBase();
        ~PageBase();

        virtual void        OnSessionDataChanged();

        virtual void        BuzzerPressed(s32 _s32Team);

        void                StartRound(std::shared_ptr<GameInfo>    _pGameInfo,
                                       std::shared_ptr<RoundInfo>   _pRoundInfo);

        void                CloseRound();

    protected:
        virtual void        OnStartRound() = 0;
        virtual void        OnCloseRound() = 0;

        virtual void        OnResize(qRect2D<s32>   &_r2dClient);

        // paint for std items like title, pointtwin etc.
        // this shrinks the remaining rect for the specific game content
        virtual void        OnPaintStdItems(qRect2D<s32>    &_r2dClient,
                                            qPainter        &_p);

        // content of the specific game, draw in the remaining rect
        virtual void        OnPaintGameStuff(const qRect2D<s32> &_r2dGame,
                                             qPainter           &_p);

    protected:
        virtual void        resizeEvent(QResizeEvent *_pEvent) override;
        virtual void        paintEvent(QPaintEvent *_pEvent) override;

}; // class PageBase

