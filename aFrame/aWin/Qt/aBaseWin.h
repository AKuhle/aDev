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
#include <QWidget>

#include "aWin_def.h"

#include "aBaseWin_i.h"

#include "aRect.h"

// #include <QDragEnterEvent>
// #include <QDragMoveEvent>
// #include <QDropEvent>
// #include <QMimeData>
// #include <QWheelEvent>
// #include <QShowEvent>

// #include "aUrl.h"
// #include "aString.h"

// #include "aCtrlMgr.h"
// #include "aToolMgr.h"

/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {



/*******************************************************************************
* class aBaseWin
*******************************************************************************/
class aBaseWin : private QWidget,
                 public aBaseWin_i
{
    Q_OBJECT


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(SysWin *_pParent);

    public:
        virtual ~aBaseWin();

        // QWidget is private => provide cast operator for QWidget
        //operator QWidget*()         { return static_cast<QWidget*>(this); }
        SysWin*                 asSysWin()  { return this; }


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        void                    setParent(SysWin *_pParent) override;
        SysWin*                 parent() const override;

        void                    update() override;
        void                    repaint() override;

        void                    setVisible(bool _bVisible) override;
        bool                    isVisible() const override;

        void                    setMouseTracking(bool _bEnable) override;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                    setMinW(s32 _s32MinW) override;
        void                    setMinH(s32 _s32MinH) override;

        void                    setMaxW(s32 _s32MaxW) override;
        void                    setMaxH(s32 _s32MaxH) override;

        void                    setGeometry(s32 _s32X,
                                            s32 _s32Y,
                                            s32 _s32W,
                                            s32 _s32H) override;

        aRect                   geometryRect() const override;
        s32                     geometryW() const override;
        s32                     geometryH() const override;


    /*******************************************************************************
    * qt handler
    *******************************************************************************/
    protected:
        bool                    eventFilter(QObject *_pObj,
                                            QEvent  *_pEvent) override;

    private:
        u16                     modifierFromMouseEvent(QMouseEvent *_pMouseEvent) const;
        // void                    dragEnterEvent(QDragEnterEvent *_pEvent) override;
        // void                    dragMoveEvent(QDragMoveEvent *_pEvent) override;
        // void                    dropEvent(QDropEvent   *_pEvent) override;

        // void                    wheelEvent(QWheelEvent *_pEvent) override;


    /*******************************************************************************
    * using
    *******************************************************************************/
    public:
        using aBaseWin_i::show;
        using aBaseWin_i::hide;
        using aBaseWin_i::setMouseTracking;
        using aBaseWin_i::setGeometry;
        using aBaseWin_i::setParent;
        using aBaseWin_i::parent;
        using aBaseWin_i::setLayout;
        using aBaseWin_i::update;
        using aBaseWin_i::repaint;
}; // class aBaseWin


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
