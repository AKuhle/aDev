/*******************************************************************************
* \file qMdiArea.cpp
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
#include "qMdiArea.h"
#include "qMdiWin.h"


namespace qLib
{
    /*******************************************************************************
    * qMdiArea::qMdiArea
    *******************************************************************************/
    qMdiArea::qMdiArea(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<QMdiArea>(_pParent)
    {
    } // qMdiArea::qMdiArea


    /*******************************************************************************
    * qMdiArea::~qMdiArea
    *******************************************************************************/
    qMdiArea::~qMdiArea()
    {
    } // qMdiArea::~qMdiArea


    /*******************************************************************************
    * qMdiArea::AddMdiWin
    *******************************************************************************/
    void qMdiArea::AddMdiWin(qMdiWin *_pMdiWin)
    {
        addSubWindow(_pMdiWin);
        _pMdiWin->SetVisible(true);
    } // qMdiArea::AddMdiWin


    /*******************************************************************************
    * qMdiArea::GetMdiWinList
    *******************************************************************************/
    void qMdiArea::GetMdiWinList(qPtrList<qMdiWin> &_lstMdiWin) const
    {
        QList<QMdiSubWindow *>	lstSubWins 	= subWindowList();

        for (QMdiSubWindow *pMdiSubWin : lstSubWins)
        {
            qMdiWin *pMdiWin = dynamic_cast<qMdiWin *> (pMdiSubWin);

            if (pMdiWin != nullptr)
            {
                _lstMdiWin.push_back(pMdiWin);
            }
        } // for ...
    } // qMdiArea::GetMdiWinList


    /*******************************************************************************
    * qMdiArea::ActiveMdiWin
    *******************************************************************************/
    qMdiWin* qMdiArea::ActiveMdiWin()
    {
        return dynamic_cast<qMdiWin *> (activeSubWindow());
    } // qMdiArea::ActiveMdiWin


    /*******************************************************************************
    * qMdiArea::ActiveOrTopmostMdiWin
    *******************************************************************************/
    qMdiWin* qMdiArea::ActiveOrTopmostMdiWin()
    {
        QList<QMdiSubWindow *>	lstSubWins 	= subWindowList(QMdiArea::StackingOrder);

        if (lstSubWins.size() > 0)
        {
            return dynamic_cast<qMdiWin *> (lstSubWins.back());
        }
        else
        {
            return nullptr;
        }
    } // qMdiArea::ActiveOrTopmostMdiWin



} // namespace qLib
