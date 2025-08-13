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
#include "aToolMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMainWin
*******************************************************************************/
class aMainWin : public aBaseWin,
                 public aToolMgr
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin(aBaseWin *_pParent);
        virtual ~aMainWin();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool        onSysCreateWin() override;

        bool                onButtonPress(u16           _u16Modifier,
                                          u16           _u16Btn,
                                          const aPoint  &_pntLocal,
                                          const aPoint  &_pntGlobal) override;

        bool                onMouseMove(u16             _u16Modifier,
                                        u16             _u16Btn,
                                        const aPoint    &_pntLocal,
                                        const aPoint    &_pntGlobal) override;

        bool                onButtonRelease(u16             _u16Modifier,
                                            u16             _u16Btn,
                                            const aPoint    &_pntLocal,
                                            const aPoint    &_pntGlobal) override;
}; // class aMainWin


} // namespace aWin
} // namespace aFrame
