/*******************************************************************************
* \file qListCtrlItem.cpp
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
#include "qListCtrlItem.h"
#include "qFont.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qListCtrlItem::qListCtrlItem
    *******************************************************************************/
    qListCtrlItem::qListCtrlItem()
    {
    } // qListCtrlItem::qListCtrlItem


    /*******************************************************************************
    * qListCtrlItem::~qListCtrlItem
    *******************************************************************************/
    qListCtrlItem::~qListCtrlItem()
    {
    } // qListCtrlItem::~qListCtrlItem


    /*******************************************************************************
    * qListCtrlItem::SetFont
    *******************************************************************************/
    void qListCtrlItem::SetFont(const qFont &_font)
    {
        setFont(_font.ToQFont());
    } // qListCtrlItem::SetFont


    /*******************************************************************************
    * qListCtrlItem::SetText
    *******************************************************************************/
    void qListCtrlItem::SetText(const qString16 &_text)
    {
        setText(_text.ToQString());
    } // qListCtrlItem::SetText


    /*******************************************************************************
    * qListCtrlItem::ToQListWidgetItem
    *******************************************************************************/
    const QListWidgetItem& qListCtrlItem::ToQListWidgetItem() const
    {
        return *this;
    } // qListCtrlItem::ToQListWidgetItem


    /*******************************************************************************
    * qListCtrlItem::ToQListWidgetItem
    *******************************************************************************/
    QListWidgetItem& qListCtrlItem::ToQListWidgetItem()
    {
        return *this;
    } // qListCtrlItem::ToQListWidgetItem

} // namespace qLib

#endif // _USE_QT_
