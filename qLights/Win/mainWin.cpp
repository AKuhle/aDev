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

    // load the channel icon list
    readChannelIcons();

    m_pUi->m_pDeviceTable->setIconSize(QSize(64, 64)); // set the icon size for all cells

    // connect the toolbar stuff
    connect(m_pUi->m_pActionOpenFile, &QAction::triggered, this, &MainWin::onFileOpen);
    connect(m_pUi->m_pActionSaveFile, &QAction::triggered, this, &MainWin::onFileSave);
    connect(m_pUi->m_pActionPanelDock, &QAction::triggered, this, &MainWin::onPanel);

    // connect the controller stuff
    connect(m_pUi->m_pBtnAddController, &QToolButton::clicked, this, &MainWin::onAddController);
    connect(m_pUi->m_pBtnRemoveController, &QToolButton::clicked, this, &MainWin::onRemoveController);
    connect(m_pUi->m_pBtnEditController, &QToolButton::clicked, this, &MainWin::onEditController);

    // connect the universe stuff
    connect(m_pUi->m_pBtnAddUniverse, &QToolButton::clicked, this, &MainWin::onAddUniverse);
    connect(m_pUi->m_pBtnRemoveUniverse, &QToolButton::clicked, this, &MainWin::onRemoveUniverse);
    connect(m_pUi->m_pBtnEditUniverse, &QToolButton::clicked, this, &MainWin::onEditUniverse);

    // connect the device stuff
    connect(m_pUi->m_pBtnAddDevice, &QToolButton::clicked, this, &MainWin::onAddDevice);
    connect(m_pUi->m_pBtnRemoveDevice, &QToolButton::clicked, this, &MainWin::onRemoveDevice);
    connect(m_pUi->m_pBtnEditDevice, &QToolButton::clicked, this, &MainWin::onEditDevice);

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
* MainWin::readChannelIcons
*******************************************************************************/
void  MainWin::readChannelIcons()
{
    // read the channel icons
    std::string path = "C:/Tools/aDev/qLights/Icons/Channel";

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".png")
        {
            m_lstChannelIcon.push_back(QPixmap(QString::fromStdString(entry.path().string())));
        }
    }

    // read the device icons
    path = "C:/Tools/aDev/qLights/Icons/Device";

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".png")
        {
            QString     sFile = QString::fromStdString(entry.path().string());

            if (sFile.contains("std.png"))
            {
                // insert the standard image at the beginning of the list
                m_lstDeviceIconName.insert(m_lstDeviceIconName.begin(), sFile);
            }
            else
            {
                m_lstDeviceIconName.push_back(sFile);
            }
        }
    }
} // MainWin::readChannelIcons


/*******************************************************************************
* MainWin::selectComboBoxItem
*******************************************************************************/
void  MainWin::selectComboBoxItem(QComboBox     *_pCombo,
                                  const QString &_sItem)
{
    int index = _pCombo->findText(_sItem);

    if (index != -1)
    {
        _pCombo->setCurrentIndex(index);
    }
} // MainWin::selectComboBoxItem


/*******************************************************************************
* MainWin::addController
*******************************************************************************/
void MainWin::addController(const QString &_sName,
                            const QString &_sIpAdr)
{
    shared_ptr<Controller>  pController = make_shared<Controller> (_sName, _sIpAdr);
    m_lstController.push_back(std::move(pController));
} // MainWin::addController


/*******************************************************************************
* MainWin::findController
*******************************************************************************/
shared_ptr<Controller> MainWin::findController(const QString &_sName)
{
    auto it = std::find_if(m_lstController.begin(),
                           m_lstController.end(),
                          [&_sName](shared_ptr<Controller> pCtrl) { return pCtrl->name() == _sName; }
                          );

    return (it != m_lstController.end())?   (*it) : nullptr;
} // MainWin::findController


/*******************************************************************************
* MainWin::findUniverse
*******************************************************************************/
shared_ptr<Universe> MainWin::findUniverse(const QString &_sName)
{
    auto it = std::find_if(m_lstUniverse.begin(),
                           m_lstUniverse.end(),
                          [&_sName](shared_ptr<Universe> pCtrl) { return pCtrl->name() == _sName; }
                          );

    return (it != m_lstUniverse.end())?   (*it) : nullptr;
} // MainWin::findUniverse


/*******************************************************************************
* MainWin::addUniverse
*******************************************************************************/
void MainWin::addUniverse(const QString   &_sName,
                          const QString   &_sController,
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

        shared_ptr<Universe>  pUniverse = make_shared<Universe> (_sName, wp, _s32Id);
        m_lstUniverse.push_back(std::move(pUniverse));
    }
    else
    {
        std::weak_ptr<Controller> wp;

        // create an universe w/o an controller
        shared_ptr<Universe>  pUniverse = make_shared<Universe> (_sName, wp, _s32Id);
        m_lstUniverse.push_back(std::move(pUniverse));
    }
} // MainWin::addUniverse


/*******************************************************************************
* MainWin::addDevice
*******************************************************************************/
void MainWin::addDevice(const QString &_sName,
                        const QString &_sImage)
{
    shared_ptr<Device>  pDevice = make_shared<Device> (_sName, _sImage);
    m_lstDevice.push_back(std::move(pDevice));
} // MainWin::addDevice


/*******************************************************************************
* MainWin::findDevice
*******************************************************************************/
shared_ptr<Device> MainWin::findDevice(const QString &_sName)
{
    auto it = std::find_if(m_lstDevice.begin(),
                           m_lstDevice.end(),
                          [&_sName](shared_ptr<Device> pCtrl) { return pCtrl->name() == _sName; }
                          );

    return (it != m_lstDevice.end())?   (*it) : nullptr;
} // MainWin::findDevice


/*******************************************************************************
* MainWin::addFixture
*******************************************************************************/
void MainWin::addFixture(const QString &_sName)
{
    shared_ptr<Fixture>  pFixture = make_shared<Fixture> (_sName);
    m_lstFixture.push_back(std::move(pFixture));
} // MainWin::addFixture


/*******************************************************************************
* MainWin::findFixture
*******************************************************************************/
shared_ptr<Fixture> MainWin::findFixture(const QString &_sName)
{
    auto it = std::find_if(m_lstFixture.begin(),
                           m_lstFixture.end(),
                          [&_sName](shared_ptr<Fixture> pCtrl) { return pCtrl->name() == _sName; }
                          );

    return (it != m_lstFixture.end())?   (*it) : nullptr;
} // MainWin::findFixture
