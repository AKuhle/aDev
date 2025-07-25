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

using namespace aFrame::aWin;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
PhotoLabApp	AppInstance;


/*******************************************************************************
* PhotoLabApp::PhotoLabApp
*******************************************************************************/
PhotoLabApp::PhotoLabApp()
: aAppMainWin(aVersionInfo(0, 0, 1, 0))
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
    _pMainWin = new MainWin;

    // set the style file
    _pMainWin->setStyleFile("C:\\Tools\\aDev\\aFrame\\Documents\\dark_style.json");

    if (!_pMainWin->createWin())
    {
        //_pMainWin->close();
        _pMainWin = nullptr;
    }
} // PhotoLabApp::onCreateMainWin
