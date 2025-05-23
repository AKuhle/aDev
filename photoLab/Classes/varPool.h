/*******************************************************************************
* \file BaseApp.h
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
#include "aLib_def.h"
#include "aVarPool.h"

class ViewBase;

using namespace aLib::aUtil;



/*******************************************************************************
* class VarPool
*******************************************************************************/
class VarPool : public aVarPool
{
    public:
        VarPool();
        ~VarPool();

}; // class VarPool
