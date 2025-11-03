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

    // disable enter for ok button
    QPushButton *pOkBtn = m_pUi->buttonBox->button(QDialogButtonBox::Ok);
    pOkBtn->setAutoDefault(false);
    pOkBtn->setDefault(false);
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
* DlgChase::isBlackStart
*******************************************************************************/
bool DlgChase::isBlackStart() const
{
    return m_pUi->m_pBlackStart->isChecked();
} // DlgChase::isBlackStart


/*******************************************************************************
* DlgChase::chaseSteps
*******************************************************************************/
vector<stChaseStep> DlgChase::chaseSteps() const
{
    QTableWidget            *pT         = m_pUi->m_pChaseTable;
    int                     iRowCount   = pT->rowCount();
    vector<stChaseStep>     vSteps;

    // iterate over all chase steps
    for (int row = 0; row < iRowCount; row++)
    {
        int u32Duration_ms = 0;

        // get the scene name
        QComboBox   *pCombo     = qobject_cast<QComboBox*>(pT->cellWidget(row, 0));
        QString     sSceneName  = (pCombo)?   pCombo->currentText() : "";

        // duration for his step
        QLineEdit *pLine = qobject_cast<QLineEdit*>(pT->cellWidget(row, 1));
        if (pLine)
        {
            u32Duration_ms = pLine->text().toInt();
        }

        // add the step to the vector
        vSteps.push_back (stChaseStep { sSceneName, static_cast<unsigned int> (u32Duration_ms) } );
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
        QTableWidget    *pTable = m_pUi->m_pChaseTable;
        vector<QString> vScenes = MainWin::instance()->getAllSceneNames();

        // set the chase name
        m_pUi->m_pChaseName->setText(_pChase->name());

        // set the black start flag
        m_pUi->m_pBlackStart->setChecked(_pChase->isBlackStart());

        // set the steps
        const vector<stChaseStep> &vSteps = _pChase->chaseSteps();


        // generate a line for each step
        for (const stChaseStep &step : vSteps)
        {
            QString sSceneName = step.sSceneName;
            u32     s32Duration = step.u32Duration_ms;
            int     iRowIdx = pTable->rowCount();

            // append a row
            pTable->insertRow(iRowIdx);

            // create and add the combo box
            QComboBox   *pCombo = new QComboBox();
            for (QString &sScene : vScenes)
            {
                pCombo->addItem(sScene);
            }
            int idx = pCombo->findText(sSceneName);
            if (idx != -1)
            {
                pCombo->setCurrentIndex(idx);
            }
            pTable->setCellWidget(iRowIdx, 0, pCombo);

            // create and add line edit
            QLineEdit *pLine = new QLineEdit();
            pLine->setValidator(new QIntValidator(pLine)); // Nur Ganzzahlen erlaubt
            pLine->setText(QString::number(s32Duration));
            pTable->setCellWidget(iRowIdx, 1, pLine);
        }
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

    // create the line edit
    QLineEdit *pLine = new QLineEdit();
    pLine->setValidator(new QIntValidator(pLine)); // Nur Ganzzahlen erlaubt
    pLine->setText(QString::number(0));                         // Initialwert setzen    //QLineEdit   *pLine = new QLineEdit();
    pT->setCellWidget(iNewRow, 1, pLine);
} // DlgChase::onAddScene


/*******************************************************************************
* DlgChase::onRemoveScene
*******************************************************************************/
void DlgChase::onRemoveScene(bool /*_bChecked*/)
{
    QTableWidget *pT = m_pUi->m_pChaseTable;

    s32 s32Row = pT->currentRow();

    // -1 => now row selected
    if (s32Row >= 0)
    {
        pT->removeRow(s32Row);
    }
} // DlgChase::onRemoveScene
