/*******************************************************************************
* \file qMargin.h
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


//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
namespace qLib
{
    //------------------------------------------------------------------------------
    // qMargin<T>::qMargin()
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>::qMargin()
    {
    } // qMargin<T>::qMargin()


    //------------------------------------------------------------------------------
    // qMargin<T>::qMargin()
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>::qMargin(const qMargin<T>& _rhs)
    : l(_rhs.l),
      r(_rhs.r),
      t(_rhs.t),
      b(_rhs.b)
    {
    } // qMargin<T>::qMargin()


    //------------------------------------------------------------------------------
    // qMargin<T>::qMargin()
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>::qMargin(T   _tEqualMargins)
    : l(_tEqualMargins),
      r(_tEqualMargins),
      t(_tEqualMargins),
      b(_tEqualMargins)
    {
    } // qMargin<T>::qMargin()


    //------------------------------------------------------------------------------
    // qMargin<T>::qMargin()
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>::qMargin(T   _l,
                        T   _r,
                        T   _t,
                        T   _b)
    : l(_l),
      r(_r),
      t(_t),
      b(_b)
    {
    } // qMargin<T>::qMargin()


    //------------------------------------------------------------------------------
    // qMargin<T>::~qMargin()
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>::~qMargin()
    {
    } // qMargin<T>::~qMargin()


    //------------------------------------------------------------------------------
    // qMargin<T>::Set
    //------------------------------------------------------------------------------
    template<class T>
    void qMargin<T>::Set(T  _tEqualMargins)
    {
        l = _tEqualMargins;
        r = _tEqualMargins;
        t = _tEqualMargins;
        b = _tEqualMargins;
    } // qMargin<T>::Set


    //------------------------------------------------------------------------------
    // qMargin<T>::Set
    //------------------------------------------------------------------------------
    template<class T>
    void qMargin<T>::Set(T  _l,
                         T  _r,
                         T  _t,
                         T  _b)
    {
        l = _l;
        r = _r;
        t = _t;
        b = _b;
    } // qMargin<T>::Set


    //------------------------------------------------------------------------------
    // qMargin<T>::operator=
    //------------------------------------------------------------------------------
    template<class T>
    qMargin<T>& qMargin<T>::operator=(const qMargin<T>	&_rhs)
    {
        // avoid selfcopy
        if (this != &_rhs)
        {
            l = _rhs.l;
            r = _rhs.r;
            t = _rhs.t;
            b = _rhs.b;
        }

        return *this;
    } // qMargin<T>::operator=


    //------------------------------------------------------------------------------
    // qMargin<T>::operator==
    //------------------------------------------------------------------------------
    template<class T>
    bool qMargin<T>::operator==(const qMargin<T>	&_rhs) const
    {
        return IsEqual<T>(l, _rhs.l) && IsEqual<T>(r, _rhs.r) &&
               IsEqual<T>(t, _rhs.t) && IsEqual<T>(b, _rhs.b);
    } // qMargin<T>::operator==


    //------------------------------------------------------------------------------
    // qMargin<T>::operator!=
    //------------------------------------------------------------------------------
    template<class T>
    bool qMargin<T>::operator!=(const qMargin<T>	&_rhs) const
    {
        return IsUnequal<T>(l, _rhs.l) << IsUnequal<T>(r, _rhs.r) ||
               IsUnequal<T>(t, _rhs.t) || IsUnequal<T>(b, _rhs.b);
    } // qMargin<T>::operator!=


    //------------------------------------------------------------------------------
    // qMargin<T>::w
    //------------------------------------------------------------------------------
    template<class T>
    T qMargin<T>::w() const
    {
        return l + r;
    } // qMargin<T>::w


    //------------------------------------------------------------------------------
    // qMargin<T>::h
    //------------------------------------------------------------------------------
    template<class T>
    T qMargin<T>::h() const
    {
        return t + b;
    } // qMargin<T>::h

} // namespace qLib
