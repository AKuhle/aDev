/*******************************************************************************
* \file qContextMenu.cpp
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
#include "qContextMenu.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qContextMenu::qContextMenu
    *******************************************************************************/
    qContextMenu::qContextMenu(SysWin_t   *_pParent)
    : qSysWin<QMenu>(_pParent)
	{
    } // qContextMenu::qContextMenu


    /*******************************************************************************
    * qContextMenu::~qContextMenu
    *******************************************************************************/
    qContextMenu::~qContextMenu()
	{
    } // qContextMenu::~qContextMenu


    /*******************************************************************************
    * qContextMenu::AppendMenuItem
    *******************************************************************************/
    void qContextMenu::AppendMenuItem(u16              _u16Id,
                                      const qString16  &_sIconResource,
                                      const qString16  &_sText)
    {
        QAction *pAction = addAction(QIcon(_sIconResource.ToQString()), _sText.ToQString());

        m_mapAction[_u16Id] = pAction;
    } // qContextMenu::AppendMenuItem


    /*******************************************************************************
    * qContextMenu::ShowMenu
    *******************************************************************************/
    u32 qContextMenu::ShowMenu(const qVector2D<s32> &_v2dCornerLT)
    {
        QPoint pnt(_v2dCornerLT.x(), _v2dCornerLT.y());

        QAction *pAction = exec(Parent()->mapToGlobal(pnt));

        qMap<u32, QAction*>::const_iterator cit;

        for (cit = m_mapAction.begin(); cit != m_mapAction.end(); cit++)
        {
            if (cit->second == pAction)
            {
                return cit->first;
            }
        }

        return 0;
    } // qContextMenu::ShowMenu

} // namespace qLib


#endif // _USE_QT_
