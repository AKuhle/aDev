/*******************************************************************************
* \file qGuiTools.h
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
#include "qGuiDefs.h"
#include "qVector2D.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/

    /*******************************************************************************
    * class qGuiTools
    *******************************************************************************/
    class qGuiTools
	{
        private:
            qGuiTools() = delete;
            ~qGuiTools() = delete;

        public:
            static qVector2D<s32>       LocalCursorPos(SysWin_t *_pWin);

            static void                 Update(SysWin_t *_pWin);
    }; // class qGuiTools

} // namespace qLib

#endif // _USE_QT_
