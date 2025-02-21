/*******************************************************************************
* \file qDockWin.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "qDockWin.h"


namespace qLib
{
    /*******************************************************************************
    * qDockWin::qDockWin
    *******************************************************************************/
    qDockWin::qDockWin(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<QDockWidget>(_pParent)
    {
    } // qDockWin::qDockWin


    /*******************************************************************************
    * qDockWin::~qDockWin
    *******************************************************************************/
    qDockWin::~qDockWin()
    {
    } // qDockWin::~qDockWin


    /*******************************************************************************
    * qDockWin::SetTitleBarWin
    *******************************************************************************/
    void qDockWin::SetTitleBarWin(SysWin_t *_pWin)
    {
        setTitleBarWidget(_pWin);
    } // qDockWin::SetTitleBarWin


    /*******************************************************************************
    * qDockWin::TitleBarWin
    *******************************************************************************/
    SysWin_t* qDockWin::TitleBarWin() const
    {
        return titleBarWidget();
    } // qDockWin::TitleBarWin


    /*******************************************************************************
    * qDockWin::SetCentralWin
    *******************************************************************************/
    void qDockWin::SetCentralWin(SysWin_t *_pWin)
    {
        setWidget(_pWin);
    } // qDockWin::SetCentralWin


    /*******************************************************************************
    * qDockWin::CentralWin
    *******************************************************************************/
    SysWin_t* qDockWin::CentralWin() const
    {
        return widget();
    } // qDockWin::CentralWin


    /*******************************************************************************
    * qDockWin::SetAllowedDockAreas
    *******************************************************************************/
    void qDockWin::SetAllowedDockAreas(u32 _u32Areas)
    {
        Qt::DockWidgetAreas areas = Qt::NoDockWidgetArea;

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_LEFT))
        {
            areas |= Qt::LeftDockWidgetArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_RIGHT))
        {
            areas |= Qt::RightDockWidgetArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_TOP))
        {
            areas |= Qt::TopDockWidgetArea;
        }

        if (BitsSet<u32>(_u32Areas, DOCK_AREA_BOTTOM))
        {
            areas |= Qt::BottomDockWidgetArea;
        }

        setAllowedAreas(areas);
    } // qDockWin::SetAllowedDockAreas

} //namespace qLib
