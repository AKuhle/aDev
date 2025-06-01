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
#include <QScrollBar>
#include "aCtrl.h"
#include "aScrollBarI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollBar
*******************************************************************************/
class aScrollBar : public aCtrl<QScrollBar>,
                   public aScrollBarI
{
    private:
        bool        m_bInverse      { false };

    Q_OBJECT

    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aScrollBar(SysWin *_pParent = nullptr);
        virtual ~aScrollBar();


    /*******************************************************************************
    * aScrollBar interface
    *******************************************************************************/
    public:
        void            setRange(s32    _s32Min,
                                 s32    _s32Max) override;

        void            setTracking(bool _bTracking) override;

        void            setPosition(s32 _s32Pos) override;
        void            setValue(s32 _s32Value) override;

        void            setInverse(bool _bInverse) override;


    /*******************************************************************************
    * slots
    *******************************************************************************/
    private slots:
        void            slotValueChanged(int _iValue);

}; // class aScrollBar


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
