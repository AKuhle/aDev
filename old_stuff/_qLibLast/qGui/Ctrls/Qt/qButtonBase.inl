/*******************************************************************************
* \file qButtonBase.cpp
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
#include "qButtonBase.h"


namespace qLib
{
    /*******************************************************************************
    * qButtonBase<T>::qButtonBase
    *******************************************************************************/
    template <class T>
    qButtonBase<T>::qButtonBase(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<T>(_pParent)
    {
    } // qButtonBase<T>::qButtonBase


    /*******************************************************************************
    * qButtonBase<T>::~qButtonBase
    *******************************************************************************/
    template <class T>
    qButtonBase<T>::~qButtonBase()
    {
    } // qButtonBase<T>::~qButtonBase


    /*******************************************************************************
    * qButtonBase<T>::SetCtrlEnabled
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::SetCtrlEnabled(bool _bEnabled)
    {
        this->setEnabled(_bEnabled);
    } // qButtonBase<T>::SetCtrlEnabled


    /*******************************************************************************
    * qButtonBase<T>::IsCtrlEnabled
    *******************************************************************************/
    template <class T>
    bool qButtonBase<T>::IsCtrlEnabled() const
    {
        return this->isEnabled();
    } // qButtonBase<T>::IsCtrlEnabled


    /*******************************************************************************
    * qButtonBase<T>::SetCtrlCheckable
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::SetCtrlCheckable(bool _bCheckable)
    {
        this->setCheckable(_bCheckable);
    } // qButtonBase<T>::SetCtrlCheckable


    /*******************************************************************************
    * qButtonBase<T>::IsCtrlCheckable
    *******************************************************************************/
    template <class T>
    bool qButtonBase<T>::IsCtrlCheckable() const
    {
        return this->isCheckable();
    } // qButtonBase<T>::IsCtrlCheckable


    /*******************************************************************************
    * qButtonBase<T>::SetCtrlChecked
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::SetCtrlChecked(bool _bChecked)
    {
        if (IsCtrlCheckable())
        {
            this->setChecked(_bChecked);
        }
    } // qButtonBase<T>::SetCtrlChecked


    /*******************************************************************************
    * qButtonBase<T>::IsCtrlChecked
    *******************************************************************************/
    template <class T>
    bool qButtonBase<T>::IsCtrlChecked() const
    {
        return this->isChecked();
    } // qButtonBase<T>::IsCtrlChecked


    /*******************************************************************************
    * qButtonBase<T>::SetCtrlEnabledChecked
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::SetCtrlEnabledChecked(bool _bEnabled,
                                               bool _bChecked)
    {
        SetCtrlEnabled(_bEnabled);
        SetCtrlChecked(_bChecked);
    } // qButtonBase<T>::SetCtrlEnabledChecked


    /*******************************************************************************
    * qButtonBase<T>::VarPool2Control
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::VarPool2Control()
    {
        CHECK_PRE_CONDITION_VOID(VarPool() != nullptr);

        SetCtrlChecked(VarPool()->GetBool(CtrlId()));
    } // qButtonBase<T>::VarPool2Control


    /*******************************************************************************
    * qButtonBase<T>::Control2VarPool
    *******************************************************************************/
    template <class T>
    void qButtonBase<T>::Control2VarPool()
    {
        CHECK_PRE_CONDITION_VOID(VarPool() != nullptr);

        VarPool()->SetBoolValue(CtrlId(), IsCtrlChecked());
    } // qButtonBase<T>::Control2VarPool

} // namespace qLib

#endif // _USE_QT_
