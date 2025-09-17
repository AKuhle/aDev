/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* MainWin::updateAll
*******************************************************************************/
void MainWin::updateAll()
{
    updateGui();
    updateControllerPanel();
    updateUniversePanel();
    updateDevicePanel();
    updateFixturePanel();
} // MainWin::updateAll


/*******************************************************************************
* MainWin::updateGui
*******************************************************************************/
void MainWin::updateGui()
{
    // action PanelDock
    m_pUi->m_pActionPanelDock->setChecked(m_pUi->m_pPanelDock->isVisible());
} // MainWin::updateGui


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
        const Controller    *pC = pU->controller();

        addTableWidgetItem(pT, idx, 0, pU->name());                                     // univers name
        addTableWidgetItem(pT, idx, 1, ((pC)?   pC->name() : ""));                      // controller name
        addTableWidgetItem(pT, idx, 2, ((pC)?   aString::fromValue(pU->id()) : ""));    // universe Id

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

    // iterate over all controllers
    s32 idx = 0;
    for (const shared_ptr<Device> &pD : m_lstDevice)
    {
        // controller name
        addTableWidgetItem(pT, idx, 0, pD->name());

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

    // iterate over all controllers
    s32 idx = 0;
    for (const shared_ptr<Fixture> &pF : m_lstFixture)
    {
        // controller name
        addTableWidgetItem(pT, idx, 0, pF->name());

        idx++;
    }
} // MainWin::updateFixturePanel


/*******************************************************************************
* MainWin::addTableWidgetItem
*******************************************************************************/
void MainWin::addTableWidgetItem(QTableWidget   *_pTableWidget,
                                 s32            _s32Row,
                                 s32            _s32Col,
                                 const aString  &_sItem)
{
    QTableWidgetItem    *pItem = new QTableWidgetItem(_sItem.toQString());

    pItem->setFlags(pItem->flags() & ~Qt::ItemIsEditable);

    _pTableWidget->setItem(_s32Row, _s32Col, pItem);
} // MainWin::addTableWidgetItem
