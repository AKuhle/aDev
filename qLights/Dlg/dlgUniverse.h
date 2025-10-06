#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aUtil_def.h"

class Controller;

using namespace aFrame::aUtil;
using namespace std;



namespace Ui {
class DlgUniverse;
}


/*******************************************************************************
* class DlgUniverse
*******************************************************************************/
class Universe;


/*******************************************************************************
* class DlgUniverse
*******************************************************************************/
class DlgUniverse : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgUniverse         *m_pUi;
        shared_ptr<Universe>    m_pUniverse;

    public:
        explicit DlgUniverse(QWidget                            *_pParent,
                             const list<shared_ptr<Controller>> &_lstController,
                             shared_ptr<Universe>               _pUniverse);
        ~DlgUniverse();

    private:
        void                    setCtrls(const shared_ptr<Universe> _pUniverse);

        virtual void            accept();
        virtual void            reject();
}; // class DlgUniverse
