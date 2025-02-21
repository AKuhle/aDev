/*******************************************************************************
* \file qSysDlg.h
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qVec.h"

namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qString16;

    /*******************************************************************************
    * class qSysDlg
    *******************************************************************************/
    class qSysDlg
	{
        public:
            static qString16            GetFileOpenName(const qString16& _sTitle,
                                                        const qString16& _sPath,
                                                        const qString16& _sPattern);

            static qVec<qString16>      GetFileOpenNames(const qString16& _sTitle,
                                                         const qString16& _sPath,
                                                         const qString16& _sPattern);

        private:
            qSysDlg() = delete;      // class can't be instantiated
    }; // class qSysDlg

} // namespace qLib

#endif // _USE_QT_
