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
#include "qAction.h"
#include "qListCtrl.h"
#include "qScrollBar.h"
#include "qSlider.h"
#include "qToolButton.h"
#include "qGuiVarPool.h"


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
        for (qAction *pAction : m_lstAction)
        {
            delete pAction;
        }
        m_lstAction.clear();

    } // qCtrlMgr::~qCtrlMgr


    /*******************************************************************************
    * qCtrlMgr::UpdateAllCtrls
    *******************************************************************************/
    void qCtrlMgr::UpdateAllCtrls()
    {
        // update all registered actions
        for (qCtrlI *pCtrl : m_lstAction)
        {
            OnUpdateCtrl(pCtrl);
        }

        // update all registered ctrls
        for (qCtrlI *pCtrl : m_lstCtrls)
        {
            OnUpdateCtrl(pCtrl);
        }
    } // qCtrlMgr::UpdateAllCtrls


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(QAction     *_pAction,
                            s32         _s32ID,
                            qGuiVarPool *_pVarPool    /*= nullptr*/,
                            bool        /*_bDefState*/    /*= false*/)
    {
        qAction  *pNewAction = new qAction(_pAction);
        m_lstAction.push_back(pNewAction);

        pNewAction->SetCtrlId(_s32ID);
        pNewAction->SetCtrlMgr(this);

        if (_pVarPool != nullptr)
        {
        //     // create a new pool variable, if none with the ctrl id exists
        //     // otherwise simply use the existing one
        //     if (!_pVarPool->HasBool(_s32ID))
        //     {
        //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
        //     }

        //     pNewCtrl->SetVarPool(_pVarPool);
        }

    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(qListCtrl   *_pList,
                            bool        _bCreateCtrl,
                            s32         _s32ID)
    {
        if (_bCreateCtrl)
        {
            _pList->CreateWin();
        }

        m_lstCtrls.push_back(_pList);

        _pList->SetCtrlId(_s32ID);
        _pList->SetCtrlMgr(this);
    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(qScrollBar  *_pSb,
                            bool        _bCreateCtrl,
                            s32         _s32ID)
    //VarPool    *_pVarPool    /*= nullptr*/,
    //bool       _bDefState    /*= false*/)
    {
        if (_bCreateCtrl)
        {
            _pSb->CreateWin();
        }

        m_lstCtrls.push_back(_pSb);

        _pSb->SetCtrlId(_s32ID);
        _pSb->SetCtrlMgr(this);

        // if (_pVarPool != nullptr)
        // {
        //     // create a new pool variable, if none with the ctrl id exists
        //     // otherwise simply use the existing one
        //     if (!_pVarPool->HasBool(_s32ID))
        //     {
        //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
        //     }

        //     pNewCtrl->SetVarPool(_pVarPool);
        // }

    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(qSlider *_pSlider,
                            bool    _bCreateCtrl,
                            s32     _s32ID)
    //VarPool    *_pVarPool    /*= nullptr*/,
    //bool       _bDefState    /*= false*/)
    {
        if (_bCreateCtrl)
        {
            _pSlider->CreateWin();
        }

        m_lstCtrls.push_back(_pSlider);

        _pSlider->SetCtrlId(_s32ID);
        _pSlider->SetCtrlMgr(this);

        // if (_pVarPool != nullptr)
        // {
        //     // create a new pool variable, if none with the ctrl id exists
        //     // otherwise simply use the existing one
        //     if (!_pVarPool->HasBool(_s32ID))
        //     {
        //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
        //     }

        //     pNewCtrl->SetVarPool(_pVarPool);
        // }

    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::Register
    *******************************************************************************/
    void qCtrlMgr::Register(qToolButton *_pBtn,
                            bool        _bCreateCtrl,
                            s32         _s32ID,
                            qGuiVarPool *_pVarPool    /*= nullptr*/,
                            bool        _bDefState    /*= false*/)
    {
        if (_bCreateCtrl)
        {
            _pBtn->CreateWin();
        }

        m_lstCtrls.push_back(_pBtn);

        _pBtn->SetCtrlId(_s32ID);
        _pBtn->SetCtrlMgr(this);

        if (_pVarPool != nullptr)
        {
            // create a new pool variable, if none with the ctrl id exists
            // otherwise simply use the existing one
            if (!_pVarPool->HasBool(_s32ID))
            {
                _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
            }

            _pBtn->SetVarPool(_pVarPool);
        }

    } // qCtrlMgr::Register


    /*******************************************************************************
    * qCtrlMgr::OnCtrlMessage
    *******************************************************************************/
    void qCtrlMgr::OnCtrlMessage(qCtrlI     */*_pCtrl*/,
                                 u32        /*_u32Mes*/,
                                 s64        /*_s64Value = 0*/,
                                 void       */*_pVoid1 = nullptr*/,
                                 void       */*_pVoid2 = nullptr*/)
    {
    } // qCtrlMgr::OnCtrlMessage

} // namespace qLib
