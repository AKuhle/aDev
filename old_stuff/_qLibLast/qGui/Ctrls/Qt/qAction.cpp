/*******************************************************************************
* \file qAction.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qGuiDefs.h"
#include "qAction.h"

namespace qLib
{
    /*******************************************************************************
    * qAction::qAction
    *******************************************************************************/
    qAction::qAction(QAction *_pAction)
    : m_pAction(_pAction)
    {
        // connect the handlers
        connect(m_pAction, SIGNAL(triggered(bool)),
                this, SLOT(SlotTriggered(bool)));
    } // qAction::qAction


    /*******************************************************************************
    * qAction::~qAction
    *******************************************************************************/
    qAction::~qAction()
    {
    } // qAction::~qAction


    /*******************************************************************************
    * qAction::SetCtrlEnabled
    *******************************************************************************/
    void qAction::SetCtrlEnabled(bool _bEnabled)
    {
        m_pAction->setEnabled(_bEnabled);
    } // qAction::SetCtrlEnabled


    /*******************************************************************************
    * qAction::IsCtrlEnabled
    *******************************************************************************/
    bool qAction::IsCtrlEnabled() const
    {
        return m_pAction->isEnabled();
    } // qlqAction::IsCtrlEnabled


    /*******************************************************************************
    * qAction::SetCtrlCheckable
    *******************************************************************************/
    void qAction::SetCtrlCheckable(bool _bCheckable)
    {
        m_pAction->setCheckable(_bCheckable);
    } // qAction::SetCtrlCheckable


    /*******************************************************************************
    * qAction::IsCtrlCheckable
    *******************************************************************************/
    bool qAction::IsCtrlCheckable() const
    {
        return m_pAction->isCheckable();
    } // qAction::IsCtrlCheckable


    /*******************************************************************************
    * qAction::SetCtrlChecked
    *******************************************************************************/
    void qAction::SetCtrlChecked(bool _bChecked)
    {
        if (IsCtrlCheckable())
        {
            m_pAction->setChecked(_bChecked);
        }
    } // qAction::SetCtrlChecked


    /*******************************************************************************
    * qAction::IsCtrlChecked
    *******************************************************************************/
    bool qAction::IsCtrlChecked() const
    {
        return m_pAction->isChecked();
    } // qAction::IsCtrlChecked


    /*******************************************************************************
    * qAction::SetCtrlEnabledChecked
    *******************************************************************************/
    void qAction::SetCtrlEnabledChecked(bool    _bEnabled,
                                        bool    _bChecked)
    {
        SetCtrlEnabled(_bEnabled);
        SetCtrlChecked(_bChecked);
    } // qAction::SetCtrlEnabledChecked


    /*******************************************************************************
    * qAction::SlotTriggered
    *******************************************************************************/
    void qAction::SlotTriggered(bool /*_bChecked*/)
    {
        //Control2VarPool();

        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgTriggered);
        }
    } // qAction::SlotTriggered

} // namespace qLib

#endif // _USE_QT_
