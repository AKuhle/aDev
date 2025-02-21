/*******************************************************************************
* \file qLayoutObj.h
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
#include "qDimension2D.h"
#include "qEdges.h"
#include "qRect2D.h"


namespace qLib
{
    /*******************************************************************************
    * \class qLayoutObj
    *******************************************************************************/
    class qLayoutObj
	{
        // geometry
        DeclareClassProperty(qEdges, edge, DistanceEdges)
        DeclareClassProperty(qEdges, edge, MarginEdges)
        DeclareClassProperty(qEdges, edge, BorderEdges)
        DeclareClassProperty(qEdges, edge, PaddingEdges)

        DeclareTypeProperty(enumOrientation, e, Orientation, enumOrientation::Hori)

        private:
            qDimension2D<s32>       m_d2dMinSize    { 0, 0 };
            static flt              m_minScale;

        protected:
            qLayoutObj();

        public:
            virtual ~qLayoutObj();

            // the min scale is beeing set once during app start
            // changes require a restart of the application
            static void                 SetMinScale(flt _minScale);

            virtual qDimension2D<s32>   GetMinSize() const;
            void                        SetMinSize(const qDimension2D<s32>  &_minSize);
            void                        SetMinSize(s32 _minW,
                                                   s32 _minH);
            void                        SetMinW(s32 _minW);
            void                        SetMinH(s32 _minH);

            // maximum size
            qDimension2D<s32>           GetMaxSize() const;
            void                        SetMaxSize(const qDimension2D<s32>  &_maxSize);
            void                        SetMaxSize(s32 _maxW,
                                                   s32 _maxH);
            void                        SetMaxW(s32 _maxW);
            void                        SetMaxH(s32 _maxH);

            // fixed size
            void                        SetFixedSize(const qDimension2D<s32>  &_fixSize);
            void                        SetFixedSize(s32 _fixW,
                                                     s32 _fixH);
            void                        SetFixedW(s32 _fixedW);
            void                        SetFixedH(s32 _fixedH);

            bool                        IsHoriExpandable() const; // true, if maxW > minW
            bool                        IsVertExpandable() const; // true, if maxH > minH

            void                        SetGeometry(const qRect2D<s32> &geo);
            virtual void                SetGeometry(s32 _x,
                                                    s32 _y,
                                                    s32 _w,
                                                    s32 _h);

            virtual void                SetPosition(s32 _x,
                                                    s32 _y);

            virtual void                ArangeChilds(const qRect2D<s32> &_parentRect);
    }; // class qLayoutObj

} // namespace qLib
