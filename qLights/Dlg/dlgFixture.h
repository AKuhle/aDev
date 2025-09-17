#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aUtil_def.h"

using namespace aFrame::aUtil;


namespace Ui {
class DlgFixture;
}


/*******************************************************************************
* class DlgFixture
*******************************************************************************/
class MainWin;
class Fixture;


/*******************************************************************************
* class DlgFixture
*******************************************************************************/
class DlgFixture : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgFixture  *m_pUi;
        MainWin         *m_pMainWin;
        Fixture         *m_pFixture;

    public:
        explicit DlgFixture(MainWin *_pMainWin,
                            Fixture *_pFixture);
        ~DlgFixture();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgFixture
