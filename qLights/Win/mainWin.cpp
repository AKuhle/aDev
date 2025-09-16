/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin(QWidget *parent)
: QMainWindow(parent),
  m_pUi(new Ui::MainWin)
{
    m_pUi->setupUi(this);

    // set the

    // connect the items
    connect(m_pUi->m_pActionOpenFile, &QAction::triggered, this, &MainWin::onFileOpen);
    connect(m_pUi->m_pActionSaveFile, &QAction::triggered, this, &MainWin::onFileSave);

    connect(m_pUi->m_pActionPanelDock, &QAction::triggered, this, &MainWin::onPanel);

    connect(m_pUi->m_pBtnAddController, &QToolButton::clicked, this, &MainWin::onAddController);

    updateAll();
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    delete m_pUi;
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::addController
*******************************************************************************/
void MainWin::addController(const aString &_sName,
                            const aString &_sIpAdr)
{
    //unique_ptr<Controller>  pController = make_unique<Controller> ("Showtec NET-2/3 POCKET", "192.168.1.245");
    unique_ptr<Controller>  pController = make_unique<Controller> (_sName, _sIpAdr);
    m_lstController.push_back(std::move(pController));
} // MainWin::addController
