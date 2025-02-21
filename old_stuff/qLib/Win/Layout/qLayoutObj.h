/*******************************************************************************
* \file qLayoutObj.h
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
#include "Math/qDimension2D.h"

#include "Object/qMargin.h"

using namespace qLib::Math;
using namespace qLib::Object;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qLayoutObj
*******************************************************************************/
class qLayoutObj
{
    private:
        // margins
        qMargin    m_Distance;
        qMargin    m_Margin;
        qMargin    m_Border;
        qMargin    m_Padding;

        // size
        qDimension2D<s32>   m_d2dMinSize;
        qDimension2D<s32>   m_d2dMaxSize    { S32_MAX, S32_MAX };


    protected:
        qLayoutObj();
        ~qLayoutObj();

    public:
        // margins
        const qMargin               &distance() const;
        qMargin                     &distance();

        const qMargin               &margin() const;
        qMargin                     &margin();

        const qMargin               &border() const;
        qMargin                     &border();

        const qMargin               &padding() const;
        qMargin                     &padding();

        // size
        virtual qDimension2D<s32>   minSize() const;
        s32                         minW() const;
        s32                         minH() const;
        void                        setMinSize(const qDimension2D<s32> &_d2dMin);
        void                        setMinSize(s32  _w,
                                               s32  _h);
        void                        setMinW(s32  _w);
        void                        setMinH(s32  _h);


        virtual qDimension2D<s32>   maxSize() const;
        s32                         maxW() const;
        s32                         maxH() const;
        void                        setMaxSize(const qDimension2D<s32> &_d2dMax);
        void                        setMaxSize(s32  _w,
                                               s32  _h);
        void                        setMaxW(s32  _w);
        void                        setMaxH(s32  _h);

}; // class qLayoutObj


} // namespace Win
} // namespace qLib
