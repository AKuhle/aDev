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
#include "aWin/aWin_def.h"

#include "aUtil/aMargin.h"

#include "aWin/Framework/aSysWin.h"
#include "aWin/Layout/aLayoutObj.h"
#include "aWin/Layout/aLayout.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aBaseWin
*******************************************************************************/
class aBaseWin : public aSysWin,
                 public aLayoutObj
{
    private:
        aMargin                 m_Margin;
        aMargin                 m_Border;
        aMargin                 m_Padding;

        unique_ptr<aLayout>     m_pLayout;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aBaseWin(aBaseWin *_pParent = nullptr);
        ~aBaseWin();


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        bool                        create();
        bool                        close();


    /*******************************************************************************
    * win state
    *******************************************************************************/
    public:
        void                        show();
        void                        hide();
        bool                        isVisible();


    /*******************************************************************************
    * geometry
    *******************************************************************************/
    public:
        void                        setGeometry(s32    _x,
                                                s32    _y,
                                                s32    _w,
                                                s32    _h);

        const aMargin               &margin() const;
        aMargin                     &margin();

        const aMargin               &border() const;
        aMargin                     &border();

        const aMargin               &padding() const;
        aMargin                     &padding();


    /*******************************************************************************
    * layout
    *******************************************************************************/
    public:
        void                        setLayout(unique_ptr<aLayout> _pLayout);


    /*******************************************************************************
    * handler
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();
        virtual bool                onCreate();

        virtual void                onSysResize(const aDimension2D<s32> &_d2dOld,
                                                const aDimension2D<s32> &_d2dNew);      // usually resize childs, eg. titlebar etc

        virtual void                onResize(const aDimension2D<s32> &_d2dOld,
                                             const aDimension2D<s32> &_d2dNew);         // usually for concrete user implementation

        virtual void                onPaintContentBg();


    /*******************************************************************************
    * events
    *******************************************************************************/
    protected:
        virtual void                onResizeEvent(const aDimension2D<s32> &_d2dOld,
                                                  const aDimension2D<s32> &_d2dNew) override;

        virtual void                onPaintEvent() override;

}; // class aBaseWin


} // namespace aWin
} // namespace aLib
