/*******************************************************************************
* include
*******************************************************************************/
#include "ui_DlgUniverse.h"

#include "aFrame_def.h"

#include "mainWin.h"
#include "dlgUniverse.h"
#include "controller.h"

using namespace std;


/*******************************************************************************
* DlgUniverse::DlgUniverse
*******************************************************************************/
DlgUniverse::DlgUniverse(MainWin                            *_pMainWin,
                         const list<shared_ptr<Controller>> &_lstController,
                         shared_ptr<Universe>               _pUniverse)
: QDialog(_pMainWin),
  m_pUi(new Ui::DlgUniverse),
  m_pMainWin(_pMainWin),
  m_pUniverse(_pUniverse)
{
    m_pUi->setupUi(this);

    // fill the combo box with the controllers
    m_pUi->m_pUniverseController->addItem("None");
    for (auto &pController : _lstController)
    {
        m_pUi->m_pUniverseController->addItem(pController->name());
    }

    if (m_pUniverse)
    {
        setCtrls(m_pUniverse);
    }
} // DlgUniverse::DlgUniverse


/*******************************************************************************
* DlgUniverse::~DlgUniverse
*******************************************************************************/
DlgUniverse::~DlgUniverse()
{
    delete m_pUi;
} // DlgUniverse::~DlgUniverse


/*******************************************************************************
* DlgUniverse::setCtrls
*******************************************************************************/
void DlgUniverse::setCtrls(shared_ptr<Universe> _pUniverse)
{
    if (_pUniverse)
    {
        m_pUi->m_pUniverseName->setText(_pController->name());
        m_pUi->m_pControllerAddress->setText(_pController->ipAdr());
    }
} // DlgUniverse::setCtrls


/*******************************************************************************
* DlgUniverse::readCtrls
*******************************************************************************/
void DlgUniverse::readCtrls(shared_ptr<Universe> _pUniverse)
{
    if (_pUniverse)
    {
        // set the universe name
        _pUniverse->setName(m_pUi->m_pUniverseName->text());

        // set the universe
        QString sCtrkName = _pUniverse->setController(m_pUi->m_pUniverseController->currentText());

        // set the id
        _pUniverse->setId(m_pUi->m_pUniverseId->text().toInt());
    }
} // DlgUniverse::readCtrls


/*******************************************************************************
* DlgUniverse::accept
*******************************************************************************/
void DlgUniverse::accept()
{
    if (!m_pUniverse)
    {
        // add a new universe
        m_pMainWin->addUniverse(m_pUi->m_pUniverseName->text(),
                                m_pUi->m_pUniverseController->currentText(),
                                m_pUi->m_pUniverseId->text().toInt());
    }
    else
    {
        readCtrls(m_pUniverse);
    }

    m_pMainWin->updateAll();

    QDialog::accept();
} // DlgUniverse::accept


/*******************************************************************************
* DlgUniverse::reject
*******************************************************************************/
void DlgUniverse::reject()
{
    QDialog::reject();
} // DlgUniverse::reject
