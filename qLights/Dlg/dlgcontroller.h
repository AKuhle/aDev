#pragma once

#include <QDialog>

namespace Ui {
class DlgController;
}


/*******************************************************************************
* class DlgController
*******************************************************************************/
class MainWin;
class Controller;


/*******************************************************************************
* class DlgController
*******************************************************************************/
class DlgController : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgController       *m_pUi;
        MainWin                 *m_pMainWin;
        Controller              *m_pController;

    public:
        explicit DlgController(MainWin    *_pMainWin,
                               Controller *_pController);
        ~DlgController();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgController
