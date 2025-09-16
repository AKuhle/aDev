#pragma once

#include <QDialog>

namespace Ui {
class DlgController;
}


/*******************************************************************************
* class DlgController
*******************************************************************************/
class DlgController : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgController       *m_pUi;

    public:
        explicit DlgController(QWidget *parent = nullptr);
        ~DlgController();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgController
