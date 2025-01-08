/*******************************************************************************
* \file qPhotoLabApp.cpp
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
#include "qPhotoLabApp.h"
#include "mainWin.h"

using namespace qLib;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
qPhotoLabApp	AppInstance;


/*******************************************************************************
* qPhotoLabApp::qPhotoLabApp
*******************************************************************************/
qPhotoLabApp::qPhotoLabApp()
: qAppMainWin(qLib::qVersion(0, 1, 0, 0))
{
} // qPhotoLabApp::qPhotoLabApp


/*******************************************************************************
* qPhotoLabApp::~qPhotoLabApp
*******************************************************************************/
qPhotoLabApp::~qPhotoLabApp()
{
} // qPhotoLabApp::~qPhotoLabApp


/*******************************************************************************
* qPhotoLabApp::OnCreateMainWin
*******************************************************************************/
void qPhotoLabApp::OnCreateMainWin(qMainWin *& _pMainWin)
{
    _pMainWin = new MainWin;
    _pMainWin->CreateWin();
} // qPhotoLabApp::OnCreateMainWin
