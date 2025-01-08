/*******************************************************************************
* \file qMainWinMdi.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qGuiDefs.h"
#include "qMainWinMdi.h"
#include "qMdiArea.h"
#include "qMdiWin.h"


namespace qLib
{
    /*******************************************************************************
    * qMainWinMdi::qMainWinMdi
    *******************************************************************************/
    qMainWinMdi::qMainWinMdi(SysWin_t  *_pParent  /* = nullptr */)
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
    * qMainWinMdi::AddMdiWin
    *******************************************************************************/
    void qMainWinMdi::AddMdiWin(qMdiWin *_pMdiWin)
    {
        MdiArea()->AddMdiWin(_pMdiWin);
    } // qMainWinMdi::AddMdiWin


    /*******************************************************************************
    * qMainWinMdi::GetMdiWinList
    *******************************************************************************/
    void qMainWinMdi::GetMdiWinList(qPtrList<qMdiWin> &_lstMdiWin) const
    {
        MdiArea()->GetMdiWinList(_lstMdiWin);
    } // qMainWinMdi::GetMdiWinList


    /*******************************************************************************
    * qMainWinMdi::ActiveMdiWin
    *******************************************************************************/
    qMdiWin* qMainWinMdi::ActiveMdiWin()
    {
        return (MdiArea()->ActiveMdiWin());
    } // qMainWinMdi::ActiveMdiWin


    /*******************************************************************************
    * qMainWinMdi::ActiveOrTopmostMdiWin
    *******************************************************************************/
    qMdiWin* qMainWinMdi::ActiveOrTopmostMdiWin()
    {
        return (MdiArea()->ActiveOrTopmostMdiWin());
    } // qMainWinMdi::ActiveOrTopmostMdiWin


    /*******************************************************************************
    * qMainWinMdi::OnMdiWinActivated
    *******************************************************************************/
    void qMainWinMdi::OnMdiWinActivated(qMdiWin */*_pMdiWin*/)
    {
    } // qMainWinMdi::OnMdiWinActivated


    /*******************************************************************************
    * qMainWinMdi::MdiArea
    *******************************************************************************/
    qMdiArea* qMainWinMdi::MdiArea()
    {
        return dynamic_cast<qMdiArea *> (centralWidget());
    } // qMainWinMdi::MdiArea

    /*******************************************************************************
    * qMainWinMdi::MdiArea
    *******************************************************************************/
    const qMdiArea* qMainWinMdi::MdiArea() const
    {
        return dynamic_cast<qMdiArea *> (centralWidget());
    } // qMainWinMdi::MdiArea


    /*******************************************************************************
    * qMainWinMdi::OnSysCreate
    *******************************************************************************/
    bool qMainWinMdi::OnSysCreate()
    {
        qMdiArea    *pMdiArea = new qMdiArea();
        pMdiArea->CreateWin();

        SetCentralWin(pMdiArea);

        // connect the subWindowActivated signal
        connect(pMdiArea, SIGNAL(subWindowActivated(QMdiSubWindow *)),
                this, SLOT(SlotSubWindowActivated(QMdiSubWindow *)));

        return true;
    } // qMainWinMdi::OnSysCreate


    /*******************************************************************************
    * qMainWinMdi::SlotSubWindowActivated
    *******************************************************************************/
    void qMainWinMdi::SlotSubWindowActivated(QMdiSubWindow *_pSubWin)
    {
        OnMdiWinActivated(dynamic_cast<qMdiWin *> (_pSubWin));
    } // qMainWinMdi::SlotSubWindowActivated

} // namespace qLib

#endif // _USE_QT_
