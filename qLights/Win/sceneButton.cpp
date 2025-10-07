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
* SceneButton::setScene
*******************************************************************************/
void SceneButton::setScene(shared_ptr<Scene> _pScene)
{
    m_pScene = _pScene;

    setText((m_pScene)?   m_pScene->name() : "");
} // SceneButton::setScene


/*******************************************************************************
* SceneButton::~SceneButton
*******************************************************************************/
SceneButton::~SceneButton()
{
} // SceneButton::~SceneButtonß


/*******************************************************************************
* SceneButton::showContextMenu
*******************************************************************************/
void SceneButton::showContextMenu(const QPoint &_pos)
{
    QMenu menu(this);

    QAction *saveAction = menu.addAction("Set Scene");
    connect(saveAction, &QAction::triggered, this, &SceneButton::onAssignScene);
    menu.exec(mapToGlobal(_pos));
} // SceneButton::showContextMenu


/*******************************************************************************
* SceneButton::onAssignScene
*******************************************************************************/
void SceneButton::onAssignScene()
{
    DlgScene dlg(this);

    if (dlg.exec() == QDialog::Accepted)
    {
        MainWin::instance()->assignScene(this, dlg.name());
    }
} // SceneButton::onAssignScene


/*******************************************************************************
* SceneButton::onClicked
*******************************************************************************/
void SceneButton::onClicked()
{
    const list<UniverseTuple> &lstTup = m_pScene->universes();

    for (auto &tup : lstTup)
    {
        std::get<0> (tup)->setDmxData(std::get<1> (tup), true);
    }

    MainWin::instance()->updateFaders();
} // SceneButton::onClicked
