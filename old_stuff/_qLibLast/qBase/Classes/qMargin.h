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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * class qMargin
    *******************************************************************************/
    template<class T>
    class qMargin
	{
        public:
            T       l   { 0 };
            T       r   { 0 };
            T       t   { 0 };
            T       b   { 0 };

        public:
            qMargin();

            qMargin(const qMargin<T>& _rhs);

            qMargin(T  _tEqualMargins);

            qMargin(T  _l,
                    T  _r,
                    T  _t,
                    T  _b);

            ~qMargin();

            void Set(T  _tEqualMargins);

            void Set(T  _l,
                     T  _r,
                     T  _t,
                     T  _b);

            qMargin<T>&     operator=(const qMargin<T>& _rhs);

            bool            operator==(const qMargin<T>& _rhs) const;
            bool            operator!=(const qMargin<T>& _rhs) const;

            T               w() const;  // l + r
            T               h() const;  // t + b
    }; // class qMargin

} // namespace qLib

#include "qMargin.inl"
