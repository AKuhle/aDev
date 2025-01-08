/*******************************************************************************
* \file qListCtrl.cpp
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
#include "qListCtrl.h"
#include "qListCtrlItem.h"


namespace qLib
{
    /*******************************************************************************
    * qListCtrl::qListCtrl
    *******************************************************************************/
    qListCtrl::qListCtrl(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<QListWidget>(_pParent)
    {
        connect(this, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
                this, SLOT(SlotCurrentItemChanged(QListWidgetItem*,QListWidgetItem*)));

        connect(this, SIGNAL(currentRowChanged(int)),
                this, SLOT(SlotCurrentRowChanged(int)));

        connect(this, SIGNAL(itemChanged(QListWidgetItem*)),
                this, SLOT(SlotItemChanged(QListWidgetItem*)));

        connect(this, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(SlotItemClicked(QListWidgetItem*)));
    } // qListCtrl::qListCtrl


    /*******************************************************************************
    * qListCtrl::~qListCtrl
    *******************************************************************************/
    qListCtrl::~qListCtrl()
    {
    } // qListCtrl::~qListCtrl


    /*******************************************************************************
    * qListCtrl::SetCtrlEnabled
    *******************************************************************************/
    void qListCtrl::SetCtrlEnabled(bool _bEnabled)
    {
        setEnabled(_bEnabled);
    } // qListCtrl::SetCtrlEnabled


    /*******************************************************************************
    * qListCtrl::Clear
    *******************************************************************************/
    void qListCtrl::Clear()
    {
        clear();
    } // qListCtrl::Clear


    /*******************************************************************************
    * qListCtrl::AddItem
    *******************************************************************************/
    void qListCtrl::AddItem(qListCtrlItem *_pItem)
    {
        addItem(&_pItem->ToQListWidgetItem());
    } // qListCtrl::AddItem


    /*******************************************************************************
    * qListCtrl::IsCtrlEnabled
    *******************************************************************************/
    bool qListCtrl::IsCtrlEnabled() const
    {
        return isEnabled();
    } // qListCtrl::IsCtrlEnabled


    /*******************************************************************************
    * qListCtrl::SlotCurrentItemChanged
    *******************************************************************************/
    void qListCtrl::SlotCurrentItemChanged(QListWidgetItem    *_pCurrent,
                                           QListWidgetItem    *_pPrevious)
    {
        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgCurrentItemChanged, 0,
                                     dynamic_cast<qListCtrlItem *> (_pCurrent),
                                     dynamic_cast<qListCtrlItem *> (_pPrevious));
        }
    } // qListCtrl::SlotCurrentItemChanged


    /*******************************************************************************
    * qListCtrl::SlotCurrentRowChanged
    *******************************************************************************/
    void qListCtrl::SlotCurrentRowChanged(int _iRow)
    {
        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgCurrentRowChanged, _iRow);
        }

    } // qListCtrl::SlotCurrentRowChanged


    /*******************************************************************************
    * qListCtrl::SlotItemChanged
    *******************************************************************************/
    void qListCtrl::SlotItemChanged(QListWidgetItem *_pItem)
    {
        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgItemChanged, 0,
                                     dynamic_cast<qListCtrlItem *> (_pItem));
        }

    } // qListCtrl::SlotItemChanged


    /*******************************************************************************
    * qListCtrl::SlotItemClicked
    *******************************************************************************/
    void qListCtrl::SlotItemClicked(QListWidgetItem *_pItem)
    {
        qListCtrlItem *p1 = static_cast<qListCtrlItem *> (_pItem);
        qListCtrlItem *p2 = dynamic_cast<qListCtrlItem *> (_pItem);

        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgItemClicked, 0,
                                     dynamic_cast<qListCtrlItem *> (_pItem));
        }

    } // qListCtrl::SlotItemClicked

} // namespace qLib

#endif // _USE_QT_
