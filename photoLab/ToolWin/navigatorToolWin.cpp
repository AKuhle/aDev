/*******************************************************************************
* \file NavigatorToolWin.cpp
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
#include "photoLab_defs.h"
#include "mainWin.h"
#include "navigatorToolWin.h"

#include "aLayerStack.h"

using namespace aLib::aPic;


/*******************************************************************************
* NavigatorToolWin::NavigatorToolWin
*******************************************************************************/
NavigatorToolWin::NavigatorToolWin(SysWin *_pParent /*= nullptr*/)
: ToolWinBase(_pParent),
  m_pUi(new Ui::FormNavigator)
{
    m_pUi->setupUi(this);
} // NavigatorToolWin::NavigatorToolWin


/*******************************************************************************
* NavigatorToolWin::~NavigatorToolWin
*******************************************************************************/
NavigatorToolWin::~NavigatorToolWin()
{
    delete m_pUi;
} // ~NavigatorToolWin::NavigatorToolWin


/*******************************************************************************
* NavigatorToolWin::onCreateWin
*******************************************************************************/
bool NavigatorToolWin::onCreateWin()
{
    m_pUi->m_pViewNavigator->createWin();

    return true;
} // NavigatorToolWin::onCreateWin


/*******************************************************************************
* NavigatorToolWin::navigatorView
*******************************************************************************/
NavigatorView* NavigatorToolWin::navigatorView() const
{
    return m_pUi->m_pViewNavigator;
} // NavigatorToolWin::navigatorView


/*******************************************************************************
* NavigatorToolWin::setZoomFactor
*******************************************************************************/
void NavigatorToolWin::setZoomFactor(dbl _dZoomFaktor) const
{
    ViewBase    *pView  = getActiveView();
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin     &mw     = getMainWin();

    // get the current centerpoint
    aPoint2D<s32> v2dCenter = pView->centerPoint_pic();

    pView->setZoomFactor(_dZoomFaktor);
    pView->setCenterPoint_pic(v2dCenter);
    mw.sendUpdateCmd(UPDATE_VIEW, pView);
} // NavigatorToolWin::setZoomFactor


/*******************************************************************************
* NavigatorToolWin::setZoomFactorFit
*******************************************************************************/
void NavigatorToolWin::setZoomFactorFit() const
{
    ViewBase        *pView  = getActiveView();
    CHECK_PRE_CONDITION_VOID(pView != nullptr);

    MainWin                     &mw         = getMainWin();
    aRect2D<s32>                r2dClient   = pView->clientRect();
    s32                         w, h;

    // get the syncronized layerstack
    shared_ptr<SynchronizedLS>  pSync       = getTopmostLS();
    if (pSync != nullptr)
    {
        SharedLS pLS(*pSync);

        w = pLS.get()->w();
        h = pLS.get()->h();
    }

    dbl dZfW = ((dbl) r2dClient.w()) / w;
    dbl dZfH = ((dbl) r2dClient.h()) / h;

    pView->setZoomFactor(aUtil::min<dbl> (dZfW, dZfH));
    pView->setCenterPoint_pic(w/2, h/2);
    mw.sendUpdateCmd(UPDATE_VIEW, pView);
} // NavigatorToolWin::setZoomFactorFit


/*******************************************************************************
* NavigatorToolWin::updateToolWin
*******************************************************************************/
void NavigatorToolWin::updateToolWin()
{
    updateAllCtrls();

    navigatorView()->repaint();
} // NavigatorToolWin::updateToolWin


/*******************************************************************************
* NavigatorToolWin::onRegisterCtrl
*******************************************************************************/
void NavigatorToolWin::onRegisterCtrl()
{
    registerCtrl(m_pUi->m_pZoomFit, ID_ZOOM_FIT, true);
    registerCtrl(m_pUi->m_pZoom100pcnt, ID_ZOOM_100_PCNT, true);
    registerCtrl(m_pUi->m_pZoom200pcnt, ID_ZOOM_200_PCNT, true);
} // NavigatorToolWin::onRegisterCtrl


/*******************************************************************************
* NavigatorToolWin::onUpdateCtrl
*******************************************************************************/
void NavigatorToolWin::onUpdateCtrl(aCtrlI *_pCtrl)
{
    ViewBase    *pView  = getActiveView();
    bool        bView   = (pView != nullptr);

    switch (_pCtrl->ctrlId())
    {
        case ID_ZOOM_FIT:
        case ID_ZOOM_100_PCNT:
        case ID_ZOOM_200_PCNT:
            _pCtrl->setCtrlEnabled(bView);
            break;
    } // switch
} // NavigatorToolWin::onUpdateCtrl


/*******************************************************************************
* NavigatorToolWin::onCtrlClicked
*******************************************************************************/
void NavigatorToolWin::onCtrlClicked(aCtrlI *_pCtrl)
{
    //shared_ptr<Document>    pDoc    = getActiveDoc();

    switch (_pCtrl->ctrlId())
    {
        case ID_ZOOM_FIT:
            setZoomFactorFit();
            break;

        case ID_ZOOM_100_PCNT:
            setZoomFactor(1);
            break;

        case ID_ZOOM_200_PCNT:
            setZoomFactor(2);
            break;
    } // switch
} // NavigatorToolWin::onCtrlClicked


/*******************************************************************************
* NavigatorToolWin::OnRegisterCtrl
*******************************************************************************/
// void NavigatorToolWin::OnRegisterCtrl()
// {
//     // standard toolbar
//     Register(m_pUi->m_pZoomFit, true, ID_ZOOM_FIT);
//     Register(m_pUi->m_pZoom100pcnt, true, ID_ZOOM_100_PCNT);
//     Register(m_pUi->m_pZoom200pcnt, true, ID_ZOOM_200_PCNT);

//     Register(m_pUi->m_pZoomSlider, true, ID_ZOOM_SLIDER);
//     m_pUi->m_pZoomSlider->SetRange(0, 1000);
// } // NavigatorToolWin::OnRegisterCtrl


/*******************************************************************************
* NavigatorToolWin::OnUpdateCtrl
*******************************************************************************/
// void NavigatorToolWin::OnUpdateCtrl(qCtrlI *_pCtrl)
// {
//     ViewBase    *pView  = GetActiveView();
//     bool        bView   = (pView != nullptr);

//     switch (_pCtrl->CtrlId())
//     {
//         default:
//             _pCtrl->SetCtrlEnabled(false);
//             break;

//         // ctrls, which are enabled if a view exista
//         case ID_ZOOM_FIT:
//         case ID_ZOOM_100_PCNT:
//         case ID_ZOOM_200_PCNT:
//             _pCtrl->SetCtrlEnabled(bView);
//             break;

//         case ID_ZOOM_SLIDER:
//         {
//             _pCtrl->SetCtrlEnabled(bView);

//             qSlider *pSlider = dynamic_cast<qSlider *> (_pCtrl);

//             if (bView && pSlider != nullptr)
//             {
//                 pSlider->SetValue(pView->ZoomFactor_pml());
//             }
//             break;
//         }
//     } // switch (_pCtrl->CtrlId())
// } // NavigatorToolWin::OnUpdateCtrl


/*******************************************************************************
* NavigatorToolWin::OnCtrlMessage
*******************************************************************************/
// void NavigatorToolWin::OnCtrlMessage(qCtrlI *_pCtrl,
//                                      u32    _u32Mes,
//                                      s64    _s64Value       /*= 0*/,
//                                      void   */*_pVoid1*/    /*= nullptr*/,
//                                      void   */*_pVoid2*/    /*= nullptr*/)
// {
//     shared_ptr<qLayerStack> pLS         = GetActiveLS();
//     CHECK_PRE_CONDITION_VOID(pLS != nullptr)

//     MainWin                 &mw         = GetMainWin();
//     ViewBase                *pView      = GetActiveView();
//     bool                    bView       = (pView != nullptr);
//     bool                    bTriggered  = (_u32Mes == MsgTriggered);


//     switch (_pCtrl->CtrlId())
//     {
//         case ID_ZOOM_FIT:
//             if (bTriggered)
//             {
//                 pView->SetZoomFactorFit();
//                 pView->SetCenterPoint_pic(pLS->w()/2, pLS->h()/2);
//                 mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//             }
//             break;

//         case ID_ZOOM_100_PCNT:
//             if (bTriggered && bView && IsUnequal<dbl> (pView->ZoomFactor(), 1))
//             {
//                 qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
//                 pView->SetZoomFactor(1);
//                 pView->SetCenterPoint_pic(v2dCenter_pic);
//                 mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//             }
//             break;

//         case ID_ZOOM_200_PCNT:
//             if (bTriggered && bView && IsUnequal<dbl> (pView->ZoomFactor(), 2))
//             {
//                 qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
//                 pView->SetZoomFactor(2);
//                 pView->SetCenterPoint_pic(v2dCenter_pic);
//                 mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//             }
//             break;

//         case ID_ZOOM_SLIDER:
//             if (_u32Mes == MsgSliderMoved)
//             {
//                 qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();

//                 pView->SetZoomFactor_pml(_s64Value);

//                 pView->SetCenterPoint_pic(v2dCenter_pic);
//                 mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
//             }
//             break;

//     } // switch (_pCtrl->CtrlId())
// } // NavigatorToolWin::OnCtrlMessage
