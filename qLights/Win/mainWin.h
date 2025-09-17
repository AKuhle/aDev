#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>
#include <QTableWidget>

#include "aSharedPtrList.h"
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
        aSharedPtrList<Controller>      m_lstController;
        aSharedPtrList<Universe>        m_lstUniverse;
        aSharedPtrList<Device>          m_lstDevice;
        aSharedPtrList<Fixture>         m_lstFixture;

    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        // controller
        void                addController(const aString &_sName,
                                          const aString &_sIpAdr);

        // universe
        void                addUniverse(const aString   &_sName,
                                        const aString   &_sController,
                                        s32             _s32Id);

        // device
        void                addDevice(const aString &_sName);

        // fixture
        void                addFixture(const aString &_sName);

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
                                               const aString    &_sItem);

    private slots:
        // ctrl-bar
        void                onFileOpen();
        void                onFileSave();
        void                onPanel();

        // conbtroller panel
        void                onAddController(bool _bChecked);
        void                onAddUniverse(bool _bChecked);
        void                onAddDevice(bool _bChecked);
        void                onAddFixture(bool _bChecked);
}; // class MainWin
