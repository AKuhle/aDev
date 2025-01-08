/*******************************************************************************
* \file qWinStyleFactory.h
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
#include "Win/WinStyle/qWinStyleFactory.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* \class qWinStyleFactoryDark
*******************************************************************************/
class qWinStyleFactoryDark : public qWinStyleFactory
{
    public:
        qWinStyleFactoryDark();
        virtual ~qWinStyleFactoryDark();


    /*******************************************************************************
    * qWinStyle interface
    *******************************************************************************/
    public:
        virtual void        setWinStyle(qWin &_win) override;
}; // qWinStyleFactoryDark


} // namespace Win
} // namespace qLib
