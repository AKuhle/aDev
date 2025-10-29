/*******************************************************************************
* include
*******************************************************************************/
#include <QCheckBox>

#include "ui_DlgDevice.h"

#include "aFrame_def.h"
#include "qLights_def.h"

#include "mainWin.h"
#include "dlgDevice.h"
#include "dlgChannel.h"
#include "channel.h"

using namespace std;


/*******************************************************************************
* DlgDevice::DlgDevice
*******************************************************************************/
DlgDevice::DlgDevice(QWidget                *_pParent,
                     const vector<QString>  &_lstDeviceIconName,
                     const vector<QString>  &_lstChannelIcon,
                     shared_ptr<Device>     _pDevice)
: QDialog(_pParent),
  m_pUi(new Ui::DlgDevice),
  m_pDevice(_pDevice),
  m_lstDeviceIconName(_lstDeviceIconName),
  m_lstChannelIcon(_lstChannelIcon)
{
    m_pUi->setupUi(this);

    // set the background of the image
    QPalette palette = m_pUi->m_pImage->palette();
    palette.setColor(QPalette::Window, colDeviceImageBg);
    m_pUi->m_pImage->setAutoFillBackground(true);
    m_pUi->m_pImage->setPalette(palette);

    // set the cobtrols for the given device
    setCtrls(m_pDevice);

    // connect the add prev/next button
    connect(m_pUi->m_pPrev, &QToolButton::clicked, this, &DlgDevice::onPrevImage);
    connect(m_pUi->m_pNext, &QToolButton::clicked, this, &DlgDevice::onNextImage);

    // connect the add channel button
    connect(m_pUi->m_pBtnAddChannel, &QToolButton::clicked, this, &DlgDevice::onAddChannel);
    connect(m_pUi->m_pBtnRemoveChannel, &QToolButton::clicked, this, &DlgDevice::onRemoveChannel);
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
                           const QString    &_sPixmapName,
                           bool             _bBrigthness)
{
    QTableWidget    *pT         = m_pUi->m_pChannelTable;
    int             iNewRow     = pT->rowCount();

    // append a row
    pT->insertRow(iNewRow);

    // set the nr
    pT->setItem(iNewRow, 0, new QTableWidgetItem(QString::number(_s32ChannelNr)));

    // set the name
    pT->setItem(iNewRow, 1, new QTableWidgetItem(_s32ChannelName));

    // set the icon
    QTableWidgetItem *pItem = new QTableWidgetItem;
    pItem->setIcon(QIcon(QPixmap(_sPixmapName)));
    pItem->setTextAlignment(Qt::AlignHCenter);
    pItem->setData(Qt::UserRole, QVariant(_sPixmapName));
    pT->setItem(iNewRow, 2, pItem);

    // set the brightness checkbox
    QCheckBox *pBright = new QCheckBox;
    pBright->setChecked(_bBrigthness);
    pT->setCellWidget(iNewRow, 3, pBright);
} // DlgDevice::addChannel


/*******************************************************************************
* DlgDevice::setCtrls
*******************************************************************************/
void DlgDevice::setCtrls(const shared_ptr<Device> _pDevice)
{
    if (_pDevice)
    {
        const vector<shared_ptr<Channel>>   vChannel  = _pDevice->channel();
        QTableWidget                        *pT         = m_pUi->m_pChannelTable;

        // set the device name
        m_pUi->m_pDeviceName->setText(_pDevice->name());

        // set the device image
        setDeviceIcon(_pDevice->pixmapName());

        // empty the previous table
        pT->clearContents();

        // set the channel of the device
        for (auto pChannel : vChannel)
        {
            int             iNewRow     = pT->rowCount();

            // append a row
            pT->insertRow(iNewRow);

            // set the nr
            pT->setItem(iNewRow, 0, new QTableWidgetItem(QString::number(pChannel->nr())));

            // set the name
            pT->setItem(iNewRow, 1, new QTableWidgetItem(pChannel->name()));

            // set the icon
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setIcon(QIcon(pChannel->pixmap()));
            pItem->setTextAlignment(Qt::AlignHCenter);
            pItem->setData(Qt::UserRole, QVariant(pChannel->pixmapName()));
            pT->setItem(iNewRow, 2, pItem);

            // set the brightness checkbox
            QCheckBox *pBright = new QCheckBox;
            pBright->setChecked(pChannel->isBrightnessChannel());
            pT->setCellWidget(iNewRow, 3, pBright);
        }
    }
    else
    {
        // set the standard device image
        if (m_lstDeviceIconName.size() > 0)
        {
            setDeviceIcon(m_lstDeviceIconName.at(0));
        }
    }
} // DlgDevice::setCtrls


/*******************************************************************************
* DlgDevice::setDeviceIcon
*******************************************************************************/
void DlgDevice::setDeviceIcon(const QString &_path)
{
    QPixmap pm(_path);

    if (pm.isNull() && m_lstDeviceIconName.size() > 0)
    {
        pm.load(m_lstDeviceIconName.at(0));
    }

    if (!pm.isNull())
    {
        pm = pm.scaled(64, 64);
        m_pUi->m_pImage->setPixmap(pm);

        // set the ImageIdx
        for (u16 i= 0; i< m_lstDeviceIconName.size(); i++)
        {
            if (m_lstDeviceIconName.at(i) == _path)
            {
                m_s32ImageIdx = i;
                break;
            }
        }
    }

} // DlgDevice::setDeviceIcon


/*******************************************************************************
* DlgDevice::accept
*******************************************************************************/
void DlgDevice::accept()
{
    QTableWidget                    *pT         = m_pUi->m_pChannelTable;
    vector<shared_ptr<Channel>>     vChannel;

    // put the channels in a vector
    for (int row = 0; row < pT->rowCount(); ++row)
    {
        s32         s32ChannelNr    = pT->item(row, 0)->text().toInt();
        QString     s32ChannelName  = pT->item(row, 1)->text();

        QString     sPixmapName     = pT->item(row, 2)->data(Qt::UserRole).toString();

        QCheckBox   *pBright        = qobject_cast<QCheckBox*>(pT->cellWidget(row, 3));
        bool        bBrightness     = pBright->isChecked();

        vChannel.push_back(make_shared<Channel> (s32ChannelNr, s32ChannelName, sPixmapName, bBrightness));
    }

    if (!m_pDevice)
    {
        // add a new device
        MainWin::instance()->addDevice(m_pUi->m_pDeviceName->text(),
                                       m_lstDeviceIconName.at(m_s32ImageIdx),
                                       vChannel);
    }
    else
    {
        // set the device name
        m_pDevice->setName(m_pUi->m_pDeviceName->text());

        // set the device name
        m_pDevice->setPixmap(m_lstDeviceIconName.at(m_s32ImageIdx));

        m_pDevice->setChannel(vChannel);

        // modify the existing device
        // m_pController->setName(aString::fromQString(m_pUi->m_pControllerName->text()));
        // m_pController->setIpAdr(aString::fromQString(m_pUi->m_pControllerAddress->text()));
    }

    MainWin::instance()->updateAll();

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
* DlgDevice::onPrevImage
*******************************************************************************/
void DlgDevice::onPrevImage(bool /*_bChecked*/)
{
    s32     s32Size = m_lstDeviceIconName.size();

    CHECK_PRE_CONDITION_VOID (s32Size > 0);

    // jump to next image, 0 if end is reached
    m_s32ImageIdx = (m_s32ImageIdx == 0)?   (s32Size - 1) : min(s32Size - 1, m_s32ImageIdx - 1);

    setDeviceIcon(m_lstDeviceIconName.at(m_s32ImageIdx));
} // DlgDevice::onPrevImage


/*******************************************************************************
* DlgDevice::onNextImage
*******************************************************************************/
void DlgDevice::onNextImage(bool /*_bChecked*/)
{
    s32     s32Size = m_lstDeviceIconName.size();

    CHECK_PRE_CONDITION_VOID (s32Size > 0);

    // jump to next image, 0 if end is reached
    m_s32ImageIdx = (m_s32ImageIdx >= s32Size - 1)?   0 : m_s32ImageIdx + 1;

    setDeviceIcon(m_lstDeviceIconName.at(m_s32ImageIdx));

} // DlgDevice::onNextImage


/*******************************************************************************
* DlgDevice::onAddChannel
*******************************************************************************/
void DlgDevice::onAddChannel(bool /*_bChecked*/)
{
    DlgChannel dlg(this, m_lstChannelIcon);

    dlg.exec();
} // DlgDevice::onAddChannel


/*******************************************************************************
* DlgDevice::onRemoveChannel
*******************************************************************************/
void DlgDevice::onRemoveChannel(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pChannelTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        pT->removeRow(s32Row);
    }
} // DlgDevice::onRemoveChannel
