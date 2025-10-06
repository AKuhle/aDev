/*******************************************************************************
* \file Chase.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QString>



/*******************************************************************************
* class Chase
*******************************************************************************/
class Chase
{
    private:
        QString     m_sName;

    public:
        Chase(const QString   &_sName);

        ~Chase();

        QString                         name() const                { return m_sName; }
}; // class Chase
