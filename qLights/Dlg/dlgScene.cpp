/*******************************************************************************
* include
*******************************************************************************/
#include "ui_dlgScene.h"

#include "aFrame_def.h"
#include "sceneButton.h"
#include "scene.h"

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

    // set the scene name
    if (_pScene)
    {
        m_pUi->m_pSceneName->setText(_pScene->name());
    }
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
