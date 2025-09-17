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
                         const aSharedPtrList<Controller>   &_lstController,
                         Universe                           *_pUniverse)
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
        m_pUi->m_pUniverseController->addItem(pController->name().toQString());
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
* DlgUniverse::accept
*******************************************************************************/
void DlgUniverse::accept()
{
    if (!m_pUniverse)
    {
        // add a new universe
        m_pMainWin->addUniverse(aString::fromQString(m_pUi->m_pUniverseName->text()),
                                aString::fromQString(m_pUi->m_pUniverseController->currentText()),
                                aString::fromQString(m_pUi->m_pUniverseId->text()).to_s32());
    }
    else
    {
        // modify the existing controller
        // m_pController->setName(m_pUi->m_pControllerName->text());
        // m_pController->setIpAdr(m_pUi->m_pControllerAddress->text());
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
