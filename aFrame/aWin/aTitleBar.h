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
* class aTitleBar
*******************************************************************************/
class aTitleBar : public aBaseWin,
                  public aToolMgr
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aTitleBar(aBaseWin *_pParent);
        virtual ~aTitleBar();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                    onSysCreateWin() override;

        bool                    onDoubleClick(u16           _u16Modifier,
                                              u16           _u16Btn,
                                              const aPoint  &_pntLocal,
                                              const aPoint  &_pntGlobal) override;

        bool                    onButtonPress(u16           _u16Modifier,
                                              u16           _u16Btn,
                                              const aPoint  &_pntLocal,
                                              const aPoint  &_pntGlobal) override;

        bool                    onMouseMove(u16             _u16Modifier,
                                            u16             _u16Btn,
                                            const aPoint    &_pntLocal,
                                            const aPoint    &_pntGlobal) override;

        bool                    onButtonRelease(u16             _u16Modifier,
                                                u16             _u16Btn,
                                                const aPoint    &_pntLocal,
                                                const aPoint    &_pntGlobal) override;

}; // class aTitleBar


} // namespace aWin
} // namespace aFrame
