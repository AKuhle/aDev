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

    //connect(m_pUi->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(m_pUi->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
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
    m_pMainWin->addController(aString::fromQString(m_pUi->m_pName->text()),
                              aString::fromQString(m_pUi->m_pAddress->text()));

    m_pMainWin->updateControllerPanel();

    QDialog::accept();
} // DlgController::accept


/*******************************************************************************
* DlgController::reject
*******************************************************************************/
void DlgController::reject()
{
    QDialog::reject();
} // DlgController::reject
