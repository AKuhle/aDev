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
class aSysWin_sys : public T,
                    public aSysWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aSysWin_sys(SysWinClass *_pParent = nullptr);

    public:
        virtual ~aSysWin_sys();

        virtual void            _setParent(SysWinClass *_pParent) override;
        virtual SysWinClass*    _parent() override;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    protected:
        void                    _setMinSize(s32  _w,
                                            s32  _h) override;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        virtual bool            _isVisible() const override;
        virtual void            _setVisible(bool _bVisible) override;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual void            dragEnterEvent(QDragEnterEvent *_pEvent) override;
        virtual void            dragMoveEvent(QDragMoveEvent *_pEvent) override;
        virtual void            dropEvent(QDropEvent   *_pEvent) override;

}; // class aSysWin_sys


} // namespace aWin
} // namespace aLib

#include "aSysWin_sys.inl"

#endif //_USE_QT_
