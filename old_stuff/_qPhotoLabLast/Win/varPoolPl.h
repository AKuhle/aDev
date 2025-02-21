/*******************************************************************************
* \file varPoolPl.h
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

using namespace qLib;


/*******************************************************************************
* class VarPoolPl
*******************************************************************************/
class VarPoolPl : public qGuiVarPool
{
    public:
        VarPoolPl();
        ~VarPoolPl();

    private:
        void            AddVariables();
}; // class VarPoolPl
