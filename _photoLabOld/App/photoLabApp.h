/*******************************************************************************
* \file photoLabApp.h
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

class PhotoLabApp;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
extern PhotoLabApp	AppInstance;


/*******************************************************************************
* class PhotoLabApp
*******************************************************************************/
class PhotoLabApp : public aAppMainWin
{
    public:
        PhotoLabApp();
        virtual ~PhotoLabApp();


    /*******************************************************************************
    * interface of qAppMainWin
    *******************************************************************************/
    protected:
        virtual void        onCreateMainWin(aMainWin *& _pMainWin) override;

}; // class PhotoLabApp
