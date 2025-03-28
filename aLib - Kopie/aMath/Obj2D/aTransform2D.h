/*******************************************************************************
* \file aTransform2D.cpp
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
#include "aHelper.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aMath {


/*******************************************************************************
* class aTransform2D
*******************************************************************************/
template<class tSrc, class tDst>
class aTransform2D
{
    private:
        tSrc		m_tSrc1		{ 0 };
        tSrc		m_tSrc2		{ 0 };
        tDst		m_tDst1		{ 0 };
        tDst		m_tDst2		{ 0 };

        tSrc		m_deltaSrc	{ 0 };
        tDst		m_deltaDst	{ 0 };

    public:
        aTransform2D();

        aTransform2D(const tSrc		_tSrc1,
                   const tSrc		_tSrc2,
                   const tDst		_tDst1,
                   const tDst		_tDst2);

        virtual ~aTransform2D() = default;

        void			set(const tSrc		_tSrc1,
                            const tSrc		_tSrc2,
                            const tDst		_tDst1,
                            const tDst		_tDst2);

        tDst			src2Dst(const tSrc	_tSrcX,
                                bool        _bClamp) const;

        tSrc			dst2Src(const tDst	_tDstX,
                                bool        _bClamp) const;
}; // class aTransform2D


} // namespace aMath
} // namespace aLib

#include "aTransform2D.inl"
