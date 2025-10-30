/*******************************************************************************
* includes
*******************************************************************************/
#include <QMenu>
#include "sceneButton.h"
#include "dlgScene.h"
#include "scene.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* SceneButton::SceneButton
*******************************************************************************/
SceneButton::SceneButton(QWidget *parent)
: QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &SceneButton::onClicked);
} // SceneButton::SceneButton


/*******************************************************************************
* SceneButton::init
*******************************************************************************/
void SceneButton::init()
{
    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, &QPushButton::customContextMenuRequested,
            this, &SceneButton::showContextMenu);
} // SceneButton::init


/*******************************************************************************
* SceneButton::~SceneButton
*******************************************************************************/
SceneButton::~SceneButton()
{
} // SceneButton::~SceneButton


/*******************************************************************************
* SceneButton::setScene
*******************************************************************************/
void SceneButton::setScene(shared_ptr<Scene> _pScene)
{
    m_pScene = _pScene;

    setText((m_pScene)?   m_pScene->name() : "");
} // SceneButton::setScene


/*******************************************************************************
* SceneButton::showContextMenu
*******************************************************************************/
void SceneButton::showContextMenu(const QPoint &_pos)
{
    QMenu menu(this);

    // action: set scene
    QAction *saveAction = menu.addAction("Set Scene");
    connect(saveAction, &QAction::triggered, this, &SceneButton::onAssignScene);

    // action: remove scene
    QAction *removeAction = menu.addAction("Remove Scene");
    connect(removeAction, &QAction::triggered, this, &SceneButton::onRemoveScene);

    menu.exec(mapToGlobal(_pos));
} // SceneButton::showContextMenu


/*******************************************************************************
* SceneButton::onAssignScene
*******************************************************************************/
void SceneButton::onAssignScene()
{
    DlgScene dlg(this, m_pScene);

    if (dlg.exec() == QDialog::Accepted)
    {
        MainWin::instance()->assignScene(this, dlg.name());
    }
} // SceneButton::onAssignScene


/*******************************************************************************
* SceneButton::onRemoveScene
*******************************************************************************/
void SceneButton::onRemoveScene()
{
    MainWin::instance()->removeScene(this);
} // SceneButton::onRemoveScene


/*******************************************************************************
* SceneButton::onClicked
*******************************************************************************/
void SceneButton::onClicked()
{
    CHECK_PRE_CONDITION_VOID(m_pScene);

    // set the master brightness of the scene BEFORE the universes
    MainWin::instance()->setMasterBrightness(m_pScene->masterBrighness(), false);

    const list<UniverseTuple> &lstTup = m_pScene->universes();

    for (auto &tup : lstTup)
    {
        std::shared_ptr<Universe>   pUniverse = std::get<0> (tup);

        if (pUniverse)
        {
            // set the new universe data which was stored in the scene
            pUniverse->setDmxData(std::get<1> (tup), true);
        }
    }

    // update all channel values
    MainWin::instance()->updateAllChannelValuesFromUniverse();

    // update the faders
    MainWin::instance()->updateFaders();

} // SceneButton::onClicked
