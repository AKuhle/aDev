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
class Controller;


/*******************************************************************************
* class DlgController
*******************************************************************************/
class DlgController : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgController       *m_pUi          { nullptr };
        shared_ptr<Controller>  m_pController;

    public:
        explicit DlgController(QWidget                  *_pParent,
                               shared_ptr<Controller>   _pController);
        ~DlgController();

    private:
        void                    setCtrls(shared_ptr<Controller> _pController);
        void                    readCtrls(shared_ptr<Controller> _pController);

        virtual void            accept();
        virtual void            reject();
}; // class DlgController
