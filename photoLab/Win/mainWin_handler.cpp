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
#include "aString.h"
#include "mainWin.h"
#include "aMdiWin.h"
#include "aScrollWin.h"

using namespace aLib::aWin;
using namespace std;


/*******************************************************************************
* MainWin::onCreate
*******************************************************************************/
bool MainWin::onCreate()
{
    setMinSize(600, 400);

    return true;
} // MainWin::onCreate


/*******************************************************************************
* MainWin::onDropUrl
*******************************************************************************/
void MainWin::onDropUrl(const aUrl  &_url)
{
    cout << _url.toLocalFile() << endl;

    aScrollWin *pScrollWin = new aScrollWin(this);
    pScrollWin->create();
    pScrollWin->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    pScrollWin->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    aMdiWin *pMdiWin = new aMdiWin(this);
    pMdiWin->create();
    pMdiWin->setCentralWin(pScrollWin);

    addMdiWin(pMdiWin);
} // MainWin::onDropUrl


/*******************************************************************************
* MainWin::onUpdateCmd
*******************************************************************************/
void MainWin::onUpdateCmd(u64     /*_u64Cmd*/,
                          aDoc    */*_pDoc*/,
                          aView   */*_pView*/,
                          s64     /*_s64Param1*/,
                          s64     /*_s64Param2*/,
                          u64     /*_u64Param1*/,
                          u64     /*_u64Param2*/,
                          flt     /*_fltParam1*/,
                          flt     /*_fltParam2*/,
                          dbl     /*_dblParam1*/,
                          dbl     /*_dblParam2*/,
                          void    */*_pParam1*/,
                          void    */*_pParam2*/)
{

} // MainWin::onUpdateCmd
