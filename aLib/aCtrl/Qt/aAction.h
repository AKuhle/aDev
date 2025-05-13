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
#include <QAction>
#include "aCtrlI.h"
#include "aActionI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class
*******************************************************************************/
class aAction : public QObject,
                public aCtrlI,
                public aActionI
{
    Q_OBJECT

    private:
        QAction     *m_pAction;

    private:
        s32             m_s32CtrlID     { 0 };
        aCtrlMgr        *m_pCtrlMgr     { nullptr };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aAction(QAction *_pAction);
        virtual ~aAction();


    /*******************************************************************************
    * aCtrlI interface
    *******************************************************************************/
    public:
        void            setCtrlId(s32 _s32CtrlID) override;
        s32             ctrlId() const override;

        void            setCtrlMgr(aCtrlMgr *_pCtrlMgr) override;
        aCtrlMgr*       ctrlMgr() const override;

        void            setCtrlEnabled(bool _bEnabled) override;
        bool            ctrlEnabled() const override;

        void            setCtrlChecked(bool _bChecked) override;
        void            setCtrlEnabledChecked(bool _bEnabled,
                                              bool _bChecked) override;
        bool            ctrlChecked() const override;


    /*******************************************************************************
    * slots
    *******************************************************************************/
    private slots:
        void            slotTriggered(bool _bChecked);

}; // class aAction


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
