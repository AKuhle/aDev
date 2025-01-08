/*******************************************************************************
* \file qToolButton.cpp
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
#include "qToolButton.h"
#include "qGuiVarPool.h"


namespace qLib
{
    /*******************************************************************************
    * qToolButton::qToolButton
    *******************************************************************************/
    qToolButton::qToolButton(SysWin_t *_pParent /*= nullptr*/)
    : qButtonBase<QToolButton>(_pParent)
    {
        // connect the handlers
        connect(this, SIGNAL(clicked(bool)),
                this, SLOT(SlotClicked(bool)));
    } // qToolButton::qToolButton


    /*******************************************************************************
    * qToolButton::~qToolButton
    *******************************************************************************/
    qToolButton::~qToolButton()
    {
    } // qToolButton::~qToolButton


    /*******************************************************************************
    * qToolButton::SlotClicked
    *******************************************************************************/
    void qToolButton::SlotClicked(bool /*_bChecked*/)
    {
        Control2VarPool();

        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgTriggered);
        }
    } // qlqToolButton::SlotClicked


} // namespace qLib

#endif // _USE_QT_









    // /*******************************************************************************
    // * qToolButton::SetCheckable
    // *******************************************************************************/
    // void qToolButton::SetCheckable(bool _bCheckable)
    // {
    //     setCheckable(_bCheckable);
    //     Control2VarPool();
    // } // qToolButton::SetCheckable


    // /*******************************************************************************
    // * qToolButton::IsCheckable
    // *******************************************************************************/
    // bool qToolButton::IsCheckable() const
    // {
    //     return isCheckable();
    // } // qToolButton::IsCheckable


    // /*******************************************************************************
    // * qToolButton::SetChecked
    // *******************************************************************************/
    // void qToolButton::SetChecked(bool _bChecked)
    // {
    //     setChecked(_bChecked);
    //     Control2VarPool();
    // } // qToolButton::SetChecked


    // /*******************************************************************************
    // * qToolButton::IsChecked
    // *******************************************************************************/
    // bool qToolButton::IsChecked() const
    // {
    //     return isChecked();
    // } // qToolButton::IsChecked


    // /*******************************************************************************
    // * qToolButton::SetEnabledChecked
    // *******************************************************************************/
    // void qToolButton::SetEnabledChecked(bool    _bEnabled,
    //                                    bool    _bChecked)
    // {
    //     SetEnabled(_bEnabled);
    //     SetChecked(_bChecked);
    // } // qToolButton::SetEnabledChecked


    // /*******************************************************************************
    // * qToolButton::SetVisible
    // *******************************************************************************/
    // void qToolButton::SetVisible(bool _bVisible)
    // {
    //     aSysWindow<QToolButton>::SetVisible(_bVisible);
    //     Control2VarPool();
    // } // qToolButton::SetVisible


    // /*******************************************************************************
    // * qToolButton::IsVisible
    // *******************************************************************************/
    // bool qToolButton::IsVisible() const
    // {
    //     return aSysWindow<QToolButton>::IsVisible();
    // } // qToolButton::IsVisible
