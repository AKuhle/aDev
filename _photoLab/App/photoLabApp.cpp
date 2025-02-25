/*******************************************************************************
* \file PhotoLabApp.cpp
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
#include "photoLabApp.h"
#include "mainWin.h"

#include "aUtil/aVersionInfo.h"

#include "aWin/Style/aWinStyleFactory_dark.h"

using namespace aLib::aWin;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
PhotoLabApp	AppInstance;


/*******************************************************************************
* PhotoLabApp::PhotoLabApp
*******************************************************************************/
PhotoLabApp::PhotoLabApp()
: aMainWinApp(aVersionInfo(0, 0, 1, 0))
{
} // PhotoLabApp::PhotoLabApp


/*******************************************************************************
* PhotoLabApp::~PhotoLabApp
*******************************************************************************/
PhotoLabApp::~PhotoLabApp()
{
} // PhotoLabApp::~PhotoLabApp


/*******************************************************************************
* PhotoLabApp::onCreateMainWin
*******************************************************************************/
void PhotoLabApp::onCreateMainWin(aMainWin *& _pMainWin)
{
    // set thze window style
    unique_ptr<aWinStyleFactoryDark> pStyle = make_unique<aWinStyleFactoryDark> ();
    aBaseWin::setWinStyleFactory(std::move (pStyle));

    _pMainWin = new MainWin;

    if (!_pMainWin->create())
    {
        _pMainWin->close();
        _pMainWin = nullptr;
    }
    else
    {
    }
} // PhotoLabApp::onCreateMainWin
