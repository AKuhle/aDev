/*******************************************************************************
* \file qWinStyleFactoryBase.h
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


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qWin;


    /*******************************************************************************
    * \class qWinStyleFactoryBase
    *******************************************************************************/
    class qWinStyleFactoryBase
	{
        protected:
            qWinStyleFactoryBase();

        public:
            virtual ~qWinStyleFactoryBase();

            virtual void        SetWinStyle(qWin &_win) = 0;
    }; // class qWinStyleFactoryBase

} // namespace qLib
