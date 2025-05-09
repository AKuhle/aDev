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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aCtrl_def.h"
#include "aCtrlMgr.h"

#include "aAction.h"
#include "aToolButton.h"

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
    for (aCtrlI *pCtrl : m_lstCtrls)
    {
        onUpdateCtrl(pCtrl);
    }
} // aCtrlMgr::updateAllCtrls


/*******************************************************************************
* aCtrlMgr::updateCtrl
*******************************************************************************/
void aCtrlMgr::updateCtrl(aCtrlI *_pCtrl)
{
    onUpdateCtrl(_pCtrl);
} // aCtrlMgr::updateCtrl


/*******************************************************************************
* aCtrlMgr::sendCtrlMessage
*******************************************************************************/
void aCtrlMgr::sendCtrlMessage(aCtrlI   *_pCtrl,
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


/*******************************************************************************
* aCtrlMgr::registerCtrl
*******************************************************************************/
void aCtrlMgr::registerCtrl(QAction     *_pAction,
                            s32         _s32ID)
                            //qGuiVarPool *_pVarPool    /*= nullptr*/,
                            //bool        /*_bDefState*/    /*= false*/);
{
    aAction  *pNewAction = new aAction(_pAction);
    m_lstCtrls.push_back(pNewAction);

    pNewAction->setCtrlId(_s32ID);
    pNewAction->setCtrlMgr(this);

    //if (_pVarPool != nullptr)
    //{
    //     // create a new pool variable, if none with the ctrl id exists
    //     // otherwise simply use the existing one
    //     if (!_pVarPool->HasBool(_s32ID))
    //     {
    //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
    //     }

    //     pNewCtrl->SetVarPool(_pVarPool);
    //}

} // aCtrlMgr::registerCtrl


/*******************************************************************************
* aCtrlMgr::registerCtrl
*******************************************************************************/
void aCtrlMgr::registerCtrl(aToolButton     *_pBtn,
                            s32             _s32ID,
                            bool           _bCreateWin)
                            //qGuiVarPool *_pVarPool    /*= nullptr*/,
                            //bool        /*_bDefState*/    /*= false*/);
{
    if (_bCreateWin)
    {
        _pBtn->createWin();
    }

    m_lstCtrls.push_back(_pBtn);

    _pBtn->setCtrlId(_s32ID);
    _pBtn->setCtrlMgr(this);

    //if (_pVarPool != nullptr)
    //{
    //     // create a new pool variable, if none with the ctrl id exists
    //     // otherwise simply use the existing one
    //     if (!_pVarPool->HasBool(_s32ID))
    //     {
    //         _pVarPool->AddBool(_s32ID, _bDefState, _bDefState);
    //     }

    //     pNewCtrl->SetVarPool(_pVarPool);
    //}

} // aCtrlMgr::registerCtrl

/*******************************************************************************
* aCtrlMgr::onCtrlClicked
*******************************************************************************/
void aCtrlMgr::onCtrlClicked(aCtrlI  */*_pCtrl*/)
{
} // aCtrlMgr::onCtrlClicked


} // namespace aWin
} // namespace aLib



// /*******************************************************************************
// * aCtrlMgr::OnCtrlValueChanged
// *******************************************************************************/
// void aCtrlMgr::OnCtrlValueChanged(qCtrlBase  */*_pCtrl*/)
// {
// } // aCtrlMgr::OnCtrlValueChanged

#endif //_USE_QT_
