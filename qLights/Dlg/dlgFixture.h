#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>

#include "aFrame_def.h"

#include "aUtil_def.h"

using namespace std;
using namespace aFrame::aUtil;


namespace Ui {
class DlgFixture;
}


/*******************************************************************************
* class DlgFixture
*******************************************************************************/
class MainWin;
class Fixture;
class Device;


/*******************************************************************************
* class DlgFixture
*******************************************************************************/
class DlgFixture : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgFixture              *m_pUi;
        MainWin                     *m_pMainWin;
        list<shared_ptr<Device>>    m_lstDevice;
        shared_ptr<Fixture>         m_pFixture;

    public:
        explicit DlgFixture(MainWin                     *_pMainWin,
                            list<shared_ptr<Device>>    _lstDevice,
                            shared_ptr<Fixture>         _pFixture);
        ~DlgFixture();

    private:
        void                    setCtrls(const shared_ptr<Fixture> _pFixture);

        virtual void            accept();
        virtual void            reject();
}; // class DlgFixture
