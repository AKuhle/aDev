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
DlgUniverse::DlgUniverse(QWidget                            *_pParent,
                         const list<shared_ptr<Controller>> &_lstController,
                         shared_ptr<Universe>               _pUniverse)
: QDialog(_pParent),
  m_pUi(new Ui::DlgUniverse),
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
void DlgUniverse::setCtrls(const shared_ptr<Universe> _pUniverse)
{
    if (_pUniverse)
    {
        // set the universe name
        m_pUi->m_pUniverseName->setText(_pUniverse->name());

        // set the controller by the controller name
        shared_ptr<Controller> pCtrl = _pUniverse->controller();
        if (pCtrl)
        {
            MainWin::selectComboBoxItem(m_pUi->m_pUniverseController,
                                        pCtrl->name());
        } // if (pCtrl)

        // set the universe id
        m_pUi->m_pUniverseId->setText(QString::number(_pUniverse->id()));
    }
} // DlgUniverse::setCtrls


/*******************************************************************************
* DlgUniverse::accept
*******************************************************************************/
void DlgUniverse::accept()
{
    if (!m_pUniverse)
    {
        // add a new universe
        MainWin::instance()->addUniverse(m_pUi->m_pUniverseName->text(),
                                         m_pUi->m_pUniverseController->currentText(),
                                         m_pUi->m_pUniverseId->text().toInt());
    }
    else
    {
        // universe name
        m_pUniverse->setName(m_pUi->m_pUniverseName->text());

        // universe controller
        shared_ptr<Controller> pC = MainWin::instance()->findController(m_pUi->m_pUniverseController->currentText());
        m_pUniverse->setController(pC); // pC could be a nullptr!

        // universe id
        m_pUniverse->setId(m_pUi->m_pUniverseId->text().toInt());
    }

    MainWin::instance()->updateAll();

    QDialog::accept();
} // DlgUniverse::accept


/*******************************************************************************
* DlgUniverse::reject
*******************************************************************************/
void DlgUniverse::reject()
{
    QDialog::reject();
} // DlgUniverse::reject
