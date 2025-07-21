/*******************************************************************************
* \file aArgument.h
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
#include "aFrame_def.h"
#include "aArgument.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aArgument::parseAndAddArgument
*******************************************************************************/
void aArgument::parseAndAddArgument(const aString &_sArg)
{
    // general format: arg=34,55,66

    aVector<aString>		vecToken;
    aVector<aString>		vecValues;

    // split Argument and values
    _sArg.splitString("=", vecToken);

    // split the values
    if (vecToken.size() == 2)
    {
        // we have values => split at ","
        vecToken.at(1).splitString(",", vecValues);
    }

    // add the Argument with the values (or with no value)
    m_mapArg[vecToken.at(0)] = vecValues;
} // aArgument::parseAndAddArgument


/*******************************************************************************
* aArgument::reportArgument
*******************************************************************************/
void aArgument::reportArgument(const aString    &_sKey,
                               const aString	&_sDecription)
{
    // print the key
    cout << _sKey;

    // fill with spaces
    for (size_t i = _sKey.length(); i < 30; i++)
    {
        wcout << " ";
    }

    // print the description
    cout << "-> " << _sDecription << endl;
} // aArgument::reportArgument


/*******************************************************************************
* aArgument::hasKey
*******************************************************************************/
bool aArgument::hasKey(const aString		&_sKey) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    return ((cit = m_mapArg.find(_sKey)) != m_mapArg.end());
} // aArgument::hasKey


/*******************************************************************************
* aArgument::values
*******************************************************************************/
bool aArgument::values(const aString    &_sKey,
                       aVector<u16>		&_vecValues) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        for (aString sVal : (*cit).second)
        {
            _vecValues.push_back(sVal.to_u16());
        }

        return true;
    }

    return false;
} // aArgument::values


/*******************************************************************************
* aArgument::values
*******************************************************************************/
bool aArgument::values(const aString    &_sKey,
                       aVector<s16>		&_vecValues) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        for (aString sVal : (*cit).second)
        {
            _vecValues.push_back(sVal.to_s16());
        }

        return true;
    }

    return false;
} // aArgument::values


/*******************************************************************************
* aArgument::values
*******************************************************************************/
bool aArgument::values(const aString    &_sKey,
                       aVector<flt>		&_vecValues) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        for (aString sVal : (*cit).second)
        {
            _vecValues.push_back(sVal.to_flt());
        }

        return true;
    }

    return false;
} // aArgument::values


/*******************************************************************************
* aArgument::values
*******************************************************************************/
bool aArgument::values(const aString	&_sKey,
                       aVector<aString> &_vecValues) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        for (aString sVal : (*cit).second)
        {
            _vecValues.push_back(sVal);
        }

        return true;
    }

    return false;
} // aArgument::values


/*******************************************************************************
* aArgument::value
*******************************************************************************/
bool aArgument::value(const aString     &_sKey,
                      u16               &_u16Value,
                      const u16         &_u16Default /*= 0*/) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {

        _u16Value = (*cit).second.at(0).to_u16();

        return true;
    }
    else
    {
        _u16Value = _u16Default;
    }

    return false;
} // aArgument::value


/*******************************************************************************
* aArgument::value
*******************************************************************************/
bool aArgument::value(const aString     &_sKey,
                      s16				&_s16Value,
                      const s16			_s16Default /*= 0*/) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        _s16Value = (*cit).second.at(0).to_s16();

        return true;
    }
    else
    {
        _s16Value = _s16Default;
    }

    return false;
} // aArgument::value


/*******************************************************************************
* aArgument::value
*******************************************************************************/
bool aArgument::value(const aString     &_sKey,
                      flt				&_fValue,
                      const flt			_fDefault /*= 0*/) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        _fValue = (*cit).second.at(0).to_flt();

        return true;
    }
    else
    {
        _fValue = _fDefault;
    }

    return false;
} // aArgument::value


/*******************************************************************************
* aArgument::value
*******************************************************************************/
bool aArgument::value(const aString     &_sKey,
                      aString			&_sValue,
                      const aString		_sDefault /*= ""*/) const
{
    aMap<aString, aVector<aString>>::const_iterator     cit;

    if ((cit = m_mapArg.find(_sKey)) != m_mapArg.end())
    {
        _sValue = (*cit).second.at(0);

        return true;
    }
    else
    {
        _sValue = _sDefault;
    }

    return false;
} // aArgument::value


} // namespace aUtil
} // namespace aFrame
