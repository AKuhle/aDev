/*******************************************************************************
* \file qRect2D.inl
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastCm_hangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
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
    : m_x(_rhs.m_x),
      m_y(_rhs.m_y),
      m_w(_rhs.m_w),
      m_h(_rhs.m_h)
	{
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D(const T		_m_x,
                               const T		_m_y,
                               const T		_m_w,
                               const T		_m_h)
        : m_x(_m_x),
          m_y(_m_y),
          m_w(_m_w),
          m_h(_m_h)
    {
    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
//    template<class T, class Tprec>
//    qRect2D<T, Tprec>::qRect2D(const qlVector2D<T>	&_v2dOrigin,
//                             const T				_w,
//                             const T				_h)
//    : m_x(_v2dOrigin.m_x),
//      m_y(_v2dOrigin.m_y),
//      m_w(_m_w),
//      m_h(_m_h)
//    {
//    } // qRect2D<T, Tprec>::qRect2D()


    /*******************************************************************************
    * qRect2D<T, Tprec>::qRect2D()
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec>::qRect2D(const qVector2D<T>& _v2dOrigin,
                               const qVector2D<T>& _v2dOppositCorner)
    : m_x(Min<T> (_v2dOrigin.x(), _v2dOppositCorner.x())),
      m_y(Min<T> (_v2dOrigin.y(), _v2dOppositCorner.y())),
      m_w(Max<T> (_v2dOrigin.x(), _v2dOppositCorner.x()) - m_x),
      m_h(Max<T> (_v2dOrigin.y(), _v2dOppositCorner.y()) - m_y)
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
        m_x = _x;
        m_y = _y;
        m_w = _w;
        m_h = _h;
    } // qRect2D<T, Tprec>::Set


//    //! Set
//    //!
//    //! Set the position and the size of the rect
//    template<class T, class Tprec>
//    void qRect2D<T, Tprec>::Set(const qlVector2D<T>	&_v2d,
//                               const T               _w,
//                               const T               _h)
//    {
//        m_x = _v2d.x;
//        m_y = _v2d.y;
//        m_w = _m_w;
//        m_h = _m_h;
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
            m_x = _rhs.m_x;
            m_y = _rhs.m_y;
            m_w = _rhs.m_w;
            m_h = _rhs.m_h;
        }

        return *this;
    } // qRect2D<T, Tprec>::operator=


    /*******************************************************************************
    * qRect2D<T, Tprec>::operator==
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::operator==(const qRect2D<T, Tprec>	&_rhs) const
    {
        return IsEqual<T>(m_x, _rhs.m_x) && IsEqual<T>(m_y, _rhs.m_y) &&
               IsEqual<T>(m_w, _rhs.m_w) && IsEqual<T>(m_h, _rhs.m_h);
    } // qRect2D<T, Tprec>::operator==


    /*******************************************************************************
    * qRect2D<T, Tprec>::operator!=
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::operator!=(const qRect2D<T, Tprec>	&_rhs) const
    {
        return IsUnequal<T>(m_x, _rhs.m_x) || IsUnequal<T>(m_y, _rhs.m_y) ||
               IsUnequal<T>(m_w, _rhs.m_w) || IsUnequal<T>(m_h, _rhs.m_h);
    } // qRect2D<T, Tprec>::operator!=


    /*******************************************************************************
    * qRect2D<T, Tprec>::Dimension
    *******************************************************************************/
    template<class T, class Tprec>
    qDimension2D<s32> qRect2D<T, Tprec>::Dimension() const
    {
        return qDimension2D<s32> (m_w, m_h);
    } // qRect2D<T, Tprec>::Dimension


    /*******************************************************************************
    * qRect2D<T, Tprec>::Resize
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Resize(Tprec _tFactor)
    {
        m_w *= _tFactor;
        m_h *= _tFactor;
    } // qRect2D<T, Tprec>::Resize


    /*******************************************************************************
    * qRect2D<T, Tprec>::CenterPoint
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T> qRect2D<T, Tprec>::CenterPoint() const
    {
        return qVector2D<T> ((T) (((dbl) m_x) + ((dbl) m_w)/2),
                             (T) (((dbl) m_y) + ((dbl) m_h)/2));
    } // qRect2D<T, Tprec>::GetCenterPoint()


//	//! SetCenterPoint
//	//!
//	//! Set the center point of the rect
//    template<class T, class Tprec>
//    void qRect2D<T, Tprec>::SetCenterPoint(const T	_m_x,
//                                     const T	_m_y)
//	{
//		m_x = _m_x - m_w/2;
//		m_y = _m_y - m_h/2;
//    } // qRect2D<T, Tprec>::SetCenterPoint


    /*******************************************************************************
    * qRect2D<T, Tprec>::SetEmpty
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::SetEmpty()
    {
        m_x = m_y = m_w = m_h = 0;
    } // qRect2D<T, Tprec>::SetEmpty


    /*******************************************************************************
    * qRect2D<T, Tprec>::IsEmpty
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::IsEmpty() const
    {
        return IsZero<T>(m_x) && IsZero<T>(m_y) && IsZero<T>(m_w) && IsZero<T>(m_h);
    } // qRect2D<T, Tprec>::IsEmpty


    /*******************************************************************************
    * qRect2D<T, Tprec>::Shrink
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Shrink(T _tValue)
    {
        m_x += _tValue;
        m_y += _tValue;
        m_w -= 2 * _tValue;
        m_h -= 2 * _tValue;
    } // qRect2D<T, Tprec>::Shrink


    /*******************************************************************************
    * qRect2D<T, Tprec>::Expand
    *******************************************************************************/
    template<class T, class Tprec>
    void qRect2D<T, Tprec>::Expand(T _tValue)
    {
        m_x -= _tValue;
        m_y -= _tValue;
        m_w += 2 * _tValue;
        m_h += 2 * _tValue;
    } // qRect2D<T, Tprec>::Expand


    /*******************************************************************************
    * qRect2D<T, Tprec>::Intersect
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec> qRect2D<T, Tprec>::Intersect(const qRect2D<T, Tprec>	&_rhs) const
    {
        qRect2D<T, Tprec> r2dIntersect;   // initial the rect is empty

        T           tMinX   = Max(m_x, _rhs.m_x);
        T           tMinY   = Max(m_y, _rhs.m_y);
        T           tMaxX   = Min(m_x + m_w, _rhs.m_x + _rhs.m_w);
        T           tMaxY   = Min(m_y + m_h, _rhs.m_y + _rhs.m_h);

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
        return PointInRect(_v2d.x(), _v2d.y());
    } // qRect2D<T, Tprec>::PointInRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::PointInRect
    *******************************************************************************/
    template<class T, class Tprec>
    bool qRect2D<T, Tprec>::PointInRect(const T _x,
                                        const T _y) const
    {
        return (_x >= m_x) &&
               (_y >= m_y) &&
               (_x < m_x + m_w) &&
               (_y < m_y + m_h);
    } // qRect2D<T, Tprec>::PointInRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::FitIntoRect
    *******************************************************************************/
//    template<class T, class Tprec>
//    qRect2D<T, Tprec> qRect2D<T, Tprec>::FitIntoRect(const qRect2D<T, Tprec>	&_rct2FitInto) const
//	{
//        qRect2D<T, Tprec>	rctResult(*this);
//		dbl		fFactFit  = ((dbl) _rct2FitInto.m_w) / ((dbl) _rct2FitInto.m_h);
//		dbl		fFactThis = ((dbl) m_w) / ((dbl) m_h);

//		if (fFactFit > fFactThis)
//		{
//            // fitqRect2D is more wide than this => expand the width
//			T	tCenterm_x	= (m_x+m_w)/2;

//			rctResult.m_w = (T) (m_h * fFactFit);
//			rctResult.m_x = (T) (tCenterx - rctResult.m_w/2);
//		}
//		else
//		{
//            // fitqRect2D is more high than this => expand the height
//			T		tCentery	= (m_y+m_h)/2;

//			rctResult.m_h = (T) (m_w / fFactFit);
//			rctResult.m_y = (T) (tCentery - rctResult.m_h/2);
//		}

//		return rctResult;
//    } // qRect2D<T, Tprec>::FitIntoRect


    /*******************************************************************************
    * qRect2D<T, Tprec>::Transform
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T> qRect2D<T, Tprec>::Transform(const qRect2D<T, Tprec>&  _rctDst,
                                              const qVector2D<T>&       _v2dTransform) const
    {
        qTransform<T, T> transX(m_x, m_x + m_w, _rctDst.m_x, _rctDst.m_x + _rctDst.m_w);
        qTransform<T, T> transY(m_y, m_y + m_h, _rctDst.m_y, _rctDst.m_y + _rctDst.m_h);

        qVector2D<T> v2d(transX.Src2Dst(_v2dTransform.x()),
                         transY.Src2Dst(_v2dTransform.y()));

        return v2d;
    } // qRect2D<T, Tprec>::Transform


    /*******************************************************************************
    * qRect2D<T, Tprec>::Transform
    *******************************************************************************/
    template<class T, class Tprec>
    qRect2D<T, Tprec> qRect2D<T, Tprec>::Transform(const qRect2D<T, Tprec>		&_rctDst,
                                                   const qRect2D<T, Tprec>		&_rctTransform) const
    {
        qTransform<T, T> transX(m_x, m_x + m_w, _rctDst.m_x, _rctDst.m_x + _rctDst.m_w);
        qTransform<T, T> transY(m_y, m_y + m_h, _rctDst.m_y, _rctDst.m_y + _rctDst.m_h);

        qVector2D<T> v2d1(transX.Src2Dst(_rctTransform.m_x),
                          transY.Src2Dst(_rctTransform.m_y));

        qVector2D<T> v2d2(transX.Src2Dst(_rctTransform.m_x + _rctTransform.m_w),
                          transY.Src2Dst(_rctTransform.m_y + _rctTransform.m_h));

        return qRect2D<T, Tprec>(v2d1, v2d2);
    } // qRect2D<T, Tprec>::Transform

} // namespace qLib
