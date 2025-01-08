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
#include "aUtil/aColor.h"

#include "aGraphic/aPainter.h"

#include "aWin/Framework/aBaseWin.h"

using namespace aLib::aUtil;
using namespace aLib::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aBaseWin::onSysCreate
*******************************************************************************/
bool aBaseWin::onSysCreate()
{
    return true;
} // aBaseWin::onSysCreate


/*******************************************************************************
* aBaseWin::onCreate
*******************************************************************************/
bool aBaseWin::onCreate()
{
    return true;
} // aBaseWin::onCreate


/*******************************************************************************
* aBaseWin::onSysResize
*******************************************************************************/
void aBaseWin::onSysResize(const aDimension2D<s32> &/*_d2dOld*/,
                           const aDimension2D<s32> &/*_d2dNew*/)
{
    if (m_pLayout != nullptr)
    {
        //m_pLayout->arrangeChilds(layoutRect());
    }
} // aBaseWin::onSysResize


/*******************************************************************************
* aBaseWin::onResize
*******************************************************************************/
void aBaseWin::onResize(const aDimension2D<s32> &/*_d2dOld*/,
                        const aDimension2D<s32> &/*_d2dNew*/)
{
} // aBaseWin::onResize


/*******************************************************************************
* aBaseWin::onResizeEvent
*******************************************************************************/
void aBaseWin::onResizeEvent(const aDimension2D<s32> &_d2dOld,
                             const aDimension2D<s32> &_d2dNew)
{
    onSysResize(_d2dOld, _d2dNew);
    onResize(_d2dOld, _d2dNew);
} // aBaseWin::onResizeEvent


/*******************************************************************************
* aBaseWin::onPaintContentBg
*******************************************************************************/
void aBaseWin::onPaintContentBg()
{
    aPainter    p(this);

    p.drawFilledRect(50, 50, 50, 50, &colDarkCyan);
} // aBaseWin::onPaintContentBg

/*******************************************************************************
* aBaseWin::onPaintEvent
*******************************************************************************/
void aBaseWin::onPaintEvent()
{
    // onPaintMargin();

    // onPaintBorder();

    // onPaintPaddingBg();
    // onPaintPadding();

    onPaintContentBg();
    // onPaintContent();

} // aBaseWin::onPaintEvent


} // namespace aWin
} // namespace aLib
