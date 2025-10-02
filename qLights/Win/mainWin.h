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
#include "fixture.h"


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
        vector<vector<shared_ptr<Fixture>>> m_banks { { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
                                                      { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
                                                      { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
                                                      { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
                                                      { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };

        // scene buttons
        // vector<vector<shared_ptr<Fixture>>> m_banks { { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };

        // bank buttons
        // vector<vector<shared_ptr<Fixture>>> m_banks { { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },
        //                                               { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };

    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        // controller
        void                    addController(const QString &_sName,
                                          const QString &_sIpAdr);

        shared_ptr<Controller>  findController(const QString &_sName);


        // universe
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
                                           shared_ptr<Device>   _pDevice);

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

        void                    onBankButton_1(bool _bChecked);
        void                    onBankButton_2(bool _bChecked);
        void                    onBankButton_3(bool _bChecked);
        void                    onBankButton_4(bool _bChecked);
        void                    onBankButton_5(bool _bChecked);

        void                    onSceneButton_1(bool _bChecked);
        void                    onSceneButton_2(bool _bChecked);
        void                    onSceneButton_3(bool _bChecked);
        void                    onSceneButton_4(bool _bChecked);
        void                    onSceneButton_5(bool _bChecked);

        void                    onChaseButton_1(bool _bChecked);
        void                    onChaseButton_2(bool _bChecked);
        void                    onChaseButton_3(bool _bChecked);
        void                    onChaseButton_4(bool _bChecked);
        void                    onChaseButton_5(bool _bChecked);
}; // class MainWin
