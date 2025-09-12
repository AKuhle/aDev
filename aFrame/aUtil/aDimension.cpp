/*******************************************************************************
* \file aDimension.inl
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
* includes
*******************************************************************************/
#include "aDimension.h"
#include "aHelper.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aDimension::aDimension
*******************************************************************************/
aDimension::aDimension()
{
} // aDimension::aDimension


/*******************************************************************************
* aDimension::aDimension()
*******************************************************************************/
aDimension::aDimension(const aDimension	&_rhs)
: m_w(_rhs.m_w),
  m_h(_rhs.m_h)
{
    // don't call operator= to avoid multiple assignments
}


/*******************************************************************************
* aDimension::aDimension
*******************************************************************************/
aDimension::aDimension(const s32  _w,
                         const s32  _h)
: m_w(_w),
  m_h(_h)
{
} // aDimension::aDimension


/*******************************************************************************
* aDimension::~aDimension
*******************************************************************************/
aDimension::~aDimension()
{
} // aDimension::~aDimension


/*******************************************************************************
* aDimension::operator=
*******************************************************************************/
aDimension& aDimension::operator=(const aDimension	&_rhs)
{
    m_w = _rhs.m_w;
    m_h = _rhs.m_h;

    return *this;
} // aDimension::operator=


/*******************************************************************************
* aDimension::operator==
*******************************************************************************/
bool aDimension::operator==(const aDimension	&_rhs) const
{
    return isEqual(m_w, _rhs.m_w) &&
           isEqual(m_h, _rhs.m_h);
} // aDimension::operator==


/*******************************************************************************
* aDimension::operator!=
*******************************************************************************/
bool aDimension::operator!=(const aDimension	&_rhs) const
{
    return isUnequal(m_w, _rhs.m_w) ||
           isUnequal(m_h, _rhs.m_h);
} // aDimension::operator!=


/*******************************************************************************
* aDimension::operator+=
*******************************************************************************/
aDimension& aDimension::operator+=(const aDimension &_rhs)
{
    m_w += _rhs.m_w;
    m_h += _rhs.m_h;

    return *this;
} // aDimension::operator+=


/*******************************************************************************
* aDimension::operator*=
*******************************************************************************/
aDimension& aDimension::operator*=(dbl _dMuliplicator)
{
    m_w *= _dMuliplicator;
    m_h *= _dMuliplicator;

    return *this;
} // aDimension::operator*=


/*******************************************************************************
* aDimension::operator*
*******************************************************************************/
aDimension aDimension::operator*(dbl	_dMuliplicator) const
{
    return aDimension ((s32) (((dbl) m_w) * _dMuliplicator),
                       (s32) (((dbl) m_h) * _dMuliplicator));
} // aDimension::operator*


/*******************************************************************************
* aDimension::w
*******************************************************************************/
s32 aDimension::w() const
{
    return m_w;
} // aDimension::w


/*******************************************************************************
* aDimension::h
*******************************************************************************/
s32 aDimension::h() const
{
    return m_h;
} // aDimension::h


/*******************************************************************************
* aDimension::w
*******************************************************************************/
s32& aDimension::w()
{
    return m_w;
} // aDimension::w


/*******************************************************************************
* aDimension::h
*******************************************************************************/
s32& aDimension::h()
{
    return m_h;
} // aDimension::h


/*******************************************************************************
* aDimension::set
*******************************************************************************/
void aDimension::set(const s32  _w,
                     const s32  _h)
{
    m_w = _w;
    m_h = _h;
} // aDimension::set


/*******************************************************************************
* aDimension::setEmpty
*******************************************************************************/
void aDimension::setEmpty()
{
    m_w = m_h = 0;
} // aDimension::setEmpty


/*******************************************************************************
* aDimension::isEmpty
*******************************************************************************/
bool aDimension::isEmpty() const
{
    return isZero(m_w) && isZero(m_h);
} // aDimension::isEmpty


/*******************************************************************************
* aDimension::max
*******************************************************************************/
aDimension aDimension::max(const aDimension &_rhs) const
{
    return aDimension (aUtil::max(m_w, _rhs.m_w),
                       aUtil::max(m_h, _rhs.m_h));
} // aDimension::max


/*******************************************************************************
* aDimension::max
*******************************************************************************/
aDimension aDimension::max(const aDimension &_dim1,
                           const aDimension &_dim2)
{
    return aDimension (aUtil::max(_dim1.m_w, _dim2.m_w),
                       aUtil::max(_dim1.m_h, _dim2.m_h));
} // aDimension::max


} // namespace aUtil
} // namespace aFrame
