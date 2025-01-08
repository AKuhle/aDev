/*******************************************************************************
* \file qRect2D.inl
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


/*******************************************************************************
* includes
*******************************************************************************/


namespace qLib
{
    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D()
	{
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D(const qRect2D<T, Tprec>	&_rhs)
    : x(_rhs.x),
      y(_rhs.y),
      w(_rhs.w),
      h(_rhs.h)
	{
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D(const T		_x,
                               const T		_y,
                               const T		_w,
                               const T		_h)
        : x(_x),
          y(_y),
          w(_w),
          h(_h)
    {
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
//    template<class T, class Tprec>
//    qRect2D<T, Tprec>::qRect2D(const qlVector2D<T>	&_v2dOrigin,
//                             const T				_w,
//                             const T				_h)
//    : x(_v2dOrigin.x),
//      y(_v2dOrigin.y),
//      w(_w),
//      h(_h)
//    {
//    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D(const qVector2D<T>& _v2dOrigin,
                               const qVector2D<T>& _v2dOppositCorner)
    : x(MU<T>::Min (_v2dOrigin.x, _v2dOppositCorner.x)),
      y(MU<T>::Min (_v2dOrigin.y, _v2dOppositCorner.y)),
      w(MU<T>::Max (_v2dOrigin.x, _v2dOppositCorner.x) - x),
      h(MU<T>::Max (_v2dOrigin.y, _v2dOppositCorner.y) - y)
    {
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::~qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::~qRect2D()
	{
    } // qRect2D<T, Tprec>::~qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::Set
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Set(const T	_x,
                               const T	_y,
                               const T	_w,
                               const T	_h)
    {
        x = _x;
        y = _y;
        w = _w;
        h = _h;
    } // qRect2D<T, Tprec>::Set


//    //! Set
//    //!
//    //! Set the position and the size of the rect
//    template<class T, class Tprec>
//    void qRect2D<T, Tprec>::Set(const qlVector2D<T>	&_v2d,
//                               const T               _w,
//                               const T               _h)
//    {
//        x = _v2d.x;
//        y = _v2d.y;
//        w = _w;
//        h = _h;
//    } // qRect2D<T, Tprec>::Set


    /*******************************************************************************
    * qRect2D<T, Tprec>::operator=
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>& qRect2D<T, Tprec>::operator=(const qRect2D<T, Tprec>	&_rhs)
    {
        // avoid selfcopy
        if (this != &_rhs)
        {
            x = _rhs.x;
            y = _rhs.y;
            w = _rhs.w;
            h = _rhs.h;
        }

        return *this;
    } // qRect2D<T, Tprec>::operator=


    /*******************************************************************************
    * qRect2D<T, Tprec>::operator==
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::operator==(const qRect2D<T, Tprec>	&_rhs) const
    {
        return MU<T>::IsEqual(x, _rhs.x) && MU<T>::IsEqual(y, _rhs.y) &&
               MU<T>::IsEqual(w, _rhs.w) && MU<T>::IsEqual(h, _rhs.h);
    } // qRect2D<T, Tprec>::operator==


    /*******************************************************************************
    * qRect2D<T, Tprec>::operator!=
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::operator!=(const qRect2D<T, Tprec>	&_rhs) const
    {
        return MU<T>::IsUnequal(x, _rhs.x) || MU<T>::IsUnequal(y, _rhs.y) ||
               MU<T>::IsUnequal(w, _rhs.w) || MU<T>::IsUnequal(h, _rhs.h);
    } // qRect2D<T, Tprec>::operator!=


    /*******************************************************************************
    * qRect2D<T, Tprec>::Dimension
    *******************************************************************************/
    template<class T, class Tprec>
    qDimension2D<s32> qRect2D<T, Tprec>::Dimension() const
    {
        return qDimension2D<s32> (w, h);
    } // qRect2D<T, Tprec>::Dimension


    /*******************************************************************************
    * qRect2D<T, Tprec>::Resize
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Resize(Tprec _tFactor)
    {
        w *= _tFactor;
        h *= _tFactor;
    } // qRect2D<T, Tprec>::Resize


    /*******************************************************************************
    * qRect2D<T, Tprec>::CenterPoint
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T> qRect2D<T, Tprec>::CenterPoint() const
    {
        return qVector2D<T> ((T) (((dbl) x) + ((dbl) w)/2),
                             (T) (((dbl) y) + ((dbl) h)/2));
    } // qRect2D<T, Tprec>::GetCenterPoint()


//	//! SetCenterPoint
//	//!
//	//! Set the center point of the rect
//    template<class T, class Tprec>
//    void qRect2D<T, Tprec>::SetCenterPoint(const T	_x,
//                                     const T	_y)
//	{
//		x = _x - w/2;
//		y = _y - h/2;
//    } // qRect2D<T, Tprec>::SetCenterPoint


    /*******************************************************************************
    * qRect2D<T, Tprec>::SetEmpty
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::SetEmpty()
    {
        x = y = w = h = 0;
    } // qRect2D<T, Tprec>::SetEmpty


    /*******************************************************************************
    * qRect2D<T, Tprec>::IsEmpty
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::IsEmpty() const
    {
        return MU<T>::IsZero(x) &&
               MU<T>::IsZero(y) &&
               MU<T>::IsZero(w) &&
               MU<T>::IsZero(h);
    } // qRect2D<T, Tprec>::IsEmpty


    /*******************************************************************************
    * qRect2D<T, Tprec>::Shrink
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Shrink(T _tValue)
    {
        x += _tValue;
        y += _tValue;
        w -= 2 * _tValue;
        h -= 2 * _tValue;
    } // qRect2D<T, Tprec>::Shrink


    /*******************************************************************************
    * qRect2D<T, Tprec>::Expand
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Expand(T _tValue)
    {
        x -= _tValue;
        y -= _tValue;
        w += 2 * _tValue;
        h += 2 * _tValue;
    } // qRect2D<T, Tprec>::Expand


    /*******************************************************************************
    * qRect2D<T, Tprec>::Intersect
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec> qRect2D<T, Tprec>::Intersect(const qRect2D<T, Tprec>	&_rhs) const
    {
        qRect2D<T, Tprec> r2dIntersect;   // initial the rect is empty

        T           tMinX   = MU<T>::Max(x, _rhs.x);
        T           tMinY   = MU<T>::Max(y, _rhs.y);
        T           tMaxX   = MU<T>::Min(x + w, _rhs.x + _rhs.w);
        T           tMaxY   = MU<T>::Min(y + h, _rhs.y + _rhs.h);

        if ((tMinX <= tMaxX) && tMinY <= tMaxY)
        {
            r2dIntersect.Set(tMinX, tMinY, tMaxX-tMinX, tMaxY-tMinY);
        }

        return r2dIntersect;
    } // qRect2D<T, Tprec>::Intersect


    /*******************************************************************************
    * qRect2D<T, Tprec>::PointInRect
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::PointInRect(const qVector2D<T>& _v2d) const
    {
        return PointInRect(_v2d.x, _v2d.y);
    } // qRect2D<T, Tprec>::PointInRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::PointInRect
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::PointInRect(const T _x,
                                        const T _y) const
    {
        return (_x >= x) &&
               (_y >= y) &&
               (_x < x + w) &&
               (_y < y + h);
    } // qRect2D<T, Tprec>::PointInRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::FitIntoRect
    *******************************************************************************/
//    template<class T, class Tprec>
//    qRect2D<T, Tprec> qRect2D<T, Tprec>::FitIntoRect(const qRect2D<T, Tprec>	&_rct2FitInto) const
//	{
//        qRect2D<T, Tprec>	rctResult(*this);
//		dbl		fFactFit  = ((dbl) _rct2FitInto.w) / ((dbl) _rct2FitInto.h);
//		dbl		fFactThis = ((dbl) w) / ((dbl) h);

//		if (fFactFit > fFactThis)
//		{
//            // fitqRect2D is more wide than this => expand the width
//			T	tCenterx	= (x+w)/2;

//			rctResult.w = (T) (h * fFactFit);
//			rctResult.x = (T) (tCenterx - rctResult.w/2);
//		}
//		else
//		{
//            // fitqRect2D is more high than this => expand the height
//			T		tCentery	= (y+h)/2;

//			rctResult.h = (T) (w / fFactFit);
//			rctResult.y = (T) (tCentery - rctResult.h/2);
//		}

//		return rctResult;
//    } // qRect2D<T, Tprec>::FitIntoRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::Transform
    *******************************************************************************/
    // template<class T, class Tprec>
    // qVector2D<T> qRect2D<T, Tprec>::Transform(const qRect2D<T, Tprec>&  _rctDst,
    //                                           const qVector2D<T>&       _v2dTransform) const
    // {
    //     qTransform<T, T> transX(x, x + w, _rctDst.x, _rctDst.x + _rctDst.w);
    //     qTransform<T, T> transY(y, y + h, _rctDst.y, _rctDst.y + _rctDst.h);

    //     qVector2D<T> v2d(transX.Src2Dst(_v2dTransform.x),
    //                      transY.Src2Dst(_v2dTransform.y));

    //     return v2d;
    // } // qRect2D<T, Tprec>::Transform


    /*******************************************************************************
    * qRect2D<T, Tprec>::Transform
    *******************************************************************************/
    // template<class T, class Tprec>
    // qRect2D<T, Tprec> qRect2D<T, Tprec>::Transform(const qRect2D<T, Tprec>		&_rctDst,
    //                                                const qRect2D<T, Tprec>		&_rctTransform) const
    // {
    //     qTransform<T, T> transX(x, x + w, _rctDst.x, _rctDst.x + _rctDst.w);
    //     qTransform<T, T> transY(y, y + h, _rctDst.y, _rctDst.y + _rctDst.h);

    //     qVector2D<T> v2d1(transX.Src2Dst(_rctTransform.x),
    //                       transY.Src2Dst(_rctTransform.y));

    //     qVector2D<T> v2d2(transX.Src2Dst(_rctTransform.x + _rctTransform.w),
    //                       transY.Src2Dst(_rctTransform.y + _rctTransform.h));

    //     return qRect2D<T, Tprec>(v2d1, v2d2);
    // } // qRect2D<T, Tprec>::Transform

} // namespace qLib
