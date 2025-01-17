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

        virtual aDimension2D<s32>   minDim() const override;

        virtual void                arrangeChilds(aRect2D<s32>  _r2dLayout) = 0;

    protected:
        virtual aDimension2D<s32>   calculateMinDim() const = 0;

    /*******************************************************************************
    * aLayoutObj interfasce
    *******************************************************************************/
    public:
        virtual void                setGeometry(s32    _x,
                                                s32    _y,
                                                s32    _w,
                                                s32    _h) override;
}; // class aLayout


} // namespace aWin
} // namespace aLib
