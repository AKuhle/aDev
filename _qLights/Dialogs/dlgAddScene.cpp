#include "dlgAddScene.h"
#include "ui_DlgAddScene.h"


/*******************************************************************************
* DlgAddScene::DlgAddScene
*******************************************************************************/
DlgAddScene::DlgAddScene(QWidget        *_pParent,
                         const aString  &_sSceneName)
: aDialog(_pParent),
  m_sSceneName(_sSceneName)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::DlgAddScene;
        m_pUi->setupUi(this);
    #endif
} // DlgAddScene::DlgAddScene


/*******************************************************************************
* DlgAddScene::~DlgAddScene
*******************************************************************************/
DlgAddScene::~DlgAddScene()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // DlgAddScene::~DlgAddScene


/*******************************************************************************
* DlgAddScene::onCreateWin
*******************************************************************************/
bool DlgAddScene::onCreateWin()
{
    setWinTitle("Add Scene");
    m_pUi->m_pSceneName->setText(m_sSceneName.toQString());

    return true;
} // DlgAddScene::onCreateWin


/*******************************************************************************
* DlgAddScene::onAccepted
*******************************************************************************/
void DlgAddScene::onAccepted()
{
    m_sSceneName = m_pUi->m_pSceneName->editText();
} // DlgAddScene::onAccepted


/*******************************************************************************
* DlgAddScene::onRegisterCtrl
*******************************************************************************/
void DlgAddScene::onRegisterCtrl()
{
    //registerCtrl(m_pUi->m)
} // DlgAddScene::onRegisterCtrl


/*******************************************************************************
* DlgAddScene::onUpdateCtrl
*******************************************************************************/
void DlgAddScene::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
} // DlgAddScene::onUpdateCtrl
