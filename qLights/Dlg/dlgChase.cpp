/*******************************************************************************
* include
*******************************************************************************/
#include <QCheckBox>

#include "ui_DlgChase.h"

#include "aFrame_def.h"
#include "qLights_def.h"

#include "mainWin.h"
#include "dlgChase.h"

using namespace std;


/*******************************************************************************
* DlgChase::DlgChase
*******************************************************************************/
DlgChase::DlgChase(QWidget              *_pParent,
                   shared_ptr<Chase>    _pChase)
: QDialog(_pParent),
  m_pUi(new Ui::DlgChase),
  m_pChase(_pChase)
{
    m_pUi->setupUi(this);

    // set the controls for the given device
    setCtrls(m_pChase);

    // connect the add channel button
    connect(m_pUi->m_pBtnAddScene, &QToolButton::clicked, this, &DlgChase::onAddScene);
    connect(m_pUi->m_pBtnRemoveScene, &QToolButton::clicked, this, &DlgChase::onRemoveScene);
} // DlgChase::DlgChase


/*******************************************************************************
* DlgChase::~DlgChase
*******************************************************************************/
DlgChase::~DlgChase()
{
    delete m_pUi;
} // DlgChase::~DlgChase


/*******************************************************************************
* DlgChase::setCtrls
*******************************************************************************/
void DlgChase::setCtrls(const shared_ptr<Chase> _pChase)
{
    if (_pChase)
    {
        // const vector<shared_ptr<Channel>>   vChannel  = _pDevice->channel();
        // QTableWidget                        *pT         = m_pUi->m_pChannelTable;

        // // set the device name
        // m_pUi->m_pDeviceName->setText(_pDevice->name());

        // // set the device image
        // setDeviceIcon(_pDevice->pixmapName());

        // // empty the previous table
        // pT->clearContents();

        // // set the channel of the device
        // for (auto pChannel : vChannel)
        // {
        //     int             iNewRow     = pT->rowCount();

        //     // append a row
        //     pT->insertRow(iNewRow);

        //     // set the nr
        //     pT->setItem(iNewRow, 0, new QTableWidgetItem(QString::number(pChannel->nr())));

        //     // set the name
        //     pT->setItem(iNewRow, 1, new QTableWidgetItem(pChannel->name()));

        //     // set the icon
        //     QTableWidgetItem *pItem = new QTableWidgetItem;
        //     pItem->setIcon(QIcon(pChannel->pixmap()));
        //     pItem->setTextAlignment(Qt::AlignHCenter);
        //     pItem->setData(Qt::UserRole, QVariant(pChannel->pixmapName()));
        //     pT->setItem(iNewRow, 2, pItem);

        //     // set the brightness checkbox
        //     QCheckBox *pBright = new QCheckBox;
        //     pBright->setChecked(pChannel->isBrightnessChannel());
        //     pT->setCellWidget(iNewRow, 3, pBright);
        // }
    }
} // DlgChase::setCtrls


/*******************************************************************************
* DlgChase::accept
*******************************************************************************/
void DlgChase::accept()
{
    // QTableWidget                    *pT         = m_pUi->m_pChannelTable;
    // vector<shared_ptr<Channel>>     vChannel;

    // // put the channels in a vector
    // for (int row = 0; row < pT->rowCount(); ++row)
    // {
    //     s32         s32ChannelNr    = pT->item(row, 0)->text().toInt();
    //     QString     s32ChannelName  = pT->item(row, 1)->text();

    //     QString     sPixmapName     = pT->item(row, 2)->data(Qt::UserRole).toString();

    //     QCheckBox   *pBright        = qobject_cast<QCheckBox*>(pT->cellWidget(row, 3));
    //     bool        bBrightness     = pBright->isChecked();

    //     vChannel.push_back(make_shared<Channel> (s32ChannelNr, s32ChannelName, sPixmapName, bBrightness));
    // }

    // if (!m_pDevice)
    // {
    //     // add a new device
    //     MainWin::instance()->addDevice(m_pUi->m_pDeviceName->text(),
    //                                    m_lstDeviceIconName.at(m_s32ImageIdx),
    //                                    vChannel);
    // }
    // else
    // {
    //     // set the device name
    //     m_pDevice->setName(m_pUi->m_pDeviceName->text());

    //     // set the device name
    //     m_pDevice->setPixmap(m_lstDeviceIconName.at(m_s32ImageIdx));

    //     m_pDevice->setChannel(vChannel);

    //     // modify the existing device
    //     // m_pController->setName(aString::fromQString(m_pUi->m_pControllerName->text()));
    //     // m_pController->setIpAdr(aString::fromQString(m_pUi->m_pControllerAddress->text()));
    // }

    // MainWin::instance()->updateAll();

    QDialog::accept();
} // DlgChase::accept


/*******************************************************************************
* DlgChase::reject
*******************************************************************************/
void DlgChase::reject()
{
    QDialog::reject();
} // DlgChase::reject


/*******************************************************************************
* DlgChase::onAddScene
*******************************************************************************/
void DlgChase::onAddScene(bool /*_bChecked*/)
{
    QTableWidget    *pT         = m_pUi->m_pChaseTable;
    int             iNewRow     = pT->rowCount();

    // append a row
    pT->insertRow(iNewRow);

    // create the combo box
    QComboBox   *pCombo = new QComboBox();

    // add all scene names
    vector<QString> vScenes = MainWin::instance()->getAllSceneNames();
    for (QString &sScene : vScenes)
    {
        pCombo->addItem(sScene);
    }
    pT->setCellWidget(iNewRow, 0, pCombo);

} // DlgChase::onAddScene


/*******************************************************************************
* DlgChase::onRemoveScene
*******************************************************************************/
void DlgChase::onRemoveScene(bool /*_bChecked*/)
{
    // QTableWidget *pT = m_pUi->m_pChannelTable;

    // s32 s32Row = pT->currentRow();

    // // -1 => now row selected
    // if (s32Row >= 0)
    // {
    //     pT->removeRow(s32Row);
    // }
} // DlgChase::onRemoveScene
