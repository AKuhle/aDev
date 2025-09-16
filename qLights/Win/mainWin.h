#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QMainWindow>

#include "aUniquePtrList.h"
#include "controller.h"


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
        aUniquePtrList<Controller>      m_lstController;

    public:
        MainWin(QWidget *parent = nullptr);
        ~MainWin();

        // controller
        void                addController(const aString &_sName,
                                          const aString &_sIpAdr);

        // update
        void                updateAll();
        void                updateGui();
        void                updateControllerPanel();


    private slots:
        // ctrl-bar
        void                onFileOpen();
        void                onFileSave();
        void                onPanel();

        // conbtroller panel
        void                onAddController(bool _bChecked);
}; // class MainWin
