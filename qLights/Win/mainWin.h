#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>

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

        Ui::MainWin                         *m_pUi      { nullptr };
        list<shared_ptr<Controller>>        m_lstController;
        list<shared_ptr<Universe>>          m_lstUniverse;
        list<shared_ptr<Device>>            m_lstDevice;
        list<shared_ptr<Fixture>>           m_lstFixture;

        vector<QString>                     m_lstDeviceIconName;
        vector<QString>                     m_lstChannelIcon;

        // active buttons
        s32                                 m_s32ActiveBank     { BANK_1 };
        s32                                 m_s32ActiveScene    { SCENE_1 };
        s32                                 m_s32ActiveChase    { CHASE_1 };

        // bank buttons
        using BankTuple = std::tuple<BankButton *, shared_ptr<Fixture>>;
        vector<vector<BankTuple>>           m_vvBankButtons;

        // scene buttons
        //using SceneTuple = std::tuple<SceneButton *, shared_ptr<Scene>>;
        vector<vector<SceneButton *>>       m_vvSceneButtons;

        // chase buttons
        using ChaseTuple = std::tuple<ChaseButton *, shared_ptr<Chase>>;
        vector<vector<ChaseTuple>>          m_vvChaseButtons;

        // faders
        vector<Fader *>                     m_vFaders;


    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        static MainWin*         instance()                  { return m_pInstance; }

        // controller
        void                    addController(const QString &_sName,
                                              const QString &_sIpAdr);

        shared_ptr<Controller>  findController(const QString &_sName);


        // universe
        const list<shared_ptr<Universe>>& universes() const  { return m_lstUniverse; }

        shared_ptr<Universe>    findUniverse(const QString &_sName);

        void                    addUniverse(const QString   &_sName,
                                            const QString   &_sController,
                                            s32             _s32Id);

        // device
        void                    addDevice(const QString                     &_sName,
                                          const QString                     &_sImage,
                                          const vector<shared_ptr<Channel>> &_vChannel);

        shared_ptr<Device>      findDevice(const QString &_sName);

        // fixture
        void                    addFixture(const QString        &_sName,
                                           shared_ptr<Device>   _pDevice,
                                           shared_ptr<Universe> _pUniverse,
                                           s32                  _s32Adress);

        // banks
        void                    assignFixture(BankButton    *_pBankBtn,
                                              const QString &_sFixtureName);

        // faders
        void                    assignFaders(shared_ptr<Fixture> _pFixture);


        shared_ptr<Fixture>     findFixture(const QString &_sName);

        // update
        void                    updateAll();

        void                    updatePanel();

        void                    updateBankButtons();
        void                    updateSceneButtons();
        void                    updateChaseButtons();

        void                    updateControllerPanel();
        void                    updateUniversePanel();
        void                    updateDevicePanel();
        void                    updateFixturePanel();

        // public Qt helper
        static void             selectComboBoxItem(QComboBox     *_pCombo,
                                                   const QString &_sItem);


    private:
        void                    createCtrlVectors();

        static void             addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                   s32              _s32Row,
                                                   s32              _s32Col,
                                                   s32              _s32Value);

        static void             addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                   s32              _s32Row,
                                                   s32              _s32Col,
                                                   const QString    &_sItem);

        static void             addTableWidgetItem(QTableWidget     *_pTableWidget,
                                                   s32              _s32Row,
                                                   s32              _s32Col,
                                                   const QPixmap    &_pixmap);

        void                    readChannelIcons();


    private slots:
        // ctrl-bar
        void                    onFileOpen();
        void                    onFileSave();
        void                    onPanel();

        // conbtroller panel
        void                    onAddController(bool _bChecked);
        void                    onRemoveController(bool _bChecked);
        void                    onEditController(bool _bChecked);

        void                    onAddUniverse(bool _bChecked);
        void                    onRemoveUniverse(bool _bChecked);
        void                    onEditUniverse(bool _bChecked);

        void                    onAddDevice(bool _bChecked);
        void                    onRemoveDevice(bool _bChecked);
        void                    onEditDevice(bool _bChecked);

        void                    onAddFixture(bool _bChecked);
        void                    onRemoveFixture(bool _bChecked);
        void                    onEditFixture(bool _bChecked);

        void                    onBankSelector_1(bool _bChecked);
        void                    onBankSelector_2(bool _bChecked);
        void                    onBankSelector_3(bool _bChecked);
        void                    onBankSelector_4(bool _bChecked);
        void                    onBankSelector_5(bool _bChecked);
        void                    onClearBank(bool _bChecked);

        void                    onSceneSelector_1(bool _bChecked);
        void                    onSceneSelector_2(bool _bChecked);
        void                    onSceneSelector_3(bool _bChecked);
        void                    onSceneSelector_4(bool _bChecked);
        void                    onSceneSelector_5(bool _bChecked);

        void                    onChaseSelector_1(bool _bChecked);
        void                    onChaseSelector_2(bool _bChecked);
        void                    onChaseSelector_3(bool _bChecked);
        void                    onChaseSelector_4(bool _bChecked);
        void                    onChaseSelector_5(bool _bChecked);
}; // class MainWin
