#include "dlgAddBank.h"
#include "ui_dlgAddBank.h"


/*******************************************************************************
* DlgAddBank::DlgAddBank
*******************************************************************************/
DlgAddBank::DlgAddBank(QWidget     *_pParent,
                       aString     &_sBankName)
: aDialog(_pParent),
  m_sBankName(_sBankName)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::DlgAddBank;
        m_pUi->setupUi(this);
    #endif
} // DlgAddBank::DlgAddBank


/*******************************************************************************
* DlgAddBank::~DlgAddBank
*******************************************************************************/
DlgAddBank::~DlgAddBank()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // DlgAddBank::~DlgAddBank


/*******************************************************************************
* DlgAddBank::onCreateWin
*******************************************************************************/
bool DlgAddBank::onCreateWin()
{
    setWinTitle("Add Bank");

    return true;
} // DlgAddBank::onCreateWin


/*******************************************************************************
* DlgAddBank::onAccepted
*******************************************************************************/
void DlgAddBank::onAccepted()
{
    m_sBankName = m_pUi->m_pBankName->editText();
} // DlgAddBank::onAccepted


/*******************************************************************************
* DlgAddBank::onRegisterCtrl
*******************************************************************************/
void DlgAddBank::onRegisterCtrl()
{
    //registerCtrl(m_pUi->m)
} // DlgAddBank::onRegisterCtrl


/*******************************************************************************
* DlgAddBank::onUpdateCtrl
*******************************************************************************/
void DlgAddBank::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
} // DlgAddBank::onUpdateCtrl
