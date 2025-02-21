/*******************************************************************************
* \file ToolBoxToolWin.cpp
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
#include "defsPl.h"
#include "mainWin.h"
#include "ToolBoxToolWin.h"


using namespace qLib;


/*******************************************************************************
* ToolBoxToolWin::ToolBoxToolWin
*******************************************************************************/
ToolBoxToolWin::ToolBoxToolWin()
: m_pUi(new Ui::FormToolBox)
{
    m_pUi->setupUi(this);
} // ToolBoxToolWin::ToolBoxToolWin


/*******************************************************************************
* ToolBoxToolWin::~ToolBoxToolWin
*******************************************************************************/
ToolBoxToolWin::~ToolBoxToolWin()
{
    delete m_pUi;
} // ~ToolBoxToolWin::ToolBoxToolWin


/*******************************************************************************
* ToolBoxToolWin::UpdateToolWin
*******************************************************************************/
void ToolBoxToolWin::UpdateToolWin()
{
    UpdateAllCtrls();
} // ToolBoxToolWin::UpdateToolWin


/*******************************************************************************
* ToolBoxToolWin::OnRegisterCtrl
*******************************************************************************/
void ToolBoxToolWin::OnRegisterCtrl()
{
    // standard toolbar
    Register(m_pUi->m_pBtnMove, true, ID_MOVE);
    Register(m_pUi->m_pBtnZoom, true, ID_ZOOM);

    Register(m_pUi->m_pTb_03, true, ID_DUMMY);
    Register(m_pUi->m_pTb_04, true, ID_DUMMY);
    Register(m_pUi->m_pTb_05, true, ID_DUMMY);
    Register(m_pUi->m_pTb_06, true, ID_DUMMY);
    Register(m_pUi->m_pTb_07, true, ID_DUMMY);
    Register(m_pUi->m_pTb_08, true, ID_DUMMY);
    Register(m_pUi->m_pTb_09, true, ID_DUMMY);
    Register(m_pUi->m_pTb_10, true, ID_DUMMY);
    Register(m_pUi->m_pTb_11, true, ID_DUMMY);
    Register(m_pUi->m_pTb_12, true, ID_DUMMY);
    Register(m_pUi->m_pTb_13, true, ID_DUMMY);
    Register(m_pUi->m_pTb_14, true, ID_DUMMY);
    Register(m_pUi->m_pTb_15, true, ID_DUMMY);
    Register(m_pUi->m_pTb_16, true, ID_DUMMY);
} // ToolBoxToolWin::OnRegisterCtrl


/*******************************************************************************
* ToolBoxToolWin::OnUpdateCtrl
*******************************************************************************/
void ToolBoxToolWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    MainWin     &mw     = GetMainWin();
    enumMode    mode    = mw.Mode();

    // std::shared_ptr<DocPl>  pDoc    = GetActiveDoc();
    // bool                    bDoc    = (pDoc != nullptr);

    bool                    bView   = (GetActiveView() != nullptr);
    // bool                    bC      = IsCalculating();

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        // ctrls, which are enabled if a view exista
        case ID_MOVE:
            _pCtrl->SetCtrlEnabledChecked(bView, mode == enumMode::Move);
            break;

        case ID_ZOOM:
            _pCtrl->SetCtrlEnabledChecked(bView, mode == enumMode::Zoom);
            break;

    } // switch (_pCtrl->CtrlId())
} // ToolBoxToolWin::OnUpdateCtrl


/*******************************************************************************
* ToolBoxToolWin::OnCtrlMessage
*******************************************************************************/
void ToolBoxToolWin::OnCtrlMessage(qCtrlI   *_pCtrl,
                                   u32      _u32Mes,
                                   s64      /*_s64Value*/  /*= 0*/,
                                   void     */*_pVoid1*/   /*= nullptr*/,
                                   void     */*_pVoid2*/   /*= nullptr*/)
{
    MainWin &mw         = GetMainWin();
    bool    bTriggered  = (_u32Mes == MsgTriggered);

    // std::shared_ptr<DocPl>  pDoc        = GetActiveDoc();
    // bool                    bDoc        = (pDoc != nullptr);


    switch (_pCtrl->CtrlId())
    {
        case ID_MOVE:
            if (bTriggered)
                mw.SetMode(enumMode::Move);
            break;

        case ID_ZOOM:
            if (bTriggered)
                mw.SetMode(enumMode::Zoom);
            break;

    } // switch (_pCtrl->CtrlId())
} // ToolBoxToolWin::OnCtrlMessage


/*******************************************************************************
* ToolBoxToolWin::OnCreate
*******************************************************************************/
bool ToolBoxToolWin::OnCreate()
{
    return true;
} // ToolBoxToolWin::OnCreate
