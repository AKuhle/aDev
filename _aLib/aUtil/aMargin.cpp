/*******************************************************************************
* \file aMargin.h
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
#include "aUtil/aMargin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aMargin::aMargin
*******************************************************************************/
aMargin::aMargin()
{
} // aMargin::aMargin


/*******************************************************************************
* aMargin::aMargin
*******************************************************************************/
aMargin::aMargin(s32 _lrtb)
: m_l(_lrtb),
  m_r(_lrtb),
  m_t(_lrtb),
  m_b(_lrtb)
{
} // aMargin::aMargin


/*******************************************************************************
* aMargin::aMargin
*******************************************************************************/
aMargin::aMargin(s32  _l,
                 s32  _r,
                 s32  _t,
                 s32  _b)
: m_l(_l),
  m_r(_r),
  m_t(_t),
  m_b(_b)
{
} // aMargin::aMargin


/*******************************************************************************
* aMargin::~aMargin
*******************************************************************************/
aMargin::~aMargin()
{
} // aMargin::~aMargin


/*******************************************************************************
* aMargin::set
*******************************************************************************/
void aMargin::set(s32  _lrtb)
{
    m_l = _lrtb;
    m_r = _lrtb;
    m_t = _lrtb;
    m_b = _lrtb;
} // aMargin::set


/*******************************************************************************
* aMargin::set
*******************************************************************************/
void aMargin::set(s32  _l,
                  s32  _r,
                  s32  _t,
                  s32  _b)
{
    m_l = _l;
    m_r = _r;
    m_t = _t;
    m_b = _b;
} // aMargin::set


} // namespace aUtil
} // namespace aLib
