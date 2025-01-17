/*******************************************************************************
* \file aCtrl.inl
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
#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aCtrl::aCtrl
*******************************************************************************/
aCtrl::aCtrl(aBaseWin   *_pParent,
             u32        _u32Id)
: aBaseWin(_pParent),
  m_u32CtrlId(_u32Id)
{
} // aCtrl::aCtrl


/*******************************************************************************
* aCtrl::~aCtrl
*******************************************************************************/
aCtrl::~aCtrl()
{
} // aCtrl::~aCtrl


/*******************************************************************************
* aCtrl::setCtrlMgr
*******************************************************************************/
void aCtrl::setCtrlMgr(aCtrlMgr *_pCtrlMgr)
{
    m_pCtrlMgr = _pCtrlMgr;
} // aCtrl::setCtrlMgr


/*******************************************************************************
* aCtrl::ctrlMgr
*******************************************************************************/
aCtrlMgr* aCtrl::ctrlMgr() const
{
    return m_pCtrlMgr;
} // aCtrl::ctrlMgr


/*******************************************************************************
* aCtrl::setHoverColor
*******************************************************************************/
void aCtrl::setHoverColor(const aColor  &_color)
{
    m_colHover = _color;
} // aCtrl::setHoverColor


/*******************************************************************************
* aCtrl::hoverColor
*******************************************************************************/
const aColor& aCtrl::hoverColor() const
{
    return m_colHover;
} // aCtrl::hoverColor


/*******************************************************************************
* aCtrl::setDisabledColor
*******************************************************************************/
void aCtrl::setDisabledColor(const aColor  &_color)
{
    m_colDisabled = _color;
} // aCtrl::setDisabledColor


/*******************************************************************************
* aCtrl::disabledColor
*******************************************************************************/
const aColor& aCtrl::disabledColor() const
{
    return m_colDisabled;
} // aCtrl::disabledColor


/*******************************************************************************
* aCtrl::setNormalColor
*******************************************************************************/
void aCtrl::setNormalColor(const aColor  &_color)
{
    m_colNormal = _color;
} // aCtrl::setNormalColor


/*******************************************************************************
* aCtrl::normalColor
*******************************************************************************/
const aColor& aCtrl::normalColor() const
{
    return m_colNormal;
} // aCtrl::normalColor


/*******************************************************************************
* aCtrl::setSelectedColor
*******************************************************************************/
void aCtrl::setSelectedColor(const aColor  &_color)
{
    m_colSelected = _color;
} // aCtrl::setSelectedColor


/*******************************************************************************
* aCtrl::selectedColor
*******************************************************************************/
const aColor& aCtrl::selectedColor() const
{
    return m_colSelected;
} // aCtrl::selectedColor


} // namespace aWin
} // namespace aLib
