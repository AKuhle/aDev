/*******************************************************************************
* \file qLightsApp.cpp
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
#include "qLightsApp.h"
#include "mainWin.h"

#include "aUtil/aVersionInfo.h"


using namespace aLib::aWin;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
qLightsApp	AppInstance;


/*******************************************************************************
* qLightsApp::qLightsApp
*******************************************************************************/
qLightsApp::qLightsApp()
: aAppMainWin(aVersionInfo(0, 0, 1, 0))
{
} // qLightsApp::qLightsApp


/*******************************************************************************
* qLightsApp::~qLightsApp
*******************************************************************************/
qLightsApp::~qLightsApp()
{
} // qLightsApp::~qLightsApp


/*******************************************************************************
* qLightsApp::onCreateMainWin
*******************************************************************************/
void qLightsApp::onCreateMainWin(aMainWin *& _pMainWin)
{
    _pMainWin = new MainWin;
    if (!_pMainWin->createWin())
    {
        //_pMainWin->close();
        _pMainWin = nullptr;
    }
} // qLightsApp::onCreateMainWin
