/*******************************************************************************
* \file qGamesVarPool.cpp
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
#include "qColor.h"

#include "gamesDefs.h"
#include "GamesVarPool.h"

using namespace qLib;


/*******************************************************************************
* GamesVarPool::GamesVarPool
*******************************************************************************/
GamesVarPool::GamesVarPool()
{
    qColor col1(0, 0, 0.1, 1);
    qColor col2(0, 0, 0.3, 1);
    AddColor(ID_VP_GAME_BG_1, col1, col1);
    AddColor(ID_VP_GAME_BG_2, col2, col2);

} // GamesVarPool::GamesVarPool


/*******************************************************************************
* GamesVarPool::GamesVarPool
*******************************************************************************/
GamesVarPool::GamesVarPool(const GamesVarPool &_rhs)
: qVarPool(_rhs)
{
} // GamesVarPool::GamesVarPool


/*******************************************************************************
* GamesVarPool::~GamesVarPool
*******************************************************************************/
GamesVarPool::~GamesVarPool()
{
} // GamesVarPool::~GamesVarPool


/*******************************************************************************
* GamesVarPool::operator=
*******************************************************************************/
GamesVarPool& GamesVarPool::operator=(const GamesVarPool &_rhs)
{
    // clear the previous stuff
    ClearAllEntries();

    // call the baseclass implementation
    qVarPool::operator=(_rhs);

    return *this;
} // GamesVarPool::operator=
