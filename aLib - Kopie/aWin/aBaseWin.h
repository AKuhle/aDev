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
#include "aGraphic_def.h"
#include "aBaseWin_sys.h"
#include "aDimension2D.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBaseWin
*******************************************************************************/
template<class T>
class aBaseWin : public aBaseWin_sys<T>
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(SysWinClass *_pParent);

    public:
        virtual ~aBaseWin();

        bool                create();

        void                setParent(SysWinClass *_pParent);
        SysWinClass*        parent() const;

        void                update();
        void                repaint();


    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
         void               setVisible(bool _bVisible);
         void               show();
         void               hide();
         bool               isVisible() const;

        void                setMouseTracking(bool _bEnable);


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                setMinSize(const aDimension2D<s32> &_dim);
        void                setMinSize(s32  _s32W,
                                       s32  _s32H);

        aRect2D<s32>        clientRect() const;
        s32                 clientW() const;
        s32                 clientH() const;


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool        onSysCreate();
        virtual bool        onCreate();

        virtual void        onDropUrl(const aUrl  &_url);
        virtual bool        onPaint();


    /*******************************************************************************
    * system handler
    *******************************************************************************/
    protected:
        void                onSysDropUrl(const aUrl  &_url) override;
        bool                onSysPaint() override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib

#include "aBaseWin.inl"
#include "aBaseWin_handler.inl"


// /*******************************************************************************
// * window geometry
// *******************************************************************************/
// public:
//     void                setMinSize(aDimension2D<s32>  _dim);
//     void                setMinSize(s32  _w,
//                                    s32  _h);
