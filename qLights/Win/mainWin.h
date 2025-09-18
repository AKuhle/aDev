#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>
#include <QTableWidget>

#include "aSharedPtrList.h"
#include "aVector.h"
#include "controller.h"
#include "universe.h"
#include "device.h"
#include "fixture.h"


using namespace aFrame::aUtil;

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
        Ui::MainWin                     *m_pUi      { nullptr };
        list<shared_ptr<Controller>>    m_lstController;
        list<shared_ptr<Universe>>      m_lstUniverse;
        list<shared_ptr<Device>>        m_lstDevice;
        list<shared_ptr<Fixture>>       m_lstFixture;
        aVector<QPixmap>                m_lstChannelIcon;

    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        // controller
        void                addController(const QString &_sName,
                                          const QString &_sIpAdr);
        Controller*         findController(const QString &_sName);


        // universe
        void                addUniverse(const QString   &_sName,
                                        const QString   &_sController,
                                        s32             _s32Id);

        // device
        void                addDevice(const QString &_sName);

        // fixture
        void                addFixture(const QString &_sName);

        // update
        void                updateAll();
        void                updateGui();
        void                updateControllerPanel();
        void                updateUniversePanel();
        void                updateDevicePanel();
        void                updateFixturePanel();


    private:
        void                addTableWidgetItem(QTableWidget     *_pTableWidget,
                                               s32              _s32Row,
                                               s32              _s32Col,
                                               const QString    &_sItem);

        void                readChannelIcons();


    private slots:
        // ctrl-bar
        void                onFileOpen();
        void                onFileSave();
        void                onPanel();

        // conbtroller panel
        void                onAddController(bool _bChecked);
        void                onRemoveController(bool _bChecked);
        void                onEditController(bool _bChecked);

        void                onAddUniverse(bool _bChecked);
        void                onAddDevice(bool _bChecked);
        void                onAddFixture(bool _bChecked);
}; // class MainWin
