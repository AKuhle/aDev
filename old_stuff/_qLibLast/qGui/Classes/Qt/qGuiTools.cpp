/*******************************************************************************
* \file qGuiTools.cpp
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
#include "qGuiTools.h"



namespace qLib
{
    /*******************************************************************************
    * qGuiTools::LocalCursorPos
    *******************************************************************************/
    qVector2D<s32> qGuiTools::LocalCursorPos(SysWin_t *_pWin)
    {
        QPoint pos =_pWin->mapFromGlobal(QCursor::pos());

        return qVector2D<s32> (pos.x(), pos.y());
    } // qGuiTools::LocalCursorPos


    /*******************************************************************************
    * qGuiTools::Update
    *******************************************************************************/
    void qGuiTools::Update(SysWin_t *_pWin)
    {
        _pWin->update();
    } // qGuiTools::Update

} // namespace qLib


#endif // _USE_QT_
