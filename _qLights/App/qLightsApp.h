/*******************************************************************************
* \file qLightsApp.h
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
#include "aApp_def.h"

#include "aMainWin.h"

#include "aAppMainWin.h"

using namespace aLib::aApp;
using namespace aLib::aWin;

class qLightsApp;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
extern qLightsApp	AppInstance;


/*******************************************************************************
* class qLightsApp
*******************************************************************************/
class qLightsApp : public aAppMainWin
{
    public:
        qLightsApp();
        virtual ~qLightsApp();


    /*******************************************************************************
    * interface of qAppMainWin
    *******************************************************************************/
    protected:
        virtual void        onCreateMainWin(aMainWin *& _pMainWin) override;

}; // class qLightsApp
