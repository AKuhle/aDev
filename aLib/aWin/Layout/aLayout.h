/*******************************************************************************
* \file aLayout.h
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
#include "aMath/Obj2D/aRect2D.h"

#include "aWin/Layout/aLayoutObj.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLayout
*******************************************************************************/
class aLayout : public aLayoutObj
{
    public:
        aLayout();
        ~aLayout();

        virtual void            layoutRect2ContentRect(aRect2D<s32> &_r2d);

        virtual void            arrangeChilds(aRect2D<s32>  _r2d) = 0;
}; // class aLayout


} // namespace aWin
} // namespace aLib