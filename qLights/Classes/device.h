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
#include "qLights_def.h"
#include "channelDevice.h"


class Universe;

using namespace std;
using namespace aFrame;


/*******************************************************************************
* class Device
*******************************************************************************/
class Device
{
    private:
        QString                             m_sName;
        QString                             m_sPixmapName;
        QPixmap                             m_pixmap;
        vector<stRgbGroup>                  m_vRgbGroups;
        vector<shared_ptr<ChannelDevice>>   m_vChannel;

    public:
        Device(const QString                            &_sName,
               const QString                            &_sPixmap,
               const vector<stRgbGroup>                 &_vRgbGroups,
               const vector<shared_ptr<ChannelDevice>>  &_vChannel);
        ~Device();

        const QString&                          name() const                                                    { return m_sName; }
        void                                    setName(const QString &_sName)                                  { m_sName = _sName; }

        const QPixmap&                          pixmap() const                                                  { return m_pixmap; }
        const QString&                          pixmapName() const                                              { return m_sPixmapName; }
        void                                    setPixmap(const QString &_sPixmapName);

        const vector<shared_ptr<ChannelDevice>> &channel() const                                                { return m_vChannel; }
        s32                                     channelCount() const                                            { return m_vChannel.size(); }
        void                                    setChannel(const vector<shared_ptr<ChannelDevice>> &_vChannel)  { m_vChannel = _vChannel; }

        const vector<stRgbGroup>&               rgbGroups() const                                               { return m_vRgbGroups; }
        void                                    setRgbGroups(const vector<stRgbGroup>& _vRgbGroups)             { m_vRgbGroups = _vRgbGroups; }
}; // class Device
