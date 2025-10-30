/*******************************************************************************
* include
*******************************************************************************/
#include "ui_DlgFixture.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgFixture.h"
#include "device.h"
#include "fixture.h"

using namespace std;


/*******************************************************************************
* DlgFixture::DlgFixture
*******************************************************************************/
DlgFixture::DlgFixture(QWidget                      *_pParent,
                       list<shared_ptr<Device>>     _lstDevice,
                       list<shared_ptr<Universe>>   _lstUniverse,
                       shared_ptr<Fixture>          _pFixture)
: QDialog(_pParent),
  m_pUi(new Ui::DlgFixture),
  m_lstDevice(_lstDevice),
  m_lstUniverse(_lstUniverse),
  m_pFixture(_pFixture)
{
    m_pUi->setupUi(this);

    // set icon size for the device combo box
    m_pUi->m_pDevice->setIconSize(QSize(36, 36));

    // fill the combo box with the device icons
    for (auto pDevice : m_lstDevice)
    {
        const QString   &name   = pDevice->name();
        const QPixmap   &pixmap = pDevice->pixmap();

        QIcon icon(pixmap.scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        m_pUi->m_pDevice->addItem(icon, name, QVariant(name));
        //m_pUi->m_pChannelIcon->setItemData(m_pUi->m_pChannelIcon->count()-1, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    // fill the combo box with the universe names
    for (auto pUniverse : m_lstUniverse)
    {
        const QString   &name   = pUniverse->name();

        m_pUi->m_pUniverse->addItem(name);
    }

    // set the cobtrols for the given fixture
    setCtrls(_pFixture);
} // DlgFixture::DlgFixture


/*******************************************************************************
* DlgFixture::~DlgFixture
*************************************s******************************************/
DlgFixture::~DlgFixture()
{
    delete m_pUi;
} // DlgFixture::~DlgFixture


/*******************************************************************************
* DlgFixture::setCtrls
*******************************************************************************/
void DlgFixture::setCtrls(const shared_ptr<Fixture> _pFixture)
{
    if (_pFixture)
    {
        m_pUi->m_pFixtureName->setText(_pFixture->name());
        MainWin::selectComboBoxItem(m_pUi->m_pUniverse, _pFixture->universe()->name());
        m_pUi->m_pAdress->setValue(_pFixture->adress());
    }

//comboBox->addItem(QIcon("pfad/zum/bild.png"), "Text");
} // DlgFixture::setCtrls


/*******************************************************************************
* DlgFixture::accept
*******************************************************************************/
void DlgFixture::accept()
{
    QString sFixture    = m_pUi->m_pFixtureName->text();

    // get the device
    int                     index       = m_pUi->m_pDevice->currentIndex();
    int                     indexU      = m_pUi->m_pUniverse->currentIndex();

    QString                 sDevice     = m_pUi->m_pDevice->itemData(index).toString();
    shared_ptr<Device>      pDevice     = MainWin::instance()->findDevice(sDevice);

    QString                 sUniverse   = m_pUi->m_pUniverse->itemData(indexU).toString();
    shared_ptr<Universe>    pUniverse   = MainWin::instance()->findUniverse(sUniverse);

    s32                     s32Adress   = m_pUi->m_pAdress->value();

    if (!m_pFixture)
    {
        // add a new fixture
        MainWin::instance()->addFixture(sFixture, pDevice, pUniverse, s32Adress);
    }
    else
    {
        // modify the existing fixture
        m_pFixture->setName(sFixture);
        m_pFixture->setDevice(pDevice);
        m_pFixture->setAdress(s32Adress);
    }

    MainWin::instance()->updateAll();

    QDialog::accept();
} // DlgFixture::accept


/*******************************************************************************
* DlgFixture::reject
*******************************************************************************/
void DlgFixture::reject()
{
    QDialog::reject();
} // DlgFixture::reject
