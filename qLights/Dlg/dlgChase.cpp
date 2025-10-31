/*******************************************************************************
* include
*******************************************************************************/
#include <QCheckBox>

#include "ui_DlgChase.h"

#include "aFrame_def.h"
#include "qLights_def.h"

#include "mainWin.h"
#include "dlgChase.h"
#include "chase.h"
#include "chaseStep.h"

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
* DlgChase::name
*******************************************************************************/
QString DlgChase::name() const
{
    return m_pUi->m_pChaseName->text();
} // DlgChase::name


/*******************************************************************************
* DlgChase::chaseSteps
*******************************************************************************/
vector<shared_ptr<ChaseStep>> DlgChase::chaseSteps() const
{
    QTableWidget                    *pT         = m_pUi->m_pChaseTable;
    int                             iRowCount   = pT->rowCount();

    vector<shared_ptr<ChaseStep>>   vSteps;

    // iterate over all chase steps
    for (int row = 0; row < iRowCount; ++row)
    {
        // duration for his step
        u32 u32Duration_ms = pT->item(row, 1)->text().toInt();

        // start scene for this step
        QString sStart = pT->item(row, 0)->text();
        shared_ptr<Scene> pStartScene = MainWin::instance()->findScene(sStart);

        QString sEnd = (row < iRowCount-1)?    pT->item(row, 0)->text() : "";
        shared_ptr<Scene> pEndScene = MainWin::instance()->findScene(sEnd);

        shared_ptr<ChaseStep> pStep = make_shared<ChaseStep> (pStartScene, pEndScene, u32Duration_ms);

        vSteps.push_back(pStep);
    }

    return vSteps;
} // DlgChase::chaseSteps


/*******************************************************************************
* DlgChase::setCtrls
*******************************************************************************/
void DlgChase::setCtrls(const shared_ptr<Chase> _pChase)
{
    if (_pChase)
    {
        m_pUi->m_pChaseName->setText(_pChase->name());
    }
} // DlgChase::setCtrls


/*******************************************************************************
* DlgChase::accept
*******************************************************************************/
void DlgChase::accept()
{
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
