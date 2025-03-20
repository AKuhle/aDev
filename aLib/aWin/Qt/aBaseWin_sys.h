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
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMimeData>

#include "aBaseWin_sysi.h"
#include "aUrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {



/*******************************************************************************
* class aBaseWin_sys
*******************************************************************************/
template<class T>
class aBaseWin_sys : public T,
                     private aBaseWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin_sys(SysWinClass *_pParent);

    public:
        virtual ~aBaseWin_sys();

    public:
        void                    setParent(SysWinClass *_pParent) override;
        SysWinClass*            parent() const override;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        void                    setVisible(bool _bVisible) override;
        bool                    isVisible() const override;

        void                    setMouseTracking(bool _bEnable) override;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                setMinSize(s32  _s32W,
                                       s32  _s32H) override;


    // /*******************************************************************************
    // * qt handler
    // *******************************************************************************/
    protected:
        void                    dragEnterEvent(QDragEnterEvent *_pEvent) override;
        void                    dragMoveEvent(QDragMoveEvent *_pEvent) override;
        void                    dropEvent(QDropEvent   *_pEvent) override;

    //     void                    paintEvent(QPaintEvent *_pEvent) override;

}; // class aBaseWin_sys


} // namespace aWin
} // namespace aLib

#include "aBaseWin_sys.inl"

#endif //_USE_QT_
