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

#include "aBaseWin_i.h"
#include "aRect2D.h"
#include "aPainter.h"
#include "aColor.h"
#include "aString.h"

#include "aStyleItemFillSolid.h"

using namespace aFrame::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* namespace
*******************************************************************************/
unique_ptr<aStyleParser>       aBaseWin_i::m_pStyleParser;


/*******************************************************************************
* aBaseWin_i::aBaseWin_i
*******************************************************************************/
aBaseWin_i::aBaseWin_i()
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
        setWinStyle();

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
* aBaseWin_i::setStyleFile
*******************************************************************************/
void aBaseWin_i::setStyleFile(const aPath    &_path)
{
    m_pStyleParser = make_unique<aStyleParser> (_path);

    if (!m_pStyleParser->isValid())
    {
        m_pStyleParser = nullptr;
    }
} // aBaseWin_i::setStyleFile


/*******************************************************************************
* aBaseWin_i::setBgStyle
*******************************************************************************/
void aBaseWin_i::setBgStyle(shared_ptr<aStyleItemFill>  _pBgStyle)
{
    m_pBgStyle = _pBgStyle;
} // aBaseWin_i::setBgStyle


/*******************************************************************************
* aBaseWin_i::bgStyle
*******************************************************************************/
shared_ptr<aStyleItemFill> aBaseWin_i::bgStyle() const
{
    return m_pBgStyle;
} // aBaseWin_i::bgStyle


/*******************************************************************************
* aBaseWin_i::setWinStyle
*******************************************************************************/
void aBaseWin_i::setWinStyle()
{
    if (m_pStyleParser)
    {
        m_pStyleParser->setStyle(this);
    }

} // aBaseWin_i::setWinStyle


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
* aBaseWin_i::setMinDim
*******************************************************************************/
void aBaseWin_i::setMinDim(const aDimension2D<s32> &_minDim)
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
void aBaseWin_i::setMaxDim(const aDimension2D<s32> &_maxDim)
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
* aBaseWin_i::marginRect
*******************************************************************************/
aRect2D<s32> aBaseWin_i::marginRect() const
{
    return aRect2D<s32>(0, 0, geometryW(), geometryH());
} // aBaseWin_i::marginRect


/*******************************************************************************
* aBaseWin_i::borderRect
*******************************************************************************/
aRect2D<s32> aBaseWin_i::borderRect() const
{
    aRect2D<s32>    r = marginRect();

    r.x() += m_margin.l();
    r.y() += m_margin.t();
    r.w() -= m_margin.w();
    r.h() -= m_margin.h();

    return r;
} // aBaseWin_i::borderRect


/*******************************************************************************
* aBaseWin_i::paddingRect
*******************************************************************************/
aRect2D<s32> aBaseWin_i::paddingRect() const
{
    aRect2D<s32>    r = borderRect();

    r.x() += m_border.l();
    r.y() += m_border.t();
    r.w() -= m_border.w();
    r.h() -= m_border.h();

    return r;
} // aBaseWin_i::paddingRect


/*******************************************************************************
* aBaseWin_i::contentRect
*******************************************************************************/
aRect2D<s32> aBaseWin_i::contentRect() const
{
    aRect2D<s32>    r = paddingRect();

    r.x() += m_padding.l();
    r.y() += m_padding.t();
    r.w() -= m_padding.w();
    r.h() -= m_padding.h();

    return r;
} // aBaseWin_i::contentRect


/*******************************************************************************
* aBaseWin_i::onSysCreateWin
*******************************************************************************/
bool aBaseWin_i::onSysCreateWin()
{
    return true;
} // aBaseWin_i::onSysCreateWin


/*******************************************************************************
* aBaseWin_i::onCreateWin
*******************************************************************************/
bool aBaseWin_i::onCreateWin()
{
    return true;
} // aBaseWin_i::onCreateWin


/*******************************************************************************
* aBaseWin_i::onPaint
*******************************************************************************/
void aBaseWin_i::onPaint()
{
    onPaintMargin();
    onPaintBorder();
    onPaintPadding();
    onPaintContentBg();
    onPaintContent();
} // aBaseWin_i::onPaint


/*******************************************************************************
* aBaseWin_i::onPaintMargin
*******************************************************************************/
void aBaseWin_i::onPaintMargin()
{
} // aBaseWin_i::onPaintMargin


/*******************************************************************************
* aBaseWin_i::onPaintBorder
*******************************************************************************/
void aBaseWin_i::onPaintBorder()
{
} // aBaseWin_i::onPaintBorder


/*******************************************************************************
* aBaseWin_i::onPaintPadding
*******************************************************************************/
void aBaseWin_i::onPaintPadding()
{
} // aBaseWin_i::onPaintPadding


/*******************************************************************************
* aBaseWin_i::onPaintContentBg
*******************************************************************************/
void aBaseWin_i::onPaintContentBg()
{
    aStyleItemFillSolid *pfi = dynamic_cast<aStyleItemFillSolid *> (m_pBgStyle.get());

    if (pfi)
    {
        aRect2D<s32>    r = contentRect();
        aPainter        p(sysWinPtr());
        aColor          col = pfi->fillColor();

        p.drawFilledRect(r, &col);
    }
} // aBaseWin_i::onPaintContentBg


/*******************************************************************************
* aBaseWin_i::onPaintContent
*******************************************************************************/
void aBaseWin_i::onPaintContent()
{
} // aBaseWin_i::onPaintContent


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
//                           const aVector2D<s32> &/*_v2dLocal*/,
//                           const aVector2D<s32> &/*_v2dGlobal*/)
// {
//     return false;
// } // aBaseWin::onWheel
