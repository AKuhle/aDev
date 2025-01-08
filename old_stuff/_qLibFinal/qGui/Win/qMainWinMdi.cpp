/*******************************************************************************
* \file qMainWinMdi.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMainWinMdi.h"
#include "qMdiWin.h"
#include "qMdiWin.h"


namespace qLib
{
    /*******************************************************************************
    * qMainWinMdi::qMainWinMdi
    *******************************************************************************/
    qMainWinMdi::qMainWinMdi(qWin  *_pParent  /* = nullptr */)
    : qMainWin(_pParent)
    {
    } // qMainWinMdi::qMainWinMdi


    /*******************************************************************************
    * qMainWinMdi::~qMainWinMdi
    *******************************************************************************/
    qMainWinMdi::~qMainWinMdi()
    {
    } // qMainWinMdi::~qMainWinMdi


    /*******************************************************************************
    * qMainWinMdi::OnSysCreate
    *******************************************************************************/
    bool qMainWinMdi::OnSysCreate()
    {
        qMainWin::OnSysCreate();

        qMdiWin     *pMdiWin = new qMdiWin(this);
        pMdiWin->CreateWin();

        SetCenterWin(pMdiWin);

        return true;
    } // qMainWinMdi::OnSysCreate


    /*******************************************************************************
    * qMainWinMdi::AddMdiChild
    *******************************************************************************/
    void qMainWinMdi::AddMdiChild(qMdiChild *_pChild)
    {
        CHECK_PRE_CONDITION_VOID(GetMdiWin() != nullptr)

        GetMdiWin()->AddMdiChild(_pChild);
    } // qMainWinMdi::AddMdiChild


    /*******************************************************************************
    * qMainWinMdi::GetMdiWin
    *******************************************************************************/
    qMdiWin* qMainWinMdi::GetMdiWin()
    {
        return dynamic_cast<qMdiWin *> (GetCenterWin());
    } // GetMdiWin


    /*******************************************************************************
    * qMainWinMdi::ActivateMdiChild
    *******************************************************************************/
    void qMainWinMdi::ActivateMdiChild(qMdiChild *_pChild)
    {
        CHECK_PRE_CONDITION_VOID(GetMdiWin() != nullptr)

        GetMdiWin()->ActivateMdiChild(_pChild);
    } // qMainWinMdi::ActivateMdiChild

} // namespace qLib
