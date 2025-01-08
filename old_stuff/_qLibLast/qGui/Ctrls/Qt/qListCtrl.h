/*******************************************************************************
* \file qListCtrl.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qSysWin.h"
#include "qCtrl_i.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qListCtrlItem;


    /*******************************************************************************
    * \class qListCtrlCtrl
    *******************************************************************************/
    // Messages:    MsgCurrentItemChanged   -> pVoid1 = _pCurrent, pVoid2 = _pPrev
    //              MsgCurrentRowChanged    -> int = iRow
    //              MsgItemChanged          -> pVoid1 = _pItem
    //              MsgItemClicked          -> pVoid1 = _pItem
    class qListCtrl : public qSysWin<QListWidget>,
                      public qCtrlI
    {
        Q_OBJECT

        public:
            qListCtrl(SysWin_t *_pParent = nullptr);

            virtual ~qListCtrl();

            void                Clear();

            void                AddItem(qListCtrlItem *_pItem);


        /*******************************************************************************
        * interface of qCtrlI
        *******************************************************************************/
        protected:
            virtual void        SetCtrlEnabled(bool _bEnabled) override;
            virtual bool        IsCtrlEnabled() const override;

            // virtual void    VarPool2Control() override;
            // virtual void    Control2VarPool() override;^^


        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            void                SlotCurrentItemChanged(QListWidgetItem    *_pCurrent,
                                                       QListWidgetItem    *_pPrevious);

            void                SlotCurrentRowChanged(int _iRow);

            void                SlotItemChanged(QListWidgetItem *_pItem);

            void                SlotItemClicked(QListWidgetItem *_pItem);
    }; // class qListCtrl

} // namespace qLib

#endif // _USE_QT_
