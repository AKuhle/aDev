/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_formMainWin.h"

#include "aAppMainWin.h"
#include "mainWin.h"
#include "ctrlPanel.h"

using namespace aLib::aApp;


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
    // save the configuration
    if (m_pCtrlPanel)
    {
        aPath   path = get_appPath() / LAST_CONFIG;
        m_pCtrlPanel->writeConfiguration(path);
    }

    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::setWorkMode
*******************************************************************************/
void MainWin::setWorkMode(enumWorkMode _eMode)
{
    m_eWorkMode = _eMode;

    sendUpdateCmd(UPDATE_GUI);
} // MainWin::setWorkMode


/*******************************************************************************
* MainWin::getMasterBrightness
*******************************************************************************/
dbl MainWin::getMasterBrightness() const
{
    CHECK_PRE_CONDITION(m_pCtrlPanel != nullptr, 0);

    return m_pCtrlPanel->getMasterBrightness();
} // MainWin::getMasterBrightness


/*******************************************************************************
* MainWin::onCreateWin
*******************************************************************************/
bool MainWin::onCreateWin()
{
    m_pCtrlPanel = new CtrlPanel(this);
    m_pCtrlPanel->createWin();

    setCentralWin(m_pCtrlPanel);

    // read the last configuration
    aPath   path = get_appPath() / LAST_CONFIG;
    m_pCtrlPanel->readConfiguration(path);

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
