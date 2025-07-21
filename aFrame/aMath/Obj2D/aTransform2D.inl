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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* aTransform2D<tSrc, tDst>::aTransform2D
*******************************************************************************/
template<class tSrc, class tDst>
aTransform2D<tSrc, tDst>::aTransform2D()
{
} // aTransform2D<tSrc, tDst>::aTransform2D


/*******************************************************************************
* aTransform2D<tSrc, tDst>::aTransform2D
*******************************************************************************/
template<class tSrc, class tDst>
aTransform2D<tSrc, tDst>::aTransform2D(const tSrc   _tSrc1,
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
} // aTransform2D<tSrc, tDst>::aTransform2D


/*******************************************************************************
* aTransform2D<tSrc, tDst>::set
*******************************************************************************/
template<class tSrc, class tDst>
void aTransform2D<tSrc, tDst>::set(const tSrc		_tSrc1,
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
} // aTransform2D<tSrc, tDst>::set


/*******************************************************************************
* aTransform2D<tSrc, tDst>::src2Dst
*******************************************************************************/
template<class tSrc, class tDst>
tDst aTransform2D<tSrc, tDst>::src2Dst(const tSrc   _tSrcX,
                                       bool         _bClamp) const
{
     tDst tDstVal = m_tDst1 + (tDst) (((dbl) (_tSrcX - m_tSrc1)) * m_deltaDst / m_deltaSrc);

     return (_bClamp)?   aUtil::clamp<tDst>(tDstVal, m_tDst1, m_tDst2) : tDstVal;
} // aTransform2D<tSrc, tDst>::src2Dst


/*******************************************************************************
* aTransform2D<tSrc, tDst>::dst2Src
*******************************************************************************/
template<class tSrc, class tDst>
tSrc aTransform2D<tSrc, tDst>::dst2Src(const tDst   _tDstX,
                                       bool         _bClamp) const
{
    tSrc tSrcVal = m_tSrc1 + (tSrc) (((dbl) (_tDstX - m_tDst1)) * m_deltaSrc / m_deltaDst);

    return (_bClamp)?   aUtil::clamp<tDst>(tSrcVal, m_tSrc1, m_tSrc2) : tSrcVal;
} // aTransform2D<tSrc, tDst>::dst2Src


} // namespace aMath
} // namespace aFrame
