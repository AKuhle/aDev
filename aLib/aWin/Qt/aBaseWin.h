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
#include <QWheelEvent>
#include <QShowEvent>

#include "aBaseWinI.h"
#include "aUrl.h"
#include "aString.h"

#include "aCtrlMgr.h"
#include "aToolMgr.h"

/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {



/*******************************************************************************
* class aBaseWin
*******************************************************************************/
template<class T>
class aBaseWin : public T,
                 public aBaseWinI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(SysWin *_pParent);

    public:
        virtual ~aBaseWin();

        bool                    createWin() override;
        bool                    closeWin() override;

        aBaseWinI*              widget2BaseWin(QWidget *_pWidget);
        QWidget*                baseWin2Widget(aBaseWinI *_pWin);

        // template <class aWin>
        // aWin                    win_cast(aBaseWinI *_pWin) const
        // {
        //     return (aWin) _pWin;
        // }

        void                    setParent(SysWin *_pParent) override;
        SysWin*                 parent() const override;

        void                    update() override;
        void                    repaint() override;

        void                    setWinTitle(const aString &_sTitle) override;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        void                    setVisible(bool _bVisible) override;
        void                    show() override;
        void                    hide() override;
        bool                    isVisible() const override;

        void                    setMouseTracking(bool _bEnable) override;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                    setMinSize(const aDimension2D<s32> &_dim) override;
        void                    setMinSize(s32  _s32W,
                                           s32  _s32H) override;
        void                    setMinW(s32  _s32W);
        void                    setMinH(s32  _s32H);
        void                    setFixedW(s32  _s32W) override;
        void                    setFixedH(s32  _s32H) override;

        aRect2D<s32>            clientRect() const override;
        s32                     clientW() const override;
        s32                     clientH() const override;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        bool                    onSysCreateWin() override;
        bool                    onCreateWin() override;
        bool                    onCloseWin() override;

        void                    onDropUrl(const aUrl  &_url) override;
        bool                    onPaint() override;

    public:
        bool                    onWheel(u32                  _u32Modifiers,
                                        s32                  _s32Degree,
                                        const aVector2D<s32> &_v2dLocal,
                                        const aVector2D<s32> &_v2dGlobal) override;


    // /*******************************************************************************
    // * qt handler
    // *******************************************************************************/
    private:
        void                    dragEnterEvent(QDragEnterEvent *_pEvent) override;
        void                    dragMoveEvent(QDragMoveEvent *_pEvent) override;
        void                    dropEvent(QDropEvent   *_pEvent) override;

        void                    paintEvent(QPaintEvent *_pEvent) override;

        void                    wheelEvent(QWheelEvent *_pEvent) override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib

#include "aBaseWin.inl"
#include "aBaseWin_handler.inl"

#endif //_USE_QT_
