/*******************************************************************************
* \file qContextMenu.h
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
#include <QMenu>

#include "qSysWin.h"
#include "qGuiDefs.h"
#include "qVector2D.h"
#include "qMap.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qString16;


    /*******************************************************************************
    * class qContextMenu
    *******************************************************************************/
    class qContextMenu : public qSysWin<QMenu>
	{
        private:
            qMap<u32, QAction*>        m_mapAction;

        public:
            qContextMenu(SysWin_t   *_pParent);
            virtual ~qContextMenu();

            void            AppendMenuItem(u16              _u16Id,
                                           const qString16  &_sIconResource,
                                           const qString16  &_sText);

            u32             ShowMenu(const qVector2D<s32> &_v2dCornerLT);

    }; // class qContextMenu

} // namespace qLib

#endif // _USE_QT_
