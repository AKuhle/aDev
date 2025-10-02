/*******************************************************************************
* \file Device.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QString>

#include "aFrame_def.h"
#include "channel.h"


class Universe;

using namespace std;
using namespace aFrame;


/*******************************************************************************
* class Device
*******************************************************************************/
class Device
{
    private:
        QString                         m_sName;
        QString                         m_sPixmapName;
        QPixmap                         m_pixmap;
        vector<shared_ptr<Channel>>     m_vChannel;

    public:
        Device(const QString                        &_sName,
               const QString                        &_sPixmap,
               const vector<shared_ptr<Channel>>    &_vChannel);
        ~Device();

        const QString&                      name() const                                                { return m_sName; }
        void                                setName(const QString &_sName)                              { m_sName = _sName; }

        const QPixmap&                      pixmap() const                                              { return m_pixmap; }
        const QString&                      pixmapName() const                                          { return m_sPixmapName; }
        void                                setPixmap(const QString &_sPixmapName);

        const vector<shared_ptr<Channel>>   &channel() const                                            { return m_vChannel; }
        s32                                 channelCount() const                                        { return m_vChannel.size(); }
        void                                setChannel(const vector<shared_ptr<Channel>> &_vChannel)    { m_vChannel = _vChannel; }

        //void                                addUniverse(u32 _u32Id);

        // void                                setDmxChannelValue(s32      _s32UniverseId,
        //                                                        s32      _s32DmxChannelNr,
        //                                                        u8       _u8Value,
        //                                                        bool     _bSend);

        //void                                sendAllUniverses();

        //shared_ptr<Universe>                universe(u32 _u32Id);

        //void                                resetAllUniverses();
}; // class Device
