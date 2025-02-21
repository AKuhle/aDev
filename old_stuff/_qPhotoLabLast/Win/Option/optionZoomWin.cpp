/*******************************************************************************
* \file OptionZoomWin.cpp
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
#include "optionZoomWin.h"


using namespace qLib;


/*******************************************************************************
* OptionZoomWin::OptionZoomWin
*******************************************************************************/
OptionZoomWin::OptionZoomWin()
: m_pUi(new Ui::FormOptionZoom)
{
    m_pUi->setupUi(this);
} // OptionZoomWin::OptionZoomWin


/*******************************************************************************
* OptionZoomWin::~OptionZoomWin
*******************************************************************************/
OptionZoomWin::~OptionZoomWin()
{
    delete m_pUi;
} // ~OptionZoomWin::OptionZoomWin


/*******************************************************************************
* OptionZoomWin::UpdateToolWin
*******************************************************************************/
void OptionZoomWin::UpdateToolWin()
{
    UpdateAllCtrls();
} // OptionZoomWin::UpdateToolWin


/*******************************************************************************
* OptionZoomWin::OnRegisterCtrl
*******************************************************************************/
void OptionZoomWin::OnRegisterCtrl()
{
    MainWin     &mw = GetMainWin();
    VarPoolPl   &vp = mw.VarPool();

    Register(m_pUi->m_pBtnHalfCut, true, ID_HALF_CUT, &vp, false);
    Register(m_pUi->m_pBtnThirdCut, true, ID_THIRD_CUT, &vp, false);
    Register(m_pUi->m_pBtnGoldenCut, true, ID_GOLDEN_CUT, &vp, true);
    Register(m_pUi->m_pBtnGoldenCoil, true, ID_GOLDEN_COIL, &vp, false);
} // OptionZoomWin::OnRegisterCtrl


/*******************************************************************************
* OptionZoomWin::OnUpdateCtrl
*******************************************************************************/
void OptionZoomWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    ViewBase    *pView  = GetActiveView();
    bool        bView   = (pView != nullptr);

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        // ctrls, which are enabled if a view exista
        case ID_HALF_CUT:
        case ID_THIRD_CUT:
        case ID_GOLDEN_CUT:
        case ID_GOLDEN_COIL:
            _pCtrl->SetCtrlEnabled(bView);
            break;

    } // switch (_pCtrl->CtrlId())
} // OptionZoomWin::OnUpdateCtrl


/*******************************************************************************
* OptionZoomWin::OnCtrlMessage
*******************************************************************************/
void OptionZoomWin::OnCtrlMessage(qCtrlI    *_pCtrl,
                                  u32       _u32Mes,
                                  s64       /*_s64Value*/  /*= 0*/,
                                  void      */*_pVoid1*/   /*= nullptr*/,
                                  void      */*_pVoid2*/   /*= nullptr*/)
{
    shared_ptr<qLayerStack> pLS         = GetActiveLS();
    CHECK_PRE_CONDITION_VOID(pLS != nullptr)

    //MainWin                 &mw         = GetMainWin();
    // ViewBase                *pView      = GetActiveView();
    // bool                    bView       = (pView != nullptr);
    bool                    bTriggered  = (_u32Mes == MsgTriggered);


    switch (_pCtrl->CtrlId())
    {
        case ID_HALF_CUT:
        case ID_THIRD_CUT:
        case ID_GOLDEN_CUT:
        case ID_GOLDEN_COIL:
            if (bTriggered)
            {
            }
            break;

    } // switch (_pCtrl->CtrlId())
} // OptionZoomWin::OnCtrlMessage


/*******************************************************************************
* OptionZoomWin::OnCreate
*******************************************************************************/
bool OptionZoomWin::OnCreate()
{
    return true;
} // OptionZoomWin::OnCreate
