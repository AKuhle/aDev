/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>
#include <QMessageBox>

#include "ui_mainWin.h"
#include "mainWin.h"
#include "scene.h"
#include "chase.h"

using namespace std;


/*******************************************************************************
* statics
*******************************************************************************/
MainWin *MainWin::m_pInstance           { nullptr };
u8      MainWin::m_u8MasterBrightness   { 255 };


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin(QWidget *parent)
: QMainWindow(parent),
  m_pUi(new Ui::MainWin)
{
    m_pInstance = this;

    m_pUi->setupUi(this);

    // init the member variables
    initMember();

    // load the channel icon list
    readChannelIcons();

    // set the icon size in the tables
    m_pUi->m_pDeviceTable->setIconSize(QSize(64, 64)); // set the icon size for all cells
    m_pUi->m_pFixtureTable->setIconSize(QSize(64, 64)); // set the icon size for all cells

    // connect the toolbar stuff
    connect(m_pUi->m_pActionOpenFile, &QAction::triggered, this, &MainWin::onFileOpen);
    connect(m_pUi->m_pActionSaveFile, &QAction::triggered, this, &MainWin::onFileSave);
    connect(m_pUi->m_pActionPanelDock, &QAction::triggered, this, &MainWin::onPanel);
    connect(m_pUi->m_pActionShowValues, &QAction::triggered, this, &MainWin::onShowValues);

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
    connect(m_pUi->m_pResetFixtures, &QPushButton::clicked, this, &MainWin::onResetFixtures);

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

    // connect the fader buttons
    connect(m_pUi->m_pFadeIn, &QPushButton::clicked, this, &MainWin::onFaderIn);
    connect(m_pUi->m_pFadeOut, &QPushButton::clicked, this, &MainWin::onFaderOut);
    connect(m_pUi->m_pSwitchOn, &QPushButton::clicked, this, &MainWin::onSwitchOn);
    connect(m_pUi->m_pSwitchOff, &QPushButton::clicked, this, &MainWin::onSwitchOff);
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    delete m_pUi;
} // MainWin::~MainWin


/*******************************************************************************
* MainWin::initMember
*******************************************************************************/
void MainWin::initMember()
{
    // generate BANK_COUNT sets of BANK_BTN_COUNT buttons
    for (s32 i = 0; i < BANK_SET_COUNT; i++)
    {
        vector<stBankBtn>  m_vBankBtn;

        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_1, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_2, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_3, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_4, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_5, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_6, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_7, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_8, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_9, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_10, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_11, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_12, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_13, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_14, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_15, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_16, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_17, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_18, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_19, nullptr });
        m_vBankBtn.push_back(stBankBtn { m_pUi->m_pBankBtn_20, nullptr });

        m_vvBankButtons.push_back(m_vBankBtn);
    }

    // generate SCENE_COUNT sets of SCENE_BTN_COUNT buttons
    for (s32 i = 0; i < SCENE_SET_COUNT; i++)
    {
        vector<stSceneBtn>  m_vSceneSet;

        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_1, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_2, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_3, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_4, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_5, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_6, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_7, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_8, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_9, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_10, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_11, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_12, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_13, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_14, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_15, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_16, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_17, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_18, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_19, nullptr });
        m_vSceneSet.push_back(stSceneBtn { m_pUi->m_pSceneBtn_20, nullptr });

        m_vvSceneButtons.push_back(m_vSceneSet);
    }
    // initialize the scene buttons
    for (auto sceneBtn : m_vvSceneButtons.at(0))
    {
        sceneBtn.pBtn->init();
    }


    // generate CHASE_COUNT sets of CHASE_BTN_COUNT buttons
    for (s32 i = 0; i < CHASE_SET_COUNT; i++)
    {
        vector<stChaseBtn>  m_vChaseTuple;

        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_1, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_2, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_3, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_4, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_5, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_6, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_7, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_8, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_9, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_10, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_11, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_12, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_13, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_14, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_15, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_16, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_17, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_18, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_19, nullptr });
        m_vChaseTuple.push_back(stChaseBtn { m_pUi->m_pChaseBtn_20, nullptr });

        m_vvChaseButtons.push_back(m_vChaseTuple);
    }
    // initialize the chase buttons
    for (auto chaseBtn : m_vvChaseButtons.at(0))
    {
        chaseBtn.pBtn->init();
    }

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

    // set the master fader
    m_pMasterFader = m_pUi->m_pFader_m;
    m_pMasterFader->setMasterFader();

    // set the bg of the switch on/off buttons
    m_pUi->m_pSwitchOn->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                  .arg(255)
                                  .arg(255)
                                  .arg(0));

    m_pUi->m_pSwitchOff->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                  .arg(0)
                                  .arg(0)
                                  .arg(0));

    // set the scribble strip for the faders
    m_pUi->m_pFader_1->init(m_pUi->m_pScribbleStrip_1, m_pUi->m_pFaderInfo_1, "1");
    m_pUi->m_pFader_2->init(m_pUi->m_pScribbleStrip_2, m_pUi->m_pFaderInfo_2, "2");
    m_pUi->m_pFader_3->init(m_pUi->m_pScribbleStrip_3, m_pUi->m_pFaderInfo_3, "3");
    m_pUi->m_pFader_4->init(m_pUi->m_pScribbleStrip_4, m_pUi->m_pFaderInfo_4, "4");
    m_pUi->m_pFader_5->init(m_pUi->m_pScribbleStrip_5, m_pUi->m_pFaderInfo_5, "5");
    m_pUi->m_pFader_6->init(m_pUi->m_pScribbleStrip_6, m_pUi->m_pFaderInfo_6, "6");
    m_pUi->m_pFader_7->init(m_pUi->m_pScribbleStrip_7, m_pUi->m_pFaderInfo_7, "7");
    m_pUi->m_pFader_8->init(m_pUi->m_pScribbleStrip_8, m_pUi->m_pFaderInfo_8, "8");
    m_pUi->m_pFader_9->init(m_pUi->m_pScribbleStrip_9, m_pUi->m_pFaderInfo_9, "9");
    m_pUi->m_pFader_10->init(m_pUi->m_pScribbleStrip_10, m_pUi->m_pFaderInfo_10, "10");
    m_pUi->m_pFader_11->init(m_pUi->m_pScribbleStrip_11, m_pUi->m_pFaderInfo_11, "11");
    m_pUi->m_pFader_12->init(m_pUi->m_pScribbleStrip_12, m_pUi->m_pFaderInfo_12, "12");
    m_pUi->m_pFader_13->init(m_pUi->m_pScribbleStrip_13, m_pUi->m_pFaderInfo_13, "13");
    m_pUi->m_pFader_14->init(m_pUi->m_pScribbleStrip_14, m_pUi->m_pFaderInfo_14, "14");
    m_pUi->m_pFader_15->init(m_pUi->m_pScribbleStrip_15, m_pUi->m_pFaderInfo_15, "15");
    m_pUi->m_pFader_16->init(m_pUi->m_pScribbleStrip_16, m_pUi->m_pFaderInfo_16, "16");
    m_pUi->m_pFader_17->init(m_pUi->m_pScribbleStrip_17, m_pUi->m_pFaderInfo_17, "17");
    m_pUi->m_pFader_18->init(m_pUi->m_pScribbleStrip_18, m_pUi->m_pFaderInfo_18, "18");
    m_pUi->m_pFader_19->init(m_pUi->m_pScribbleStrip_19, m_pUi->m_pFaderInfo_19, "19");
    m_pUi->m_pFader_20->init(m_pUi->m_pScribbleStrip_20, m_pUi->m_pFaderInfo_20, "20");
    m_pUi->m_pFader_21->init(m_pUi->m_pScribbleStrip_21, m_pUi->m_pFaderInfo_21, "21");
    m_pUi->m_pFader_22->init(m_pUi->m_pScribbleStrip_22, m_pUi->m_pFaderInfo_22, "22");
    m_pUi->m_pFader_23->init(m_pUi->m_pScribbleStrip_23, m_pUi->m_pFaderInfo_23, "23");
    m_pUi->m_pFader_24->init(m_pUi->m_pScribbleStrip_24, m_pUi->m_pFaderInfo_24, "24");

    m_pMasterFader->init(m_pUi->m_pScribbleStrip_m, m_pUi->m_pFaderInfo_m, "Msr");
    m_pMasterFader->setEnabled(true);

    // all buttons have the same bg color => get this color from any button
    m_colPushBtnBg = m_pUi->m_pBankBtn_1->palette().color(QPalette::Button);

} // MainWin::initMember


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
* MainWin::resetAllUniverses
*******************************************************************************/
void MainWin::resetAllUniverses(bool _bSend)
{
    for (auto &_pUniverse : m_lstUniverse)
    {
        _pUniverse->reset(_bSend);
    }
} // MainWin::resetAllUniverses


/*******************************************************************************
* MainWin::sendAllUniverses
*******************************************************************************/
void MainWin::sendAllUniverses()
{
    for (auto &_pUniverse : m_lstUniverse)
    {
        _pUniverse->sendDmxData();
    }
} // MainWin::sendAllUniverses


/*******************************************************************************
* MainWin::setMasterBrightness
*******************************************************************************/
void MainWin::setMasterBrightness(u8    _u8Value,
                                  bool  _bSend)
{
    CHECK_PRE_CONDITION_VOID(m_pMasterFader);

    m_u8MasterBrightness = _u8Value;

    updateMasterFader();

    // update the brightness in all fixtures
    for (shared_ptr<Universe> pU : m_lstUniverse)
    {
        pU->updateBrightness(_bSend);
    }
} // MainWin::setMasterBrightness


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
    // create the new fixture
    shared_ptr<Fixture>  pFixture = make_shared<Fixture> (_sName, _pDevice, _pUniverse, _s32Adress);

    // init the dmx-values in the universe
    _pUniverse->attachFixture(pFixture);

    // add the fixture to the fixture list
    m_lstFixture.push_back(std::move(pFixture));
} // MainWin::addFixture


/*******************************************************************************
* MainWin::activateBankButton
*******************************************************************************/
void MainWin::activateBankButton(shared_ptr<Fixture> _pFixture)
{
    for (stBankBtn &bankBtn : m_vvBankButtons.at(m_s32ActiveBank))
    {
        if (_pFixture && bankBtn.pFixture == _pFixture)
        {
            // _pFixture != nullptr AND _pFixture assigned to the button
            // => set active color
            bankBtn.pBtn->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                        .arg(m_colActive.red())
                                        .arg(m_colActive.green())
                                        .arg(m_colActive.blue()));
        }
        else
        {
            // _pFixture == nullptr OR _pFixture not assigned to the button
            // => set standard bg color
            bankBtn.pBtn->setStyleSheet(QString("background-color: rgb(%1, %2, %3);")
                                        .arg(m_colPushBtnBg.red())
                                        .arg(m_colPushBtnBg.green())
                                        .arg(m_colPushBtnBg.blue()));
        }
    }
} // MainWin::activateBankButton


/*******************************************************************************
* MainWin::assignFixture
*******************************************************************************/
void MainWin::assignFixture(BankButton    *_pBankBtn,
                            const QString &_sFixtureName)
{
    shared_ptr<Fixture>  pFixture = findFixture(_sFixtureName);

    for (stBankBtn &bankBtn : m_vvBankButtons.at(m_s32ActiveBank))
    {
        if (bankBtn.pBtn == _pBankBtn)
        {
            bankBtn.pFixture = pFixture;

            bankBtn.pBtn->setFixture(pFixture);
        }
    }
} // MainWin::assignFixture


/*******************************************************************************
* MainWin::assignScene
*******************************************************************************/
void MainWin::assignScene(SceneButton   *_pSceneBtn,
                          const QString &_sSceneName)
{
    // search the scene in the vector of scene buttons
    for (stSceneBtn &sceneBtn : m_vvSceneButtons.at(m_s32ActiveScene))
    {
        if (sceneBtn.pBtn == _pSceneBtn)
        {
            // scene button found => create a new scene
            shared_ptr<Scene> pScene = make_shared<Scene> (_sSceneName, m_u8MasterBrightness);
            pScene->addUniverses(m_lstUniverse);

            // set the scene in the tuple of the current set
            sceneBtn.pScene = pScene;

            // set the scene in the button
            _pSceneBtn->setScene(pScene);
        }
    }
} // MainWin::assignScene


/*******************************************************************************
* MainWin::findScene
*******************************************************************************/
shared_ptr<Scene> MainWin::findScene(const QString &_sName)
{
    CHECK_PRE_CONDITION(_sName != "", nullptr);

    // iterate over all scene sets
    for (s32 iSet = 0; iSet < SCENE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iScene = 0; iScene < SCENE_BTN_COUNT; iScene++)
        {
            shared_ptr<Scene> pScene = m_vvSceneButtons.at(iSet).at(iScene).pScene;

            if (pScene && pScene->name() == _sName)
            {
                return m_vvSceneButtons.at(iSet).at(iScene).pScene;
            }
        }
    }

    return nullptr;
} // MainWin::findScene


/*******************************************************************************
* MainWin::removeScene
*******************************************************************************/
void MainWin::removeScene(SceneButton   *_pSceneBtn)
{
    CHECK_PRE_CONDITION_VOID(_pSceneBtn);

    // search the scene in the vector of scene buttons in the current set
    for (stSceneBtn &sceneBtn : m_vvSceneButtons.at(m_s32ActiveScene))
    {
        if (sceneBtn.pBtn == _pSceneBtn && sceneBtn.pScene != nullptr)
        {
            vector<shared_ptr<Chase>> vChases = getAllChases();
            for (const shared_ptr<Chase> &pChase : vChases)
            {
                // scene is used in a chase => deletion not possible
                if (pChase->isSceneInChase(sceneBtn.pScene->name()))
                {
                    QMessageBox msgBox;

                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.setWindowTitle("Warning");
                    msgBox.setText("Scene is used in a chase,\nand can't be deleted!");     // Mehrzeiliger Text
                    msgBox.exec();

                    return;
                }
            }

            // remove the scene from the tuple of the current set
            sceneBtn.pScene = nullptr;

            // remove the scene in the button
            _pSceneBtn->setScene(nullptr);
        }
    }
} // MainWin::removeScene


/*******************************************************************************
* MainWin::getAllSceneNames
*******************************************************************************/
vector<QString> MainWin::getAllSceneNames() const
{
    vector<QString> vScenes;

    // iterate over all scene sets
    for (s32 iSet = 0; iSet < SCENE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iScene = 0; iScene < SCENE_BTN_COUNT; iScene++)
        {
            const stSceneBtn &sceneBtn  = m_vvSceneButtons.at(iSet).at(iScene);
            shared_ptr<Scene> pScene =sceneBtn.pScene;

            if (pScene)
            {
                vScenes.push_back(pScene->name());
            }
        }
    }

    return vScenes;
} // MainWin::getAllSceneNames


/*******************************************************************************
* MainWin::assignChase
*******************************************************************************/
void MainWin::assignChase(ChaseButton       *_pChaseBtn,
                          shared_ptr<Chase> _pChase)
{
    // search the chase btn in the vector of chase buttons for the current set
    for (stChaseBtn &chaseBtn : m_vvChaseButtons.at(m_s32ActiveChase))
    {
        if (chaseBtn.pBtn == _pChaseBtn)
        {
            // set the chase in the tuple of the current set
            chaseBtn.pChase = _pChase;

            // set the scene in the button
            _pChaseBtn->setChase(_pChase);
        }
    }
} // MainWin::assignChase


/*******************************************************************************
* MainWin::removeChase
*******************************************************************************/
void MainWin::removeChase(ChaseButton   *_pChaseBtn)
{
    // search the scene in the vector of scene buttons in the current set
    for (stChaseBtn &chaseBtn : m_vvChaseButtons.at(m_s32ActiveChase))
    {
        if (chaseBtn.pBtn == _pChaseBtn)
        {
            // remove the scene from the tuple of the current set
            chaseBtn.pChase = nullptr;

            // remove the scene in the button
            _pChaseBtn->setChase(nullptr);
        }
    }
} // MainWin::removeChase


/*******************************************************************************
* MainWin::getAllChases
*******************************************************************************/
vector<shared_ptr<Chase>> MainWin::getAllChases() const
{
    vector<shared_ptr<Chase>> vChases;

    // iterate over all scene sets
    for (s32 iSet = 0; iSet < CHASE_SET_COUNT; iSet++)
    {
        // iterate over all scene button within the current set
        for (s32 iChase = 0; iChase < CHASE_BTN_COUNT; iChase++)
        {
            const stChaseBtn &chaseBtn  = m_vvChaseButtons.at(iSet).at(iChase);
            shared_ptr<Chase> pChase = chaseBtn.pChase;

            if (pChase)
            {
                vChases.push_back(pChase);
            }
        }
    }

    return vChases;
} // MainWin::getAllChases


/*******************************************************************************
* MainWin::assignFaders
*******************************************************************************/
void MainWin::assignFaders(shared_ptr<Fixture> _pFixture)
{
    // _pFixture can be nullptr

    // set the button with the selected fixture to active
    m_pActiveFixture = _pFixture;
    activateBankButton(m_pActiveFixture);

    s32                                 iChannelIdx = 1;
    shared_ptr<Channel>                 pChannel;

    for (Fader *pFader : m_vFaders)
    {
        if (_pFixture)
        {
            const vector<shared_ptr<Channel>> &vChannel = _pFixture->device()->channel();

            auto it = std::find_if(vChannel.begin(), vChannel.end(),
                                   [iChannelIdx](const std::shared_ptr<Channel> &ch)
                                   { return ch && ch->nr() == iChannelIdx; } );

            pChannel = (it != vChannel.end())?   *it : nullptr;

            pFader->assignChannel(_pFixture, pChannel);
        }
        else
        {
            pFader->assignChannel(nullptr, nullptr);
        }

        iChannelIdx++;
    }
} // MainWin::assignFaders


/*******************************************************************************
* MainWin::updateAllChannelValuesFromUniverse
*******************************************************************************/
void MainWin::updateAllChannelValuesFromUniverse()
{
    for (shared_ptr<Fixture> pF : m_lstFixture)
    {
        pF->updateAllChannelValuesFromUniverse();
    }
} // MainWin::updateAllChannelValuesFromUniverse


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
