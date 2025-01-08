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
#include "qLib.h"
#include "defsPl.h"
#include "mainWin.h"
#include "navigatorToolWin.h"


using namespace qLib;


/*******************************************************************************
* NavigatorToolWin::NavigatorToolWin
*******************************************************************************/
NavigatorToolWin::NavigatorToolWin()
: m_pUi(new Ui::FormNavigator)
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
* NavigatorToolWin::NavigatorView
*********************************************B**********************************/
ViewNavigator* NavigatorToolWin::NavigatorView() const
{
    return m_pUi->m_pViewNavigator;
} // NavigatorToolWin::NavigatorView


/*******************************************************************************
* NavigatorToolWin::UpdateToolWin
*******************************************************************************/
void NavigatorToolWin::UpdateToolWin()
{
    UpdateAllCtrls();

    NavigatorView()->Repaint();
} // NavigatorToolWin::UpdateToolWin


/*******************************************************************************
* NavigatorToolWin::OnRegisterCtrl
*******************************************************************************/
void NavigatorToolWin::OnRegisterCtrl()
{
    // standard toolbar
    Register(m_pUi->m_pZoomFit, true, ID_ZOOM_FIT);
    Register(m_pUi->m_pZoom100pcnt, true, ID_ZOOM_100_PCNT);
    Register(m_pUi->m_pZoom200pcnt, true, ID_ZOOM_200_PCNT);

    Register(m_pUi->m_pZoomSlider, true, ID_ZOOM_SLIDER);
    m_pUi->m_pZoomSlider->SetRange(0, 1000);
} // NavigatorToolWin::OnRegisterCtrl


/*******************************************************************************
* NavigatorToolWin::OnUpdateCtrl
*******************************************************************************/
void NavigatorToolWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    ViewBase    *pView  = GetActiveView();
    bool        bView   = (pView != nullptr);

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        // ctrls, which are enabled if a view exista
        case ID_ZOOM_FIT:
        case ID_ZOOM_100_PCNT:
        case ID_ZOOM_200_PCNT:
            _pCtrl->SetCtrlEnabled(bView);
            break;

        case ID_ZOOM_SLIDER:
        {
            _pCtrl->SetCtrlEnabled(bView);

            qSlider *pSlider = dynamic_cast<qSlider *> (_pCtrl);

            if (bView && pSlider != nullptr)
            {
                pSlider->SetValue(pView->ZoomFactor_pml());
            }
            break;
        }
    } // switch (_pCtrl->CtrlId())
} // NavigatorToolWin::OnUpdateCtrl


/*******************************************************************************
* NavigatorToolWin::OnCtrlMessage
*******************************************************************************/
void NavigatorToolWin::OnCtrlMessage(qCtrlI *_pCtrl,
                                     u32    _u32Mes,
                                     s64    _s64Value       /*= 0*/,
                                     void   */*_pVoid1*/    /*= nullptr*/,
                                     void   */*_pVoid2*/    /*= nullptr*/)
{
    shared_ptr<qLayerStack> pLS         = GetActiveLS();
    CHECK_PRE_CONDITION_VOID(pLS != nullptr)

    MainWin                 &mw         = GetMainWin();
    ViewBase                *pView      = GetActiveView();
    bool                    bView       = (pView != nullptr);
    bool                    bTriggered  = (_u32Mes == MsgTriggered);


    switch (_pCtrl->CtrlId())
    {
        case ID_ZOOM_FIT:
            if (bTriggered)
            {
                pView->SetZoomFactorFit();
                pView->SetCenterPoint_pic(pLS->w()/2, pLS->h()/2);
                mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
            }
            break;

        case ID_ZOOM_100_PCNT:
            if (bTriggered && bView && IsUnequal<dbl> (pView->ZoomFactor(), 1))
            {
                qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
                pView->SetZoomFactor(1);
                pView->SetCenterPoint_pic(v2dCenter_pic);
                mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
            }
            break;

        case ID_ZOOM_200_PCNT:
            if (bTriggered && bView && IsUnequal<dbl> (pView->ZoomFactor(), 2))
            {
                qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();
                pView->SetZoomFactor(2);
                pView->SetCenterPoint_pic(v2dCenter_pic);
                mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
            }
            break;

        case ID_ZOOM_SLIDER:
            if (_u32Mes == MsgSliderMoved)
            {
                qVector2D<s32> v2dCenter_pic = pView->CenterPoint_pic();

                pView->SetZoomFactor_pml(_s64Value);

                pView->SetCenterPoint_pic(v2dCenter_pic);
                mw.SendUpdateCmd(UPDATE_VIEW | UPDATE_GUI, pView);
            }
            break;

    } // switch (_pCtrl->CtrlId())
} // NavigatorToolWin::OnCtrlMessage


/*******************************************************************************
* NavigatorToolWin::OnCreate
*******************************************************************************/
bool NavigatorToolWin::OnCreate()
{
    m_pUi->m_pViewNavigator->CreateWin();

    return true;
} // NavigatorToolWin::OnCreate
