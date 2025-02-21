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


/*******************************************************************************
* forwards
*******************************************************************************/
class PageBase;
class GameInfo;
class RoundInfo;


/*******************************************************************************
* class GameWin
*******************************************************************************/
class GameWin : public QWidget
{
    Q_OBJECT

    private:
        PageBase                    *m_pPage        { nullptr };
        std::shared_ptr<GameInfo>   m_pGameInfo;
        std::shared_ptr<RoundInfo>  m_pRoundInfo;

    public:
        GameWin(QWidget *_pParent = nullptr);
        ~GameWin();

        void                        SetPage(enumPages                   _enumPage,
                                            std::shared_ptr<GameInfo>   _pGameInfo); // can be nullptr

        void                        OnSessionDataChanged();

        void                        BuzzerPressed(s32 _s32Team);

        std::shared_ptr<GameInfo>   GetCurrentGI() const    { return m_pGameInfo; }

        void                        SetRI(std::shared_ptr<RoundInfo> _pRI);
        std::shared_ptr<RoundInfo>  GetCurrentRI() const    { return m_pRoundInfo; }

        void                        StartRound();
        void                        CloseRound();

    private:
        void                        ResizePage();

    protected:
        virtual void                mouseDoubleClickEvent(QMouseEvent *event);
        virtual void                resizeEvent(QResizeEvent *_pEvent);

}; // class GameWin
