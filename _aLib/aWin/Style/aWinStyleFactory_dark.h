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
#include "aWin/Style/aWinStyleFactory.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* \class aWinStyleFactoryDark
*******************************************************************************/
class aWinStyleFactoryDark : public aWinStyleFactory
{
    public:
        aWinStyleFactoryDark();
        virtual ~aWinStyleFactoryDark();

    private:
        void                setDefaults(aBaseWin &_win);

    /*******************************************************************************
    * qWinStyle interface
    *******************************************************************************/
    public:
        virtual void        setWinStyle(aBaseWin &_win) override;

}; // aWinStyleFactoryDark


} // namespace aWin
} // namespace aLib
