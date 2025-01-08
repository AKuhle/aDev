/*******************************************************************************
* \file qTransform.cpp
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


namespace qLib
{
    /*******************************************************************************
    * class qTransform
    *******************************************************************************/
    template<class tSrc, class tDst>
    class qTransform
	{
		private:
			tSrc		m_tSrc1		{ 0 };
			tSrc		m_tSrc2		{ 0 };
			tDst		m_tDst1		{ 0 };
			tDst		m_tDst2		{ 0 };

			tSrc		m_deltaSrc	{ 0 };
			tDst		m_deltaDst	{ 0 };

		public:
            qTransform();

            qTransform(const tSrc		_tSrc1,
                       const tSrc		_tSrc2,
                       const tDst		_tDst1,
                       const tDst		_tDst2);

            virtual ~qTransform() = default;
	
			void			Set(const tSrc		_tSrc1,
								const tSrc		_tSrc2,
								const tDst		_tDst1,
								const tDst		_tDst2);

			tDst			Src2Dst(const tSrc	_tSrcX) const;
			tSrc			Dst2Src(const tDst	_tDstX) const;
    }; // class qTransform

} // namespace qLib

#include "qTransform.inl"
