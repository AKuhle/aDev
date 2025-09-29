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
        shared_ptr<Device>      m_pDevice;
        const vector<QString>   &m_lstDeviceIconName;
        const vector<QPixmap>   &m_lstChannelIcon;
        s32                     m_s32ImageIdx       { 0 };

    public:
        explicit DlgDevice(MainWin                  *_pMainWin,
                           const vector<QString>    &_lstDeviceIconName,
                           const vector<QPixmap>    &_lstChannelIcon,
                           shared_ptr<Device>       _pDevice);
        ~DlgDevice();

        void                    addChannel(s32              _s32ChannelNr,
                                           const QString    &_s32ChannelName,
                                           const QPixmap    &_pixmap,
                                           bool             _bBrigthness);

    private:
        void                    setCtrls(const shared_ptr<Device> _pDevice);
        void                    setDeviceIcon(const QString &_path);

        virtual void            accept();
        virtual void            reject();

    private slots:
        void                    onPrevImage(bool _bChecked);
        void                    onNextImage(bool _bChecked);

        void                    onAddChannel(bool _bChecked);
}; // class DlgDevice
