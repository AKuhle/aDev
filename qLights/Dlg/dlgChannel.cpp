/*******************************************************************************
* include
*******************************************************************************/
#include "ui_DlgChannel.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgChannel.h"
#include "controller.h"
#include "channel.h"
#include "dlgDevice.h"

using namespace std;


/*******************************************************************************
* DlgChannel::DlgChannel
*******************************************************************************/
DlgChannel::DlgChannel(DlgDevice                *_pDlgDevice,
                       const vector<QString>    &_lstChannelIcon)
: QDialog(_pDlgDevice),
  m_pUi(new Ui::DlgChannel),
  m_pDlgDevice(_pDlgDevice)
{
    m_pUi->setupUi(this);

    // set icon size and centered
    m_pUi->m_pChannelIcon->setIconSize(QSize(36, 36));
    m_pUi->m_pChannelIcon->setStyleSheet("QComboBox QAbstractItemView::item { qproperty-textAlignment: 'AlignCenter'; }");

    // fill the combo box with the channel icons
    for (auto &rscName : _lstChannelIcon)
    {
        QPixmap pixmap(rscName);
        QIcon icon(pixmap.scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        m_pUi->m_pChannelIcon->addItem(icon, "", QVariant(rscName));
        //m_pUi->m_pChannelIcon->setItemData(m_pUi->m_pChannelIcon->count()-1, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
} // DlgChannel::DlgChannel


/*******************************************************************************
* DlgChannel::~DlgChannel
*******************************************************************************/
DlgChannel::~DlgChannel()
{
    delete m_pUi;
} // DlgChannel::~DlgChannel


/*******************************************************************************
* DlgChannel::accept
*******************************************************************************/
void DlgChannel::accept()
{
    s32     s32ChannelNr    = m_pUi->m_pChannelNr->text().toInt();
    QString s32ChannelName  = m_pUi->m_pChannelName->text();
    bool    bBrigthness     = m_pUi->m_pChannelBrightness->isChecked();

    int     index = m_pUi->m_pChannelIcon->currentIndex();
    QString sPixmap = m_pUi->m_pChannelIcon->itemData(index).toString();

    m_pDlgDevice->addChannel(s32ChannelNr, s32ChannelName, sPixmap, bBrigthness);

    QDialog::accept();
} // DlgChannel::accept


/*******************************************************************************
* DlgChannel::reject
*******************************************************************************/
void DlgChannel::reject()
{
    QDialog::reject();
} // DlgChannel::reject
