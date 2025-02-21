/*******************************************************************************
* \file qAppMainWinI.h
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
#include "aWin/aWin_def.h"

using namespace aLib::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* \class aMainWinApp_i
*******************************************************************************/
class aMainWinApp_i
{
    protected:
        aMainWinApp_i() = default;

    public:
        virtual ~aMainWinApp_i() = default;

    private:
        aMainWinApp_i(const aMainWinApp_i	&_rhs) = delete;
        aMainWinApp_i(aMainWinApp_i	&&_rhs) = delete;
        aMainWinApp_i& operator=(const aMainWinApp_i	&_rhs) = delete;
        aMainWinApp_i& operator=(aMainWinApp_i &&_rhs) = delete;


    protected:
        virtual void        onCreateMainWin(aMainWin *&_pMainWin) = 0;
}; // class aMainWinApp_i


} // namespace aApp
} // namespace aLib
