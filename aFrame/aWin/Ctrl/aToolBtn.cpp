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
* aToolBtn::onPaintContentBg
*******************************************************************************/
void aToolBtn::onPaintContentBg()
{
    switch (btnStyle())
    {
        case enumBtnStyle::MASKED_MODE:
            break;

        case enumBtnStyle::MASKED_ROUND_MODE:
            break;
    }
} // aToolBtn::onPaintContentBg


/*******************************************************************************
* aToolBtn::onPaintContent
*******************************************************************************/
void aToolBtn::onPaintContent()
{
    aPainter                p(this);
    shared_ptr<aPixmap>     pPix        = pixmap();
    aColor                  col         = stateColor();

    switch (btnStyle())
    {
        case enumBtnStyle::MASKED_MODE:
            if (pPix)
            {
                pPix->setMaskedColor(col);

                p.drawPixmap(*pPix, 0, 0);
            }
            break;

        case enumBtnStyle::MASKED_ROUND_MODE:
            break;
    }
} // aToolBtn::onPaintContent


} // namespace aWin
} // namespace aFrame
