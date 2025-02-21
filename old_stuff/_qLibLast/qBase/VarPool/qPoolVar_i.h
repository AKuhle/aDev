/*******************************************************************************
* \file qPoolVar.h
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
* include
*******************************************************************************/
#pragma once



/*******************************************************************************
* class qPoolVarI
*******************************************************************************/
namespace qLib
{
	template <class T>
    class qPoolVarI
	{
        private:
			T			tValue;
			T			tDefault;
			T			tMin;
			T			tMax;

            bool		m_bMinMax	{ false };

        public:
            qPoolVarI() = default;

            qPoolVarI(const T		&_tValue,
                     const T		&_tDefault)
			: tValue(_tValue),
			  tDefault(_tDefault),
			  tMin(_tValue),		// any value to avoid unitialized variable
			  tMax(_tValue),		// any value to avoid unitialized variable
              m_bMinMax(false)
			{
			}

            qPoolVarI(const T		&_tValue,
                     const T		&_tDefault,
                     const T		&_tMin,
                     const T		&_tMax)
            : tValue(_tValue),
			  tDefault(_tDefault),
			  tMin(_tMin),
			  tMax(_tMax),
              m_bMinMax(true)
			{
			}

            qPoolVarI& operator=(const qPoolVarI	&_rhs)
			{
				tValue		= _rhs.tValue;
				tDefault	= _rhs.tDefault;
				tMin		= _rhs.tMin;
				tMax		= _rhs.tMax;
				m_bMinMax	= _rhs.m_bMinMax;

				return *this;
            } // qPoolVarI::operator=

            const T&            Value() const           { return tValue; }
            const T&            Default() const         { return tDefault; }
            const T&            Min() const             { return tMin; }
            const T&            Max() const             { return tMax; }
            const bool&         MinMax() const          { return m_bMinMax; }

            T&                  Value()                 { return tValue; }
            T&                  Default()               { return tDefault; }
            T&                  Min()                   { return tMin; }
            T&                  Max()                   { return tMax; }
            bool&               MinMax()                { return m_bMinMax; }

            bool                IsMinMaxValue() const   { return m_bMinMax; }

    }; // class qPoolVarI

} // namespace qLib
