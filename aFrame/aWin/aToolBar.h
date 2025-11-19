/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin_def.h"

#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolBar
*******************************************************************************/
class aToolBar : public aBaseWin
{
    private:
        u32         m_u32AllowedDockPos     { DOCK_POS_T };
        u32         m_u32DockPos            { DOCK_POS_T };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aToolBar(aBaseWin *_pParent = nullptr);
        virtual ~aToolBar();

        void                    addChild(aBaseWin *_pWin);


    public:
        void                    setAllowedDockPosition(u32 _u32AllowedDockPos);
        u32                     allowedDockPosition() const;

        void                    setDockPosition(u32 _u32DockPos);
        u32                     dockPosition() const;


    private:
        aMargin                 borderMarginFromPosition() const;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                    onSysCreateWin() override;
        virtual void            onPaintBorder() override;
        virtual aRect           paddingRect() const override;

}; // class aToolBar


} // namespace aWin
} // namespace aFrame
