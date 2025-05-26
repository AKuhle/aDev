/*******************************************************************************
* \file scene.h
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

using namespace aLib::aUtil;


/*******************************************************************************
* class Scene
*******************************************************************************/
class Scene
{
    private:
        aString     m_sName;

    public:
        Scene(const aString   &_sName);
        ~Scene();

        const aString&          name() const                    { return m_sName; }
        void                    setName(const aString &_sName)  { m_sName = _sName; }

}; // class Scene
