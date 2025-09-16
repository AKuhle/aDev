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
    QTableWidget *pT = m_pUi->m_pControllerTable;

    pT->clear();
    pT->setRowCount(m_lstController.size());

    // iterate over all controllers
    s32 idx = 0;
    for (auto it = m_lstController.begin(); it != m_lstController.end(); it++)
    {
        Controller *pC = (*it).get();

        pT->setItem(idx, 0, new QTableWidgetItem(pC->name().toQString()));
        pT->setItem(idx, 1, new QTableWidgetItem(pC->ipAdr().toQString()));
        idx++;
    }
} // MainWin::updateControllerPanel
