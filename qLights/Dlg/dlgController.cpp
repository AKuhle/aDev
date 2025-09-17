/*******************************************************************************
* include
*******************************************************************************/
#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgController.h"
#include "ui_dlgController.h"

using namespace std;


/*******************************************************************************
* DlgController::DlgController
*******************************************************************************/
DlgController::DlgController(MainWin    *_pMainWin,
                             Controller *_pController)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgController),
  m_pMainWin(_pMainWin),
  m_pController(_pController)
{
    m_pUi->setupUi(this);
} // DlgController::DlgController


/*******************************************************************************
* DlgController::~DlgController
*******************************************************************************/
DlgController::~DlgController()
{
    delete m_pUi;
} // DlgController::~DlgController


/*******************************************************************************
* DlgController::accept
*******************************************************************************/
void DlgController::accept()
{
    if (!m_pController)
    {
        // add a new controller
        m_pMainWin->addController(aString::fromQString(m_pUi->m_pControllerName->text()),
                                  aString::fromQString(m_pUi->m_pControllerAddress->text()));
    }
    else
    {
        // modify the existing controller
        m_pController->setName(aString::fromQString(m_pUi->m_pControllerName->text()));
        m_pController->setIpAdr(aString::fromQString(m_pUi->m_pControllerAddress->text()));
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
