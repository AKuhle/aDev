#include "dlgRemoveScene.h"
#include "ui_DlgRemoveScene.h"


/*******************************************************************************
* DlgRemoveScene::DlgRemoveScene
*******************************************************************************/
DlgRemoveScene::DlgRemoveScene(QWidget        *_pParent,
                         const aString  &_sSceneName)
: aDialog(_pParent),
  m_sSceneName(_sSceneName)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::DlgRemoveScene;
        m_pUi->setupUi(this);
    #endif
} // DlgRemoveScene::DlgRemoveScene


/*******************************************************************************
* DlgRemoveScene::~DlgRemoveScene
*******************************************************************************/
DlgRemoveScene::~DlgRemoveScene()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // DlgRemoveScene::~DlgRemoveScene


/*******************************************************************************
* DlgRemoveScene::onCreateWin
*******************************************************************************/
bool DlgRemoveScene::onCreateWin()
{
    setWinTitle("Remove Scene");
    m_pUi->m_pSceneName->setText(m_sSceneName.toQString());

    return true;
} // DlgRemoveScene::onCreateWin


/*******************************************************************************
* DlgRemoveScene::onAccepted
*******************************************************************************/
void DlgRemoveScene::onAccepted()
{
} // DlgRemoveScene::onAccepted


/*******************************************************************************
* DlgRemoveScene::onRegisterCtrl
*******************************************************************************/
void DlgRemoveScene::onRegisterCtrl()
{
    //registerCtrl(m_pUi->m)
} // DlgRemoveScene::onRegisterCtrl


/*******************************************************************************
* DlgRemoveScene::onUpdateCtrl
*******************************************************************************/
void DlgRemoveScene::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
} // DlgRemoveScene::onUpdateCtrl
