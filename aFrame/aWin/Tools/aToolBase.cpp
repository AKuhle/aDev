/*******************************************************************************
* \file aToolBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolBase.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolBase::aToolBase
*******************************************************************************/
aToolBase::aToolBase(aBaseWin   *_pOwner,
                     u32        _u32ToolId,
                     u32        _u32Flags       /*= TF_NONE*/)
: m_pOwner(_pOwner),
  m_u32ToolId(_u32ToolId),
  m_u32Flags(_u32Flags)
{
} // aToolBase::aToolBase


/*******************************************************************************
* aToolBase::~aToolBase
*******************************************************************************/
aToolBase::~aToolBase()
{
} // aToolBase::~aToolBase


/*******************************************************************************
* aToolBase::onLDoubleClick
*******************************************************************************/
bool aToolBase::onLDoubleClick(u16              /*_u16Modifier*/,
                               const aPoint     &/*_pntLocal*/,
                               const aPoint     &/*_pntGlobal*/)
{
    return false;
} // aToolBase::onLDoubleClick


/*******************************************************************************
* aToolBase::onMDoubleClick
*******************************************************************************/
bool aToolBase::onMDoubleClick(u16              /*_u16Modifier*/,
                               const aPoint     &/*_pntLocal*/,
                               const aPoint     &/*_pntGlobal*/)
{
    return false;
} // aToolBase::onMDoubleClick


/*******************************************************************************
* aToolBase::onRDoubleClick
*******************************************************************************/
bool aToolBase::onRDoubleClick(u16              /*_u16Modifier*/,
                               const aPoint     &/*_pntLocal*/,
                               const aPoint     &/*_pntGlobal*/)
{
    return false;
} // aToolBase::onRDoubleClick


/*******************************************************************************
* aToolBase::onToolLDoubleClick
*******************************************************************************/
bool aToolBase::onToolLDoubleClick(u16              _u16Modifier,
                                   const aPoint     &_pntLocal,
                                   const aPoint     &_pntGlobal)
{
    return onLDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
} // aToolBase::onToolLDoubleClick


/*******************************************************************************
* aToolBase::onToolMDoubleClick
*******************************************************************************/
bool aToolBase::onToolMDoubleClick(u16              _u16Modifier,
                                   const aPoint     &_pntLocal,
                                   const aPoint     &_pntGlobal)
{
    return onMDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
} // aToolBase::onToolMDoubleClick


/*******************************************************************************
* aToolBase::onToolRDoubleClick
*******************************************************************************/
bool aToolBase::onToolRDoubleClick(u16              _u16Modifier,
                                   const aPoint     &_pntLocal,
                                   const aPoint     &_pntGlobal)
{
    return onRDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
} // aToolBase::onToolRDoubleClick


} // namespace aWin
} // namespace aFrame
