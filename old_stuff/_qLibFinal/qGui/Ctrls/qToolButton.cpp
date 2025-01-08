/*******************************************************************************
* \file qToolButton.inl
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
#include "qToolButton.h"
#include "qPainter.h"
#include "qPixmap.h"
#include "qBrush.h"


namespace qLib
{
    /*******************************************************************************
    * qToolButton::qToolButton
    *******************************************************************************/
    qToolButton::qToolButton(qWin  *_pParent,
                             u32   _u32Id)
    : qButtonBase(_pParent, _u32Id)
	{
    } // qToolButton::qToolButton


    /*******************************************************************************
    * qToolButton::~qToolButton
    *******************************************************************************/
    qToolButton::~qToolButton()
	{
    } // qToolButton::~qToolButton


    /*******************************************************************************
    * qToolButton::OnPaintMarginBg
    *******************************************************************************/
    // void qToolButton::OnPaintMarginBg()
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
    // } // qToolButton::OnPaintMarginBg


    /*******************************************************************************
    * qToolButton::OnPaintBorder
    *******************************************************************************/
    // void qToolButton::OnPaintBorder()
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
    // } // qToolButton::OnPaintBorder


    /*******************************************************************************
    * qToolButton::OnPaintPaddingBg
    *******************************************************************************/
    // void qToolButton::OnPaintPaddingBg()
    // {
    //     qStyleFillBase   *pStyle = GetPaddingFillStyle();

    //     if (pStyle != nullptr)
    //     {
    //         qRect2D<s32>    r = GetPaddingRect();
    //         qPainter        p(this);

    //         pStyle->Draw(p, r, &GetPaddingEdges());
    //     }
    // } // qToolButton::OnPaintPaddingBg


    /*******************************************************************************
    * qToolButton::OnPaintContentBg
    *******************************************************************************/
    void qToolButton::OnPaintContentBg()
    {
        qRect2D<s32>    rContent   = GetContentRect();

        switch (GetButtonStyle())
        {
            default:
                qButtonBase::OnPaintContentBg();
                break;

            case enumButtonStyle::MASKED_MODE:
                return;

            case enumButtonStyle::MASKED_ROUND_MODE:
            {
                if (IsHover())
                {
                    qPainter    p(this);

                    p.DrawFilledCircle(rContent.CenterPoint(),
                                       MU<s32>::Min(rContent.w / 2, rContent.h/2),
                                       &GetHoverColor());
                    return;
                }
                break;
            }
        } // switch

    } // qToolButton::OnPaintContentBg


    /*******************************************************************************
    * qToolButton::OnPaintContent
    *******************************************************************************/
    void qToolButton::OnPaintContent()
    {
        qPixmap *pPix = GetPixmap();
        CHECK_PRE_CONDITION_VOID(pPix != nullptr);

        qPainter        p(this);
        qRect2D<s32>    r2dContent = GetContentRect();

        // resize the pixmap
        qPixmap             newPix  = pPix->Scale(r2dContent.Dimension());

        switch (GetButtonStyle())
        {
            case enumButtonStyle::MASKED_MODE:
                if (IsDisabled())
                    newPix.Fill(GetDisabledColor());
                else if (IsSelected())
                    newPix.Fill(GetSelectedColor());
                else if (IsHover())
                    newPix.Fill(GetHoverColor());
                else
                    newPix.Fill(GetNormalColor());
                break;

            case enumButtonStyle::MASKED_ROUND_MODE:
                if (IsDisabled())
                    newPix.Fill(GetDisabledColor());
                else if (IsSelected())
                    newPix.Fill(GetSelectedColor());
                else
                    newPix.Fill(GetNormalColor());
                break;
        } // switch

        // draw the pixmap
        p.DrawPixmap(newPix, r2dContent.x, r2dContent.y);

    } // qToolButton::OnPaintContent

} // namespace qLib
