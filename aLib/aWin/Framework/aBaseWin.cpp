/*******************************************************************************
* \file aBaseWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* statics
*******************************************************************************/
unique_ptr<aWinStyleFactory> aBaseWin::m_pWinStyleFactory;


/*******************************************************************************
* aBaseWin::aBaseWin
*******************************************************************************/
aBaseWin::aBaseWin(aBaseWin  *_pParent  /* = nullptr */)
: aSysWin(_pParent)
{
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::~aBaseWin
*******************************************************************************/
aBaseWin::~aBaseWin()
{
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::create
*******************************************************************************/
bool aBaseWin::create()
{
    bool bSuccess = onSysCreate() && onCreate();

    if (bSuccess)
    {
        if (m_pWinStyleFactory != nullptr)
        {
            m_pWinStyleFactory->setWinStyle(*this);
        }
    }

    return bSuccess;
} // aBaseWin::create


/*******************************************************************************
* aBaseWin::setWinStyleFactory
*******************************************************************************/
void aBaseWin::setWinStyleFactory(unique_ptr<aWinStyleFactory> _pWinStyleFactory)
{
    m_pWinStyleFactory = std::move(_pWinStyleFactory);
} // aBaseWin::setWinStyleFactory


/*******************************************************************************
* aBaseWin::close
*******************************************************************************/
bool aBaseWin::close()
{
    return true;
} // aBaseWin::close


/*******************************************************************************
* aBaseWin::sysWin
*******************************************************************************/
aSysWin_t* aBaseWin::sysWin()
{
    return _sysWin();
} // aBaseWin::sysWin


/*******************************************************************************
* aBaseWin::repaint
*******************************************************************************/
void aBaseWin::repaint()
{
    _repaint();
} // aBaseWin::repaint


/*******************************************************************************
* aBaseWin::update
*******************************************************************************/
void aBaseWin::update()
{
    _update();
} // aBaseWin::update


/*******************************************************************************
* aBaseWin::show
*******************************************************************************/
void aBaseWin::show()
{
    _show();
} // aBaseWin::show


/*******************************************************************************
* aBaseWin::hide
*******************************************************************************/
void aBaseWin::hide()
{
    _hide();
} // aBaseWin::hide


/*******************************************************************************
* aBaseWin::isVisible
*******************************************************************************/
bool aBaseWin::isVisible()
{
    return _isVisible();
} // aBaseWin::isVisible


/*******************************************************************************
* aBaseWin::setEnabled
*******************************************************************************/
void aBaseWin::setEnabled(bool _bEnabled)
{
    return _setEnabled(_bEnabled);
} // aBaseWin::setEnabled


/*******************************************************************************
* aBaseWin::isEnabled
*******************************************************************************/
bool aBaseWin::isEnabled() const
{
    return _isEnabled();
} // aBaseWin::isEnabled


/*******************************************************************************
* aBaseWin::isDisabled
*******************************************************************************/
bool aBaseWin::isDisabled() const
{
    return !_isEnabled();
} // aBaseWin::isDisabled


/*******************************************************************************
* aBaseWin::showMaximized
*******************************************************************************/
void aBaseWin::showMaximized()
{
    return _showMaximized();
} // aBaseWin::showMaximized


/*******************************************************************************
* aBaseWin::showMinimized
*******************************************************************************/
void aBaseWin::showMinimized()
{
    return _showMinimized();
} // aBaseWin::showMinimized


/*******************************************************************************
* aBaseWin::showNormal
*******************************************************************************/
void aBaseWin::showNormal()
{
    return _showNormal();
} // aBaseWin::showNormal


/*******************************************************************************
* aBaseWin::toggleMaximized
*******************************************************************************/
void aBaseWin::toggleMaximized()
{
    if (isMaximized())
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
} // aBaseWin::toggleMaximized


/*******************************************************************************
* aBaseWin::isMaximized
*******************************************************************************/
bool aBaseWin::isMaximized() const
{
    return _isMaximized();
} // aBaseWin::isMaximized


/*******************************************************************************
* aBaseWin::isMinimized
*******************************************************************************/
bool aBaseWin::isMinimized() const
{
    return _isMinimized();
} // aBaseWin::isMinimized


/*******************************************************************************
* aBaseWin::isHover
*******************************************************************************/
bool aBaseWin::isHover() const
{
    return m_bHover;
} // aBaseWin::isMinimized


/*******************************************************************************
* aBaseWin::modifiers
*******************************************************************************/
u32 aBaseWin::modifiers() const
{
    return _modifiers();
} // aBaseWin::modifiers


/*******************************************************************************
* aBaseWin::mouseButton
*******************************************************************************/
u32 aBaseWin::mouseButton() const
{
    return _mouseButton();
} // aBaseWin::mouseButton


/*******************************************************************************
* aBaseWin::localCursorPos
*******************************************************************************/
aVector2D<s32> aBaseWin::localCursorPos() const
{
    return _localCursorPos();
} // aBaseWin::localCursorPos


/*******************************************************************************
* aBaseWin::globalCursorPos
*******************************************************************************/
aVector2D<s32> aBaseWin::globalCursorPos() const
{
    return _globalCursorPos();
} // aBaseWin::globalCursorPos


/*******************************************************************************
* aBaseWin::minDim
*******************************************************************************/
aDimension2D<s32> aBaseWin::minDim() const
{
    aDimension2D<s32>   d2dMin = aLayoutObj::minDim();

    if (m_pLayout != nullptr)
    {
        d2dMin = d2dMin.max(m_pLayout->minDim());
    }

    return d2dMin;
} // aBaseWin::minDim


/*******************************************************************************
* aBaseWin::setGeometry
*******************************************************************************/
void aBaseWin::setGeometry(const aRect2D<s32>  &_r2d)
{
    setGeometry(_r2d.x(), _r2d.y(), _r2d.w(), _r2d.h());
} // aBaseWin::setGeometry


/*******************************************************************************
* aBaseWin::setGeometry
*******************************************************************************/
void aBaseWin::setGeometry(s32  _x,
                           s32  _y,
                           s32  _w,
                           s32  _h)
{
    _setGeometry(_x, _y, _w, _h);
} // aBaseWin::setGeometry


/*******************************************************************************
* aBaseWin::geometry
*******************************************************************************/
aRect2D<s32> aBaseWin::geometry() const
{
    return _geometry();
} // aBaseWin::geometry


/*******************************************************************************
* aBaseWin::w
*******************************************************************************/
s32 aBaseWin::w() const
{
    return _w();
} // aBaseWin::w


/*******************************************************************************
* aBaseWin::h
*******************************************************************************/
s32 aBaseWin::h() const
{
    return _h();
} // aBaseWin::h



/*******************************************************************************
* aBaseWin::winRect
*******************************************************************************/
aRect2D<s32> aBaseWin::winRect() const
{
    return aRect2D<s32> (0, 0, w(), h());
} // aBaseWin::winRect


/*******************************************************************************
* aBaseWin::borderRect
*******************************************************************************/
aRect2D<s32> aBaseWin::borderRect() const
{
    aRect2D<s32>    r = winRect();

    // maximized wins don't have a margin
    if (!isMaximized())
    {
        r -= margin();
    }

    return r;
} // aBaseWin::borderRect


/*******************************************************************************
* aBaseWin::paddingRect
*******************************************************************************/
aRect2D<s32> aBaseWin::paddingRect() const
{
    aRect2D<s32>    r = borderRect();

    // maximized wins don't show a border
    if (!isMaximized())
    {
        r -= border();
    }

    return r;
} // aBaseWin::paddingRect


/*******************************************************************************
* aBaseWin::contentRect
*******************************************************************************/
aRect2D<s32> aBaseWin::contentRect() const
{
    return paddingRect() - padding();
} // aBaseWin::contentRect


/*******************************************************************************
* aBaseWin::layoutRect
*******************************************************************************/
aRect2D<s32> aBaseWin::layoutRect() const
{
    return contentRect();
} // aBaseWin::layoutRect


/*******************************************************************************
* aBaseWin::setLayout
*******************************************************************************/
void aBaseWin::setLayout(unique_ptr<aLayout> _pLayout)
{
    m_pLayout = std::move(_pLayout);
} // aBaseWin::setLayout


/*******************************************************************************
* aBaseWin::parent
*******************************************************************************/
aBaseWin* aBaseWin::parent() const
{
    return static_cast<aBaseWin *> (_parent());
} // aBaseWin::parent


/*******************************************************************************
* aBaseWin::setParent
*******************************************************************************/
void aBaseWin::setParent(aBaseWin *_pParent)
{
    _setParent(_pParent);
} // aBaseWin::setParent


/*******************************************************************************
* aBaseWin::setCursor
*******************************************************************************/
void aBaseWin::setCursor(const aCursor &_cursor)
{
    _setCursor(_cursor);
} // aBaseWin::setCursor


/*******************************************************************************
* aBaseWin::setMouseTracking
*******************************************************************************/
void aBaseWin::setMouseTracking(bool _bEnable)
{
    _setMouseTracking(_bEnable);
} // aBaseWin::setMouseTracking

} // namespace aWin
} // namespace aLib
