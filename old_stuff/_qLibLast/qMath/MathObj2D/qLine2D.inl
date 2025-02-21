/*******************************************************************************
* \file qLine2D.inl
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


namespace qLib
{
    /*******************************************************************************
    * qLine2D<T, Tprec>::qLine2D
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>::qLine2D()
	{
    } // qLine2D<T, Tprec>::qLine2D


    /*******************************************************************************
    * qLine2D<T, Tprec>::qLine2D
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>::qLine2D(const qLine2D<T, Tprec>& _rhs)
    : m_v2dStart(_rhs.m_v2dStart),
      m_v2dEnd(_rhs.m_v2dEnd)
	{
    } // qLine2D<T, Tprec>::qLine2D


    /*******************************************************************************
    * qLine2D<T, Tprec>::qLine2D
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>::qLine2D(const qVector2D<T, Tprec>&  _v2dStart,
                               const qVector2D<T, Tprec>&  _v2dEnd)
    : m_v2dStart(_v2dStart),
        m_v2dEnd(_v2dEnd)
    {
    } // qLine2D<T, Tprec>::qLine2D


    /*******************************************************************************
    * qLine2D<T, Tprec>::qLine2D
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>::qLine2D(T   _tStartX,
                               T   _tStartY,
                               T   _tEndX,
                               T   _tEndY)
        : m_v2dStart(_tStartX, _tStartY),
        m_v2dEnd(_tEndX, _tEndY)
    {
    } // qLine2D<T, Tprec>::qLine2D


    /*******************************************************************************
    * qLine2D<T, Tprec>::~qLine2D
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>::~qLine2D()
    {
    } // qLine2D<T, Tprec>::~qLine2D


    /*******************************************************************************
    * qLine2D<T, Tprec>::operator=
    *******************************************************************************/
    template<class T, class Tprec>
    qLine2D<T, Tprec>& qLine2D<T, Tprec>::operator=(const qLine2D<T, Tprec> &_rhs)
    {
        m_v2dStart = _rhs.m_v2dStart;
        m_v2dEnd = _rhs.m_v2dEnd;

        return *this;
    } // qLine2D<T, Tprec>::operator=


    /*******************************************************************************
    * qLine2D<T, Tprec>::StartPoint
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qLine2D<T, Tprec>::StartPoint() const
    {
        return m_v2dStart;
    } // qLine2D<T, Tprec>::StartPoint


    /*******************************************************************************
    * SetStartPoint
    *******************************************************************************/
    template<class T, class Tprec>
    void qLine2D<T, Tprec>::SetStartPoint(const qVector2D<T, Tprec>& _v2dStart)
    {
        m_v2dStart = _v2dStart;
    } // SetStartPoint


    /*******************************************************************************
    * SetStartPoint
    *******************************************************************************/
    template<class T, class Tprec>
    void qLine2D<T, Tprec>::SetStartPoint(T   _tStartX,
                                          T   _tStartY)
    {
        m_v2dStart.Set(_tStartX, _tStartY);
    } // SetStartPoint


    /*******************************************************************************
    * EndPoint
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qLine2D<T, Tprec>::EndPoint() const
    {
        return m_v2dEnd;
    } // EndPoint


    /*******************************************************************************
    * SetEndPoint
    *******************************************************************************/
    template<class T, class Tprec>
    void qLine2D<T, Tprec>::SetEndPoint(const qVector2D<T, Tprec>& _v2dEnd)
    {
        m_v2dEnd = _v2dEnd;
    } // SetEndPoint


    /*******************************************************************************
    * SetEndPoint
    *******************************************************************************/
    template<class T, class Tprec>
    void qLine2D<T, Tprec>::SetEndPoint(T   _tEndX,
                                        T   _tEndY)
    {
        m_v2dEnd.Set(_tEndX, _tEndY);
    } // SetEndPo


    /*******************************************************************************
    * Set
    *******************************************************************************/
    template<class T, class Tprec>
    void qLine2D<T, Tprec>::Set(T   _tStartX,
                                T   _tStartY,
                                T   _tEndX,
                                T   _tEndY)
    {
        m_v2dStart.Set(_tStartX, _tStartY);
        m_v2dEnd.Set(_tEndX, _tEndY);
    } // Set


    /*******************************************************************************
    * Perpendicular
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qLine2D<T, Tprec>::Perpendicular(const qVector2D<T, Tprec>  &_v2dPoint,
                                                         dbl                        &_dblLambda) const
    {
        qVector2D<dbl> u(m_v2dEnd.x() - m_v2dStart.x(), m_v2dEnd.y() - m_v2dStart.y());
        u.Normalize();

        dbl r = (u.x()*(_v2dPoint.x() - m_v2dStart.x()) + u.y()*(_v2dPoint.y() - m_v2dStart.y()));

        r = Clamp<dbl> (r, 0, (m_v2dEnd - m_v2dStart).Norm());

        _dblLambda = r / (m_v2dEnd - m_v2dStart).Norm();

        return qVector2D<T, Tprec> (m_v2dStart.x() + r*u.x(),
                                    m_v2dStart.y() + r*u.y());
    } // Perpendicular


    /*******************************************************************************
    * PointOnLine
    *******************************************************************************/
    template<class T, class Tprec>
    qVector2D<T, Tprec> qLine2D<T, Tprec>::PointOnLine(dbl _dDistFromStart_pcnt) const
    {
        qVector2D<dbl> u(m_v2dEnd.x() - m_v2dStart.x(), m_v2dEnd.y() - m_v2dStart.y());

        return qVector2D<T, Tprec> (m_v2dStart.x() + _dDistFromStart_pcnt * u.x(),
                                    m_v2dStart.y() + _dDistFromStart_pcnt * u.y());
    } // PointOnLine


} // namespace qLib
