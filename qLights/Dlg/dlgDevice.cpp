/*******************************************************************************
* include
*******************************************************************************/
#include <QCheckBox>

#include "ui_DlgDevice.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgDevice.h"
#include "dlgChannel.h"
#include "channel.h"

using namespace std;


/*******************************************************************************
* DlgDevice::DlgDevice
*******************************************************************************/
DlgDevice::DlgDevice(MainWin                *_pMainWin,
                     const vector<QPixmap>  &_lstChannelIcon,
                     Device                 *_pDevice)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgDevice),
  m_pMainWin(_pMainWin),
  m_pDevice(_pDevice),
  m_lstChannelIcon(_lstChannelIcon)
{
    m_pUi->setupUi(this);

    connect(m_pUi->m_pBtnAddChannel, &QToolButton::clicked, this, &DlgDevice::onAddChannel);
} // DlgDevice::DlgDevice


/*******************************************************************************
* DlgDevice::~DlgDevice
*******************************************************************************/
DlgDevice::~DlgDevice()
{
    delete m_pUi;
} // DlgDevice::~DlgDevice


/*******************************************************************************
* DlgDevice::addChannel
*******************************************************************************/
void DlgDevice::addChannel(s32              _s32ChannelNr,
                           const QString    &_s32ChannelName,
                           const QPixmap    &_pixmap,
                           bool             _bBrigthness)
{
    QTableWidget    *pT         = m_pUi->m_pChannelTable;
    int             iNewRow     = pT->rowCount();
    QCheckBox       *pBright    = new QCheckBox;

    // append a row
    pT->insertRow(iNewRow);

    // set the nr
    pT->setItem(iNewRow, 0, new QTableWidgetItem(QString::number(_s32ChannelNr)));

    // set the name
    pT->setItem(iNewRow, 1, new QTableWidgetItem(_s32ChannelName));

    // set the icon
    QTableWidgetItem *pItem = new QTableWidgetItem;
    pItem->setIcon(QIcon(_pixmap));
    pT->setItem(iNewRow, 2, pItem);

    // set the brightness checkbox
    pBright->setChecked(_bBrigthness);
    pT->setCellWidget(iNewRow, 3, pBright);


    //m_pChannelTable
} // DlgDevice::addChannel


/*******************************************************************************
* DlgDevice::accept
*******************************************************************************/
void DlgDevice::accept()
{
    if (!m_pDevice)
    {
        // add a new device
        m_pMainWin->addDevice(m_pUi->m_pDeviceName->text());
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


/*******************************************************************************
* DlgDevice::onAddChannel
*******************************************************************************/
void DlgDevice::onAddChannel(bool /*_bChecked*/)
{
    DlgChannel dlg(this, m_lstChannelIcon);

    dlg.exec();
} // DlgDevice::onAddChannel
