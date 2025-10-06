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
} // SceneButton::~SceneButtonß


// /*******************************************************************************
// * SceneButton::setFixture
// *******************************************************************************/
// void SceneButton::setFixture(shared_ptr<Fixture> _pFixture)
// {
//     setFixedHeight(32);
//     setIconSize(QSize(30, 30));

//     m_pFixture = _pFixture;

//     if (m_pFixture)
//     {
//         setIcon(QIcon(m_pFixture->device()->pixmap()));
//         setText(m_pFixture->name());
//     }
//     else
//     {
//         setIcon(QIcon());
//         setText("");
//     }
// } // SceneButton::setFixture


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
        const list<shared_ptr<Universe>> &lstUniverse  = MainWin::instance()->universes();
        QString                          sSceneName    = dlg.name();

        // set the button text to the scene name
        setText(sSceneName);

        // create a new scene
        m_pScene = make_shared<Scene> (sSceneName);

        for (auto pUniverse : lstUniverse)
        {
            m_pScene->addUniverse(pUniverse, pUniverse->dmxData());
        }

    }
} // SceneButton::onAssignScene
