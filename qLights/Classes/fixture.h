/*******************************************************************************
* \file Fixture.h
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

class Device;
class Universe;

using namespace std;
using namespace aFrame;



/*******************************************************************************
* class Fixture
*******************************************************************************/
class Fixture
{
    private:
        QString                 m_sName;
        shared_ptr<Device>      m_pDevice;
        shared_ptr<Universe>    m_pUniverse;
        s32                     m_s32Adress     { 1 };

    public:
        Fixture(const QString           &_sName,
                shared_ptr<Device>      _pDevice,
                shared_ptr<Universe>    _pUniverse,
                s32                     _s32Adress);
        ~Fixture();

        const QString&                      name() const                                    { return m_sName; }
        void                                setName(const QString &_sName)                  { m_sName = _sName; }

        shared_ptr<Device>                  device() const                                  { return m_pDevice; }
        void                                setDevice(shared_ptr<Device>  _pDevice)         { m_pDevice = _pDevice; }

        shared_ptr<Universe>                universe() const                                { return m_pUniverse; }
        void                                setUniverse(shared_ptr<Universe> _pUniverse)    { m_pUniverse = _pUniverse; }

        s32                                 adress() const                                  { return m_s32Adress; }
        void                                setAdress(s32 _s32Adress)                       { m_s32Adress = _s32Adress; }

        void                                resetFixture();

        void                                updateAllChannelValuesFromUniverse();
}; // class Fixture
