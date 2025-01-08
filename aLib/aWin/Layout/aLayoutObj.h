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
        aDimension2D<s32>   m_d2dMinSize;
        aDimension2D<s32>   m_d2dMaxSize    { S32_MAX, S32_MAX };


    protected:
        aLayoutObj();
        ~aLayoutObj();

    public:
        // margins
        const aMargin               &distance() const;
        aMargin                     &distance();


        // size
        virtual aDimension2D<s32>   minSize() const;
        s32                         minW() const;
        s32                         minH() const;
        void                        setMinSize(const aDimension2D<s32> &_d2dMin);
        void                        setMinSize(s32  _w,
                                               s32  _h);
        void                        setMinW(s32  _w);
        void                        setMinH(s32  _h);


        virtual aDimension2D<s32>   maxSize() const;
        s32                         maxW() const;
        s32                         maxH() const;
        void                        setMaxSize(const aDimension2D<s32> &_d2dMax);
        void                        setMaxSize(s32  _w,
                                               s32  _h);
        void                        setMaxW(s32  _w);
        void                        setMaxH(s32  _h);

}; // class aLayoutObj


} // namespace aWin
} // namespace aLib
