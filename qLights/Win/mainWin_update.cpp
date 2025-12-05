/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "qLights_def.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* MainWin::initGui
*******************************************************************************/
void MainWin::initGui()
{
    m_s32ActiveBank = BANK_1;
    m_s32ActiveScene = SCENE_1;
    m_s32ActiveChase = CHASE_1;
    m_pActiveFixture = nullptr;
} // MainWin::initGui


/*******************************************************************************
* MainWin::updateAll
*******************************************************************************/
void MainWin::updateAll()
{
    updateToolbar();

    updateBankButtons();
    updateSceneButtons();
    updateChaseButtons();
    updateFaders();

    updateControllerPanel();
    updateUniversePanel();
    updateDevicePanel();
    updateFixturePanel();
} // MainWin::updateAll


/*******************************************************************************
* MainWin::updateToolbar
*******************************************************************************/
void MainWin::updateToolbar()
{
    // load/save btn only visible, when side pane is visible
    m_pUi->m_pActionOpenFile->setEnabled(m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pActionSaveFile->setEnabled(m_pUi->m_pPanelDock->isVisible());

    // action PanelDock
    m_pUi->m_pActionPanelDock->setChecked(m_pUi->m_pPanelDock->isVisible());

    // action show values
    m_pUi->m_pActionShowValues->setChecked(isShowValues());

    // action rgb groups, only visible without panel dock
    m_pUi->m_pRgbGroup1->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pRgbGroup2->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pRgbGroup3->setVisible(!m_pUi->m_pPanelDock->isVisible());

    m_pUi->m_pRgbGroup1->setEnabled(m_pActiveFixture != nullptr &&
                                    m_pActiveFixture->device()->rgbGroupSize() >= 1);
    m_pUi->m_pRgbGroup2->setEnabled(m_pActiveFixture != nullptr &&
                                    m_pActiveFixture->device()->rgbGroupSize() >= 2);
    m_pUi->m_pRgbGroup3->setEnabled(m_pActiveFixture != nullptr &&
                                    m_pActiveFixture->device()->rgbGroupSize() >= 3);

    // ligth and fade buttons
    m_pUi->m_pSwitchOn->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pSwitchOff->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeIn_1s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeIn_2s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeIn_3s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeIn_5s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeIn_10s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeOut_1s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeOut_2s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeOut_3s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeOut_5s->setVisible(!m_pUi->m_pPanelDock->isVisible());
    m_pUi->m_pFadeOut_10s->setVisible(!m_pUi->m_pPanelDock->isVisible());
} // MainWin::updateToolbar


/*******************************************************************************
* MainWin::updateBankButtons
*******************************************************************************/
void MainWin::updateBankButtons()
{
    m_pUi->m_pBankSelector_1->setChecked(m_s32ActiveBank == BANK_1);
    m_pUi->m_pBankSelector_2->setChecked(m_s32ActiveBank == BANK_2);
    m_pUi->m_pBankSelector_3->setChecked(m_s32ActiveBank == BANK_3);
    m_pUi->m_pBankSelector_4->setChecked(m_s32ActiveBank == BANK_4);
    m_pUi->m_pBankSelector_5->setChecked(m_s32ActiveBank == BANK_5);

    vector<stBankBtn> &vBank = m_vvBankButtons.at(m_s32ActiveBank);

    for (stBankBtn bankBtn : vBank)
    {
        bankBtn.pBtn->setFixture(bankBtn.pFixture);
    }
} // MainWin::updateBankButtons


/*******************************************************************************
* MainWin::updateSceneButtons
*******************************************************************************/
void MainWin::updateSceneButtons()
{
    // check the actice scene set
    m_pUi->m_pSceneSelector_1->setChecked(m_s32ActiveScene == SCENE_1);
    m_pUi->m_pSceneSelector_2->setChecked(m_s32ActiveScene == SCENE_2);
    m_pUi->m_pSceneSelector_3->setChecked(m_s32ActiveScene == SCENE_3);
    m_pUi->m_pSceneSelector_4->setChecked(m_s32ActiveScene == SCENE_4);
    m_pUi->m_pSceneSelector_5->setChecked(m_s32ActiveScene == SCENE_5);

    // get the vector of scene buttons for the active set
    vector<stSceneBtn> &vSceneBtn = m_vvSceneButtons.at(m_s32ActiveScene);

    // update the buttons with the assigne scene for the active set
    for (stSceneBtn &sceneBtn : vSceneBtn)
    {
        sceneBtn.pBtn->setScene(sceneBtn.pScene);
    }
} // MainWin::updateSceneButtons


/*******************************************************************************
* MainWin::updateChaseButtons
*******************************************************************************/
void MainWin::updateChaseButtons()
{
    // check the actice chase set
    m_pUi->m_pChaseSelector_1->setChecked(m_s32ActiveChase == CHASE_1);
    m_pUi->m_pChaseSelector_2->setChecked(m_s32ActiveChase == CHASE_2);
    m_pUi->m_pChaseSelector_3->setChecked(m_s32ActiveChase == CHASE_3);
    m_pUi->m_pChaseSelector_4->setChecked(m_s32ActiveChase == CHASE_4);
    m_pUi->m_pChaseSelector_5->setChecked(m_s32ActiveChase == CHASE_5);

    // get the vector of chase buttons for the active set
    vector<stChaseBtn> &vChaseBtn = m_vvChaseButtons.at(m_s32ActiveChase);

    // update the buttons with the assigne scene for the active set
    for (stChaseBtn &chaseBtn : vChaseBtn)
    {
        chaseBtn.pBtn->setChase(chaseBtn.pChase);
    }
} // MainWin::updateChaseButtons


/*******************************************************************************
* MainWin::updateFaders
*******************************************************************************/
void MainWin::updateFaders()
{
    for (Fader *pFader : m_vFaders)
    {
        pFader->update();
    }

    // update the master fader
    updateMasterFader();
} // MainWin::updateFaders


/*******************************************************************************
* MainWin::updateMasterFader
*******************************************************************************/
void MainWin::updateMasterFader()
{
    // update the master fader
    m_pMasterFader->update();
} // MainWin::updateMasterFader


/*******************************************************************************
* MainWin::updateControllerPanel
*******************************************************************************/
void MainWin::updateControllerPanel()
{
    QTableWidget        *pT = m_pUi->m_pControllerTable;

    pT->clearContents();
    pT->setRowCount(m_lstController.size());

    // iterate over all controllers
    s32 idx = 0;
    for (const shared_ptr<Controller> &pC : m_lstController)
    {
        // controller name
        addTableWidgetItem(pT, idx, 0, pC->name());

        // controller adress
        addTableWidgetItem(pT, idx, 1, pC->ipAdr());
    }
} // MainWin::updateControllerPanel


/*******************************************************************************
* MainWin::updateUniversePanel
*******************************************************************************/
void MainWin::updateUniversePanel()
{
    QTableWidget *pT = m_pUi->m_pUniverseTable;

    pT->clearContents();
    pT->setRowCount(m_lstUniverse.size());

    // iterate over all universes
    s32 idx = 0;
    for (const shared_ptr<Universe> &pU : m_lstUniverse)
    {
        shared_ptr<Controller> pC = pU->controller();

        // univers name
        addTableWidgetItem(pT, idx, 0, pU->name());

        // controller name
        addTableWidgetItem(pT, idx, 1, (pC)?   pC->name() : "no Controller");

        // universe Id
        addTableWidgetItem(pT, idx, 2, QString::number(pU->id()));

        idx++;
    }
} // MainWin::updateUniversePanel


/*******************************************************************************
* MainWin::updateDevicePanel
*******************************************************************************/
void MainWin::updateDevicePanel()
{
    QTableWidget        *pT = m_pUi->m_pDeviceTable;

    pT->clearContents();
    pT->setRowCount(m_lstDevice.size());

    // iterate over all devices
    s32 idx = 0;
    for (const shared_ptr<Device> &pD : m_lstDevice)
    {
        // set the row size to 64
        pT->setRowHeight(idx, 64);

        // device image
        const QPixmap &pix = pD->pixmap();
        if (!pix.isNull())
        {
            addTableWidgetItem(pT, idx, 0, pix);
        }

        // device name
        addTableWidgetItem(pT, idx, 1, pD->name());

        // channel count
        addTableWidgetItem(pT, idx, 2, pD->channelCount());

        idx++;
    }
} // MainWin::updateDevicePanel


/*******************************************************************************
* MainWin::updateFixturePanel
*******************************************************************************/
void MainWin::updateFixturePanel()
{
    QTableWidget        *pT = m_pUi->m_pFixtureTable;

    pT->clearContents();
    pT->setRowCount(m_lstFixture.size());

    // iterate over all fixtures
    s32 idx = 0;
    for (const shared_ptr<Fixture> &pF : m_lstFixture)
    {
        // set the row size to 64
        pT->setRowHeight(idx, 64);

        // device image
        const QPixmap &pix = pF->device()->pixmap();
        if (!pix.isNull())
        {
            addTableWidgetItem(pT, idx, 0, pix);
        }

        // fixture name
        addTableWidgetItem(pT, idx, 1, pF->name());

        // fixture adress
        addTableWidgetItem(pT, idx, 2, QString::number(pF->adress()));

        idx++;
    }
} // MainWin::updateFixturePanel


/*******************************************************************************
* MainWin::addTableWidgetItem
*******************************************************************************/
void MainWin::addTableWidgetItem(QTableWidget   *_pTableWidget,
                                 s32            _s32Row,
                                 s32            _s32Col,
                                 s32            _s32Value)
{
    QTableWidgetItem    *pItem = new QTableWidgetItem(QString::number(_s32Value));

    pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);

    _pTableWidget->setItem(_s32Row, _s32Col, pItem);
} // MainWin::addTableWidgetItem


/*******************************************************************************
* MainWin::addTableWidgetItem
*******************************************************************************/
void MainWin::addTableWidgetItem(QTableWidget   *_pTableWidget,
                                 s32            _s32Row,
                                 s32            _s32Col,
                                 const QString  &_sItem)
{
    QTableWidgetItem    *pItem = new QTableWidgetItem(_sItem);

    pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);

    _pTableWidget->setItem(_s32Row, _s32Col, pItem);
} // MainWin::addTableWidgetItem


/*******************************************************************************
* MainWin::addTableWidgetItem
*******************************************************************************/
void MainWin::addTableWidgetItem(QTableWidget   *_pTableWidget,
                                 s32            _s32Row,
                                 s32            _s32Col,
                                 const QPixmap  &_pixmap)
{
    QTableWidgetItem    *pItem = new QTableWidgetItem();
    pItem->setIcon(QIcon(_pixmap));

    pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);

    _pTableWidget->setItem(_s32Row, _s32Col, pItem);
} // MainWin::addTableWidgetItem
