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
        void                        show();
        void                        hide();
        bool                        isVisible();

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
        virtual aRect2D<s32>        contentRect() const;    // paddingRect - padding()

        // the rect to arrange the childs of a layout, usually equal to the content rect
        //
        // e.g. for aMainWin: content rect is smaller then the layout rect
        // because of the titlebar, docking areas etc. which belongs to the layout
        virtual aRect2D<s32>        layoutRect() const;


    /*******************************************************************************
    * layout
    *******************************************************************************/
    public:
        void                        setLayout(unique_ptr<aLayout> _pLayout);


    /*******************************************************************************
    * members
    *******************************************************************************/
    public:
        aBaseWin*                   parent() const;
        void                        setParent(aBaseWin *_pParent);

        void                        setCursor(const aCursor &_cursor);

        void                        setMouseTracking(bool _bEnable);


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();
        virtual bool                onCreate();

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


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        virtual void                onResizeEvent(const aDimension2D<s32> &_d2dOld,
                                                  const aDimension2D<s32> &_d2dNew) override;

        virtual void                onPaintEvent() override;

        virtual bool                onEnterEvent(u32                     _u32Modifiers,
                                                 const aVector2D<s32>    &_v2dLocal,
                                                 const aVector2D<s32>    &_v2dGlobal) override;

        virtual bool                onLeaveEvent(u32 _u32Modifiers) override;

        virtual bool                onWheelEvent(u32                    _u32Modifiers,
                                                 s32                    _s32Degree,
                                                 const aVector2D<s32>   &_v2dLocal,
                                                 const aVector2D<s32>   &_v2dGlobal) override;

        virtual bool                onDoubleClickEvent(u32                  _u32Modifiers,
                                                       u32                  _u32MouseButton,
                                                       const aVector2D<s32> &_v2dLocal,
                                                       const aVector2D<s32> &_v2dGlobal) override;

        virtual bool                onMousePressEvent(u32                   _u32Modifiers,
                                                      u32                   _u32MouseButton,
                                                      const aVector2D<s32>  &_v2dLocal,
                                                      const aVector2D<s32>  &_v2dGlobal) override;

        virtual bool                onMouseMoveEvent(u32                    _u32Modifiers,
                                                     u32                    _u32MouseButton,
                                                     const aVector2D<s32>   &_v2dLocal,
                                                     const aVector2D<s32>   &_v2dGlobal) override;

        virtual bool                onMouseReleaseEvent(u32                     _u32Modifiers,
                                                        u32                     _u32MouseButton,
                                                        const aVector2D<s32>    &_v2dLocal,
                                                        const aVector2D<s32>    &_v2dGloba) override;
}; // class aBaseWin


} // namespace aWin
} // namespace aLib
