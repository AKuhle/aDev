/*******************************************************************************
* \file aSysWinQt.h
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

#include "aWin/Framework/aSysWin_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {
namespace SysQt {



/*******************************************************************************
* class aSysWinQt
*******************************************************************************/
class aSysWinQt : private QWidget,
                  public aSysWinI
{
    protected:
        aSysWinQt(aSysWinQt *_pParent = nullptr);
        virtual ~aSysWinQt();

        aSysWin_t*                  _sysWin() override;

        aSysWin*                    _parent() const override;
        void                        _setParent(aSysWin *_pParent) override;

        void                        _setCursor(const aCursor &_cursor) override;

        void                        _setFont(const aFont &_font) override;
        aFont                       _font() const override;

        void                        _setFocusPolicy(enumFocusPolicy _policy);
        void                        _setFocus() override;
        bool                        _hasFocus() const override;

        void                        _setMouseTracking(bool _bEnable) override;

        void                        _raise() override;
        void                        _lower() override;

        void                        _enableDrop(bool _bEnable) override;

        void                        _repaint() override;
        void                        _update() override;


    /*******************************************************************************
    * Qt specific
    *******************************************************************************/
    public:
        QWidget*                    getQWidget();


    /*******************************************************************************
    * win state
    *******************************************************************************/
    protected:
        void                        _close() override;

        void                        _show() override;
        void                        _hide() override;
        bool                        _isVisible() const override;

        void                        _setEnabled(bool _bEnabled) override;
        bool                        _isEnabled() const override;

        void                        _showMaximized() override;
        void                        _showMinimized() override;
        void                        _showNormal() override;
        bool                        _isMaximized() const override;
        bool                        _isMinimized() const override;

        u32                         _modifiers() const override;
        u32                         _mouseButton() const override;
        u32                         _mouseButton(QMouseEvent *_pEvent) const;
        aVector2D<s32>              _localCursorPos() const override;
        aVector2D<s32>              _globalCursorPos() const override;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    protected:
        void                        _setGeometry(s32    _x,
                                                 s32    _y,
                                                 s32    _w,
                                                 s32    _h) override;

        aRect2D<s32>                _geometry() const override;

        s32                         _w() const override;
        s32                         _h() const override;


    /*******************************************************************************
    * system events
    *******************************************************************************/
    private:
        void                        focusInEvent(QFocusEvent *_pEvent);
        void                        focusOutEvent(QFocusEvent *_pEvent);

        void                        resizeEvent(QResizeEvent *_pEvent) override;
        void                        paintEvent(QPaintEvent *_pEvent) override;

        void                        enterEvent(QEnterEvent *_pEvent) override;
        void                        leaveEvent(QEvent *_pEvent) override;

        void                        wheelEvent(QWheelEvent *_pEvent) override;
        void                        mouseDoubleClickEvent(QMouseEvent *_pEvent) override;
        void                        mousePressEvent(QMouseEvent *_pEvent) override;
        void                        mouseMoveEvent(QMouseEvent *_pEvent) override;
        void                        mouseReleaseEvent(QMouseEvent *_pEvent) override;

        virtual void                dragEnterEvent(QDragEnterEvent *_pEvent) override;
        virtual void                dragMoveEvent(QDragMoveEvent *_pEvent) override;
        virtual void                dropEvent(QDropEvent   *_pEvent) override;

}; // class aSysWinQt



} // namespace SysQt
} // namespace aWin
} // namespace qLib


#endif // _USE_QT_
