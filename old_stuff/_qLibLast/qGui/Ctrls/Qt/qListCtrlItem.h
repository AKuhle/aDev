/*******************************************************************************
* \file qListCtrlItem.h
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
    * \class qListCtrlItemCtrl
    *******************************************************************************/
    class qListCtrlItem : public QListWidgetItem
    {
        public:
            qListCtrlItem();

            virtual ~qListCtrlItem();

            void                    SetFont(const qFont &_font);
            void                    SetText(const qString16 &_text);

            const QListWidgetItem&  ToQListWidgetItem() const;
            QListWidgetItem&        ToQListWidgetItem();
    }; // class qListCtrlItem

} // namespace qLib

#endif // _USE_QT_
