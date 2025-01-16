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
* aToolButton::OnPaintMarginBg
*******************************************************************************/
// void aToolButton::OnPaintMarginBg()
// {
//     // maximized wins don't have a margin
//     if (!IsMaximized())
//     {
//         qStyleFillBase   *pStyle = GetMarginFillStyle();

//         if (pStyle != nullptr)
//         {
//             qRect2D<s32>    r = GetMarginRect();
//             qPainter        p(this);

//             pStyle->Draw(p, r);
//         }
//     }
// } // aToolButton::OnPaintMarginBg


/*******************************************************************************
* aToolButton::OnPaintBorder
*******************************************************************************/
// void aToolButton::OnPaintBorder()
// {
//     // maximized wins don't show a border
//     if (!IsMaximized())
//     {
//         qStyleBorderBase   *pStyle = GetBorderStyle();

//         if (pStyle != nullptr)
//         {
//             qRect2D<s32>    r = GetBorderRect();
//             qPainter        p(this);

//             pStyle->Draw(p, r);
//         }
//     }
// } // aToolButton::OnPaintBorder


/*******************************************************************************
* aToolButton::OnPaintPaddingBg
*******************************************************************************/
// void aToolButton::OnPaintPaddingBg()
// {
//     qStyleFillBase   *pStyle = GetPaddingFillStyle();

//     if (pStyle != nullptr)
//     {
//         qRect2D<s32>    r = GetPaddingRect();
//         qPainter        p(this);

//         pStyle->Draw(p, r, &GetPaddingEdges());
//     }
// } // aToolButton::OnPaintPaddingBg


/*******************************************************************************
* aToolButton::OnPaintContentBg
*******************************************************************************/
// void aToolButton::OnPaintContentBg()
// {
//     qRect2D<s32>    rContent   = GetContentRect();

//     switch (GetButtonStyle())
//     {
//         default:
//             qButtonBase::OnPaintContentBg();
//             break;

//         case enumButtonStyle::MASKED_MODE:
//             return;

//         case enumButtonStyle::MASKED_ROUND_MODE:
//         {
//             if (IsHover())
//             {
//                 qPainter    p(this);

//                 p.DrawFilledCircle(rContent.CenterPoint(),
//                                    MU<s32>::Min(rContent.w / 2, rContent.h/2),
//                                    &GetHoverColor());
//                 return;
//             }
//             break;
//         }
//     } // switch

// } // aToolButton::OnPaintContentBg


/*******************************************************************************
* aToolButton::OnPaintContent
*******************************************************************************/
// void aToolButton::OnPaintContent()
// {
//     qPixmap *pPix = GetPixmap();
//     CHECK_PRE_CONDITION_VOID(pPix != nullptr);

//     qPainter        p(this);
//     qRect2D<s32>    r2dContent = GetContentRect();

//     // resize the pixmap
//     qPixmap             newPix  = pPix->Scale(r2dContent.Dimension());

//     switch (GetButtonStyle())
//     {
//         case enumButtonStyle::MASKED_MODE:
//             if (IsDisabled())
//                 newPix.Fill(GetDisabledColor());
//             else if (IsSelected())
//                 newPix.Fill(GetSelectedColor());
//             else if (IsHover())
//                 newPix.Fill(GetHoverColor());
//             else
//                 newPix.Fill(GetNormalColor());
//             break;

//         case enumButtonStyle::MASKED_ROUND_MODE:
//             if (IsDisabled())
//                 newPix.Fill(GetDisabledColor());
//             else if (IsSelected())
//                 newPix.Fill(GetSelectedColor());
//             else
//                 newPix.Fill(GetNormalColor());
//             break;
//     } // switch

//     // draw the pixmap
//     p.DrawPixmap(newPix, r2dContent.x, r2dContent.y);

// } // aToolButton::OnPaintContent


} // namespace aWin
} // namespace aLib
