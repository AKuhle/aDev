/*******************************************************************************
* \file aPoolVarBase.h
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
#include "aUtil_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aPoolVarBase
*******************************************************************************/
template <class T>
class aPoolVarBase
{
    private:
        T			m_tValue;
        T			m_tDefault;
        T			m_tMin;
        T			m_tMax;

        bool		m_bMinMax	{ false };

    public:
        aPoolVarBase(const aPoolVarBase<T> &_rhs)
        {
            m_tValue	= _rhs.m_tValue;
            m_tDefault	= _rhs.m_tDefault;
            m_tMin		= _rhs.m_tMin;
            m_tMax		= _rhs.m_tMax;
            m_bMinMax	= _rhs.m_bMinMax;
        }

        aPoolVarBase(const T		&_tValue,
                     const T		&_tDefault)
        : m_tValue(_tValue),
          m_tDefault(_tDefault),
          m_tMin(_tValue),		// any value to avoid unitialized variable
          m_tMax(_tValue),		// any value to avoid unitialized variable
          m_bMinMax(false)
        {
        }

        aPoolVarBase(const T		&_tValue,
                     const T		&_tDefault,
                     const T		&_tMin,
                     const T		&_tMax)
        : m_tValue(_tValue),
          m_tDefault(_tDefault),
          m_tMin(_tMin),
          m_tMax(_tMax),
          m_bMinMax(true)
        {
        }

        aPoolVarBase<T>& operator=(const aPoolVarBase<T> &_rhs)
        {
            m_tValue	= _rhs.m_tValue;
            m_tDefault	= _rhs.m_tDefault;
            m_tMin		= _rhs.m_tMin;
            m_tMax		= _rhs.m_tMax;
            m_bMinMax	= _rhs.m_bMinMax;

            return *this;
        } // aPoolVarBase::operator=

        const T&            val() const             { return m_tValue; }
        const T&            defVal() const          { return m_tDefault; }
        const T&            minVal() const          { return m_tMin; }
        const T&            maxVal() const          { return m_tMax; }
        const bool&         minMax() const          { return m_bMinMax; }

        T&                  val()                   { return m_tValue; }
        T&                  defVal()                { return m_tDefault; }
        T&                  minVal()                { return m_tMin; }
        T&                  maxVal()                { return m_tMax; }
        bool&               minMax()                { return m_bMinMax; }


        virtual void        add2JsonFile(aJsonFile  &_jFile,
                                         u32        _u32keyID) const = 0;

}; // class aPoolVarBase


} // namespace aUtil
} // namespace aFrame
