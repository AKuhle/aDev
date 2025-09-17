/*******************************************************************************
* include
*******************************************************************************/
#include "ui_DlgDevice.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "DlgDevice.h"

using namespace std;


/*******************************************************************************
* DlgDevice::DlgDevice
*******************************************************************************/
DlgDevice::DlgDevice(MainWin  *_pMainWin,
                     Device   *_pDevice)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgDevice),
  m_pMainWin(_pMainWin),
  m_pDevice(_pDevice)
{
    m_pUi->setupUi(this);
} // DlgDevice::DlgDevice


/*******************************************************************************
* DlgDevice::~DlgDevice
*******************************************************************************/
DlgDevice::~DlgDevice()
{
    delete m_pUi;
} // DlgDevice::~DlgDevice


/*******************************************************************************
* DlgDevice::accept
*******************************************************************************/
void DlgDevice::accept()
{
    if (!m_pDevice)
    {
        // add a new device
        m_pMainWin->addDevice(aString::fromQString(m_pUi->m_pDeviceName->text()));
    }
    else
    {
        // modify the existing device
        // m_pController->setName(aString::fromQString(m_pUi->m_pControllerName->text()));
        // m_pController->setIpAdr(aString::fromQString(m_pUi->m_pControllerAddress->text()));
    }

    m_pMainWin->updateAll();

    QDialog::accept();
} // DlgDevice::accept


/*******************************************************************************
* DlgDevice::reject
*******************************************************************************/
void DlgDevice::reject()
{
    QDialog::reject();
} // DlgDevice::reject
