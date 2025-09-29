#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>

#include "qLights_def.h"

using namespace std;

class Controller;


namespace Ui {
class DlgChannel;
}


/*******************************************************************************
* class DlgChannel
*******************************************************************************/
class DlgDevice;


/*******************************************************************************
* class DlgChannel
*******************************************************************************/
class DlgChannel : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgChannel      *m_pUi;
        DlgDevice           *m_pDlgDevice   { nullptr };

    public:
        explicit DlgChannel(DlgDevice               *_pDlgDevice,
                            const vector<QString>   &_lstChannelIcon);
        ~DlgChannel();

    private:
        virtual void                        accept();
        virtual void                        reject();
}; // class DlgChannel
