/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin_def.h"
#include "aUtil/aUrl.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aDockWinI
*******************************************************************************/
class aDockWinI
{
    public:
        virtual ~aDockWinI() = default;

        virtual void            setObjectName(const aString  &_sName) = 0;
        virtual void            setWindowTitle(const aString  &_sTile) = 0;

    protected:
        virtual void            setCentralWin(SysWin *_pWin) = 0;
        virtual SysWin*         centralWin() = 0;

        virtual void            setAllowedAreas(u16 _u16Areas) = 0;

}; // class aDockWinI


} // namespace aWin
} // namespace aLib
