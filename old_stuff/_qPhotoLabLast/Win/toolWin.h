/*******************************************************************************
* \file ToolWin.h
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

#include "qLib.h"

#include "ui_formNavigator.h"

using namespace qLib;


/*******************************************************************************
* forwards
*******************************************************************************/
class ViewNavigator;


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class ToolWin
*******************************************************************************/
class ToolWin : public qSysWin<QWidget>
                // public qCmdMgr,
                // public qProgress
{
    public:
        ToolWin();
        ~ToolWin();

        virtual void        UpdateToolWin() = 0;

}; // class ToolWin
