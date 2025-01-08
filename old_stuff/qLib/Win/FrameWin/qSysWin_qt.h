/*******************************************************************************
* \file qSysWinQt.h
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

#include "Win/FrameWin/qSysWin_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {
namespace SysQt {


/*******************************************************************************
* class qSysWinQt
*******************************************************************************/
class qSysWinQt : private QWidget,
                  public qSysWinI
{
    private:

    protected:
        qSysWinQt(qSysWinQt *_pParent = nullptr);
        ~qSysWinQt();


    /*******************************************************************************
    * qSysWinI interface
    *******************************************************************************/
    public:
        virtual qWin*           parent() const override;
        void                    setParent(qWin *_pParent) override;

        virtual void            show() override;
        virtual void            hide() override;
        virtual void            setVisible(bool _bVisible) override;
        virtual bool            isVisible() const override;

        virtual void            showMaximized() override;
        virtual void            showMinimized() override;
        virtual void            showNormal() override;
        virtual bool            isMaximized() const override;
        virtual bool            isMinimized() const override;

        virtual void            setMouseTracking(bool _bEnable) override;

        virtual void            setCursor(const qCursor &_cursor) override;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    public:
        virtual qRect2D<s32>    geometry() const override;
        virtual void            setGeometry(const qRect2D<s32> &_r2d) override;
        virtual void            setGeometry(s32 _x,
                                            s32 _y,
                                            s32 _w,
                                            s32 _h) override;

        s32                     w() const override;
        s32                     h() const override;


    /*******************************************************************************
    * helper
    *******************************************************************************/
    protected:
        virtual qVector2D<s32>  globalCursorPos() const override;
        virtual qVector2D<s32>  localCursorPos() const override;
        virtual u32             modifiers() const override;
        virtual u32             mouseButton() const override;
        u32                     mouseButton(QMouseEvent *_pEvent) const;


    /*******************************************************************************
    * Qt specific
    *******************************************************************************/
    public:
        QWidget*                getQWidget()            { return this; }
    //     u32                     mouseButton(QMouseEvent *_pEvent) const;


    /*******************************************************************************
    * system events
    *******************************************************************************/
    private:
        virtual void            resizeEvent(QResizeEvent *_pEvent) override;
        virtual void            paintEvent(QPaintEvent *_pEvent) override;

        virtual void            enterEvent(QEnterEvent *_pEvent) override;
        virtual void            leaveEvent(QEvent *_pEvent) override;

        virtual void            wheelEvent(QWheelEvent *_pEvent) override;
        virtual void            mouseDoubleClickEvent(QMouseEvent *_pEvent) override;
        virtual void            mousePressEvent(QMouseEvent *_pEvent) override;
        virtual void            mouseMoveEvent(QMouseEvent *_pEvent) override;
        virtual void            mouseReleaseEvent(QMouseEvent *_pEvent) override;
}; // class qSysWinQt



} // namespace SysQt
} // namespace Win
} // namespace qLib


#endif // _USE_QT_





    //protected:
    //     bool                _CloseWin();

    //     SysWin_t*           _Parent() const;
    //     void                _SetParent(SysWin_t *_pParent); // can be nullptr

    //     bool                _IsDisabled() const;
    //     void                _SetDisabled(bool _bDisabled);

    //     qRect2D<s32>        _Geometry() const;
    //     s32                 _w() const;
    //     s32                 _h() const;

    //     void                _SetGeometry(s32 _x,
    //                                      s32 _y,
    //                                      s32 _w,
    //                                      s32 _h);

    //     void                _SetPosition(s32 _x,
    //                                      s32 _y);

    //     void                _EnableDrop(bool _bAccept);

    //     void                _SetCursor(const qCursor &_cursor);

    //     void                _Update();      // update queue
    //     void                _Repaint();     // updates immidiately


    // /*******************************************************************************
    // * event handler
    // *******************************************************************************/
    // protected:
    //     virtual void        OnOsResize(const qDimension2D<s32>    &_oldSize,
    //                                    const qDimension2D<s32>    &_newSize) = 0;

    //     virtual void        OnOsPaint() = 0;

    //     virtual bool        OnOsEnter(u32                   _u32Modifiers,
    //                                   const qVector2D<s32>    &_v2dLocal,
    //                                   const qVector2D<s32>    &_v2dGlobal) = 0;

    //     virtual bool        OnOsLeave(u32 _u32Modifiers) = 0;

    //     virtual bool        OnOsWheel(u32                     _u32Modifiers,
    //                                   s32                     _s32Degree,
    //                                   const qVector2D<s32>    &_v2dLocal,
    //                                   const qVector2D<s32>    &_v2dGlobal) = 0;

    //     virtual bool        OnOsDoubleClick(u32                   _u32Modifiers,
    //                                         u32                   _u32MouseButton,
    //                                         const qVector2D<s32>  &_v2dLocal,
    //                                         const qVector2D<s32>  &_v2dGlobal) = 0;

    //     virtual bool        OnOsMousePress(u32                   _u32Modifiers,
    //                                        u32                   _u32MouseButton,
    //                                        const qVector2D<s32>  &_v2dLocal,
    //                                        const qVector2D<s32>  &_v2dGlobal) = 0;

    //     virtual bool        OnOsMouseMove(u32                   _u32Modifiers,
    //                                       u32                   _u32MouseButton,
    //                                       const qVector2D<s32>   &_v2dLocal,
    //                                       const qVector2D<s32>   &_v2dGlobal) = 0;

    //     virtual bool        OnOsMouseRelease(u32                   _u32Modifiers,
    //                                          u32                   _u32MouseButton,
    //                                          const qVector2D<s32>  &_v2dLocal,
    //                                          const qVector2D<s32>  &_v2dGlobal) = 0;

    //     virtual void        OnOsDropUrl(const qUrl  &_url) = 0;


