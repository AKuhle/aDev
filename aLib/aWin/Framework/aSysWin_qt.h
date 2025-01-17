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

        virtual aSysWin*            _parent() const override;
        virtual void                _setParent(aSysWin *_pParent) override;

        virtual void                _setCursor(const aCursor &_cursor) override;

        virtual void                _setMouseTracking(bool _bEnable) override;

        virtual void                _repaint() override;
        virtual void                _update() override;


    /*******************************************************************************
    * Qt specific
    *******************************************************************************/
    public:
        QWidget*                    getQWidget();


    /*******************************************************************************
    * win state
    *******************************************************************************/
    protected:
        virtual void                _show() override;
        virtual void                _hide() override;
        virtual bool                _isVisible() const override;

        virtual void                _setEnabled(bool _bEnabled) override;
        virtual bool                _isEnabled() const override;

        virtual void                _showMaximized() override;
        virtual void                _showMinimized() override;
        virtual void                _showNormal() override;
        virtual bool                _isMaximized() const override;
        virtual bool                _isMinimized() const override;

        virtual u32                 _modifiers() const override;
        virtual u32                 _mouseButton() const override;
        u32                         _mouseButton(QMouseEvent *_pEvent) const;
        virtual aVector2D<s32>      _localCursorPos() const override;
        virtual aVector2D<s32>      _globalCursorPos() const override;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    protected:
        virtual void                _setGeometry(s32    _x,
                                                 s32    _y,
                                                 s32    _w,
                                                 s32    _h) override;

        virtual aRect2D<s32>        _geometry() const override;

        virtual s32                 _w() const override;
        virtual s32                 _h() const override;


    /*******************************************************************************
    * system events
    *******************************************************************************/
    private:
        virtual void                resizeEvent(QResizeEvent *_pEvent) override;
        virtual void                paintEvent(QPaintEvent *_pEvent) override;

        virtual void                enterEvent(QEnterEvent *_pEvent) override;
        virtual void                leaveEvent(QEvent *_pEvent) override;

        virtual void                wheelEvent(QWheelEvent *_pEvent) override;
        virtual void                mouseDoubleClickEvent(QMouseEvent *_pEvent) override;
        virtual void                mousePressEvent(QMouseEvent *_pEvent) override;
        virtual void                mouseMoveEvent(QMouseEvent *_pEvent) override;
        virtual void                mouseReleaseEvent(QMouseEvent *_pEvent) override;

}; // class aSysWinQt



} // namespace SysQt
} // namespace aWin
} // namespace qLib


#endif // _USE_QT_
