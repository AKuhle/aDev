/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_formMainWin.h"

#include "mainWin.h"
#include "ctrlPanel.h"


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin()
{
    #ifdef _USE_QT_
        m_pUi = new Ui::FormMainWin;
        m_pUi->setupUi(this);
    #endif
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::onCreateWin
*******************************************************************************/
bool MainWin::onCreateWin()
{
    CtrlPanel   *pCtrlPanel = new CtrlPanel(this);
    pCtrlPanel->createWin();

    setCentralWin(pCtrlPanel);

    return true;
} // MainWin::onCreateWin


/*******************************************************************************
* MainWin::onCloseWin
*******************************************************************************/
bool MainWin::onCloseWin()
{
    return true;
} // MainWin::onCloseWin

