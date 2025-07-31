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
#include <QObject>

#include "aWin_def.h"

#include "aBaseWin_i.h"

#include "aRect.h"

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

/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {



/*******************************************************************************
* class aBaseWin
*******************************************************************************/
class aBaseWin : public QObject,
                 public aBaseWin_i
{
    Q_OBJECT

    protected:
        SysWin      *m_pWin;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(SysWin *_pWin);

    public:
        virtual ~aBaseWin();

        SysWin*                 sysWinPtr() override;


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        void                    setVisible(bool _bVisible) override;
        bool                    isVisible() const override;


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                    setMinW(s32 _s32MinW) override;
        void                    setMinH(s32 _s32MinH) override;

        void                    setMaxW(s32 _s32MaxW) override;
        void                    setMaxH(s32 _s32MaxH) override;

        aRect                   geometryRect() const override;
        s32                     geometryW() const override;
        s32                     geometryH() const override;


    // /*******************************************************************************
    // * qt handler
    // *******************************************************************************/
    protected:
        bool                    eventFilter(QObject *_pObj,
                                            QEvent  *_pEvent) override;

    private:
        // void                    dragEnterEvent(QDragEnterEvent *_pEvent) override;
        // void                    dragMoveEvent(QDragMoveEvent *_pEvent) override;
        // void                    dropEvent(QDropEvent   *_pEvent) override;

        // void                    wheelEvent(QWheelEvent *_pEvent) override;

}; // class aBaseWin


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
