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
#include "Win/winDefs.h"
#include "Win/WinStyle/qWinStyle.h"
#include "Win/Layout/qLayout.h"
#include "Win/FrameWin/qSysWin.h"

#include "Tool/qToolMgr.h"

using namespace std;
using namespace qLib::Tool;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qWin
*******************************************************************************/
class qWin : public qSysWin,
             public qWinStyle,
             public qLayoutObj,
             public qToolMgr
{
    private:
        static unique_ptr<qWinStyleFactory> m_pWinStyleFactory;
        unique_ptr<qLayout>                 m_pLayout;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        qWin(qWin *_pParent = nullptr);
        ~qWin();

    /*******************************************************************************
    * public members
    *******************************************************************************/
    public:
        bool                        createWin();

        virtual qWin*               parent() const override                     { return qSysWin::parent(); }
        virtual void                setParent(qWin *_pParent) override          { qSysWin::setParent(_pParent); }

        virtual qVector2D<s32>      globalCursorPos() const  override           { return qSysWin::globalCursorPos(); }
        virtual qVector2D<s32>      localCursorPos() const  override            { return qSysWin::localCursorPos(); }
        virtual u32                 modifiers() const  override                 { return qSysWin::modifiers(); }
        virtual u32                 mouseButton() const  override               { return qSysWin::mouseButton(); }
        virtual void                setMouseTracking(bool _bEnable)  override   { qSysWin::setMouseTracking(_bEnable); }

        virtual void                setCursor(const qCursor &_cursor)           { qSysWin::setCursor(_cursor); }


    /*******************************************************************************
    * win state
    *******************************************************************************/
    public:
        virtual void                show() override                             { qSysWin::show(); }
        virtual void                hide() override                             { qSysWin::hide(); }
        virtual void                setVisible(bool _bVisible) override         { qSysWin::setVisible(_bVisible); }
        virtual bool                isVisible() const override                  { return qSysWin::isVisible(); }

        virtual void                showMaximized() override                    { qSysWin::showMaximized(); }
        virtual void                showMinimized() override                    { qSysWin::showMinimized(); }
        virtual void                showNormal() override                       { qSysWin::showNormal(); }
        virtual bool                isMaximized() const override                { return qSysWin::isMaximized(); }
        virtual bool                isMinimized() const override                { return qSysWin::isMinimized(); }

        void                        toggleMaximized();


    /*******************************************************************************
    * style
    *******************************************************************************/
    public:
        static void                 setWinStyleFactory(unique_ptr<qWinStyleFactory>_pWinStyle);


    /*******************************************************************************
    * Layout
    *******************************************************************************/
    public:
        void                        setLayout(unique_ptr<qLayout>_pLayout);
        qLayout*                    layout() const;
        void                        updateLayout();


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    public:
        virtual qRect2D<s32>        geometry() const override                       { return qSysWin::geometry();}
        virtual void                setGeometry(const qRect2D<s32> &_r2d) override  { qSysWin::setGeometry(_r2d); }
        virtual void                setGeometry(s32 _x,
                                                s32 _y,
                                                s32 _w,
                                                s32 _h) override                    { qSysWin::setGeometry(_x, _y, _w, _h); }

        virtual s32                 w() const override                              { return qSysWin::w();}
        virtual s32                 h() const override                              { return qSysWin::h();}

            // geometry within the window, (0, 0) is left top
        virtual qRect2D<s32>        marginRect() const;     // == margin rect (0, 0, w, h)
        virtual qRect2D<s32>        borderRect() const;     // == winRect - margin()
        virtual qRect2D<s32>        paddingRect() const;    // == borderRect - border()
        virtual qRect2D<s32>        layoutRect() const;    // == paddingRect - padding()
        virtual qRect2D<s32>        contentRect() const;    // == paddingRect - padding()


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool                onSysCreateWin();
        virtual bool                onCreateWin();

        virtual void                onSysResize(const qDimension2D<s32> &_d2dOld,
                                                const qDimension2D<s32> &_d2dNew);      // usually resize childs, eg. titlebar etc

        virtual void                onResize(const qDimension2D<s32> &_d2dOld,
                                             const qDimension2D<s32> &_d2dNew);         // usually for concrete user implementation


        virtual void                onPaintMargin();

        virtual void                onPaintBorder();

        virtual void                onPaintPaddingBg();
        virtual void                onPaintPadding();

        virtual void                onPaintContentBg();
        virtual void                onPaintContent();

        virtual bool                onEnter(u32                     _u32Modifiers,
                                            const qVector2D<s32>    &_v2dLocal,
                                            const qVector2D<s32>    &_v2dGlobal);

        virtual bool                onLeave(u32 _u32Modifiers);

        virtual bool                onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const qVector2D<s32>    &_v2dLocal,
                                            const qVector2D<s32>    &_v2dGlobal);

        virtual bool                onDoubleClick(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

        virtual bool                onMousePress(u32                    _u32Modifiers,
                                                 u32                    _u32MouseButton,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal);

        virtual bool                onMouseMove(u32                     _u32Modifiers,
                                                u32                     _u32MouseButton,
                                                const qVector2D<s32>    &_v2dLocal,
                                                const qVector2D<s32>    &_v2dGlobal);

        virtual bool                onMouseRelease(u32                  _u32Modifiers,
                                                   u32                  _u32MouseButton,
                                                   const qVector2D<s32> &_v2dLocal,
                                                   const qVector2D<s32> &_v2dGlobal);


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        virtual void                onResizeEvent(const qDimension2D<s32> &_d2dOld,
                                                  const qDimension2D<s32> &_d2dNew) override;

        virtual void                onPaintEvent() override;

        virtual bool                onEnterEvent(u32                     _u32Modifiers,
                                                 const qVector2D<s32>    &_v2dLocal,
                                                 const qVector2D<s32>    &_v2dGlobal) override;

        virtual bool                onLeaveEvent(u32 _u32Modifiers) override;

        virtual bool                onWheelEvent(u32                    _u32Modifiers,
                                                 s32                    _s32Degree,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal) override;

        virtual bool                onDoubleClickEvent(u32                  _u32Modifiers,
                                                       u32                  _u32MouseButton,
                                                       const qVector2D<s32> &_v2dLocal,
                                                       const qVector2D<s32> &_v2dGlobal) override;

        virtual bool                onMousePressEvent(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const qVector2D<s32>  &_v2dLocal,
                                                      const qVector2D<s32>  &_v2dGlobal) override;

        virtual bool                onMouseMoveEvent(u32                    _u32Modifiers,
                                                     u32                    _u32MouseButton,
                                                     const qVector2D<s32>   &_v2dLocal,
                                                     const qVector2D<s32>   &_v2dGlobal) override;

        virtual bool                onMouseReleaseEvent(u32                     _u32Modifiers,
                                                        u32                     _u32MouseButton,
                                                        const qVector2D<s32>    &_v2dLocal,
                                                        const qVector2D<s32>    &_v2dGlobal) override;


}; // class qWin


} // namespace Win
} // namespace qLib
