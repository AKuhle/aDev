/*******************************************************************************
* include
*******************************************************************************/
#include "ui_dlgScene.h"

#include "aFrame_def.h"
#include "sceneButton.h"
#include "scene.h"

#include "mainWin.h"
#include "dlgScene.h"

using namespace std;


/*******************************************************************************
* DlgScene::DlgScene
*******************************************************************************/
DlgScene::DlgScene(SceneButton          *_pParent,
                   shared_ptr<Scene>    _pScene)
: QDialog(_pParent),
  m_pUi(new Ui::DlgScene)
{
    m_pUi->setupUi(this);

    // set the icon size in the tables
    m_pUi->m_pFixtureTable->setIconSize(QSize(64, 64)); // set the icon size for all cells

    // initialize the ctrls
    setCtrls(_pScene);

    // connect the add/remove fixture button
    connect(m_pUi->m_pBtnAddFixture, &QToolButton::clicked, this, &DlgScene::onAddFixture);
    connect(m_pUi->m_pBtnRemoveFixture, &QToolButton::clicked, this, &DlgScene::onRemoveFixture);
} // DlgScene::DlgScene


/*******************************************************************************
* DlgScene::~DlgScene
*******************************************************************************/
DlgScene::~DlgScene()
{
    delete m_pUi;
} // DlgScene::~DlgScene


/*******************************************************************************
* DlgScene::name
*******************************************************************************/
QString DlgScene::name() const
{
    return m_pUi->m_pSceneName->text();
} // DlgScene::name


/*******************************************************************************
* DlgScene::fixtureNames
*******************************************************************************/
vector<QString> DlgScene::fixtureNames() const
{
    QTableWidget    *pT         = m_pUi->m_pFixtureTable;
    int             iRowCount   = pT->rowCount();
    vector<QString> vFix;

    // iterate over all chase steps
    for (int row = 0; row < iRowCount; row++)
    {
        // get the scene name
        QComboBox   *pCombo     = qobject_cast<QComboBox*>(pT->cellWidget(row, 1));
        QString     sFixName    = (pCombo)?   pCombo->currentText() : "";

        // add the step to the vector
        vFix.push_back(sFixName);
    }

    return vFix;
} // DlgScene::fixtureNames


/*******************************************************************************
* DlgScene::isBlackStart
*******************************************************************************/
bool DlgScene::isBlackStart() const
{
    return m_pUi->m_pBlackStart->isChecked();
} // DlgScene::isBlackStart


/*******************************************************************************
* DlgScene::setCtrls
*******************************************************************************/
void DlgScene::setCtrls(const shared_ptr<Scene> _pScene)
{
    // set the scene name
    if (_pScene)
    {
        QTableWidget *pTable = m_pUi->m_pFixtureTable;

        m_pUi->m_pSceneName->setText(_pScene->name());

        // set the black start flag
        m_pUi->m_pBlackStart->setChecked(_pScene->isBlackStart());

        // fill the fixture table
        const vector<shared_ptr<Fixture>> &vFixtures = _pScene->fixtures();
        for (shared_ptr<Fixture> pFix : vFixtures)
        {
            QComboBox   *pCombo = new QComboBox();
            int         iRowIdx = pTable->rowCount();

            pTable->insertRow(iRowIdx);

            // add all fixture names to the combo box
            for (const shared_ptr<Fixture> &pAllFix : vFixtures)
            {
                pCombo->addItem(pAllFix->name());
            }

            int idx = pCombo->findText(pFix->name());
            if (idx != -1)
            {
                pCombo->setCurrentIndex(idx);
            }
        }
    }
} // DlgScene::setCtrls


/*******************************************************************************
* DlgScene::onAddFixture
*******************************************************************************/
void DlgScene::onAddFixture(bool /*_bChecked*/)
{
    QTableWidget                    *pT             = m_pUi->m_pFixtureTable;
    const list<shared_ptr<Fixture>> &lstFixtures    = MainWin::instance()->getAllFixtures();
    int                             iNewRow         = pT->rowCount();

    // append a row
    pT->insertRow(iNewRow);

    // set the row size to 64
    pT->setRowHeight(iNewRow, 64);

    // create the combo box
    QComboBox   *pCombo = new QComboBox();
    connect(pCombo, QOverload<int>::of(&QComboBox::activated),
            this, &DlgScene::onComboChanged);

    // add all fixture names
    for (const shared_ptr<Fixture> &pFix : lstFixtures)
    {
        pCombo->addItem(pFix->name());
    }

    pT->setCellWidget(iNewRow, 1, pCombo);

    // update the fixture icon
    updateFixtureIcon(iNewRow);

} // DlgScene::onAddFixture


/*******************************************************************************
* DlgScene::onRemoveFixture
*******************************************************************************/
void DlgScene::onRemoveFixture(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pFixtureTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        pT->removeRow(s32Row);
    }
} // DlgScene::onRemoveFixture


/*******************************************************************************
* DlgScene::onComboChanged
*******************************************************************************/
void DlgScene::onComboChanged(int /*_iIdx*/)
{
    QTableWidget *pT = m_pUi->m_pFixtureTable;

    s32 s32Row = pT->currentRow();

    updateFixtureIcon(s32Row);
} // DlgScene::onComboChanged


/*******************************************************************************
* DlgScene::updateFixtureIcon
*******************************************************************************/
void DlgScene::updateFixtureIcon(int    _iRow)
{
    QTableWidget *pT = m_pUi->m_pFixtureTable;

    // get the scene name
    QComboBox           *pCombo     = qobject_cast<QComboBox*>(pT->cellWidget(_iRow, 1));
    QString             sFixName    = (pCombo)?   pCombo->currentText() : "";
    shared_ptr<Fixture> pFix        = MainWin::instance()->findFixture(sFixName);

    if (pFix)
    {
        shared_ptr<Device> pDev = pFix->device();

        if (pDev)
        {
            // device image
            const QPixmap &pix = pDev->pixmap();
            if (!pix.isNull())
            {
                QTableWidgetItem    *pItem = new QTableWidgetItem();
                pItem->setIcon(QIcon(pix));

                pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);
                pT->setItem(_iRow, 0, pItem);
            }
        }
    }
} // DlgScene::updateFixtureIcon


/*******************************************************************************
* DlgScene::accept
*******************************************************************************/
void DlgScene::accept()
{
    QDialog::accept();
} // DlgScene::accept


/*******************************************************************************
* DlgScene::reject
*******************************************************************************/
void DlgScene::reject()
{
    QDialog::reject();
} // DlgScene::reject
