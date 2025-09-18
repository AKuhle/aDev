#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aUtil_def.h"
#include "aVector.h"

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
        const aVector<QPixmap>  &m_lstChannelIcon;

    public:
        explicit DlgDevice(MainWin                  *_pMainWin,
                           const aVector<QPixmap>   &_lstChannelIcon,
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
