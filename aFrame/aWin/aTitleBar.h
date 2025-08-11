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
#include "aToolManager.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aTitleBar
*******************************************************************************/
class aTitleBar : public aBaseWin,
                  public aToolManager
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aTitleBar(SysWin *_pParent);
        virtual ~aTitleBar();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                    onSysCreateWin();

        virtual bool                    onLDoubleClick(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);
}; // class aTitleBar


} // namespace aWin
} // namespace aFrame
