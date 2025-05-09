/*******************************************************************************
* \file aDockWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin_def.h"
#include "aDockWin.h"
#include "aHelper.h"
#include "aString.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aDockWin::aDockWin
*******************************************************************************/
aDockWin::aDockWin(SysWin *_pParent)
: aBaseWin<QDockWidget>(_pParent)
{
} // aDockWin::aDockWin


/*******************************************************************************
* aDockWin::~aDockWin
*******************************************************************************/
aDockWin::~aDockWin()
{
} // aDockWin::~aDockWin


/*******************************************************************************
* aDockWin::setObjectName
*******************************************************************************/
void aDockWin::setObjectName(const aString  &_sName)
{
    QDockWidget::setObjectName(_sName.toQString());
} // aDockWin::setObjectName


/*******************************************************************************
* aDockWin::setWindowTitle
*******************************************************************************/
void aDockWin::setWindowTitle(const aString  &_sTile)
{
    QDockWidget::setWindowTitle(_sTile.toQString());
} // aDockWin::setWindowTitle


/*******************************************************************************
* aDockWin::setCentralWin
*******************************************************************************/
void aDockWin::setCentralWin(SysWin *_pWin)
{
    QDockWidget::setWidget(_pWin);
} // aDockWin::setCentralWin


/*******************************************************************************
* aDockWin::centralWin
*******************************************************************************/
SysWin* aDockWin::centralWin()
{
    return QDockWidget::widget();
} // aDockWin::centralWin


/*******************************************************************************
* aDockWin::setAllowedAreas
*******************************************************************************/
void aDockWin::setAllowedAreas(u16 _u16Areas)
{
    Qt::DockWidgetAreas areas = Qt::NoDockWidgetArea;

    if (isBitsSet<u32>(_u16Areas, DOCK_POS_L))
    {
        areas |= Qt::LeftDockWidgetArea;
    }

    if (isBitsSet<u32>(_u16Areas, DOCK_POS_R))
    {
        areas |= Qt::RightDockWidgetArea;
    }

    if (isBitsSet<u32>(_u16Areas, DOCK_POS_T))
    {
        areas |= Qt::TopDockWidgetArea;
    }

    if (isBitsSet<u32>(_u16Areas, DOCK_POS_B))
    {
        areas |= Qt::BottomDockWidgetArea;
    }

    QDockWidget::setAllowedAreas(areas);
} // aDockWin::setAllowedAreas


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
