#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QPushButton>

#include "qLights_def.h"
#include "controller.h"
#include "universe.h"
#include "device.h"
#include "fader.h"

class BankButton;
class SceneButton;
class ChaseButton;
class Fixture;
class Scene;
class Chase;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public QMainWindow
{
    Q_OBJECT

    private:
        static MainWin                      *m_pInstance;

        Ui::MainWin                         *m_pUi                  { nullptr };
        list<shared_ptr<Controller>>        m_lstController;
        list<shared_ptr<Universe>>          m_lstUniverse;
        list<shared_ptr<Device>>            m_lstDevice;
        list<shared_ptr<Fixture>>           m_lstFixture;

        vector<QString>                     m_lstDeviceIconName;
        vector<QString>                     m_lstChannelIcon;

        QColor                              m_colPushBtnBg;
        QColor                              m_colActive             { 0, 110, 98 };

        // active buttons
        s32                                 m_s32ActiveBank         { BANK_1 };
        s32                                 m_s32ActiveScene        { SCENE_1 };
        s32                                 m_s32ActiveChase        { CHASE_1 };
        shared_ptr<Fixture>                 m_pActiveFixture;

        bool                                m_bShowValues           { false };

        static u8                           m_u8MasterBrightness;

        // fade in/out values to fade the master brightness
        float                               m_fFaderValue;
        float                               m_fFaderStep;
        u8                                  m_u8FaderInterval;

        // bank buttons
        // all sets have the same buttons, but different Fixtures per layer
        vector<vector<stBankBtn>>           m_vvBankButtons;

        // scene buttons
        // all sets have the same buttons, but different scenes per layer
        vector<vector<stSceneBtn>>          m_vvSceneButtons;

        // chase buttons
        // all sets have the same buttons, but different chases per layer
        vector<vector<stChaseBtn>>          m_vvChaseButtons;

        // faders
        vector<Fader *>                     m_vFaders;
        Fader                               *m_pMasterFader         { nullptr };


    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        static MainWin*             instance()                  { return m_pInstance; }

        bool                        isShowValues() const        { return m_bShowValues; }

        // controller
        void                        addController(const QString &_sName,
                                                  const QString &_sIpAdr);

        shared_ptr<Controller>      findController(const QString &_sName);


        // universe
        const list<shared_ptr<Universe>>& universes() const     { return m_lstUniverse; }

        shared_ptr<Universe>        findUniverse(const QString &_sName);

        void                        addUniverse(const QString   &_sName,
                                                const QString   &_sController,
                                                s32             _s32Id);

        void                        resetAllUniverses();

        void                        setMasterBrightness(u8 _u8Value);
        static u8                   masterBrightness()          { return m_u8MasterBrightness; }


        // device
        void                        addDevice(const QString                             &_sName,
                                              const QString                             &_sImage,
                                              const vector<shared_ptr<ChannelDevice>>   &_vChannel);

        shared_ptr<Device>          findDevice(const QString &_sName);

        // fixture
        void                        addFixture(const QString        &_sName,
                                               shared_ptr<Device>   _pDevice,
                                               shared_ptr<Universe> _pUniverse,
                                               s32                  _s32Adress);

        shared_ptr<Fixture>         findFixture(const QString &_sName);

        const list<shared_ptr<Fixture>>&    getAllFixtures() const  { return m_lstFixture; }

        // banks
        void                        activateBankButton(shared_ptr<Fixture> _pFixture);

        void                        assignFixture(BankButton    *_pBankBtn,
                                                  const QString &_sFixtureName);

        // scenes
        void                        assignScene(SceneButton     *_pBankBtn,
                                                const QString   &_sSceneName,
                                                bool            _bBlackStart,
                                                vector<QString> _vFixtureNames);

        shared_ptr<Scene>           findScene(const QString &_sName);


        void                        removeScene(SceneButton   *_pSceneBtn);

        vector<QString>             getAllSceneNames() const;

        // chases
        void                        activateChaseButton(Chase   *_pChase,
                                                        bool    _bActive);

        void                        assignChase(ChaseButton         *_pBankBtn,
                                                shared_ptr<Chase>   _pChase);

        void                        removeChase(ChaseButton   *_pBankBtn);

        vector<shared_ptr<Chase>>   getAllChases() const;

        // faders
        void                        assignFaders(shared_ptr<Fixture> _pFixture);
        void                        updateFaders() const;

        // update
        void                        initGui();  // reset all active banks/scenes etc.

        void                        updateAll();

        void                        updateToolbar();

        void                        updateBankButtons();
        void                        updateSceneButtons();
        void                        updateChaseButtons();
        void                        updateFaders();
        void                        updateMasterFader();

        void                        updateControllerPanel();
        void                        updateUniversePanel();
        void                        updateDevicePanel();
        void                        updateFixturePanel();

        // public Qt helper
        static void                 selectComboBoxItem(QComboBox     *_pCombo,
                                                       const QString &_sItem);


    private:
        void                        initMember();

        static void                 addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                       s32              _s32Row,
                                                       s32              _s32Col,
                                                       s32              _s32Value);

        static void                 addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                       s32              _s32Row,
                                                       s32              _s32Col,
                                                       const QString    &_sItem);

        static void                 addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                       s32              _s32Row,
                                                       s32              _s32Col,
                                                       const QPixmap    &_pixmap);

        void                        readChannelIcons();

        void                        onStartFaderIn(int    _iSteps,
                                                   int    _iDuration_ms);

        void                        onStartFaderOut(int    _iSteps,
                                                    int    _iDuration_ms);

        void                        openFile(aPath _path);
        void                        saveFile(aPath _path);



    private slots:
        // ctrl-bar
        void                        onFileOpen();
        void                        onFileSave();
        void                        onBackupOpen();
        void                        onBackupSave();
        void                        onPanel();
        void                        onShowValues();

        // controller panel
        void                        onAddController(bool _bChecked);
        void                        onRemoveController(bool _bChecked);
        void                        onEditController(bool _bChecked);

        void                        onAddUniverse(bool _bChecked);
        void                        onRemoveUniverse(bool _bChecked);
        void                        onEditUniverse(bool _bChecked);

        void                        onAddDevice(bool _bChecked);
        void                        onRemoveDevice(bool _bChecked);
        void                        onEditDevice(bool _bChecked);

        void                        onAddFixture(bool _bChecked);
        void                        onRemoveFixture(bool _bChecked);
        void                        onEditFixture(bool _bChecked);

        void                        onBankSelector_1(bool _bChecked);
        void                        onBankSelector_2(bool _bChecked);
        void                        onBankSelector_3(bool _bChecked);
        void                        onBankSelector_4(bool _bChecked);
        void                        onBankSelector_5(bool _bChecked);
        void                        onClearBank(bool _bChecked);
        void                        onResetFixtures(bool _bChecked);

        void                        onSceneSelector_1(bool _bChecked);
        void                        onSceneSelector_2(bool _bChecked);
        void                        onSceneSelector_3(bool _bChecked);
        void                        onSceneSelector_4(bool _bChecked);
        void                        onSceneSelector_5(bool _bChecked);
        void                        onClearScenes(bool _bChecked);

        void                        onChaseSelector_1(bool _bChecked);
        void                        onChaseSelector_2(bool _bChecked);
        void                        onChaseSelector_3(bool _bChecked);
        void                        onChaseSelector_4(bool _bChecked);
        void                        onChaseSelector_5(bool _bChecked);
        void                        onClearChases(bool _bChecked);

        void                        onFaderIn_1s(bool _bChecked);
        void                        onFaderIn_2s(bool _bChecked);
        void                        onFaderIn_3s(bool _bChecked);
        void                        onFaderIn_5s(bool _bChecked);
        void                        onFaderIn_10s(bool _bChecked);
        void                        onFaderOut_1s(bool _bChecked);
        void                        onFaderOut_2s(bool _bChecked);
        void                        onFaderOut_3s(bool _bChecked);
        void                        onFaderOut_5s(bool _bChecked);
        void                        onFaderOut_10s(bool _bChecked);
        void                        onFade();
        void                        onSwitchOn(bool _bChecked);
        void                        onSwitchOff(bool _bChecked);
}; // class MainWin
