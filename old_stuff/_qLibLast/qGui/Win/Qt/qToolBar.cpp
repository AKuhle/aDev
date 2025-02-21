/*******************************************************************************
* \file qToolBar.cpp
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qGuiDefs.h"
#include "qToolBar.h"


namespace qLib
{
    /*******************************************************************************
    * qToolBar::qToolBar
    *******************************************************************************/
    qToolBar::qToolBar(SysWin_t  *_pParent  /* = nullptr */)
    : qSysWin<QToolBar>(_pParent)
    {
    } // qToolBar::qToolBar


    /*******************************************************************************
    * qToolBar::~qToolBar
    *******************************************************************************/
    qToolBar::~qToolBar()
    {
    } // ~qToolBar::qToolBar


    /*******************************************************************************
    * qToolBar::SetAllowedDockAreas
    *******************************************************************************/
    void qToolBar::SetAllowedDockAreas(u32 _u32Areas)
    {
        Qt::ToolBarAreas areas = Qt::NoToolBarArea;

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_LEFT))
        {
            areas |= Qt::LeftToolBarArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_RIGHT))
        {
            areas |= Qt::RightToolBarArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_TOP))
        {
            areas |= Qt::TopToolBarArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_BOTTOM))
        {
            areas |= Qt::BottomToolBarArea;
        }

        setAllowedAreas(areas);
    } // qToolBar::SetAllowedDockAreas

} //namespace qLib

#endif // _USE_QT_
