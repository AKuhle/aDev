/*******************************************************************************
* \file qVarPool.cpp
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
#include "qGamesDefs.h"
#include "varPool.h"


namespace qLib
{
    /*******************************************************************************
    * VarPool::VarPool
    *******************************************************************************/
    VarPool::VarPool()
    {
        qColor col1(0, 0, 0.1, 1);
        qColor col2(0, 0, 0.3, 1);
        AddColor(ID_VP_GAME_BG_1, col1, col1);
        AddColor(ID_VP_GAME_BG_2, col2, col2);

    } // VarPool::VarPool


    /*******************************************************************************
    * VarPool::VarPool
    *******************************************************************************/
    VarPool::VarPool(const VarPool &_rhs)
    : qGuiVarPool(_rhs)
    {
    } // VarPool::VarPool


    /*******************************************************************************
    * VarPool::~VarPool
    *******************************************************************************/
    VarPool::~VarPool()
    {
    } // VarPool::~VarPool


    /*******************************************************************************
    * VarPool::operator=
    *******************************************************************************/
    VarPool& VarPool::operator=(const VarPool &_rhs)
    {
        // clear the previous stuff
        ClearAllEntries();

        // call the baseclass implementation
        qGuiVarPool::operator=(_rhs);

        return *this;
    } // VarPool::operator=

} // namespace qLib
