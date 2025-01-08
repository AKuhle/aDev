/*******************************************************************************
* \file qCtrlMgr
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
#include "qCtrlMgr.h"
#include "qCtrlBase.h"


namespace qLib
{
    /*******************************************************************************
    * qCtrlMgr::qCtrlMgr
    *******************************************************************************/
    qCtrlMgr::qCtrlMgr()
    {
    } // qCtrlMgr::qCtrlMgr


    /*******************************************************************************
    * qCtrlMgr::~qCtrlMgr
    *******************************************************************************/
    qCtrlMgr::~qCtrlMgr()
	{
        // delete all qActions
        // for (qAction *pAction : m_lstAction)
        // {
        //     delete pAction;
        // }
        // m_lstAction.clear();

    } // qCtrlMgr::~qCtrlMgr


    /*******************************************************************************
    * qCtrlMgr::UpdateAllCtrls
    *******************************************************************************/
    void qCtrlMgr::UpdateAllCtrls()
    {
        // // update all registered actions
        // for (qCtrlI *pCtrl : m_lstAction)
        // {
        //     OnUpdateCtrl(pCtrl);
        // }

        // update all registered ctrls
        for (qCtrlBase *pCtrl : m_lstCtrls)
        {
            OnUpdateCtrl(pCtrl);
        }
    } // qCtrlMgr::UpdateAllCtrls


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(qCtrlBase   *_pCtrl)
    {
        m_lstCtrls.push_back(_pCtrl);

        _pCtrl->SetCtrlMgr(this);
    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::SendCtrlMessage
    *******************************************************************************/
    void qCtrlMgr::SendCtrlMessage(qCtrlBase *_pCtrl,
                                   u32       _u32Mes)
    {
        switch (_u32Mes)
        {
            case MSG_CLICKED:
                OnCtrlClicked(_pCtrl);
                break;

            case MSG_VALUE_CHANGED:
                OnCtrlValueChanged(_pCtrl);
                break;
        }

    } // qCtrlMgr::SendCtrlMessage


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    // void qCtrlMgr::Register(QAction     *_pAction,
    //                         s32         _s32ID,
    //                         qGuiVarPool *_pVarPool    /*= nullptr*/,
    //                         bool        /*_bDefState*/    /*= false*/)
    // {
    //     qAction  *pNewAction = new qAction(_pAction);
    //     m_lstAction.push_back(pNewAction);

    //     pNewAction->SetCtrlId(_s32ID);
    //     pNewAction->SetCtrlMgr(this);

    //     if (_pVarPool != nullptr)
    //     {
    //     //     // create a new pool variable, if none with the ctrl id exists
    //     //     // otherwise simply use the existing one
    //     //     if (!_pVarPool->HasBool(_s32ID))
    //     //     {
    //     //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
    //     //     }

    //     //     pNewCtrl->SetVarPool(_pVarPool);
    //     }

    // } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::OnCtrlClicked
    *******************************************************************************/
    void qCtrlMgr::OnCtrlClicked(qCtrlBase  */*_pCtrl*/)
    {
    } // qCtrlMgr::OnCtrlClicked


    /*******************************************************************************
    * qCtrlMgr::OnCtrlValueChanged
    *******************************************************************************/
    void qCtrlMgr::OnCtrlValueChanged(qCtrlBase  */*_pCtrl*/)
    {
    } // qCtrlMgr::OnCtrlValueChanged

} // namespace qLib
