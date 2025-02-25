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
#include "aSysWin_sys.h"
#include "aDimension2D.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBaseWin
*******************************************************************************/
template<class T>
class aBaseWin : public aSysWin_sys<T>
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(SysWinClass *_pParent = nullptr);
        virtual ~aBaseWin();

    public:
        bool                create();

        void                setParent(SysWinClass *_pParent);


    /*******************************************************************************
    * window geometry
    *******************************************************************************/
    public:
        void                setMinSize(aDimension2D<s32>  _dim);
        void                setMinSize(s32  _w,
                                       s32  _h);

    /*******************************************************************************
    * window state
    *******************************************************************************/
    public:
        // visibility
        bool                isVisible() const;
        void                setVisible(bool _bVisible);
        void                show();
        void                hide();


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool        onSysCreate()                       { return true; }
        virtual bool        onCreate()                          { return true; }

        virtual void        onDropUrl(const aUrl  &/*_url*/)    {}


    /*******************************************************************************
    * system events
    *******************************************************************************/
    private:
        virtual void        _onOsDropUrl(const aUrl  &_url) override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib


#include "aBaseWin.inl"
