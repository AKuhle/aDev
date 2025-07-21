/*******************************************************************************
* \file ToolWinBase.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "ui_formNavigator.h"

#include "aPlainWin.h"

using namespace aLib;
using namespace aLib::aWin;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewNavigator;


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class ToolWinBase
*******************************************************************************/
class ToolWinBase : public aPlainWin
{
    protected:
        ToolWinBase(SysWin *_pParent);
        ~ToolWinBase();

    public:
        virtual void        updateToolWin() = 0;

}; // class ToolWinBase
