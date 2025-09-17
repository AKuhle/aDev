#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aUtil_def.h"

using namespace aFrame::aUtil;


namespace Ui {
class DlgDevice;
}


/*******************************************************************************
* class DlgDevice
*******************************************************************************/
class MainWin;
class Device;


/*******************************************************************************
* class DlgDevice
*******************************************************************************/
class DlgDevice : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgDevice   *m_pUi;
        MainWin         *m_pMainWin;
        Device          *m_pDevice;

    public:
        explicit DlgDevice(MainWin  *_pMainWin,
                           Device   *_pDevice);
        ~DlgDevice();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgDevice
