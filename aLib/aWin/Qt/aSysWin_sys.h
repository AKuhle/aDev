/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

#include "aWin_def.h"

#include "aUrl.h"

#include "aSysWin_sysi.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {



/*******************************************************************************
* class aSysWin_sys
*******************************************************************************/
template<class T>
class aSysWin_sys : private T,
                    public aSysWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aSysWin_sys(SysWinClass *_pParent = nullptr);

    public:
        virtual ~aSysWin_sys();

        T*                  ssysWinClass() { return this; }


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        virtual bool        _isVisible() const override;
        virtual void        _setVisible(bool _bVisible) override;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual void        dragEnterEvent(QDragEnterEvent *_pEvent) override;
        virtual void        dragMoveEvent(QDragMoveEvent *_pEvent) override;
        virtual void        dropEvent(QDropEvent   *_pEvent) override;

}; // class aSysWin_sys


} // namespace aWin
} // namespace aLib

#include "aSysWin_sys.inl"

#endif //_USE_QT_
