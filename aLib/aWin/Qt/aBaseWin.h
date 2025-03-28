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

#include "aBaseWinI.h"
#include "aUrl.h"


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

        bool                    create() override;

        aBaseWinI*              widget2BaseWin(QWidget *_pWidget);
        QWidget*                baseWin2Widget(aBaseWinI *_pWin);

        template <class aWin>
        aWin                    win_cast(aBaseWinI *_pWin) const
        {
            return (aWin) _pWin;
        }

        void                    setParent(SysWin *_pParent) override;
        SysWin*                 parent() const override;

        void                    update() override;
        void                    repaint() override;


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

        aRect2D<s32>            clientRect() const override;
        s32                     clientW() const override;
        s32                     clientH() const override;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        bool                    onSysCreate() override;
        bool                    onCreate() override;

        void                    onDropUrl(const aUrl  &_url) override;
        bool                    onPaint() override;


    // /*******************************************************************************
    // * qt handler
    // *******************************************************************************/
    private:
        void                    dragEnterEvent(QDragEnterEvent *_pEvent) override;
        void                    dragMoveEvent(QDragMoveEvent *_pEvent) override;
        void                    dropEvent(QDropEvent   *_pEvent) override;

        void                    paintEvent(QPaintEvent *_pEvent) override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib

#include "aBaseWin.inl"
#include "aBaseWin_handler.inl"

#endif //_USE_QT_
