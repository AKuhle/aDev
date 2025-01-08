/*******************************************************************************
* \file qGamesVarPool.h
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
* include
*******************************************************************************/
#include "qVarPool.h"


/*******************************************************************************
* class GamesVarPool
*******************************************************************************/
class GamesVarPool : public qLib::qVarPool
{
    protected:

    public:
        GamesVarPool();
        GamesVarPool(const GamesVarPool &_rhs);
        virtual ~GamesVarPool();

        GamesVarPool&            operator=(const GamesVarPool &_rhs);

}; // class GamesVarPool
