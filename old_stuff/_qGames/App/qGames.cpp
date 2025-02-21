/*******************************************************************************
* \file qGames.cpp
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
#include "qGames.h"
#include "mainWin.h"

using namespace qLib;


/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
qGames	AppInstance;


/*******************************************************************************
* qGames::qGames
*******************************************************************************/
qGames::qGames()
: qAppMainWin(/*qLib::qVersion(0, 1, 0, 0)*/)
{
} // qGames::qGames


/*******************************************************************************
* qGames::~qGames
*******************************************************************************/
qGames::~qGames()
{
} // qGames::~qGames


/*******************************************************************************
* qGames::OnCreateMainWin
*******************************************************************************/
void qGames::OnCreateMainWin(qMainWin *&_pMainWin)
{
    // set the gui scale
    qWin::SetMinScale(1);

    _pMainWin = new MainWin;

    if (!_pMainWin->CreateWin())
    {
        _pMainWin = nullptr;
    }
} // qGames::OnCreateMainWin
