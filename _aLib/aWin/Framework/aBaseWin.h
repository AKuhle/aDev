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
#include "aWin/aWin_def.h"

#include "aUtil/aMargin.h"

#include "aWin/Framework/aSysWin.h"
#include "aWin/Style/aWinStyle.h"
#include "aWin/Style/aWinStyleFactory.h"
#include "aWin/Layout/aLayoutObj.h"
#include "aWin/Layout/aLayout.h"
#include "aWin/Tool/aToolMgr.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBaseWin
*******************************************************************************/
class aBaseWin : private aSysWin,
                 public aWinStyle,
                 public aLayoutObj,
                 public aToolMgr
{
    private:
        static unique_ptr<aWinStyleFactory> m_pWinStyleFactory;

        unique_ptr<aLayout>                 m_pLayout;

        bool                                m_bHover        { false };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(aBaseWin *_pParent = nullptr);
        ~aBaseWin();


    public:
        bool                        create();
        bool                        close();

        aSysWin_t*                  sysWin();

        void                        repaint();
        void                        update();


    /*******************************************************************************
    * window style
    *******************************************************************************/
    public:
        static void                 setWinStyleFactory(unique_ptr<aWinStyleFactory> _pWinStyleFactory);


    /*******************************************************************************
    * win state
    *******************************************************************************/
    public:
        virtual void                show();
        virtual void                hide();
        virtual bool                isVisible();

        void                        setEnabled(bool _bEnabled);
        bool                        isEnabled() const;
        bool                        isDisabled() const;

        void                        showMaximized();
        void                        showMinimized();
        void                        showNormal();
        void                        toggleMaximized();
        bool                        isMaximized() const;
        bool                        isMinimized() const;

        bool                        isHover() const;

        u32                         modifiers() const;
        u32                         mouseButton() const;
        aVector2D<s32>              localCursorPos() const;
        aVector2D<s32>              globalCursorPos() const;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    public:
        // max of the minDimension and the dimension of the layout (if exist)
        virtual aDimension2D<s32>   minDim() const;

        // geometry is relativ to the parent
        void                        setGeometry(const aRect2D<s32>  &_r2d);

        // implemetation from aLayoutObj
        virtual void                setGeometry(s32    _x,
                                                s32    _y,
                                                s32    _w,
                                                s32    _h) override;

        aRect2D<s32>                geometry() const;

        s32                         w() const;
        s32                         h() const;

        virtual aRect2D<s32>        winRect() const;        // (0, 0, w, h)
        virtual aRect2D<s32>        borderRect() const;     // winRect() - margin()
        virtual aRect2D<s32>        paddingRect() const;    // borderRect - border()

        // the rect to arrange the childs of a layout, usually equal to the content rect
        //
        // e.g. for aMainWin: content rect is smaller then the layout rect
        // because of the titlebar, docking areas etc. which belongs to the layout
        virtual aRect2D<s32>        layoutRect() const;

        virtual aRect2D<s32>        contentRect() const;    // paddingRect - padding()


    /*******************************************************************************
    * layout
    *******************************************************************************/
    public:
        aLayout*                    layout() const;
        void                        setLayout(unique_ptr<aLayout> _pLayout);
        void                        updateLayout();


    /*******************************************************************************
    * members
    *******************************************************************************/
    public:
        aBaseWin*                   parent() const;
        void                        setParent(aBaseWin *_pParent);

        void                        setCursor(const aCursor &_cursor);

        void                        setFont(const aFont &_font);
        aFont                       font() const;

        void                        setFocusPolicy(enumFocusPolicy _policy);
        void                        setFocus();
        bool                        hasFocus() const;

        void                        setMouseTracking(bool _bEnable);

        // Raises this widget to the top of the parent widget's stack.
        void                        raise();

        // Lowers the widget to the bottom of the parent widget's stack.
        void                        lower();

        void                        enableDrop(bool _bEnable);

    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();
        virtual bool                onCreate();
        virtual bool                onClose();

        virtual void                onFocusIn(enumFocusReason  _eReason);
        virtual void                onFocusOut(enumFocusReason  _eReason);

        virtual void                onSysResize(const aDimension2D<s32> &_d2dOld,
                                                const aDimension2D<s32> &_d2dNew);      // usually resize childs, eg. titlebar etc

        virtual void                onResize(const aDimension2D<s32> &_d2dOld,
                                             const aDimension2D<s32> &_d2dNew);         // usually for concrete user implementation

        virtual void                onPaintMargin();
        virtual void                onPaintBorder();
        virtual void                onPaintPaddingBg();
        virtual void                onPaintPadding();
        virtual void                onPaintContentBg();
        virtual void                onPaintContent();

        virtual bool                onEnter(u32                     _u32Modifiers,
                                            const aVector2D<s32>    &_v2dLocal,
                                            const aVector2D<s32>    &_v2dGlobal);

        virtual bool                onLeave(u32 _u32Modifiers);

        virtual bool                onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const aVector2D<s32>    &_v2dLocal,
                                            const aVector2D<s32>    &_v2dGlobal);

        bool                        onDoubleClick(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const aVector2D<s32>  &_v2dLocal,
                                                  const aVector2D<s32>  &_v2dGlobal);

        virtual bool                onMousePress(u32                    _u32Modifiers,
                                                 u32                    _u32MouseButton,
                                                 const aVector2D<s32>   &_v2dLocal,
                                                 const aVector2D<s32>   &_v2dGlobal);

        virtual bool                onMouseMove(u32                     _u32Modifiers,
                                                u32                     _u32MouseButton,
                                                const aVector2D<s32>    &_v2dLocal,
                                                const aVector2D<s32>    &_v2dGlobal);

        virtual bool                onMouseRelease(u32                  _u32Modifiers,
                                                   u32                  _u32MouseButton,
                                                   const aVector2D<s32> &_v2dLocal,
                                                   const aVector2D<s32> &_v2dGlobal);

        virtual void                onDropUrl(const aUrl &_url);


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        void                        onFocusInEvent(enumFocusReason  _eReason) override;
        void                        onFocusOutEvent(enumFocusReason  _eReason) override;

        void                        onResizeEvent(const aDimension2D<s32> &_d2dOld,
                                                  const aDimension2D<s32> &_d2dNew) override;

        void                        onPaintEvent() override;

        bool                        onEnterEvent(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal) override;

        bool                        onLeaveEvent(u32 _u32Modifiers) override;

        bool                        onWheelEvent(u32                    _u32Modifiers,
                                                 s32                    _s32Degree,
                                                 const aVector2D<s32>   &_v2dLocal,
                                                 const aVector2D<s32>   &_v2dGlobal) override;

        bool                        onDoubleClickEvent(u32                  _u32Modifiers,
                                                       u32                  _u32MouseButton,
                                                       const aVector2D<s32> &_v2dLocal,
                                                       const aVector2D<s32> &_v2dGlobal) override;

        bool                        onMousePressEvent(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const aVector2D<s32>  &_v2dLocal,
                                                      const aVector2D<s32>  &_v2dGlobal) override;

        bool                        onMouseMoveEvent(u32                    _u32Modifiers,
                                                     u32                    _u32MouseButton,
                                                     const aVector2D<s32>   &_v2dLocal,
                                                     const aVector2D<s32>   &_v2dGlobal) override;

        bool                        onMouseReleaseEvent(u32                     _u32Modifiers,
                                                        u32                     _u32MouseButton,
                                                        const aVector2D<s32>    &_v2dLocal,
                                                        const aVector2D<s32>    &_v2dGloba) override;

        void                        onDropUrlEvent(const aUrl &_url) override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib
