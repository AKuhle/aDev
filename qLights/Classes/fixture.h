/*******************************************************************************
* \file fixture.h
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
#include "aString.h"
#include "aPushButton.h"

using namespace aLib::aWin;
using namespace aLib::aUtil;


/*******************************************************************************
* class Fixture
*******************************************************************************/
class Fixture : public aPushButton
{
    private:
        aString         m_sName;


    public:
        Fixture(SysWin *_pParent = nullptr);
        ~Fixture();

        const aString&      name() const                    { return m_sName; }
        void                setName(const aString &_s)      { m_sName = _s; }

}; // class Fixture
