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
#include "aBaseWin_i.h"
#include "aRect2D.h"
#include "aPainter.h"
#include "aColor.h"

using namespace aFrame::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


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
* aBaseWin_i::onPaintContent
*******************************************************************************/
void aBaseWin_i::onPaintContent()
{
    aRect2D<s32>    r = contentRect();
    aPainter        p(sysWinPtr());

    p.drawFilledRect(r, &colAqua);
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
