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
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aMargin.h"
#include "aDimension.h"

#include "aWinStyle.h"


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

using namespace std;

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aBaseWin_i
*******************************************************************************/
class aBaseWin_i : public aWinStyle
{
    // geometry
    private:
        SysWin                          *m_pWinInstance;

        aMargin                         m_margin;
        aMargin                         m_padding;

        // layout
        unique_ptr<aLayout_i>           m_pLayout;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin_i(SysWin *_pWinInstance);

    public:
        virtual ~aBaseWin_i();

        bool                            createWin();
        // bool                    closeWin() override;

        aString                         className() const;

        virtual void                    setParent(SysWin *_pParent) = 0;
        virtual SysWin*                 parent() const = 0;

        virtual void                    update() = 0;
        virtual void                    repaint() = 0;

        // aBaseWin_iI*              widget2BaseWin(QWidget *_pWidget);
        // QWidget*                baseWin2Widget(aBaseWin_iI *_pWin);

        // template <class aWin>
        // aWin                    win_cast(aBaseWin_iI *_pWin) const
        // {
        //     return (aWin) _pWin;
        // }

        // void                    setWinTitle(const aString &_sTitle) override;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        void                            show();
        void                            hide();
        virtual void                    setVisible(bool _bVisible) = 0;
        virtual bool                    isVisible() const = 0;

        virtual bool                    isMinimized() const = 0;
        virtual bool                    isMaximized() const = 0;
        virtual void                    showMinimized() = 0;
        virtual void                    showMaximized() = 0;
        void                            toggleMaximized();

        virtual void                    setMouseTracking(bool _bEnable) = 0;


    /*******************************************************************************
    * layout
    *******************************************************************************/
    public:
        void                            setLayout(unique_ptr<aLayout_i> _pLayout);


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        // void                    setFixedW(s32  _s32W) override;
        // void                    setFixedH(s32  _s32H) override;

        void                            setMinDim(const aDimension &_minDim);
        void                            setMinDim(s32 _s32MinW,
                                          s32 _s32MinH);
        virtual void                    setMinW(s32 _s32MinW) = 0;
        virtual void                    setMinH(s32 _s32MinH) = 0;

        void                            setMaxDim(const aDimension &_maxDim);
        void                            setMaxDim(s32 _s32MaxW,
                                          s32 _s32MaxH);
        virtual void                    setMaxW(s32 _s32MaxW) = 0;
        virtual void                    setMaxH(s32 _s32MaxH) = 0;

        virtual void                    setGeometry(s32 _s32X,
                                                    s32 _s32Y,
                                                    s32 _s32W,
                                                    s32 _s32H) = 0;

        virtual aRect                   geometryRect() const = 0;
        virtual s32                     geometryW() const = 0;
        virtual s32                     geometryH() const = 0;

        virtual aRect                   marginRect() const;

        virtual aRect                   borderRect() const;

        virtual aRect                   paddingRect() const;

        virtual aRect                   contentRect() const;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool                    onSysCreateWin();
        virtual bool                    onCreateWin();
    //     bool                    onCloseWin() override;


        // wheel event, true => event handled
        virtual bool                    onWheel(u16             _u16Modifier,
                                                s16             _s16Degree,
                                                const aPoint    &_pntLocal,
                                                const aPoint    &_pntGlobal);


        // double click events, true => event handled
        virtual bool                    onLDoubleClick(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);

        virtual bool                    onMDoubleClick(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);

        virtual bool                    onRDoubleClick(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);


        // mouse pressed events, true => event handled
        virtual bool                    onLButtonPress(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);

        virtual bool                    onMButtonPress(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);

        virtual bool                    onRButtonPress(u16          _u16Modifier,
                                                       const aPoint &_pntLocal,
                                                       const aPoint &_pntGlobal);


        // mouse move events, true => event handled
        // separate handler for moves without/multiple buttons
        virtual bool                    onLMouseMove(u16          _u16Modifier,
                                                     const aPoint &_pntLocal,
                                                     const aPoint &_pntGlobal);

        virtual bool                    onMMouseMove(u16          _u16Modifier,
                                                     const aPoint &_pntLocal,
                                                     const aPoint &_pntGlobal);

        virtual bool                    onRMouseMove(u16          _u16Modifier,
                                                     const aPoint &_pntLocal,
                                                     const aPoint &_pntGlobal);

        // only called, if mouseTracking is enabled
        virtual bool                    onMouseMove(u16          _u16Modifier,
                                                    const aPoint &_pntLocal,
                                                    const aPoint &_pntGlobal);

        virtual bool                    onMultipleMouseMove(u16             _u16Modifier,
                                                            const aPoint    &_pntLocal,
                                                            const aPoint    &_pntGlobal,
                                                            bool            _bLBtn,
                                                            bool            _bMBtn,
                                                            bool            _bRBtn);

        // mouse release events, true => event handled
        virtual bool                    onLButtonRelease(u16          _u16Modifier,
                                                         const aPoint &_pntLocal,
                                                         const aPoint &_pntGlobal);

        virtual bool                    onMButtonRelease(u16          _u16Modifier,
                                                         const aPoint &_pntLocal,
                                                         const aPoint &_pntGlobal);

        virtual bool                    onRButtonRelease(u16          _u16Modifier,
                                                         const aPoint &_pntLocal,
                                                         const aPoint &_pntGlobal);


        virtual void                    onSysResize(const aDimension   &_dOldDim,
                                                    const aDimension   &_dNewDim);

        virtual void                    onResize(const aDimension   &_dOldDim,
                                                 const aDimension   &_dNewDim);

        virtual void                    onPaint();
        virtual void                    onPaintMargin();
        virtual void                    onPaintBorder();
        virtual void                    onPaintPadding();
        virtual void                    onPaintContentBg();
        virtual void                    onPaintContent();


    //     void                    onDropUrl(const aUrl  &_url) override;

    // public:
    //     bool                    onWheel(u32                  _u32Modifiers,
    //                                     s32                  _s32Degree,
    //                                     const aPoint2D<s32> &_v2dLocal,
    //                                     const aPoint2D<s32> &_v2dGlobal) override;
}; // class aBaseWin_i


} // namespace aWin
} // namespace aFrame
