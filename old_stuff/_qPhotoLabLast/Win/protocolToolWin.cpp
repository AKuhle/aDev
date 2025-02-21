/*******************************************************************************
* \file ProtocolToolWin.cpp
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
#include "qBaseDefs.h"
#include "mainWin.h"
#include "docPl.h"

#include "protocolToolWin.h"


using namespace qLib;


/*******************************************************************************
* ProtocolToolWin::ProtocolToolWin
*******************************************************************************/
ProtocolToolWin::ProtocolToolWin()
: m_pUi(new Ui::FormProtocol)
{
    m_pUi->setupUi(this);
} // ProtocolToolWin::ProtocolToolWin


/*******************************************************************************
* ProtocolToolWin::~ProtocolToolWin
*******************************************************************************/
ProtocolToolWin::~ProtocolToolWin()
{
    delete m_pUi;
} // ~ProtocolToolWin::ProtocolToolWin


/*******************************************************************************
* ProtocolToolWin::UpdateToolWin
*******************************************************************************/
void ProtocolToolWin::UpdateToolWin()
{
    shared_ptr<DocPl> pDoc = GetActiveDoc();
    CHECK_PRE_CONDITION_VOID(pDoc != nullptr)

    const qUniquePtrList<qCmdI>                     &lstUndo    = pDoc->UndoList();
    const qUniquePtrList<qCmdI>                     &lstRedo    = pDoc->RedoList();
    qCmdI                                           *pActiveCmd = pDoc->ActiveCmd();
    qUniquePtrList<qCmdI>::const_iterator           cit;
    qUniquePtrList<qCmdI>::const_reverse_iterator   crit;

    // clear old content
    m_pUi->m_pLwProtocol->Clear();

    // add the undo cmds
    for (cit = lstUndo.begin(); cit != lstUndo.end(); cit++)
    {
        qListCtrlItem   *pItem = new qListCtrlItem();
        pItem->SetText((*cit)->CmdName());

        // active cmd is highlighted
        qFont   fnt = Font();
        if (pActiveCmd == cit->get())
        {
            fnt.SetBold(true);
        }
        pItem->SetFont(fnt);

        m_pUi->m_pLwProtocol->AddItem(pItem);
    }

    // add the redo cmds
    for (crit = lstRedo.rbegin(); crit != lstRedo.rend(); crit++)
    {
        qListCtrlItem   *pItem = new qListCtrlItem();
        pItem->SetFont(Font());
        pItem->SetText((*crit)->CmdName());

        m_pUi->m_pLwProtocol->AddItem(pItem);
    }

} // ProtocolToolWin::UpdateToolWin


/*******************************************************************************
* ProtocolToolWin::OnRegisterCtrl
*******************************************************************************/
void ProtocolToolWin::OnRegisterCtrl()
{
    Register(m_pUi->m_pLwProtocol, true, ID_CMD_LIST);
} // ProtocolToolWin::OnRegisterCtrl


/*******************************************************************************
* ProtocolToolWin::OnUpdateCtrl
*******************************************************************************/
void ProtocolToolWin::OnUpdateCtrl(qCtrlI *_pCtrl)
{
    //std::shared_ptr<DocPl>  pDoc    = GetActiveDoc();
    //bool                    bDoc    = (pDoc != nullptr);

    //bool                    bView   = (GetActiveView() != nullptr);
    //bool                    bC      = IsCalculating();

    switch (_pCtrl->CtrlId())
    {
        default:
            _pCtrl->SetCtrlEnabled(false);
            break;

        case ID_CMD_LIST:
            _pCtrl->SetCtrlEnabled(true);
            break;
    } // switch (_pCtrl->CtrlId())

} // ProtocolToolWin::OnUpdateCtrl


/*******************************************************************************
* ProtocolToolWin::OnCtrlMessage
*******************************************************************************/
void ProtocolToolWin::OnCtrlMessage(qCtrlI  */*_pCtrl*/,
                                    u32     _u32Mes,
                                    s64     _s64Value   /*= 0*/,
                                    void     *_pVoid1   /*= nullptr*/,
                                    void     */*_pVoid2*/   /*= nullptr*/)
{
    //std::shared_ptr<DocPl>  pDoc        = GetActiveDoc();
    //bool                    bDoc        = (pDoc != nullptr);

    switch (_u32Mes)
    {
        case MsgCurrentItemChanged:
            qLog::Log(__FUNCTION__, enumCoutColor::magenta, "MsgCurrentItemChanged", _pVoid1);
            break;

        case MsgCurrentRowChanged:
            qLog::Log(__FUNCTION__, enumCoutColor::magenta, "MsgCurrentRowChanged", _s64Value);
            break;

        case MsgItemChanged:
            qLog::Log(__FUNCTION__, enumCoutColor::magenta, "MsgItemChanged", _pVoid1);
            break;

        case MsgItemClicked:
            qLog::Log(__FUNCTION__, enumCoutColor::magenta, "MsgItemClicked", _pVoid1);
            break;
    } // switch (_u32Mes)

} // ProtocolToolWin::OnCtrlMessage


/*******************************************************************************
* ProtocolToolWin::OnCreate
*******************************************************************************/
bool ProtocolToolWin::OnCreate()
{
    return true;
} // ProtocolToolWin::OnCreate
