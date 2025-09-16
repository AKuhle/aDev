/*******************************************************************************
* include
*******************************************************************************/
#include "aFrame_def.h"

#include "dlgController.h"
#include "ui_dlgController.h"

using namespace std;


/*******************************************************************************
* DlgController::DlgController
*******************************************************************************/
DlgController::DlgController(QWidget *parent) :
QDialog(parent),
m_pUi(new Ui::DlgController)
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
    QDialog::accept();
} // DlgController::accept


/*******************************************************************************
* DlgController::reject
*******************************************************************************/
void DlgController::reject()
{
    QDialog::reject();
} // DlgController::reject
