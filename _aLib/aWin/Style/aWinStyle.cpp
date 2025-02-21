/*******************************************************************************
* \file aWinStyle.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Style/aWinStyle.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aWinStyle::aWinStyle
*******************************************************************************/
aWinStyle::aWinStyle()
{
} // aWinStyle::aWinStyle


/*******************************************************************************
* aWinStyle::~aWinStyle
*******************************************************************************/
aWinStyle::~aWinStyle()
{
} // aWinStyle::~aWinStyle


/*******************************************************************************
* aWinStyle::margin
*******************************************************************************/
const aMargin& aWinStyle::margin() const
{
    return m_margin;
} // aWinStyle::margin


/*******************************************************************************
* aWinStyle::margin
*******************************************************************************/
aMargin& aWinStyle::margin()
{
    return m_margin;
} // aWinStyle::margin


/*******************************************************************************
* aWinStyle::border
*******************************************************************************/
const aMargin& aWinStyle::border() const
{
    return m_border;
} // aWinStyle::border


/*******************************************************************************
* aWinStyle::border
*******************************************************************************/
aMargin& aWinStyle::border()
{
    return m_border;
} // aWinStyle::border


/*******************************************************************************
* aWinStyle::padding
*******************************************************************************/
const aMargin& aWinStyle::padding() const
{
    return m_padding;
} // aWinStyle::padding


/*******************************************************************************
* aWinStyle::padding
*******************************************************************************/
aMargin& aWinStyle::padding()
{
    return m_padding;
} // aWinStyle::padding


/*******************************************************************************
* aWinStyle::setBgColor
*******************************************************************************/
void aWinStyle::setBgColor(const aColor  &_color)
{
    m_colBg = _color;
} // aWinStyle::setBgColor


/*******************************************************************************
* aWinStyle::bgColor
*******************************************************************************/
const aColor& aWinStyle::bgColor() const
{
    return m_colBg;
} // aWinStyle::bgColor


/*******************************************************************************
* aWinStyle::setActiveColor
*******************************************************************************/
void aWinStyle::setActiveColor(const aColor  &_color)
{
    m_colActive = _color;
} // aWinStyle::setActiveColor


/*******************************************************************************
* aWinStyle::activeColor
*******************************************************************************/
const aColor& aWinStyle::activeColor() const
{
    return m_colActive;
} // aWinStyle::activeColor


/*******************************************************************************
* aWinStyle::setTextColor
*******************************************************************************/
void aWinStyle::setTextColor(const aColor  &_color)
{
    m_colText = _color;
} // aWinStyle::setTextColor


/*******************************************************************************
* aWinStyle::textColor
*******************************************************************************/
const aColor& aWinStyle::textColor() const
{
    return m_colText;
} // aWinStyle::textColor


/*******************************************************************************
* aWinStyle::setBorderObj
*******************************************************************************/
void aWinStyle::setBorderObj(unique_ptr<aBorderObj> _pObj)
{
    m_pBorderObj = std::move(_pObj);
} // aWinStyle::setBorderObj


/*******************************************************************************
* aWinStyle::borderObj
*******************************************************************************/
aBorderObj* aWinStyle::borderObj() const
{
    return m_pBorderObj.get();
} // aWinStyle::borderObj


/*******************************************************************************
* aWinStyle::setContentObj
*******************************************************************************/
void aWinStyle::setContentObj(unique_ptr<aFillObj> _pObj)
{
    m_pContentObj = std::move(_pObj);
} // aWinStyle::setContentObj


/*******************************************************************************
* aWinStyle::contentObj
*******************************************************************************/
aFillObj* aWinStyle::contentObj() const
{
    return m_pContentObj.get();
} // aWinStyle::contentObj


} // namespace aWin
} // namespace aLib
