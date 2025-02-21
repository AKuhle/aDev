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

#include "pageStd.h"



/*******************************************************************************
* class PageMosaic
*******************************************************************************/
class PageMosaic : public PageStd
{
    Q_OBJECT

    private:
        struct stBlocks
        {
            qRect2D<s32>    rect;
            qColor          col;
        }; // stBlocks

    private:
        // block management
        qVec<stBlocks>      m_vBlocks;
        bool                m_bCreateBlocks         { false };
        const s32           m_s32BlockIntervall_ms  { 1200 };   // time between two blocks
        const s32           m_s32BlocksPerRow       { 10 };

    public:
        PageMosaic(std::shared_ptr<GameInfo> _pGameInfo);
        ~PageMosaic();

    private:
        void                CreateBlocks(const qRect2D<s32>   &_r2dImg);


    /*******************************************************************************
    * interface of PageStd
    *******************************************************************************/
    protected:
        virtual void        OnBuzzer(s32 _s32Team);

        virtual void        OnSingleShotTimer();


    /*******************************************************************************
    * interface of PageBase
    *******************************************************************************/
    protected:
        virtual void        OnStartRound() override;
        virtual void        OnCloseRound() override;

        virtual void        OnPaintGameStuff(const qRect2D<s32> &_r2dGame,
                                             qPainter           &_p) override;
}; // class PageMosaic

