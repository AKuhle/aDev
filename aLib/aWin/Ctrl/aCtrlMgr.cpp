/*******************************************************************************
* \file aCtrlMgr
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
#include "aWin/Ctrl/aCtrlMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aCtrlMgr::aCtrlMgr
*******************************************************************************/
aCtrlMgr::aCtrlMgr()
{
} // aCtrlMgr::aCtrlMgr


/*******************************************************************************
* aCtrlMgr::~aCtrlMgr
*******************************************************************************/
aCtrlMgr::~aCtrlMgr()
{
    // delete all qActions
    // for (qAction *pAction : m_lstAction)
    // {
    //     delete pAction;
    // }
    // m_lstAction.clear();

} // aCtrlMgr::~aCtrlMgr


/*******************************************************************************
* aCtrlMgr::updateAllCtrls
*******************************************************************************/
void aCtrlMgr::updateAllCtrls()
{
    // // update all registered actions
    // for (qCtrlI *pCtrl : m_lstAction)
    // {
    //     OnUpdateCtrl(pCtrl);
    // }

    // update all registered ctrls
    for (aCtrl *pCtrl : m_lstCtrls)
    {
        onUpdateCtrl(pCtrl);
    }
} // aCtrlMgr::updateAllCtrls


/*******************************************************************************
* aCtrlMgr::registerCtrl
*******************************************************************************/
void aCtrlMgr::registerCtrl(aCtrl   *_pCtrl)
{
    m_lstCtrls.push_back(_pCtrl);

    _pCtrl->setCtrlMgr(this);
} // aCtrlMgr::registerCtrl


/*******************************************************************************
* aCtrlMgr::sendCtrlMessage
*******************************************************************************/
void aCtrlMgr::sendCtrlMessage(aCtrl    *_pCtrl,
                               u32      _u32Mes)
{
    switch (_u32Mes)
    {
        case MSG_CLICKED:
             onCtrlClicked(_pCtrl);
            break;

        // case MSG_VALUE_CHANGED:
        //     OnCtrlValueChanged(_pCtrl);
        //     break;
    }

} // aCtrlMgr::sendCtrlMessage


// /*******************************************************************************
// * aCtrlMgr::Register
// *******************************************************************************/
// // void aCtrlMgr::Register(QAction     *_pAction,
// //                         s32         _s32ID,
// //                         qGuiVarPool *_pVarPool    /*= nullptr*/,
// //                         bool        /*_bDefState*/    /*= false*/)
// // {
// //     qAction  *pNewAction = new qAction(_pAction);
// //     m_lstAction.push_back(pNewAction);

// //     pNewAction->SetCtrlId(_s32ID);
// //     pNewAction->SetCtrlMgr(this);

// //     if (_pVarPool != nullptr)
// //     {
// //     //     // create a new pool variable, if none with the ctrl id exists
// //     //     // otherwise simply use the existing one
// //     //     if (!_pVarPool->HasBool(_s32ID))
// //     //     {
// //     //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
// //     //     }

// //     //     pNewCtrl->SetVarPool(_pVarPool);
// //     }

// // } // aCtrlMgr::Register


/*******************************************************************************
* aCtrlMgr::onCtrlClicked
*******************************************************************************/
void aCtrlMgr::onCtrlClicked(aCtrl  */*_pCtrl*/)
{
} // aCtrlMgr::onCtrlClicked


// /*******************************************************************************
// * aCtrlMgr::OnCtrlValueChanged
// *******************************************************************************/
// void aCtrlMgr::OnCtrlValueChanged(qCtrlBase  */*_pCtrl*/)
// {
// } // aCtrlMgr::OnCtrlValueChanged


} // namespace aWin
} // namespace aLib
