/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>

#include "ui_mainWin.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* statics
*******************************************************************************/
MainWin *MainWin::m_pInstance    { nullptr };


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin(QWidget *parent)
: QMainWindow(parent),
  m_pUi(new Ui::MainWin)
{
    m_pInstance = this;

    m_pUi->setupUi(this);

    // create the button layers
    createCtrlVectors();

    // load the channel icon list
    readChannelIcons();

    // set the icon size in the tables
    m_pUi->m_pDeviceTable->setIconSize(QSize(64, 64)); // set the icon size for all cells
    m_pUi->m_pFixtureTable->setIconSize(QSize(64, 64)); // set the icon size for all cells

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
    connect(m_pUi->m_pBtnRemoveFixture, &QToolButton::clicked, this, &MainWin::onRemoveFixture);
    connect(m_pUi->m_pBtnEditFixture, &QToolButton::clicked, this, &MainWin::onEditFixture);

    // connect the bank buttons
    connect(m_pUi->m_pBankSelector_1, &QPushButton::clicked, this, &MainWin::onBankSelector_1);
    connect(m_pUi->m_pBankSelector_2, &QPushButton::clicked, this, &MainWin::onBankSelector_2);
    connect(m_pUi->m_pBankSelector_3, &QPushButton::clicked, this, &MainWin::onBankSelector_3);
    connect(m_pUi->m_pBankSelector_4, &QPushButton::clicked, this, &MainWin::onBankSelector_4);
    connect(m_pUi->m_pBankSelector_5, &QPushButton::clicked, this, &MainWin::onBankSelector_5);
    connect(m_pUi->m_pClearBank, &QPushButton::clicked, this, &MainWin::onClearBank);

    // connect the Scene buttons
    connect(m_pUi->m_pSceneSelector_1, &QPushButton::clicked, this, &MainWin::onSceneSelector_1);
    connect(m_pUi->m_pSceneSelector_2, &QPushButton::clicked, this, &MainWin::onSceneSelector_2);
    connect(m_pUi->m_pSceneSelector_3, &QPushButton::clicked, this, &MainWin::onSceneSelector_3);
    connect(m_pUi->m_pSceneSelector_4, &QPushButton::clicked, this, &MainWin::onSceneSelector_4);
    connect(m_pUi->m_pSceneSelector_5, &QPushButton::clicked, this, &MainWin::onSceneSelector_5);

    // connect the Chase buttons
    connect(m_pUi->m_pChaseSelector_1, &QPushButton::clicked, this, &MainWin::onChaseSelector_1);
    connect(m_pUi->m_pChaseSelector_2, &QPushButton::clicked, this, &MainWin::onChaseSelector_2);
    connect(m_pUi->m_pChaseSelector_3, &QPushButton::clicked, this, &MainWin::onChaseSelector_3);
    connect(m_pUi->m_pChaseSelector_4, &QPushButton::clicked, this, &MainWin::onChaseSelector_4);
    connect(m_pUi->m_pChaseSelector_5, &QPushButton::clicked, this, &MainWin::onChaseSelector_5);


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
* MainWin::createCtrlVectors
*******************************************************************************/
void MainWin::createCtrlVectors()
{
    // iterate over all banks
    for (s32 i = 0; i < BANK_COUNT; i++)
    {
        vector<BankTuple>  m_vBankTuple;

        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_1, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_2, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_3, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_4, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_5, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_6, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_7, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_8, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_9, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_10, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_11, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_12, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_13, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_14, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_15, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_16, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_17, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_18, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_19, nullptr));
        m_vBankTuple.push_back(make_tuple(m_pUi->m_pBankBtn_20, nullptr));

        m_vvFixturesOfBank.push_back(m_vBankTuple);

        // faders
        m_vFaders.push_back(m_pUi->m_pFader_1);
        m_vFaders.push_back(m_pUi->m_pFader_2);
        m_vFaders.push_back(m_pUi->m_pFader_3);
        m_vFaders.push_back(m_pUi->m_pFader_4);
        m_vFaders.push_back(m_pUi->m_pFader_5);
        m_vFaders.push_back(m_pUi->m_pFader_6);
        m_vFaders.push_back(m_pUi->m_pFader_7);
        m_vFaders.push_back(m_pUi->m_pFader_8);
        m_vFaders.push_back(m_pUi->m_pFader_9);
        m_vFaders.push_back(m_pUi->m_pFader_10);
        m_vFaders.push_back(m_pUi->m_pFader_11);
        m_vFaders.push_back(m_pUi->m_pFader_12);
        m_vFaders.push_back(m_pUi->m_pFader_13);
        m_vFaders.push_back(m_pUi->m_pFader_14);
        m_vFaders.push_back(m_pUi->m_pFader_15);
        m_vFaders.push_back(m_pUi->m_pFader_16);
        m_vFaders.push_back(m_pUi->m_pFader_17);
        m_vFaders.push_back(m_pUi->m_pFader_18);
        m_vFaders.push_back(m_pUi->m_pFader_19);
        m_vFaders.push_back(m_pUi->m_pFader_20);
        m_vFaders.push_back(m_pUi->m_pFader_21);
        m_vFaders.push_back(m_pUi->m_pFader_22);
        m_vFaders.push_back(m_pUi->m_pFader_23);
        m_vFaders.push_back(m_pUi->m_pFader_24);
        m_vFaders.push_back(m_pUi->m_pFader_m);

        m_pUi->m_pFader_1->init(m_pUi->m_pScribbleStrip_1);
        m_pUi->m_pFader_2->init(m_pUi->m_pScribbleStrip_2);
        m_pUi->m_pFader_3->init(m_pUi->m_pScribbleStrip_3);
        m_pUi->m_pFader_4->init(m_pUi->m_pScribbleStrip_4);
        m_pUi->m_pFader_5->init(m_pUi->m_pScribbleStrip_5);
        m_pUi->m_pFader_6->init(m_pUi->m_pScribbleStrip_6);
        m_pUi->m_pFader_7->init(m_pUi->m_pScribbleStrip_7);
        m_pUi->m_pFader_8->init(m_pUi->m_pScribbleStrip_8);
        m_pUi->m_pFader_9->init(m_pUi->m_pScribbleStrip_9);
        m_pUi->m_pFader_10->init(m_pUi->m_pScribbleStrip_10);
        m_pUi->m_pFader_11->init(m_pUi->m_pScribbleStrip_11);
        m_pUi->m_pFader_12->init(m_pUi->m_pScribbleStrip_12);
        m_pUi->m_pFader_13->init(m_pUi->m_pScribbleStrip_13);
        m_pUi->m_pFader_14->init(m_pUi->m_pScribbleStrip_14);
        m_pUi->m_pFader_15->init(m_pUi->m_pScribbleStrip_15);
        m_pUi->m_pFader_16->init(m_pUi->m_pScribbleStrip_16);
        m_pUi->m_pFader_17->init(m_pUi->m_pScribbleStrip_17);
        m_pUi->m_pFader_18->init(m_pUi->m_pScribbleStrip_18);
        m_pUi->m_pFader_19->init(m_pUi->m_pScribbleStrip_19);
        m_pUi->m_pFader_20->init(m_pUi->m_pScribbleStrip_20);
        m_pUi->m_pFader_21->init(m_pUi->m_pScribbleStrip_21);
        m_pUi->m_pFader_22->init(m_pUi->m_pScribbleStrip_22);
        m_pUi->m_pFader_23->init(m_pUi->m_pScribbleStrip_23);
        m_pUi->m_pFader_24->init(m_pUi->m_pScribbleStrip_24);
        m_pUi->m_pFader_m->init(m_pUi->m_pScribbleStrip_m);
    }

} // MainWin::createCtrlVectors


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
            QString     sFile = QString::fromStdString(entry.path().string());
            sFile.replace(QChar(92), QChar(47)); // 92 = '\', 47 = '/'

            m_lstChannelIcon.push_back(sFile);
        }
    }

    // read the device icons
    path = "C:/Tools/aDev/qLights/Icons/Device";

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".png")
        {
            QString     sFile = QString::fromStdString(entry.path().string());
            sFile.replace(QChar(92), QChar(47)); // 92 = '\', 47 = '/'

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
void MainWin::addDevice(const QString                       &_sName,
                        const QString                       &_sImage,
                        const vector<shared_ptr<Channel>>   &_vChannel)
{
    shared_ptr<Device>  pDevice = make_shared<Device> (_sName, _sImage, _vChannel);
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
void MainWin::addFixture(const QString          &_sName,
                         shared_ptr<Device>     _pDevice,
                         shared_ptr<Universe>   _pUniverse,
                         s32                    _s32Adress)
{
    shared_ptr<Fixture>  pFixture = make_shared<Fixture> (_sName, _pDevice, _pUniverse, _s32Adress);
    m_lstFixture.push_back(std::move(pFixture));
} // MainWin::addFixture


/*******************************************************************************
* MainWin::assignFixture
*******************************************************************************/
void MainWin::assignFixture(BankButton    *_pBankBtn,
                            const QString &_sFixtureName)
{
    shared_ptr<Fixture>  pFixture = findFixture(_sFixtureName);

    for (BankTuple &tup : m_vvFixturesOfBank.at(m_s32ActiveBank))
    {
        if (std::get<0> (tup) == _pBankBtn)
        {
            std::get<1> (tup) = pFixture;

            _pBankBtn->setFixture(pFixture);
        }
    }
} // MainWin::assignFixture


/*******************************************************************************
* MainWin::assignFaders
*******************************************************************************/
void MainWin::assignFaders(shared_ptr<Fixture> _pFixture)
{
} // MainWin::assignFaders


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
