/*******************************************************************************
* include
*******************************************************************************/
#include "ui_dlgController.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgController.h"

using namespace std;


/*******************************************************************************
* DlgController::DlgController
*******************************************************************************/
DlgController::DlgController(MainWin                *_pMainWin,
                             shared_ptr<Controller> _pController)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgController),
  m_pMainWin(_pMainWin),
  m_pController(_pController)
{
    m_pUi->setupUi(this);

    if (m_pController)
    {
        setCtrls(m_pController);
    }
} // DlgController::DlgController


/*******************************************************************************
* DlgController::~DlgController
*******************************************************************************/
DlgController::~DlgController()
{
    delete m_pUi;
} // DlgController::~DlgController


/*******************************************************************************
* DlgController::setCtrls
*******************************************************************************/
void DlgController::setCtrls(shared_ptr<Controller> _pController)
{
    if (_pController)
    {
        m_pUi->m_pControllerName->setText(_pController->name());
        m_pUi->m_pControllerAddress->setText(_pController->ipAdr());
    }
} // DlgController::setCtrls


/*******************************************************************************
* DlgController::readCtrls
*******************************************************************************/
void DlgController::readCtrls(shared_ptr<Controller> _pController)
{
    if (_pController)
    {
        _pController->setName(m_pUi->m_pControllerName->text());
        _pController->setIpAdr(m_pUi->m_pControllerAddress->text());
    }
} // DlgController::readCtrls


/*******************************************************************************
* DlgController::accept
*******************************************************************************/
void DlgController::accept()
{
    if (!m_pController)
    {
        // add a new controller
        m_pMainWin->addController(m_pUi->m_pControllerName->text(),
                                  m_pUi->m_pControllerAddress->text());
    }
    else
    {
        // modify the existing controller
        readCtrls(m_pController);
    }

    m_pMainWin->updateAll();

    QDialog::accept();
} // DlgController::accept


/*******************************************************************************
* DlgController::reject
*******************************************************************************/
void DlgController::reject()
{
    QDialog::reject();
} // DlgController::reject
