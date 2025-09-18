/*******************************************************************************
* include
*******************************************************************************/
#include "ui_DlgFixture.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgFixture.h"

using namespace std;


/*******************************************************************************
* DlgFixture::DlgFixture
*******************************************************************************/
DlgFixture::DlgFixture(MainWin  *_pMainWin,
                       Fixture  *_pFixture)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgFixture),
  m_pMainWin(_pMainWin),
  m_pFixture(_pFixture)
{
    m_pUi->setupUi(this);
} // DlgFixture::DlgFixture


/*******************************************************************************
* DlgFixture::~DlgFixture
*******************************************************************************/
DlgFixture::~DlgFixture()
{
    delete m_pUi;
} // DlgFixture::~DlgFixture


/*******************************************************************************
* DlgFixture::accept
*******************************************************************************/
void DlgFixture::accept()
{
    if (!m_pFixture)
    {
        // add a new device
        m_pMainWin->addFixture(m_pUi->m_pFixtureName->text());
    }
    else
    {
        // modify the existing device
        // m_pController->setName(aString::fromQString(m_pUi->m_pControllerName->text()));
        // m_pController->setIpAdr(aString::fromQString(m_pUi->m_pControllerAddress->text()));
    }

    m_pMainWin->updateAll();

    QDialog::accept();
} // DlgFixture::accept


/*******************************************************************************
* DlgFixture::reject
*******************************************************************************/
void DlgFixture::reject()
{
    QDialog::reject();
} // DlgFixture::reject
