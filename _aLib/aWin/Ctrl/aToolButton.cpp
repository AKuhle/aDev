/*******************************************************************************
* \file aToolButton.inl
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
#include "aUtil/aColor.h"

#include "aGraphic/aPainter.h"

#include "aWin/Ctrl/aToolButton.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aToolButton::aToolButton
*******************************************************************************/
aToolButton::aToolButton(aBaseWin    *_pParent,
                         u32         _u32Id)
: aButton(_pParent, _u32Id)
{
} // aToolButton::aToolButton


/*******************************************************************************
* aToolButton::~aToolButton
*******************************************************************************/
aToolButton::~aToolButton()
{
} // aToolButton::~aToolButton


/*******************************************************************************
* aToolButton::onPaintMargin
*******************************************************************************/
void aToolButton::onPaintMargin()
{
    // maximized wins don't have a margin
    // if (!IsMaximized())
    // {
    //     qStyleFillBase   *pStyle = GetMarginFillStyle();

    //     if (pStyle != nullptr)
    //     {
    //         qRect2D<s32>    r = GetMarginRect();
    //         qPainter        p(this);

    //         pStyle->Draw(p, r);
    //     }
    // }
} // aToolButton::onPaintMargin


/*******************************************************************************
* aToolButton::onPaintBorder
*******************************************************************************/
void aToolButton::onPaintBorder()
{
    // // maximized wins don't show a border
    // if (!IsMaximized())
    // {
    //     qStyleBorderBase   *pStyle = GetBorderStyle();

    //     if (pStyle != nullptr)
    //     {
    //         qRect2D<s32>    r = GetBorderRect();
    //         qPainter        p(this);

    //         pStyle->Draw(p, r);
    //     }
    // }
} // aToolButton::onPaintBorder


/*******************************************************************************
* aToolButton::onPaintPaddingBg
*******************************************************************************/
void aToolButton::onPaintPaddingBg()
{
    // qStyleFillBase   *pStyle = GetPaddingFillStyle();

    // if (pStyle != nullptr)
    // {
    //     qRect2D<s32>    r = GetPaddingRect();
    //     qPainter        p(this);

    //     pStyle->Draw(p, r, &GetPaddingEdges());
    // }
} // aToolButton::onPaintPaddingBg


/*******************************************************************************
* aToolButton::onPaintContentBg
*******************************************************************************/
void aToolButton::onPaintContentBg()
{
    aRect2D<s32>    rContent   = contentRect();

    switch (buttonStyle())
    {
        case enumButtonStyle::MASKED_MODE:
            return;

        case enumButtonStyle::MASKED_ROUND_MODE:
        {
            if (isHover())
            {
                aPainter    p(this);

                p.drawFilledCircle(rContent.centerPoint(),
                                   aUtil::min<s32>(rContent.w() / 2, rContent.h() / 2),
                                   &hoverColor());
                return;
            }
            break;
        }
    } // switch

} // aToolButton::onPaintContentBg


/*******************************************************************************
* aToolButton::onPaintContent
*******************************************************************************/
void aToolButton::onPaintContent()
{
    aPixmap *pPixmap = pixmap();

    aPainter        p(this);
    aRect2D<s32>    r2dContent = contentRect();

    switch (buttonStyle())
    {
        case enumButtonStyle::MASKED_MODE:
        {
            aPixmap     newPix      = pPixmap->scale(r2dContent.dimension());

            newPix.fill(stateColor());

            p.drawPixmap(newPix, r2dContent.x(), r2dContent.y());
            break;
        }

        case enumButtonStyle::MASKED_ROUND_MODE:
        {
            // paint the pixmap
            if (pPixmap != nullptr)
            {
                 aPixmap newPix  = pPixmap->scale(r2dContent.dimension());

                newPix.fill(stateColor());

                 p.drawPixmap(newPix, r2dContent.x(), r2dContent.y());
            }
            // if (IsDisabled())
            //     newPix.Fill(GetDisabledColor());
            // else if (IsSelected())
            //     newPix.Fill(GetSelectedColor());
            // else
            //     newPix.Fill(GetNormalColor());

            break;
        }
    } // switch

} // aToolButton::onPaintContent


} // namespace aWin
} // namespace aLib
