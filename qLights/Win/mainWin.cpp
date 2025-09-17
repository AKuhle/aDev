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

    // connect the toolbar stuff
    connect(m_pUi->m_pActionOpenFile, &QAction::triggered, this, &MainWin::onFileOpen);
    connect(m_pUi->m_pActionSaveFile, &QAction::triggered, this, &MainWin::onFileSave);
    connect(m_pUi->m_pActionPanelDock, &QAction::triggered, this, &MainWin::onPanel);

    // connect the controller stuff
    connect(m_pUi->m_pBtnAddController, &QToolButton::clicked, this, &MainWin::onAddController);

    // connect the universe stuff
    connect(m_pUi->m_pBtnAddUniverse, &QToolButton::clicked, this, &MainWin::onAddUniverse);

    // connect the device stuff
    connect(m_pUi->m_pBtnAddDevice, &QToolButton::clicked, this, &MainWin::onAddDevice);

    // connect the fixture stuff
    connect(m_pUi->m_pBtnAddFixture, &QToolButton::clicked, this, &MainWin::onAddFixture);

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
    shared_ptr<Controller>  pController = make_shared<Controller> (_sName, _sIpAdr);
    m_lstController.push_back(std::move(pController));
} // MainWin::addController


/*******************************************************************************
* MainWin::addUniverse
*******************************************************************************/
void MainWin::addUniverse(const aString   &_sName,
                          const aString   &_sController,
                          s32             _s32Id)
{
    auto it = std::find_if(m_lstController.begin(),
                           m_lstController.end(),
                           [&_sController](const std::shared_ptr<Controller> &ctrl)
                           {
                                return ctrl->name() == _sController;
                           }
    );

    if (it != m_lstController.end())
    {
        // create an universe with an controller
        std::weak_ptr<Controller> wp = *it;

        shared_ptr<Universe>  pUniverse = make_shared<Universe> (_sName, _s32Id, wp);
        m_lstUniverse.push_back(std::move(pUniverse));
    }
    else
    {
        std::weak_ptr<Controller> wp;

        // create an universe w/o an controller
        shared_ptr<Universe>  pUniverse = make_shared<Universe> (_sName, _s32Id, wp);
        m_lstUniverse.push_back(std::move(pUniverse));
    }


    //unique_ptr<Controller>  pController = make_unique<Controller> ("Showtec NET-2/3 POCKET", "192.168.1.245");
    //unique_ptr<Controller>  pController = make_unique<Controller> (_sName, _sIpAdr);
    //m_lstController.push_back(std::move(pController));
} // MainWin::addUniverse


/*******************************************************************************
* MainWin::addDevice
*******************************************************************************/
void MainWin::addDevice(const aString &_sName)
{
    shared_ptr<Device>  pDevice = make_shared<Device> (_sName);
    m_lstDevice.push_back(std::move(pDevice));
} // MainWin::addDevice


/*******************************************************************************
* MainWin::addFixture
*******************************************************************************/
void MainWin::addFixture(const aString &_sName)
{
    shared_ptr<Fixture>  pFixture = make_shared<Fixture> (_sName);
    m_lstFixture.push_back(std::move(pFixture));
} // MainWin::addFixture
