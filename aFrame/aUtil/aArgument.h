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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMap.h"
#include "aVector.h"
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aArgument
*******************************************************************************/
class aArgument
{
    private:
        aMap<aString, aVector<aString>>		m_mapArg;

    public:
        void				parseAndAddArgument(const aString	&_sArgument);

        static void			reportArgument(const aString	&_sKey,
                                           const aString	&_sDecription);

        // check if key exist
        bool				hasKey(const aString	&_sKey) const;

        // get multiple values by key
        bool				values(const aString	&_sKey,
                                   aVector<u16>		&_arValues) const;

        bool				values(const aString	&_sKey,
                                   aVector<s16>		&_arValues) const;

        bool				values(const aString	&_sKey,
                                   aVector<flt>		&_arValues) const;

        bool				values(const aString	&_sKey,
                                   aVector<aString> &_arValues) const;

        // get values by key
        bool				value(const aString		&_sKey,
                                  u16				&_u16Value,
                                  const u16			&_u16Default = 0) const;

        bool				value(const aString		&_sKey,
                                  s16				&_s16Value,
                                  const s16			_s16Default = 0) const;

        bool				value(const aString		&_sKey,
                                  flt				&_fValue,
                                  const flt			_fDefault = 0) const;

        bool				value(const aString     &_sKey,
                                  aString			&_sValue,
                                  const aString		_sDefault = "") const;

}; // class aArgument


} // namespace aUtil
} // namespace aFrame
