/*******************************************************************************
* \file qValue.h
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
* include
*******************************************************************************/
#include "Util/utilDefs.h"

using namespace qLib::Util;


namespace qLib {
namespace Object {


template <class T>
class qValue
{
    private:
        T			tValue;
        T			tDefault;
        T			tMin;
        T			tMax;
        bool		m_bMinMax	{ false };


    public:
        qValue() = default;

        qValue(const T		&_tValue,
               const T		&_tDefault)
        : tValue(_tValue),
          tDefault(_tDefault),
          tMin(_tValue),		// any value to avoid unitialized variable
          tMax(_tValue),		// any value to avoid unitialized variable
          m_bMinMax(false)
        {
        }


        qValue(const T		&_tValue,
               const T		&_tDefault,
               const T		&_tMin,
               const T		&_tMax)
        : tValue(clamp<T>(_tValue, _tMin, _tMax)),
          tDefault(clamp<T>(_tDefault, _tMin, _tMax)),
          tMin(_tMin),
          tMax(_tMax),
          m_bMinMax(true)
        {
        }


        qValue& operator=(const qValue	&_rhs)
        {
            tValue		= _rhs.tValue;
            tDefault	= _rhs.tDefault;
            tMin		= _rhs.tMin;
            tMax		= _rhs.tMax;
            m_bMinMax	= _rhs.m_bMinMax;

            return *this;
        } // qValue::operator=


        void setValue(const T    &_tVal)
        {
            if (m_bMinMax)
            {
                tValue = clamp<T>(_tVal, tMin, tMax);
            }
            else
            {
                tValue = _tVal;
            }
        }


        const T& value() const
        {
            return tValue;
        }

        // const T&            val() const             { return tValue; }
        // const T&            defVal() const          { return tDefault; }
        // const T&            minVal() const          { return tMin; }
        // const T&            maxVal() const          { return tMax; }
        // const bool&         isMinMax() const        { return m_bMinMax; }

        // T&                  val()                   { return tValue; }
        // T&                  defVal()                { return tDefault; }
        // T&                  minVal()                { return tMin; }
        // T&                  maxVal()                { return tMax; }
        // bool&               isMinMax()              { return m_bMinMax; }

}; // class qValue


} // namespace Object
} // namespace qLib
