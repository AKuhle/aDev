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
        aMargin                         m_margin;
        aMargin                         m_border;
        aMargin                         m_padding;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin_i();

    public:
        virtual ~aBaseWin_i();

        bool                            createWin();
        // bool                    closeWin() override;

        virtual SysWin*                 sysWinPtr() = 0;
        aString                         className() const;


        // aBaseWin_iI*              widget2BaseWin(QWidget *_pWidget);
        // QWidget*                baseWin2Widget(aBaseWin_iI *_pWin);

        // template <class aWin>
        // aWin                    win_cast(aBaseWin_iI *_pWin) const
        // {
        //     return (aWin) _pWin;
        // }

        // void                    setParent(SysWin *_pParent) override;
        // SysWin*                 parent() const override;

        // void                    update() override;
        // void                    repaint() override;

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

        // void                    setMouseTracking(bool _bEnable) override;


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
