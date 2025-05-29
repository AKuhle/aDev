/*******************************************************************************
* \file CtrlPanel.cpp
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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "ctrlPanel.h"
#include "controller.h"
#include "bank.h"
#include "fixture.h"

using namespace aLib::aUtil;


/*******************************************************************************
* CtrlPanel::writeConfiguration
*******************************************************************************/
void CtrlPanel::writeConfiguration(const aPath &_path)
{
    aJsonFile   jf(_path);

    // add controller and universes
    for (shared_ptr<Controller> &pController : m_vController)
    {
        pController->add2Configuration(jf);
    }

    // add banks
    for (shared_ptr<Bank> &pBank : m_vBank)
    {
        pBank->add2Configuration(jf);
    }

    // add fixtures
    for (shared_ptr<Fixture> &pFix : m_vFixture)
    {
        pFix->add2Configuration(jf);
    }

    // write the json file
    jf.write2File();
} // CtrlPanel::writeConfiguration


/*******************************************************************************
* CtrlPanel::readConfiguration
*******************************************************************************/
void CtrlPanel::readConfiguration(const aPath &_path)
{
    // delete previous configuration
    m_mapBankIoInfo.clear();
    m_mapFixtureIoInfo.clear();

    aJsonFile   jFile(_path);

    // read all entries
    jFile.readAllValues([this](const aVector<aString> &_vecKeys, const aJsonValue &_value) {
                        this->JsonCallback(_vecKeys, _value);
    });


    // generate the controller
    for (auto me : m_mapControllerIoInfo)
    {
        controllerIoInfo &ci = me.second;

        aString                         sCtrlName   = std::get<0> (ci);
        aString                         sCtrlAdress = std::get<1> (ci);
        s32                             s32CtrlUniMax = std::get<2> (ci);

        if (true)
            cout << sCtrlName << " - "
                 << sCtrlAdress << " - "
                 << s32CtrlUniMax << " - "
                 << endl;

                // generate the universes
        aMap<aString, universeIoInfo>   &mapUni = std::get<3> (ci);
        for (auto uniME : mapUni)
        {
            universeIoInfo &ui = uniME.second;

            s32         s32UniId    = std::get<0> (ui);
            QByteArray  &ba         = std::get<1> (ui);

            if (true)
                cout << s32UniId << " - "
                     << ba.size() << " - "
                     << endl;

        }

    } // for (auto me : m_mapControllerIoInfo)


    // generate the features
    for (auto me : m_mapFixtureIoInfo)
    {
        fixtureIoInfo &fi = me.second;

        aString     sFixName            = std::get<0> (fi);
        aString     sFixController      = std::get<1> (fi);
        s32         s32FixUniverseId    = std::get<2> (fi);
        s32         s32FixChannelOs     = std::get<3> (fi);

        if (true)
            cout << sFixName << " - "
                 << sFixController << " - "
                 << s32FixUniverseId << " - "
                 << s32FixChannelOs << " - "
                 << endl;

        for (auto ci : std::get<4> (fi))
        {
            aString sChannelName            = std::get<0> (ci.second);
            s32     s32ChannelUniverseId    = std::get<1> (ci.second);
            s32     s32ChannelOs            = std::get<2> (ci.second);
            s32     s32ChannelNr            = std::get<3> (ci.second);
            aString sChannelIcon            = std::get<4> (ci.second);
            bool    bChannelBrightness      = std::get<5> (ci.second);
            u32     u32ChannelValue         = std::get<6> (ci.second);

            if (true)
                cout << "     channel -->"
                     << sChannelName << " - "
                     << s32ChannelUniverseId << " - "
                     << s32ChannelOs << " - "
                     << s32ChannelNr << " - "
                     << sChannelIcon << " - "
                     << bChannelBrightness << " - "
                     << u32ChannelValue << " - "
                     << endl;

        }
    }


    // generate the banks
    for (auto me : m_mapBankIoInfo)
    {
        bankIoInfo &bi = me.second;

        aString sBankName = std::get<0> (bi);

        for (auto fix : std::get<1> (bi))
        {
            s32     s32BankBtnIdx   = fix.first;
            aString sFixName        = fix.second;

            //shared_ptr<Bank> pBank1 = createBank("KMC-1");
            //assignBank(pBank1, 0);

            if (false)
                cout <<sBankName << " - "
                     << s32BankBtnIdx << " - "
                     << sFixName << " - "
                     << endl;
        }

    }
} // CtrlPanel::readConfiguration


/*******************************************************************************
* CtrlPanel::JsonCallback
*******************************************************************************/
void CtrlPanel::JsonCallback(const aVector<aString> &_vecKeys,
                             const aJsonValue       &_value)
{
    s32     s32Size = _vecKeys.size();

    // parse bank
    if (_vecKeys.at(0).left(10) == "controller")
    {
        controllerIoInfo &ci = getControllerInfo(_vecKeys.at(0));

        if (s32Size == 1)
        {
            // fixture name
            if (_value.key() == "name")
                std::get<0> (ci) = _value.toString();

            // ip adress
            if (_value.key() == "adress")
                std::get<1> (ci) = _value.toString();

            // universeMax of the controller
            if (_value.key() == "universeMax")
                std::get<2> (ci) = _value.toDbl();
        }

        if (s32Size == 2)
        {
            universeIoInfo &ui = getUniverseInfo(ci, _vecKeys.at(0));

            // fixture name
            if (_value.key() == "id")
                std::get<0> (ui) = _value.toDbl();
        }

        if (s32Size == 3)
        {
            universeIoInfo &ui = getUniverseInfo(ci, _vecKeys.at(0));

            // fixture name
            if (_vecKeys.at(2) == "dmxdata")
            {
                QByteArray &ba = std::get<1> (ui);

                ba[_value.key().to_s32()] = _value.toDbl();
            }
        }
    }

    // parse bank
    if (_vecKeys.at(0).left(4) == "bank")
    {
        bankIoInfo &bi = getBankInfo(_vecKeys.at(0));

        // bank name
        if (s32Size == 1 && _value.key() == "name")
            std::get<0> (bi) = _value.toString();

        // bank fixtures
        if (s32Size == 2 && _vecKeys.at(1) == "fixtures")

        (std::get<1> (bi))[_value.key().to_s32()] = _value.toString();
    }


    // parse fixture
    if (_vecKeys.at(0).left(7) == "fixture")
    {
        fixtureIoInfo &fi = getFixtureInfo(_vecKeys.at(0));

        // read fixture data (name, controller, universeId, channelOs)
        if (s32Size == 1)
        {
            // fixture name
            if (_value.key() == "name")
                std::get<0> (fi) = _value.toString();

            // fixture controller
            if (_value.key() == "controller")
                std::get<1> (fi) = _value.toString();

            // fixture universeId
            if (_value.key() == "universeId")
                std::get<2> (fi) = _value.toDbl();

            // fixture universeId
            if (_value.key() == "channelOs")
                std::get<3> (fi) = static_cast<s32> (_value.toDbl());
        }

        // read fixture channel
        if (s32Size == 2)
        {
            channelIoInfo &ci = getChannelInfo(fi, _vecKeys.at(1));

            // channel controller
            if (_value.key() == "controller")
                std::get<0> (ci) = _value.toString();

            // channel universeId
            if (_value.key() == "universeId")
                std::get<1> (ci) = _value.toDbl();

            // channel channelOs
            if (_value.key() == "channelOs")
                std::get<2> (ci) = _value.toDbl();

            // channel channelNr
            if (_value.key() == "channelNr")
                std::get<3> (ci) = _value.toDbl();

            // channel icon
            if (_value.key() == "icon")
                std::get<4> (ci) = _value.toString();

            // channel brightness
            if (_value.key() == "brightness")
                std::get<5> (ci) = _value.toBool();

            // channel value
            if (_value.key() == "value")
                std::get<6> (ci) = _value.toDbl();
        }
    }

} // CtrlPanel::JsonCallback


/*******************************************************************************
* CtrlPanel::getBankInfo
*******************************************************************************/
bankIoInfo& CtrlPanel::getBankInfo(const aString &_sName)
{
    // create a new bankinfo, if it does not already exist
    if (m_mapBankIoInfo.find(_sName) == m_mapBankIoInfo.end())
    {
        m_mapBankIoInfo[_sName] = std::make_tuple("", aMap<s32, aString>{});
    }

    return m_mapBankIoInfo.find(_sName)->second;
} // CtrlPanel::getBankInfo


/*******************************************************************************
* CtrlPanel::getFixtureInfo
*******************************************************************************/
fixtureIoInfo& CtrlPanel::getFixtureInfo(const aString &_sName)
{
    // create a new fixtureinfo, if it does not already exist
    if (m_mapFixtureIoInfo.find(_sName) == m_mapFixtureIoInfo.end())
    {
        m_mapFixtureIoInfo[_sName] = std::make_tuple("", "", 0, 0, aMap<aString, channelIoInfo>{});
    }

    return m_mapFixtureIoInfo.find(_sName)->second;
} // CtrlPanel::getFixtureInfo


/*******************************************************************************
* CtrlPanel::getChannelInfo
*******************************************************************************/
channelIoInfo& CtrlPanel::getChannelInfo(fixtureIoInfo  &_fi,
                                         const aString  &_sName)
{
    aMap<aString, channelIoInfo>  &mapChannelInfo = std::get<4> (_fi);

    // create a new fixtureinfo, if it does not already exist
    if (mapChannelInfo.find(_sName) == mapChannelInfo.end())
    {
        mapChannelInfo[_sName] = std::make_tuple("", 0, 0, 0, "", false, 0);
    }

    return mapChannelInfo.find(_sName)->second;
} // CtrlPanel::getChannelInfo


/*******************************************************************************
* CtrlPanel::getControllerInfo
*******************************************************************************/
controllerIoInfo& CtrlPanel::getControllerInfo(const aString &_sName)
{
    // create a new fixtureinfo, if it does not already exist
    if (m_mapControllerIoInfo.find(_sName) == m_mapControllerIoInfo.end())
    {
        m_mapControllerIoInfo[_sName] = std::make_tuple("", "", 0, aMap<aString, universeIoInfo>{});
    }

    return m_mapControllerIoInfo.find(_sName)->second;
} // CtrlPanel::getControllerInfo


/*******************************************************************************
* CtrlPanel::getUniverseInfo
*******************************************************************************/
universeIoInfo& CtrlPanel::getUniverseInfo(controllerIoInfo &_ci,
                                           const aString    &_sName)
{
    aMap<aString, universeIoInfo>  &mapUniverseInfo = std::get<3> (_ci);

    // create a new fixtureinfo, if it does not already exist
    if (mapUniverseInfo.find(_sName) == mapUniverseInfo.end())
    {
        mapUniverseInfo[_sName] = std::make_tuple(0, QByteArray{512, 0});
    }

    return mapUniverseInfo.find(_sName)->second;
} // CtrlPanel::getUniverseInfo
