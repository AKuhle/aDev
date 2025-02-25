/*******************************************************************************
* \file BaseApp.h
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
#include "aAppMainWin.h"
#include "mainWin.h"

using namespace aLib::aApp;
using namespace aLib::aWin;


/*******************************************************************************
* getMainWin
*******************************************************************************/
MainWin& getMainWin()
{
    return *dynamic_cast<MainWin *> (get_aMainWin());
} // getMainWin


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin()
{
    //QWidget     *newnew = new Qwidget;


} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
} // MainWin::~MainWin
