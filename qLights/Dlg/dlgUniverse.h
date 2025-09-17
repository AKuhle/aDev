#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aUtil_def.h"

class Controller;

using namespace aFrame::aUtil;


namespace Ui {
class DlgUniverse;
}


/*******************************************************************************
* class DlgUniverse
*******************************************************************************/
class MainWin;
class Universe;


/*******************************************************************************
* class DlgUniverse
*******************************************************************************/
class DlgUniverse : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgUniverse         *m_pUi;
        MainWin                 *m_pMainWin;
        Universe                *m_pUniverse;

    public:
        explicit DlgUniverse(MainWin                            *_pMainWin,
                             const aSharedPtrList<Controller>   &_lstController,
                             Universe                           *_pUniverse);
        ~DlgUniverse();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgUniverse
