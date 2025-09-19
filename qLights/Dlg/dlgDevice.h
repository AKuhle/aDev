#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aFrame_def.h"
#include "aUtil_def.h"

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;


namespace Ui {
class DlgDevice;
}


/*******************************************************************************
* class DlgDevice
*******************************************************************************/
class MainWin;
class Device;
class Channel;


/*******************************************************************************
* class DlgDevice
*******************************************************************************/
class DlgDevice : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgDevice           *m_pUi;
        MainWin                 *m_pMainWin;
        Device                  *m_pDevice;
        const vector<QPixmap>   &m_lstChannelIcon;

    public:
        explicit DlgDevice(MainWin                  *_pMainWin,
                           const vector<QPixmap>    &_lstChannelIcon,
                           Device                   *_pDevice);
        ~DlgDevice();

        void                                addChannel(s32              _s32ChannelNr,
                                                       const QString    &_s32ChannelName,
                                                       const QPixmap    &_pixmap,
                                                       bool             _bBrigthness);

    private:
        virtual void                        accept();
        virtual void                        reject();

    private slots:
        void                                onAddChannel(bool _bChecked);
}; // class DlgDevice
