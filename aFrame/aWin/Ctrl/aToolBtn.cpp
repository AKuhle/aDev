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
* aBtaToolBtnn::onSysCreateWin
*******************************************************************************/
bool aToolBtn::onSysCreateWin()
{
    CHECK_PRE_CONDITION(aBtn::onSysCreateWin(), false);

    // set the fixed size
    setFixDim(sysMetrics());

    return true;
} // aToolBtn::onSysCreateWin


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

        case enumBtnStyle::ICON_MODE:
            break;

        case enumBtnStyle::ICON_STATIC_MODE:
            break;
    }
} // aToolBtn::onPaintContentBg


/*******************************************************************************
* aToolBtn::onPaintContent
*******************************************************************************/
void aToolBtn::onPaintContent()
{
    aPainter                p(this);
    shared_ptr<aPixmap>     pPix = pixmap();

    switch (btnStyle())
    {
        case enumBtnStyle::MASKED_MODE:
        {
            aColor col = stateColor();

            // draw the pixmap if it exist
            if (pPix)
            {
                pPix->setMaskedColor(col);

                p.drawPixmap(*pPix, 0, 0);
            }
            break;
        }

        case enumBtnStyle::MASKED_ROUND_MODE:
            break;

        case enumBtnStyle::ICON_MODE:
        case enumBtnStyle::ICON_STATIC_MODE:
            // draw the pixmap if it exist
            if (pPix)
            {
                p.drawPixmap(*pPix, 0, 0);
            }
            break;
    }
} // aToolBtn::onPaintContent


} // namespace aWin
} // namespace aFrame
