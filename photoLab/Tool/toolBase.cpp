/*******************************************************************************
* \file ToolBase.inl
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
#include "aHelper.h"

#include "toolBase.h"
#include "mainWin.h"
#include "viewBase.h"

using namespace aLib;
using namespace aLib::aUtil;


/*******************************************************************************
* ToolBase::ToolBase
*******************************************************************************/
ToolBase::ToolBase(ViewBase *_pOwnerView,
                   u32      _u32ToolId,
                   u64      _u64ToolBaseFunction)
: aToolBase(_pOwnerView, _u32ToolId, _u64ToolBaseFunction)
{
} // ToolBase::ToolBase


/*******************************************************************************
* ToolBase::~ToolBase
*******************************************************************************/
ToolBase::~ToolBase()
{
} // ToolBase::~ToolBase


/*******************************************************************************
* ToolBase::ownerView
*******************************************************************************/
ViewBase* ToolBase::ownerView() const
{
    return dynamic_cast<ViewBase *> (ownerWin());
} // ToolBase::ownerView


/*******************************************************************************
* ToolBase::ownerScrollWin
*******************************************************************************/
// EditScrollWin* ToolBase::ownerScrollWin() const
// {
//     ViewBase    *pView = ownerView();
//     CHECK_PRE_CONDITION(pView != nullptr, nullptr);

//     return dynamic_cast<EditScrollWin *> (pView->parent());
// } // ToolBase::ownerScrollWin


/*******************************************************************************
* ToolBase::ownerMdiWin
*******************************************************************************/
// aMdiWin* ToolBase::ownerMdiWin() const
// {
//     EditScrollWin    *pScrollWin = ownerScrollWin();
//     CHECK_PRE_CONDITION(pScrollWin != nullptr, nullptr);

//     return dynamic_cast<aMdiWin *> (pScrollWin->parent());
// } // ToolBase::ownerMdiWin


/*******************************************************************************
* ToolBase::canHandleEvent
*******************************************************************************/
bool ToolBase::canHandleEvent() const
{
    // owner must exist
    ViewBase    *pView = ownerView();
    CHECK_PRE_CONDITION(pView != nullptr, false);

    // the according mdi window has the focus => true
    //aMdiWin *pMdiWin = ownerMdiWin();
    if (true)//pMdiWin != nullptr && pMdiWin->hasFocus())
    {
        return true;
    }

    return false;
} // ToolBase::canHandleEvent


/*******************************************************************************
* ToolBase::onWheel
*******************************************************************************/
enumToolResult ToolBase::onWheel(u32                    /*_u32Modifiers*/,
                                 s32                    _s32Degree,
                                 const aPoint2D<s32>   &/*_v2dLocal*/,
                                 const aPoint2D<s32>   &/*_v2dGlobal*/)
{
    // check whether the owner view exist and the view has the focus
    CHECK_PRE_CONDITION(canHandleEvent(), enumToolResult::Unhandled);

    // view must exist and has the focus
    ViewBase    *pView  = ownerView();
    MainWin     &mw     = getMainWin();

    if (isBitsSet<u64> (toolBaseFunction(), TBF_WHEEL_ZOOM))
    {
        // transform the click position to zoom of the owner view
        //aPoint2D<s32> v2dZoom_pic = pView->Client2Pic(_v2dLocal);

        if (_s32Degree > 0)
        {
            pView->increaseZoomFactor();
        }
        else
        {
            pView->decreaseZoomFactor();
        }

        //pView->MapPic2Client(v2dZoom_pic, _v2dLocal);

        mw.sendUpdateCmd(UPDATE_VIEW, pView);

    }

    return enumToolResult::Handled;
} // ToolBase::onWheel










// /*******************************************************************************
// * ToolBase::SetZoomFactorFit
// *******************************************************************************/
// void ToolBase::SetZoomFactorFit() const
// {
//     ViewBase                *pView  = ToolBase::OwnerView();
//     shared_ptr<qLayerStack> pLS     = OwnerLS();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr && pLS != nullptr);

//     MainWin                 &mw     = GetMainWin();

//     pView->SetZoomFactorFit();
//     pView->SetCenterPoint_pic(pLS->w()/2, pLS->h()/2);
//     mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
// } // ToolBase::SetZoomFactorFit


// /*******************************************************************************
// * ToolBase::SetZoomFactor1
// *******************************************************************************/
// void ToolBase::SetZoomFactor1() const
// {
//     ViewBase *pView = ToolBase::OwnerView();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr);

//     MainWin &mw = GetMainWin();

//     if (IsUnequal<dbl> (pView->ZoomFactor(), 1))
//     {
//         qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
//         pView->SetZoomFactor(1);
//         pView->SetCenterPoint_pic(v2dCenter_pic);
//         mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//     }
//       } // ToolBase::SetZoomFactor1


// /*******************************************************************************
// * ToolBase::SetZoomFactor2
// *******************************************************************************/
// void ToolBase::SetZoomFactor2() const
// {
//     ViewBase    *pView = ToolBase::OwnerView();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr);

//     MainWin &mw = GetMainWin();

//     if (IsUnequal<dbl> (pView->ZoomFactor(), 2))
//     {
//         qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
//         pView->SetZoomFactor(2);
//         pView->SetCenterPoint_pic(v2dCenter_pic);
//         mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//     }
// } // ToolBase::SetZoomFactor2


// /*******************************************************************************
// * ToolBase::DrawSections
// *******************************************************************************/
// void ToolBase::DrawSections() const
// {
//     VarPoolPl   &vp         = GetVarPool();

//     switch (vp.GetEnum<enumSection> (ID_ENUM_SECTION))
//     {
//         case enumSection::NoCut:
//             break;

//         case enumSection::HalfCut:
//             DrawSectionsHalfCut();
//             break;

//         case enumSection::ThirdCut:
//             DrawSectionsThirdCut();
//             break;

//         case enumSection::GoldenCut:
//             DrawSectionsGoldenCut();
//             break;

//         case enumSection::GoldenCoil:
//             DrawSectionsGoldenCoil();
//             break;
//     }
// } // ToolBase::DrawSections


// /*******************************************************************************
// * ToolBase::DrawSectionsHalfCut
// *******************************************************************************/
// void ToolBase::DrawSectionsHalfCut() const
// {
//     ViewBase                *pView  = OwnerView();
//     shared_ptr<qLayerStack> pLS     = GetActiveLS();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr && pLS != nullptr);

//     s32             s32PicW     = pLS->w();
//     s32             s32PicH     = pLS->h();
//     qPainter        p(pView);
//     qPen            pen(rgbaGold);

//     // horizontal line
//     p.DrawLine(pView->Pic2Client(0, s32PicH / 2),
//                pView->Pic2Client(s32PicW, s32PicH / 2), &pen);

//     // vertical line
//     p.DrawLine(pView->Pic2Client(s32PicW / 2, 0),
//                pView->Pic2Client(s32PicW / 2, s32PicH));

// } // ToolBase::DrawSectionsHalfCut


// /*******************************************************************************
// * ToolBase::DrawSectionsThirdCut
// *******************************************************************************/
// void ToolBase::DrawSectionsThirdCut() const
// {
//     ViewBase                *pView  = OwnerView();
//     shared_ptr<qLayerStack> pLS     = GetActiveLS();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr && pLS != nullptr);

//     s32                     s32PicW     = pLS->w();
//     s32                     s32PicH     = pLS->h();
//     qPainter                p(pView);
//     qPen                    pen(rgbaGold);

//     // horizontal lines
//     p.DrawLine(pView->Pic2Client(0, s32PicH / 3),
//                pView->Pic2Client(s32PicW, s32PicH / 3), &pen);

//     p.DrawLine(pView->Pic2Client(0, s32PicH * 2 / 3),
//                pView->Pic2Client(s32PicW, s32PicH * 2 / 3), &pen);

//     // vertical lines
//     p.DrawLine(pView->Pic2Client(s32PicW / 3, 0),
//                pView->Pic2Client(s32PicW / 3, s32PicH));

//     p.DrawLine(pView->Pic2Client(s32PicW * 2 / 3, 0),
//                pView->Pic2Client(s32PicW * 2 / 3, s32PicH));

// } // ToolBase::DrawSectionsThirdCut


// /*******************************************************************************
// * ToolBase::DrawSectionsGoldenCut
// *******************************************************************************/
// void ToolBase::DrawSectionsGoldenCut() const
// {
// } // ToolBase::DrawSectionsGoldenCut


// /*******************************************************************************
// * ToolBase::DrawSectionsGoldenCoil
// *******************************************************************************/
// void ToolBase::DrawSectionsGoldenCoil() const
// {
// } // ToolBase::DrawSectionsGoldenCoil


// /*******************************************************************************
// * ToolBase::OnSetCursor
// *******************************************************************************/
// void ToolBase::OnSetCursor()
// {
//     ViewBase    *pView  = OwnerView();
//     CHECK_PRE_CONDITION_VOID(pView != nullptr);

//     MainWin     &mw     = GetMainWin();

//     switch (mw.Mode())
//     {
//         default:
//             break;

//         case enumMode::Move:
//         {
//             qCursor cur(enumCursorShape::OpenHand);
//             pView->SetCursor(cur);
//             break;
//         } // case enumMode::Move

//         case enumMode::Zoom:
//         {
//             qCursor cur(enumCursorShape::PointingHand);
//             pView->SetCursor(cur);
//             break;
//         } // case enumMode::Zoom
//     } // switch (mw.Mode())
// } // ToolBase::OnSetCursor


// /*******************************************************************************
// * ToolBase::OnPaintToolMarker
// *******************************************************************************/
// void ToolBase::OnPaintToolMarker()
// {
//     qTool::OnPaintToolMarker();

//     if (BitsSet(ToolBaseFunction(), TBF_SECTIONS))
//     {
//         DrawSections();
//     }
// } // ToolBase::OnPaintToolMarker


// /*******************************************************************************
// * ToolBase::OnLMousePress
// *******************************************************************************/
// enumToolResult ToolBase::OnLMousePress(u32                  _u32Modifiers,
//                                        const qVector2D<s32> &_v2dLocal,
//                                        const qVector2D<s32> &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnLMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//         ViewBase *pView  = OwnerView();
//         CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//         if (BitsSet(ToolBaseFunction(), TBF_LEFT_MOVE))
//         {
//             // transform the click position to zoom of the owner view
//             m_v2dMoveStart_pic = pView->Client2Pic(_v2dLocal);

//             eReturn = enumToolResult::Handled;
//         }
//     }

//     return eReturn;
// } // ToolBase::OnLMousePress


// /*******************************************************************************
// * ToolBase::OnLMouseMove
// *******************************************************************************/
// enumToolResult ToolBase::OnLMouseMove(u32                   _u32Modifiers,
//                                       const qVector2D<s32>  &_v2dLocal,
//                                       const qVector2D<s32>  &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnLMouseMove(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//         ViewBase *pView  = OwnerView();
//         CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//         MainWin         &mw     = GetMainWin();

//         if (BitsSet(ToolBaseFunction(), TBF_LEFT_MOVE))
//         {
//             pView->MapPic2Client(m_v2dMoveStart_pic, _v2dLocal);

//             mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);

//             eReturn = enumToolResult::Handled;
//         }
//     }

//     return eReturn;
// } // ToolBase::OnLMouseMove


// /*******************************************************************************
// * ToolBase::OnLMouseRelease
// *******************************************************************************/
// enumToolResult ToolBase::OnLMouseRelease(u32                _u32Modifiers,
//                                       const qVector2D<s32> &_v2dLocal,
//                                       const qVector2D<s32> &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnLMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//     }

//     return eReturn;
// } // ToolBase::OnLMouseRelease


// /*******************************************************************************
// * ToolBase::OnMMousePress
// *******************************************************************************/
// enumToolResult ToolBase::OnMMousePress(u32                  _u32Modifiers,
//                                        const qVector2D<s32> &_v2dLocal,
//                                        const qVector2D<s32> &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnMMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//         ViewBase *pView  = OwnerView();
//         CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//         if (BitsSet(ToolBaseFunction(), TBF_MIDDLE_MOVE))
//         {
//             // transform the click position to zoom of the owner view
//             m_v2dMoveStart_pic = pView->Client2Pic(_v2dLocal);

//             eReturn = enumToolResult::Handled;
//         }
//     }

//     return eReturn;
// } // ToolBase::OnMMousePress


// /*******************************************************************************
// * ToolBase::OnMMouseMove
// *******************************************************************************/
// enumToolResult ToolBase::OnMMouseMove(u32                  _u32Modifiers,
//                                       const qVector2D<s32> &_v2dLocal,
//                                       const qVector2D<s32> &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnMMousePress(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//         ViewBase *pView  = OwnerView();
//         CHECK_PRE_CONDITION(pView != nullptr, enumToolResult::Unhandled);

//         MainWin         &mw     = GetMainWin();

//         if (BitsSet(ToolBaseFunction(), TBF_MIDDLE_MOVE))
//         {
//             pView->MapPic2Client(m_v2dMoveStart_pic, _v2dLocal);

//             mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);

//             eReturn = enumToolResult::Handled;
//         }
//     }

//     return eReturn;
// } // ToolBase::OnMMouseMove


// /*******************************************************************************
// * ToolBase::OnMMouseRelease
// *******************************************************************************/
// enumToolResult ToolBase::OnMMouseRelease(u32                  _u32Modifiers,
//                                          const qVector2D<s32> &_v2dLocal,
//                                          const qVector2D<s32> &_v2dGlobal)
// {
//     enumToolResult  eReturn = qTool::OnMMouseRelease(_u32Modifiers, _v2dLocal, _v2dGlobal);

//     // base class may handle first
//     if (eReturn == enumToolResult::Unhandled)
//     {
//     }

//     return eReturn;
// } // ToolBase::OnMMouseRelease
