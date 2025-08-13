/*******************************************************************************
* \file aBaseWin_i.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aString.h"
#include "aRect.h"
#include "aStyleItemBorder.h"

#include "aBaseWin_i.h"
#include "aLayout_i.h"

using namespace aFrame::aUtil;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin_i::aBaseWin_i
*******************************************************************************/
aBaseWin_i::aBaseWin_i(SysWin *_pWinInstance)
: m_pWinInstance(_pWinInstance)
{
} // aBaseWin_i::aBaseWin_i


/*******************************************************************************
* aBaseWin_i::~aBaseWin_i
*******************************************************************************/
aBaseWin_i::~aBaseWin_i()
{
} // aBaseWin_i::~aBaseWin_i


/*******************************************************************************
* aBaseWin_i::createWin
*******************************************************************************/
bool aBaseWin_i::createWin()
{
    if (onSysCreateWin() && onCreateWin())
    {
        setStyle();

//         // aCtrlMgr initialization
//         aCtrlMgr *pCtrlMgr = dynamic_cast<aCtrlMgr *> (this);
//         if (pCtrlMgr != nullptr)
//         {
//             pCtrlMgr->onRegisterCtrl();
//         }

        return true;
    }

    return false;
} // aBaseWin_i::createWin


/*******************************************************************************
* aBaseWin_i::className
*******************************************************************************/
aString aBaseWin_i::className() const
{
    //aString sName = std::type_index(typeid(*pt)).name();
    //std::cout << "class name: " << sName << std::endl;

    const char  *sMangled_name = typeid(*this).name();

    #ifdef __GNUG__
        // GCC/Clang: Namen entmangeln
        int status = 0;
        std::unique_ptr<char, void(*)(void*)> demangled {
            abi::__cxa_demangle(sMangled_name, nullptr, nullptr, &status),
            std::free
        };

        if (status == 0)
        {
            return demangled.get();
        }
    #endif

    // Fallback: Original Name (bei MSVC bereits lesbar)
    return sMangled_name;

} // aBaseWin_i::className


/*******************************************************************************
* aBaseWin_i::show
*******************************************************************************/
void aBaseWin_i::show()
{
    setVisible(true);
} // aBaseWin_i::show


/*******************************************************************************
* aBaseWin_i::hide
*******************************************************************************/
void aBaseWin_i::hide()
{
    setVisible(false);
} // aBaseWin_i::hide


/*******************************************************************************
* aBaseWin_i::toggleMaximized
*******************************************************************************/
void aBaseWin_i::toggleMaximized()
{
    if (isMaximized())
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
} // aBaseWin_i::toggleMaximized


/*******************************************************************************
* aBaseWin_i::toggleFullScreen
*******************************************************************************/
void aBaseWin_i::toggleFullScreen()
{
    if (isFullScreen())
    {
        showNormal();
    }
    else
    {
        showFullScreen();
    }
} // aBaseWin_i::toggleFullScreen


/*******************************************************************************
* aBaseWin_i::setLayout
*******************************************************************************/
void aBaseWin_i::setLayout(unique_ptr<aLayout_i> _pLayout)
{
    m_pLayout = std::move(_pLayout);
} // aBaseWin_i::setLayout


/*******************************************************************************
* aBaseWin_i::setMinDim
*******************************************************************************/
void aBaseWin_i::setMinDim(const aDimension &_minDim)
{
    setMinW(_minDim.w());
    setMinH(_minDim.h());
} // aBaseWin_i::setMinDim


/*******************************************************************************
* aBaseWin_i::setMinDim
*******************************************************************************/
void aBaseWin_i::setMinDim(s32 _s32MinW,
                           s32 _s32MinH)
{
    setMinW(_s32MinW);
    setMinH(_s32MinH);
} // aBaseWin_i::setMinDim


/*******************************************************************************
* aBaseWin_i::setMaxDim
*******************************************************************************/
void aBaseWin_i::setMaxDim(const aDimension &_maxDim)
{
    setMaxW(_maxDim.w());
    setMaxH(_maxDim.h());
} // aBaseWin_i::setMaxDim


/*******************************************************************************
* aBaseWin_i::setMaxDim
*******************************************************************************/
void aBaseWin_i::setMaxDim(s32 _s32MaxW,
                           s32 _s32MaxH)
{
    setMinW(_s32MaxW);
    setMinH(_s32MaxH);
} // aBaseWin_i::setMaxDim


/*******************************************************************************
* aBaseWin_i::setGeometry
*******************************************************************************/
void aBaseWin_i::setGeometry(const aRect &_r)
{
    setGeometry(_r.x(), _r.y(), _r.w(), _r.h());
} // aBaseWin_i::setGeometry


/*******************************************************************************
* aBaseWin_i::marginRect
*******************************************************************************/
aRect aBaseWin_i::marginRect() const
{
    return aRect(0, 0, geometryW(), geometryH());
} // aBaseWin_i::marginRect


/*******************************************************************************
* aBaseWin_i::borderRect
*******************************************************************************/
aRect aBaseWin_i::borderRect() const
{
    aRect    r = marginRect();

    // full screen => no margin => border rect = margin rect
    if (!isFullScreen())
    {
        r.x() += m_margin.l();
        r.y() += m_margin.t();
        r.w() -= m_margin.w();
        r.h() -= m_margin.h();
    }

    return r;
} // aBaseWin_i::borderRect


/*******************************************************************************
* aBaseWin_i::paddingRect
*******************************************************************************/
aRect aBaseWin_i::paddingRect() const
{
    aRect    r = borderRect();

    // full screen => no border => padding rect = border rect
    if (!isFullScreen())
    {
        // no border => padding rect == border rect
        if (borderStyle())
        {
            const aMargin &m = borderStyle()->margin();

            r.x() += m.l();
            r.y() += m.t();
            r.w() -= m.w();
            r.h() -= m.h();
        }
    }

    return r;
} // aBaseWin_i::paddingRect


/*******************************************************************************
* aBaseWin_i::contentRect
*******************************************************************************/
aRect aBaseWin_i::contentRect() const
{
    aRect    r = paddingRect();

    r.x() += m_padding.l();
    r.y() += m_padding.t();
    r.w() -= m_padding.w();
    r.h() -= m_padding.h();

    return r;
} // aBaseWin_i::contentRect


} // namespace aWin
} // namespace aFrame



















// /*******************************************************************************
// * aBaseWin::onCloseWin
// *******************************************************************************/
// template<class T>
// bool aBaseWin::onCloseWin()
// {
//     return true;
// } // aBaseWin::onCloseWin


// /*******************************************************************************
// * aBaseWin::onDropUrl
// *******************************************************************************/
// template<class T>
// void aBaseWin::onDropUrl(const aUrl  &/*_url*/)
// {
// } // aBaseWin::onDropUrl


// /*******************************************************************************
// * aBaseWin::onPaint
// *******************************************************************************/
// template<class T>
// bool aBaseWin::onPaint()
// {
//     return false;
// } // aBaseWin::onPaint


// /*******************************************************************************
// * aBaseWin::onWheel
// *******************************************************************************/
// template<class T>
// bool aBaseWin::onWheel(u32                  /*_u32Modifiers*/,
//                           s32                  /*_s32Degree*/,
//                           const aPoint &/*_v2dLocal*/,
//                           const aPoint &/*_v2dGlobal*/)
// {
//     return false;
// } // aBaseWin::onWheel
