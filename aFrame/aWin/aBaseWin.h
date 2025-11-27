/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QWidget>
#include <QSinglePointEvent>

#include "aGraphic_def.h"
#include "aWin_def.h"

#include "aBaseWin_sys.h"
#include "aLayout_i.h"
#include "aWinStyle.h"

#include "aRect.h"


using namespace aFrame::aGraphic;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {



/*******************************************************************************
* class aBaseWin
*******************************************************************************/
class aBaseWin : public aBaseWin_sys,
                 public aWinStyle
{
    Q_OBJECT

    private:
        unique_ptr<aLayout_i>           m_pLayout;

        bool        m_bHover = false;   // mouse is on window


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(aBaseWin *_pParent);

    public:
        virtual ~aBaseWin();

        // QWidget is private => provide cast operator for QWidget
        //operator QWidget*()         { return static_cast<QWidget*>(this); }
        SysWin*                 asSysWin()          { return this; }

        bool                    createWin();
        bool                    closeWin();


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        void                    setParent(aBaseWin *_pParent)       { aBaseWin_sys::setParent(_pParent); }
        aBaseWin*               parent() const                      { return aBaseWin_sys::parent(); }

        void                    update()                            { aBaseWin_sys::update(); }
        void                    repaint()                           { aBaseWin_sys::repaint(); }

        // visibility
        void                    setVisible(bool _bVisible)          { aBaseWin_sys::setVisible(_bVisible); }
        bool                    isVisible() const                   { return aBaseWin_sys::isVisible(); }
        void                    show()                              { aBaseWin_sys::setVisible(true); }
        void                    hide()                              { aBaseWin_sys::setVisible(false); }

        void                    setEnabled(bool _bEnabled)          { aBaseWin_sys::setEnabled(_bEnabled); }
        bool                    isEnabled() const                   { return aBaseWin_sys::isEnabled(); }
        bool                    isDisabled() const                  { return !aBaseWin_sys::isEnabled(); }

        bool                    isMinimized() const                 { return aBaseWin_sys::isMinimized(); }
        void                    showMinimized()                     { aBaseWin_sys::showMinimized(); }

        bool                    isMaximized() const                 { return aBaseWin_sys::isMaximized(); }
        void                    showMaximized()                     { aBaseWin_sys::showMaximized(); }

        bool                    isFullScreen() const                { return aBaseWin_sys::isFullScreen(); }
        void                    showFullScreen()                    { aBaseWin_sys::showFullScreen(); }

        bool                    isNormal() const                    { return aBaseWin_sys::isNormal(); }
        void                    showNormal()                        { aBaseWin_sys::showNormal(); }

        void                    setMouseTracking(bool _bEnable)     { aBaseWin_sys::setMouseTracking(_bEnable); }

        void                    enableDragDrop(bool _bEnable)       { aBaseWin_sys::enableDragDrop(_bEnable); }

        void                    setCursor(const aCursor &_cursor)   { aBaseWin_sys::setCursor(_cursor); }

        bool                    isHover() const                     { return m_bHover; }


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                    setMinW(s32 _s32MinW)               { aBaseWin_sys::setMinW(_s32MinW); }
        void                    setMinH(s32 _s32MinH)               { aBaseWin_sys::setMinH(_s32MinH); }
        void                    setMinDim(const aDimension &_minDim);
        void                    setMinDim(s32 _s32MinW,
                                          s32 _s32MinH);
        s32                     minW() const;
        s32                     minH() const;
        aDimension              minDim() const;

        void                    setMaxW(s32 _s32MaxW)               { aBaseWin_sys::setMaxW(_s32MaxW); }
        void                    setMaxH(s32 _s32MaxH)               { aBaseWin_sys::setMaxH(_s32MaxH); }
        void                    setMaxDim(const aDimension &_maxDim);
        void                    setMaxDim(s32 _s32MaxW,
                                          s32 _s32MaxH);

        s32                     maxW() const                        { return aBaseWin_sys::maxW(); }
        s32                     maxH() const                        { return aBaseWin_sys::maxH(); }
        aDimension              maxDim() const                      { return aDimension(aBaseWin_sys::maxW(),
                                                                                        aBaseWin_sys::maxH()); }

        void                    setFixW(s32 _s32FixW);
        void                    setFixH(s32 _s32FixH);
        void                    setFixDim(const aDimension &_fixDim);
        void                    setFixDim(s32 _s32FixW,
                                          s32 _s32FixH);
        bool                    isFixW() const;
        bool                    isFixH() const;

        void                    setGeometry(s32 _s32X,
                                            s32 _s32Y,
                                            s32 _s32W,
                                            s32 _s32H)              { aBaseWin_sys::setGeometry(_s32X, _s32Y, _s32W, _s32H); }

        void                    setGeometry(const aRect &_r)        { aBaseWin_sys::setGeometry(_r.x(), _r.y(), _r.w(), _r.h()); }

        aRect                   geometryRect() const                { return aBaseWin_sys::geometryRect(); }
        s32                     geometryW() const                   { return aBaseWin_sys::geometryRect().w(); }
        s32                     geometryH() const                   { return aBaseWin_sys::geometryRect().h(); }

        virtual aRect           marginRect() const;

        virtual aRect           borderRect() const;

        virtual aRect           paddingRect() const;

        virtual aRect           contentRect() const;


    /*******************************************************************************
    * layout
    *******************************************************************************/
    public:
        void                    setLayout(unique_ptr<aLayout_i> _pLayout);
        aLayout_i*              layout();
        const aLayout_i*        layout() const;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        // create window window
        virtual bool            onSysCreateWin();
        virtual bool            onCreateWin();
        virtual bool            onCreateChilds();

        // close window
        virtual bool            onCloseWin();

        // resize
        virtual void            onSysResize(const aDimension   &_dOldDim,
                                            const aDimension   &_dNewDim);

        virtual void            onResize(const aDimension   &_dOldDim,
                                         const aDimension   &_dNewDim);

        // paint
        virtual void            onPaintMargin();
        virtual void            onPaintBorder();
        virtual void            onPaintPadding();
        virtual void            onPaintContentBg();
        virtual void            onPaintContent();

        // enter / leave
        virtual bool            onEnter(u16             _u16Modifier,
                                        const aPoint    &_pntLocal,
                                        const aPoint    &_pntGlobal);

        virtual bool            onLeave(u16 _u16Modifier);

        // wheel event, true => event handled
        virtual bool            onWheel(u16             _u16Modifier,
                                        s16             _s16Degree,
                                        const aPoint    &_pntLocal,
                                        const aPoint    &_pntGlobal);

        // double click events, true => event handled
        virtual bool            onDoubleClick(u16          _u16Modifier,
                                              u16          _u16Btn,
                                              const aPoint  &_pntLocal,
                                              const aPoint  &_pntGlobal);

        // mouse pressed events, true => event handled
        virtual bool            onButtonPress(u16           _u16Modifier,
                                              u16           _u16Btn,
                                              const aPoint  &_pntLocal,
                                              const aPoint  &_pntGlobal);

        // mouse move events, true => event handled
        virtual bool            onMouseMove(u16             _u16Modifier,
                                            u16             _u16Btn,
                                            const aPoint    &_pntLocal,
                                            const aPoint    &_pntGlobal);

        // mouse release events, true => event handled
        virtual bool            onButtonRelease(u16             _u16Modifier,
                                                u16             _u16Btn,
                                                const aPoint    &_pntLocal,
                                                const aPoint    &_pntGlobal);


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        // close event
        bool                    onCloseEvent() override; // return: true => window can be closed

        // enter/leave event
        bool                    onEnterEvent(u16             _u16Modifier,
                                             const aPoint    &_pntLocal,
                                             const aPoint    &_pntGlobal) override;

        bool                    onLeaveEvent(u16 _u16Modifier) override;

        // resize event
        void                    onResizeEvent(const aDimension   &_dOldDim,
                                              const aDimension   &_dNewDim) override;

        // paint event
        void                    onPaintEvent() override;

        // wheel event, true => event handled
        bool                    onWheelEvent(u16             _u16Modifier,
                                             s16             _s16Degree,
                                             const aPoint    &_pntLocal,
                                             const aPoint    &_pntGlobal) override;

        // double click events, true => event handled
        bool                    onDoubleClickEvent(u16          _u16Modifier,
                                                   u16          _u16Btn,
                                                   const aPoint  &_pntLocal,
                                                   const aPoint  &_pntGlobal) override;

        // mouse pressed events, true => event handled
        bool                    onButtonPressEvent(u16          _u16Modifier,
                                                   u16          _u16Btn,
                                                   const aPoint &_pntLocal,
                                                   const aPoint &_pntGlobal) override;

        // mouse move events, true => event handled
        bool                    onMouseMoveEvent(u16            _u16Modifier,
                                                 u16            _u16Btn,
                                                 const aPoint   &_pntLocal,
                                                 const aPoint   &_pntGlobal) override;

        // mouse release events, true => event handled
        bool                    onButtonReleaseEvent(u16            _u16Modifier,
                                                     u16            _u16Btn,
                                                     const aPoint   &_pntLocal,
                                                     const aPoint   &_pntGlobal) override;

        // drag/drop
        void                    onDropUrl(const aUrl &_url) override;


    /*******************************************************************************
    * using
    *******************************************************************************/
    public:
        using aBaseWin_sys::setGeometry;
}; // class aBaseWin


} // namespace aWin
} // namespace aFrame
