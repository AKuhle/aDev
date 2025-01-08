/*******************************************************************************
* \file qLine2D.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  this class represents a 2 dimensional line from a start to an endpoint
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "qMathObj2D.h"
#include "qVector2D.h"


namespace qLib
{
    using namespace std;

    /*******************************************************************************
    * class qLine2D
    *******************************************************************************/
    template<class T, class Tprec = dbl>
    class qLine2D : public qMathObj2D
	{
        private:
           qVector2D<T, Tprec>      m_v2dStart;     //!< startpoint
           qVector2D<T, Tprec>      m_v2dEnd;       //!< endpoint

        public:
            qLine2D();

            qLine2D(const qLine2D<T, Tprec>& _rhs);

            qLine2D(const qVector2D<T, Tprec>&  _v2dStart,
                    const qVector2D<T, Tprec>&  _v2dEnd);

            qLine2D(T   _tStartX,
                    T   _tStartY,
                    T   _tEndX,
                    T   _tEndY);

            virtual ~qLine2D();

            qLine2D<T, Tprec>&      operator=(const qLine2D<T, Tprec> &_rhs);

            qVector2D<T, Tprec>     StartPoint() const;
            void                    SetStartPoint(const qVector2D<T, Tprec>& _v2dStart);
            void                    SetStartPoint(T   _tStartX,
                                                  T   _tStartY);

            qVector2D<T, Tprec>     EndPoint() const;
            void                    SetEndPoint(const qVector2D<T, Tprec>& _v2dEnd);
            void                    SetEndPoint(T   _tEndX,
                                                T   _tEndY);

            void                    Set(T   _tStartX,
                                        T   _tStartY,
                                        T   _tEndX,
                                        T   _tEndY);

            qVector2D<T, Tprec>     Perpendicular(const qVector2D<T, Tprec> &_v2dPoint,
                                                  dbl                       &_dblLambda) const;

            // 0% => StartPoint, 100% => EndPoint
            qVector2D<T, Tprec>     PointOnLine(dbl _dDistFromStart_pcnt) const;

            friend ostream& operator<<(ostream&             _os,
                                       const qLine2D<T>&    _l2d)
            {
                _os << _l2d.m_v2dStart << "->" << _l2d.m_v2dEnd;
                return _os;
            } // operator<<
    }; // class qLine2D

} // namespace qLib

#include "qLine2D.inl"
