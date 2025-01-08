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
                  public qSysWinI
{
    protected:
        aSysWinQt(aSysWinQt *_pParent = nullptr);
        virtual ~aSysWinQt();


    /*******************************************************************************
    * Qt specific
    *******************************************************************************/
    public:
        QWidget*                getQWidget()            { return this; }
        //     u32                     mouseButton(QMouseEvent *_pEvent) const;


    /*******************************************************************************
    * win state
    *******************************************************************************/
    protected:
        virtual void            _show() override;
        virtual void            _hide() override;
        virtual bool            _isVisible() const override;


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    protected:
        virtual void            _setGeometry(s32    _x,
                                             s32    _y,
                                             s32    _w,
                                             s32    _h) override;

    /*******************************************************************************
    * system events
    *******************************************************************************/
    private:
        virtual void            resizeEvent(QResizeEvent *_pEvent) override;
        virtual void            paintEvent(QPaintEvent *_pEvent) override;


}; // class aSysWinQt



} // namespace SysQt
} // namespace aWin
} // namespace qLib


#endif // _USE_QT_
