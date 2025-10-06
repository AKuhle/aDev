/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "qLights_def.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* MainWin::updateAll
*******************************************************************************/
void MainWin::updateAll()
{
    updatePanel();

    updateBankButtons();
    updateSceneButtons();
    updateChaseButtons();

    updateControllerPanel();
    updateUniversePanel();
    updateDevicePanel();
    updateFixturePanel();
} // MainWin::updateAll


/*******************************************************************************
* MainWin::updatePanel
*******************************************************************************/
void MainWin::updatePanel()
{
    // action PanelDock
    m_pUi->m_pActionPanelDock->setChecked(m_pUi->m_pPanelDock->isVisible());
} // MainWin::updatePanel


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

    vector<BankTuple> &vBank = m_vvFixturesOfBank.at(m_s32ActiveBank);

    for (BankTuple &tup : vBank)
    {
        (std::get<0> (tup))->setFixture(std::get<1> (tup));

    }
} // MainWin::updateBankButtons


/*******************************************************************************
* MainWin::updateSceneButtons
*******************************************************************************/
void MainWin::updateSceneButtons()
{
    m_pUi->m_pSceneSelector_1->setChecked(m_s32ActiveScene == SCENE_1);
    m_pUi->m_pSceneSelector_2->setChecked(m_s32ActiveScene == SCENE_2);
    m_pUi->m_pSceneSelector_3->setChecked(m_s32ActiveScene == SCENE_3);
    m_pUi->m_pSceneSelector_4->setChecked(m_s32ActiveScene == SCENE_4);
    m_pUi->m_pSceneSelector_5->setChecked(m_s32ActiveScene == SCENE_5);
} // MainWin::updateSceneButtons


/*******************************************************************************
* MainWin::updateChaseButtons
*******************************************************************************/
void MainWin::updateChaseButtons()
{
    m_pUi->m_pChaseSelector_1->setChecked(m_s32ActiveChase == CHASE_1);
    m_pUi->m_pChaseSelector_2->setChecked(m_s32ActiveChase == CHASE_2);
    m_pUi->m_pChaseSelector_3->setChecked(m_s32ActiveChase == CHASE_3);
    m_pUi->m_pChaseSelector_4->setChecked(m_s32ActiveChase == CHASE_4);
    m_pUi->m_pChaseSelector_5->setChecked(m_s32ActiveChase == CHASE_5);
} // MainWin::updateChaseButtons


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
