/*******************************************************************************
* \file Device.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "Device.h"
#include "universe.h"

using namespace aFrame;


/*******************************************************************************
* Device::Device
*******************************************************************************/
Device::Device(const QString                            &_sName,
               const QString                            &_sPixmap,
               const vector<stRgbGroup>                 &_vRgbGroups,
               const vector<shared_ptr<ChannelDevice>>  &_vChannel)
: m_sName(_sName),
  m_vRgbGroups(_vRgbGroups),
  m_vChannel(_vChannel)
{
    setPixmap(_sPixmap);
} // Device::Device


/*******************************************************************************
* Device::~Device
*******************************************************************************/
Device::~Device()
{
} // Device::~Device


/*******************************************************************************
* Device::setPixmap
*******************************************************************************/
void Device::setPixmap(const QString &_sPixmapName)
{
    m_sPixmapName = _sPixmapName;

    m_pixmap.load(m_sPixmapName);
} // setPixmap
