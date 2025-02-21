/*******************************************************************************
* \file qMainWinSdi.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMainWinSdi.h"


namespace qLib
{
    /*******************************************************************************
    * qMainWinSdi::qMainWinSdi
    *******************************************************************************/
    qMainWinSdi::qMainWinSdi(qWin  *_pParent  /* = nullptr */)
    : qMainWin(_pParent)
    {
    } // qMainWinSdi::qMainWinSdi


    /*******************************************************************************
    * qMainWinSdi::~qMainWinSdi
    *******************************************************************************/
    qMainWinSdi::~qMainWinSdi()
    {
    } // qMainWinSdi::~qMainWinSdi


    /*******************************************************************************
    * qMainWinSdi::OnSysCreate
    *******************************************************************************/
    // bool qMainWinSdi::OnSysCreate()
    // {
    //     qMainWin::OnSysCreate();

    //     qMdiWin     *pMdiWin = new qMdiWin(this);
    //     pMdiWin->CreateWin();

    //     SetCenterWin(pMdiWin);

    //     return true;
    // } // qMainWinSdi::OnSysCreate


} // namespace qLib
