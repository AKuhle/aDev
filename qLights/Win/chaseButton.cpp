/*******************************************************************************
* includes
*******************************************************************************/
#include <QMenu>
#include "qLights_def.h"
#include "chaseButton.h"
#include "dlgChase.h"
#include "chase.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* ChaseButton::ChaseButton
*******************************************************************************/
ChaseButton::ChaseButton(QWidget *parent)
: QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &ChaseButton::onClicked);
} // ChaseButton::ChaseButton


/*******************************************************************************
* ChaseButton::init
*******************************************************************************/
void ChaseButton::init()
{
    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, &QPushButton::customContextMenuRequested,
            this, &ChaseButton::showContextMenu);
} // ChaseButton::init


/*******************************************************************************
* ChaseButton::~ChaseButton
*******************************************************************************/
ChaseButton::~ChaseButton()
{
} // ChaseButton::~ChaseButtonß


/*******************************************************************************
* ChaseButton::setChase
*******************************************************************************/
void ChaseButton::setChase(shared_ptr<Chase> _pChase)
{
    m_pChase = _pChase;

    setText((m_pChase)?   m_pChase->name() : "");
} // ChaseButton::setChase


/*******************************************************************************
* ChaseButton::showContextMenu
*******************************************************************************/
void ChaseButton::showContextMenu(const QPoint &_pos)
{
    QMenu menu(this);

    // action: set chase
    QAction *saveAction = menu.addAction("Set Chase");
    connect(saveAction, &QAction::triggered, this, &ChaseButton::onAssignChase);

    // action: remove chase
    QAction *removeAction = menu.addAction("Remove Chase");
    connect(removeAction, &QAction::triggered, this, &ChaseButton::onRemoveChase);

    menu.exec(mapToGlobal(_pos));
} // ChaseButton::showContextMenu


/*******************************************************************************
* ChaseButton::onAssignChase
*******************************************************************************/
void ChaseButton::onAssignChase()
{
    DlgChase dlg(this, m_pChase);

    if (dlg.exec() == QDialog::Accepted)
    {
        QString             sChaseName  = dlg.name();
        bool                bBlackStart = dlg.isBlackStart();
        bool                bCycle      = dlg.isCycle();
        vector<stChaseStep> vSteps      = dlg.chaseSteps();

        // create the chase
        shared_ptr<Chase> pChase = make_shared<Chase> (sChaseName, bBlackStart, bCycle, vSteps);

        MainWin::instance()->assignChase(this, pChase);
    }
} // ChaseButton::onAssignChase


/*******************************************************************************
* ChaseButton::onRemoveChase
*******************************************************************************/
void ChaseButton::onRemoveChase()
{
    MainWin::instance()->removeChase(this);
} // ChaseButton::onRemoveChase


/*******************************************************************************
* ChaseButton::onClicked
*******************************************************************************/
void ChaseButton::onClicked()
{
    // if (m_pChase)
    // {
    //     m_pChase->startChase();
    // }
} // ChaseButton::onClicked
