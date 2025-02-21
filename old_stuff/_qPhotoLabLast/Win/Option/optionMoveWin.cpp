/*******************************************************************************
* \file OptionMoveWin.cpp
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
#include "optionMoveWin.h"


using namespace qLib;


/*******************************************************************************
* OptionMoveWin::OptionMoveWin
*******************************************************************************/
OptionMoveWin::OptionMoveWin()
: m_pUi(new Ui::FormOptionMove)
{
    m_pUi->setupUi(this);
} // OptionMoveWin::OptionMoveWin


/*******************************************************************************
* OptionMoveWin::~OptionMoveWin
*******************************************************************************/
OptionMoveWin::~OptionMoveWin()
{
    delete m_pUi;
} // ~OptionMoveWin::OptionMoveWin


/*******************************************************************************
* OptionMoveWin::UpdateToolWin
*******************************************************************************/
void OptionMoveWin::UpdateToolWin()
{
    UpdateAllCtrls();
} // OptionMoveWin::UpdateToolWin


/*******************************************************************************
* OptionMoveWin::OnRegisterCtrl
*******************************************************************************/
void OptionMoveWin::OnRegisterCtrl()
{
    MainWin     &mw = GetMainWin();
    VarPoolPl   &vp = mw.VarPool();

    Register(m_pUi->m_pBtnHalfCut, true, ID_HALF_CUT, &vp, false);
    Register(m_pUi->m_pBtnThirdCut, true, ID_THIRD_CUT, &vp, false);
    Register(m_pUi->m_pBtnGoldenCut, true, ID_GOLDEN_CUT, &vp, true);
    Register(m_pUi->m_pBtnGoldenCoil, true, ID_GOLDEN_COIL, &vp, false);
} // OptionMoveWin::OnRegisterCtrl


/*******************************************************************************
* OptionMoveWin::OnUpdateCtrl
*******************************************************************************/
void OptionMoveWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    VarPoolPl   &vp         = GetVarPool();
    ViewBase    *pView      = GetActiveView();
    bool        bView       = (pView != nullptr);
    enumSection eSelection  = vp.GetEnum<enumSection> (ID_ENUM_SECTION);

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        // ctrls, which are enabled if a view exista
        case ID_HALF_CUT:
            _pCtrl->SetCtrlEnabledChecked(bView, eSelection == enumSection::HalfCut);
            break;

        case ID_THIRD_CUT:
            _pCtrl->SetCtrlEnabledChecked(bView, eSelection == enumSection::ThirdCut);
            break;

        case ID_GOLDEN_CUT:
            _pCtrl->SetCtrlEnabledChecked(bView, eSelection == enumSection::GoldenCut);
            break;

        case ID_GOLDEN_COIL:
            _pCtrl->SetCtrlEnabledChecked(bView, eSelection == enumSection::GoldenCoil);
            break;

    } // switch (_pCtrl->CtrlId())
} // OptionMoveWin::OnUpdateCtrl


/*******************************************************************************
* OptionMoveWin::OnCtrlMessage
*******************************************************************************/
void OptionMoveWin::OnCtrlMessage(qCtrlI    *_pCtrl,
                                  u32       _u32Mes,
                                  s64       /*_s64Value*/  /*= 0*/,
                                  void      */*_pVoid1*/   /*= nullptr*/,
                                  void      */*_pVoid2*/   /*= nullptr*/)
{
    MainWin     &mw         = GetMainWin();
    VarPoolPl   &vp         = GetVarPool();
    bool        bTriggered  = (_u32Mes == MsgTriggered);

    switch (_pCtrl->CtrlId())
    {
        case ID_HALF_CUT:
            if (bTriggered)
            {
                qToolButton *pButton = dynamic_cast<qToolButton *> (_pCtrl);
                CHECK_PRE_CONDITION_VOID(pButton != nullptr);

                vp.SetEnumValue(ID_ENUM_SECTION, (pButton->IsCtrlChecked())?   enumSection::HalfCut : enumSection::NoCut);
                mw.SendUpdateCmd(UPDATE_ALL_VIEWS | UPDATE_GUI);
            }
            break;

        case ID_THIRD_CUT:
            if (bTriggered)
            {
                qToolButton *pButton = dynamic_cast<qToolButton *> (_pCtrl);
                CHECK_PRE_CONDITION_VOID(pButton != nullptr);

                vp.SetEnumValue(ID_ENUM_SECTION, (pButton->IsCtrlChecked())?   enumSection::ThirdCut : enumSection::NoCut);
                mw.SendUpdateCmd(UPDATE_ALL_VIEWS | UPDATE_GUI);
            }
            break;

        case ID_GOLDEN_CUT:
            if (bTriggered)
            {
                qToolButton *pButton = dynamic_cast<qToolButton *> (_pCtrl);
                CHECK_PRE_CONDITION_VOID(pButton != nullptr);

                vp.SetEnumValue(ID_ENUM_SECTION, (pButton->IsCtrlChecked())?   enumSection::GoldenCut : enumSection::NoCut);
                mw.SendUpdateCmd(UPDATE_ALL_VIEWS | UPDATE_GUI);
            }
            break;

        case ID_GOLDEN_COIL:
            if (bTriggered)
            {
                qToolButton *pButton = dynamic_cast<qToolButton *> (_pCtrl);
                CHECK_PRE_CONDITION_VOID(pButton != nullptr);

                vp.SetEnumValue(ID_ENUM_SECTION, (pButton->IsCtrlChecked())?   enumSection::GoldenCoil : enumSection::NoCut);
                mw.SendUpdateCmd(UPDATE_ALL_VIEWS | UPDATE_GUI);
            }
            break;

    } // switch (_pCtrl->CtrlId())
} // OptionMoveWin::OnCtrlMessage


/*******************************************************************************
* OptionMoveWin::OnCreate
*******************************************************************************/
bool OptionMoveWin::OnCreate()
{
    return true;
} // OptionMoveWin::OnCreate
