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

using namespace std;
using namespace aFrame;



/*******************************************************************************
* class Fixture
*******************************************************************************/
class Fixture
{
    private:
        QString             m_sName;
        shared_ptr<Device>  m_pDevice;

    public:
        Fixture(const QString       &_sName,
                shared_ptr<Device>  _pDevice);
        ~Fixture();

        const QString&                      name() const                            { return m_sName; }
        void                                setName(const QString &_sName)          { m_sName = _sName; }

        shared_ptr<Device>                  device() const                          { return m_pDevice; }
        void                                setDevice(shared_ptr<Device>  _pDevice) { m_pDevice = _pDevice; }


        //void                                addUniverse(u32 _u32Id);

        // void                                setDmxChannelValue(s32      _s32UniverseId,
        //                                                        s32      _s32DmxChannelNr,
        //                                                        u8       _u8Value,
        //                                                        bool     _bSend);

        //void                                sendAllUniverses();

        //shared_ptr<Universe>                universe(u32 _u32Id);

        //void                                resetAllUniverses();
}; // class Fixture
