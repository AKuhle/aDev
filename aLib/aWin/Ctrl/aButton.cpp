/*******************************************************************************
* \file aButton.inl
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
#include "aWin/Tool/aButtonTool.h"
#include "aWin/Ctrl/aButton.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aButton::aButton
*******************************************************************************/
aButton::aButton(aBaseWin    *_pParent,
                 u32         _u32Id)
: aCtrl(_pParent, _u32Id)
{
} // aButton::aButton


/*******************************************************************************
* aButton::~aButton
*******************************************************************************/
aButton::~aButton()
{
} // aButton::~aButton


/*******************************************************************************
* aButton::onSysCreate
*******************************************************************************/
bool aButton::onSysCreate()
{
    // enable mouse tracking for border resize
    setMouseTracking(true);

    // start the border resize tool
    unique_ptr<aButtonTool> pTool = make_unique<aButtonTool> (this);
    setTool(std::move(pTool));

    return true;
} // aButton::onSysCreate


/*******************************************************************************
* aButton::buttonStyle
*******************************************************************************/
enumButtonStyle aButton::buttonStyle() const
{
    return m_eButtonStyle;
} // aButton::buttonStyle


/*******************************************************************************
* aButton::setButtonStyle
*******************************************************************************/
void aButton::setButtonStyle(enumButtonStyle _eStyle)
{
    m_eButtonStyle = _eStyle;
} // aButton::setButtonStyle


/*******************************************************************************
* aButton::pixmap
*******************************************************************************/
aPixmap* aButton::pixmap() const
{
    return m_pPixmap.get();
} // aButton::pixmap


/*******************************************************************************
* aButton::setPixmap
*******************************************************************************/
void aButton::setPixmap(const char    *_pRscName)
{
    m_pPixmap = make_unique<aPixmap> (_pRscName);
} // aButton::setPixmap


/*******************************************************************************
* aButton::isSelected
*******************************************************************************/
bool aButton::isSelected() const
{
    return m_bSelected;
} // aButton::isSelected


/*******************************************************************************
* aButton::setSelected
*******************************************************************************/
void aButton::setSelected(bool _bSelected)
{
    m_bSelected = _bSelected;
} // aButton::setSelected


/*******************************************************************************
* aButton::isSelectable
*******************************************************************************/
bool aButton::isSelectable() const
{
    return m_bSelectable;
} // aButton::isSelectable


/*******************************************************************************
* aButton::setSelectable
*******************************************************************************/
void aButton::setSelectable(bool _bSelectable)
{
    m_bSelectable = _bSelectable;
} // setSelectable::setS

} // namespace aWin
} // namespace aLib
