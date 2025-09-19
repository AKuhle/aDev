#pragma once

#include <QDialog>

#include "aFrame_def.h"

using namespace std;

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
        shared_ptr<Controller>  m_pController;

    public:
        explicit DlgController(MainWin                  *_pMainWin,
                               shared_ptr<Controller>   _pController);
        ~DlgController();

    private:
        void                    setCtrls(shared_ptr<Controller> _pController);
        void                    readCtrls(shared_ptr<Controller> _pController);

        virtual void            accept();
        virtual void            reject();
}; // class DlgController
