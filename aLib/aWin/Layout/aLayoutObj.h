/*******************************************************************************
* \file aLayoutObj.h
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
#include "aUtil/aMargin.h"
#include "aMath/Obj2D/aDimension2D.h"

using namespace aLib::aUtil;
using namespace aLib::aMath;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLayoutObj
*******************************************************************************/
class aLayoutObj
{
    private:
        // margins
        aMargin    m_Distance;

        // size
        aDimension2D<s32>   m_d2dMin;
        aDimension2D<s32>   m_d2dMax        { S32_MAX, S32_MAX };


    protected:
        aLayoutObj();
        ~aLayoutObj();

    public:
        // margins
        const aMargin               &distance() const;
        aMargin                     &distance();


        // min size
        virtual aDimension2D<s32>   minDim() const;
        void                        setMinDim(const aDimension2D<s32> &_d2dMin);
        void                        setMinDim(s32  _w,
                                              s32  _h);
        void                        setMinW(s32  _w);
        void                        setMinH(s32  _h);


        // max size
        virtual aDimension2D<s32>   maxDim() const;
        void                        setMaxDim(const aDimension2D<s32> &_d2dMax);
        void                        setMaxDim(s32  _w,
                                              s32  _h);
        void                        setMaxW(s32  _w);
        void                        setMaxH(s32  _h);

        // fixes size
        void                        setFixedDim(const aDimension2D<s32> &_d2dFixed);
        void                        setFixedDim(s32  _w,
                                                 s32  _h);

        // expandable
        bool                        isHoriExpandable() const; // true, if maxW > minW
        bool                        isVertExpandable() const; // true, if maxH > minH

        // interface
        virtual void                setGeometry(s32    _x,
                                                s32    _y,
                                                s32    _w,
                                                s32    _h) = 0;

}; // class aLayoutObj


} // namespace aWin
} // namespace aLib
