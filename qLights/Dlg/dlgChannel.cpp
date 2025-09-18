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
DlgChannel::DlgChannel(DlgDevice               *_pDlgDevice,
                       const aVector<QPixmap>  &_lstChannelIcon)
: QDialog(_pDlgDevice),
  m_pUi(new Ui::DlgChannel),
  m_pDlgDevice(_pDlgDevice)
{
    m_pUi->setupUi(this);

    // fill the combo box with the icons
    for (auto &pixmap : _lstChannelIcon)
    {
        m_pUi->m_pChannelIcon->addItem(QIcon(pixmap), "");
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
    aString s32ChannelName  = aString::fromQString(m_pUi->m_pChannelName->text());
    bool    bBrigthness     = m_pUi->m_pChannelBrightness->isChecked();

    int     index = m_pUi->m_pChannelIcon->currentIndex();
    QIcon   icon = m_pUi->m_pChannelIcon->itemIcon(index);
    QPixmap pixmap = icon.pixmap(48, 48); // Größe nach Bedarf wählen

    m_pDlgDevice->addChannel(s32ChannelNr, s32ChannelName, pixmap, bBrigthness);

    QDialog::accept();
} // DlgChannel::accept


/*******************************************************************************
* DlgChannel::reject
*******************************************************************************/
void DlgChannel::reject()
{
    QDialog::reject();
} // DlgChannel::reject
