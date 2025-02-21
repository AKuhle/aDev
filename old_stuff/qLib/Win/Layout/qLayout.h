/*******************************************************************************
* \file qLayout.h
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
#include "Math/qRect2D.h"
#include "Win/Layout/qLayoutObj.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qLayout
*******************************************************************************/
class qLayout : public qLayoutObj
{
    public:
        qLayout();
        ~qLayout();

        virtual void            adjustContentRect(qRect2D<s32> &_r2d);

        virtual void            arrangeChilds(qRect2D<s32>  _r2d) = 0;
}; // class qLayout


} // namespace Win
} // namespace qLib
