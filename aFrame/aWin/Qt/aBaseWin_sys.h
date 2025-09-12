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
#include "aWin_def.h"
#include "aUtil_def.h"
#include "aGraphic_def.h"

using namespace std;

using namespace aFrame::aGraphic;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aBaseWin_sys
*******************************************************************************/
class aBaseWin_sys : public QWidget
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin_sys(QWidget *_pParent);

    public:
        virtual ~aBaseWin_sys();

        aString                         className() const;

        bool                            closeWin(); // return: true => window has been closed

        void                            setParent(aBaseWin *_pParent);
        aBaseWin*                       parent() const;

        void                            update();
        void                            repaint();

    private:
        bool                            eventFilter(QObject *_pObj,
                                                    QEvent  *_pEvent);

        u16                             currentModifiers() const;

        u16                             modifierFromEvent(QSinglePointEvent *_pEvent) const;

        u16                             qtModifiers2Modifiers(Qt::KeyboardModifiers _modifiers) const;

        u16                             buttonsFromEvent(QSinglePointEvent *_pEvent) const;


    /*******************************************************************************
    * window state/appearance
    *******************************************************************************/
    public:
        // visibility
        void                            setVisible(bool _bVisible);
        bool                            isVisible() const;

        void                            setEnabled(bool _bEnabled);
        bool                            isEnabled() const;

        bool                            isMinimized() const;
        void                            showMinimized();

        bool                            isMaximized() const;
        void                            showMaximized();

        bool                            isFullScreen() const;
        void                            showFullScreen();

        bool                            isNormal() const;
        void                            showNormal();

        void                            toggleMaximized();
        void                            toggleFullScreen();

        void                            setMouseTracking(bool _bEnable);

        void                            setCursor(const aCursor &_cursor);


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                            setMinW(s32 _s32MinW);
        void                            setMinH(s32 _s32MinH);
        s32                             minW() const;
        s32                             minH() const;

        void                            setMaxW(s32 _s32MaxW);
        void                            setMaxH(s32 _s32MaxH);

        void                            setFixW(s32 _s32FixW);
        void                            setFixH(s32 _s32FixH);

        void                            setGeometry(s32 _s32X,
                                                    s32 _s32Y,
                                                    s32 _s32W,
                                                    s32 _s32H);

        aRect                           geometryRect() const;


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        // close event
        virtual bool                    onCloseEvent() = 0; // return: true => window can be closed

        // enter/leave event
        virtual bool                    onEnterEvent(u16             _u16Modifier,
                                                     const aPoint    &_pntLocal,
                                                     const aPoint    &_pntGlobal) = 0;

        virtual bool                    onLeaveEvent(u16 _u16Modifier) = 0;


        // resize event
        virtual void                    onResizeEvent(const aDimension   &_dOldDim,
                                                      const aDimension   &_dNewDim) = 0;

        // paint event
        virtual void                    onPaintEvent() = 0;

        // wheel event, true => event handled
        virtual bool                    onWheelEvent(u16             _u16Modifier,
                                                     s16             _s16Degree,
                                                     const aPoint    &_pntLocal,
                                                     const aPoint    &_pntGlobal) = 0;

        // double click events, true => event handled
        virtual bool                    onDoubleClickEvent(u16          _u16Modifier,
                                                           u16          _u16Btn,
                                                           const aPoint  &_pntLocal,
                                                           const aPoint  &_pntGlobal) = 0;

        // mouse pressed events, true => event handled
        virtual bool                    onButtonPressEvent(u16           _u16Modifier,
                                                           u16           _u16Btn,
                                                           const aPoint  &_pntLocal,
                                                           const aPoint  &_pntGlobal) = 0;

        // mouse move events, true => event handled
        virtual bool                    onMouseMoveEvent(u16             _u16Modifier,
                                                         u16             _u16Btn,
                                                         const aPoint    &_pntLocal,
                                                         const aPoint    &_pntGlobal) = 0;

        // mouse release events, true => event handled
        virtual bool                    onButtonReleaseEvent(u16             _u16Modifier,
                                                             u16             _u16Btn,
                                                             const aPoint    &_pntLocal,
                                                             const aPoint    &_pntGlobal) = 0;




    //     void                    onDropUrl(const aUrl  &_url) override;
}; // class aBaseWin_sys


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
