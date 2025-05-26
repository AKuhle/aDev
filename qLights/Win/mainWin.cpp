/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_formMainWin.h"

#include "mainWin.h"
#include "ctrlPanel.h"


/*******************************************************************************
* getMainWin
*******************************************************************************/
MainWin& getMainWin()
{
    return *dynamic_cast<MainWin *> (aLib::aApp::get_aMainWin());
} // getMainWin


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
* MainWin::setMode
*******************************************************************************/
void MainWin::setMode(enumWorkMode _eMode)
{
    m_eWorkMode = _eMode;

    sendUpdateCmd(UPDATE_GUI);
} // MainWin::setMode


/*******************************************************************************
* MainWin::onCreateWin
*******************************************************************************/
bool MainWin::onCreateWin()
{
    m_pCtrlPanel = new CtrlPanel(this);
    m_pCtrlPanel->createWin();

    setCentralWin(m_pCtrlPanel);

    sendUpdateCmd(UPDATE_GUI);

    return true;
} // MainWin::onCreateWin


/*******************************************************************************
* MainWin::onCloseWin
*******************************************************************************/
bool MainWin::onCloseWin()
{
    return true;
} // MainWin::onCloseWin

