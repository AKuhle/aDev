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
#include "qBaseDefs.h"


namespace qLib
{
    /*******************************************************************************
    * qTransform<tSrc, tDst>::qTransform
    *******************************************************************************/
    template<class tSrc, class tDst>
    qTransform<tSrc, tDst>::qTransform()
	{
    } // qTransform<tSrc, tDst>::qTransform


    /*******************************************************************************
    * qTransform<tSrc, tDst>::qTransform
    *******************************************************************************/
    template<class tSrc, class tDst>
    qTransform<tSrc, tDst>::qTransform(const tSrc   _tSrc1,
                                       const tSrc	_tSrc2,
                                       const tDst	_tDst1,
                                       const tDst	_tDst2)
	: m_tSrc1(_tSrc1),
	  m_tSrc2(_tSrc2),
	  m_tDst1(_tDst1),
	  m_tDst2(_tDst2),
	  m_deltaSrc(_tSrc2 - _tSrc1),
	  m_deltaDst(_tDst2 - _tDst1)
	{
    } // qTransform<tSrc, tDst>::qTransform


    /*******************************************************************************
    * qTransform<tSrc, tDst>::Set
    *******************************************************************************/
    template<class tSrc, class tDst>
    void qTransform<tSrc, tDst>::Set(const tSrc		_tSrc1,
                                     const tSrc		_tSrc2,
                                     const tDst		_tDst1,
                                     const tDst		_tDst2)
	{
		m_tSrc1		= _tSrc1;
		m_tSrc2		= _tSrc2;
		m_tDst1		= _tDst1;
		m_tDst2		= _tDst2;
		m_deltaSrc	= _tSrc2 - _tSrc1;
		m_deltaDst	= _tDst2 - _tDst1;
    } // qTransform<tSrc, tDst>::Set


    /*******************************************************************************
    * qTransform<tSrc, tDst>::Src2Dst
    *******************************************************************************/
    template<class tSrc, class tDst>
    tDst qTransform<tSrc, tDst>::Src2Dst(const tSrc _tSrcX,
                                         bool       _bClamp) const
	{
         tDst tDstVal = m_tDst1 + (tDst) (((dbl) (_tSrcX - m_tSrc1)) * m_deltaDst / m_deltaSrc);

         return (_bClamp)?   MU<tDst>::Clamp(tDstVal, m_tDst1, m_tDst2) : tDstVal;
    } // qTransform<tSrc, tDst>::Src2Dst


    /*******************************************************************************
    * qTransform<tSrc, tDst>::Dst2Src
    *******************************************************************************/
    template<class tSrc, class tDst>
    tSrc qTransform<tSrc, tDst>::Dst2Src(const tDst	_tDstX,
                                         bool       _bClamp) const
	{
        tSrc tSrcVal = m_tSrc1 + (tSrc) (((dbl) (_tDstX - m_tDst1)) * m_deltaSrc / m_deltaDst);

        return (_bClamp)?   MU<tDst>::Clamp(tSrcVal, m_tSrc1, m_tSrc2) : tSrcVal;
    } // qTransform<tSrc, tDst>::Dst2Src

} // namespace qLib
