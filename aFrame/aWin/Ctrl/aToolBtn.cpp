/*******************************************************************************
* \file aToolBtn.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolBtn.h"
#include "aPainter.h"
#include "aPixmap.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolBtn::aToolBtn
*******************************************************************************/
aToolBtn::aToolBtn(aBaseWin        *_pParent,
                   const aString   &_sRsc,
                   const aString   &_sLabel)
: aBtn(_pParent, _sRsc, _sLabel)
{
} // aToolBtn::_isVisible


/*******************************************************************************
* aToolBtn::~aToolBtn
*******************************************************************************/
aToolBtn::~aToolBtn()
{
} // aToolBtn::~aToolBtn


/*******************************************************************************
* aToolBtn::onPaintContent
*******************************************************************************/
void aToolBtn::onPaintContent()
{
    shared_ptr<aPixmap>     pix = pixmap();
    aPainter                p(this);

    if (pix)
    {
        p.drawPixmap(*pix, 0, 0);
    }
} // aToolBtn::onPaintContent


} // namespace aWin
} // namespace aFrame
