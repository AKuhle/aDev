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
class Fixture;
class Device;
class Universe;


/*******************************************************************************
* class DlgFixture
*******************************************************************************/
class DlgFixture : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgFixture              *m_pUi;
        list<shared_ptr<Device>>    m_lstDevice;
        list<shared_ptr<Universe>>  m_lstUniverse;
        shared_ptr<Fixture>         m_pFixture;

    public:
        explicit DlgFixture(QWidget                     *_pParent,
                            list<shared_ptr<Device>>    _lstDevice,
                            list<shared_ptr<Universe>>  _lstUniverse,
                            shared_ptr<Fixture>         _pFixture);
        ~DlgFixture();

    private:
        void                    setCtrls(const shared_ptr<Fixture> _pFixture);

        virtual void            accept();
        virtual void            reject();
}; // class DlgFixture
