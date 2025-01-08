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
#include "qWinStyleFactoryBase.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qMainWin;


    /*******************************************************************************
    * globals
    *******************************************************************************/


    /*******************************************************************************
    * \class qWinStyleFactoryDark
    *******************************************************************************/
    class qWinStyleFactoryDark : public qWinStyleFactoryBase
	{
        public:
            qWinStyleFactoryDark();
            virtual ~qWinStyleFactoryDark();

            virtual void        SetWinStyle(qWin &_win) override;

        private:
            void                SetDefaults(qWin &_win) const;

    }; // qWinStyleFactoryDark

} // namespace qLib
