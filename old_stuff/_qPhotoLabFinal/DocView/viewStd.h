/*******************************************************************************
* \file ViewStd.h
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
// #include "qLib.h"
#include "viewBase.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace qLib;

class Doc;


/*******************************************************************************
* class ViewStd
*******************************************************************************/
class ViewStd : public ViewBase
{
    public:
        ViewStd(qWin                    *_pParent,
                std::shared_ptr<Doc>    _pDoc);

        virtual ~ViewStd();


    /*******************************************************************************
    * ViewBase interface
    *******************************************************************************/
    protected:
        virtual void            UpdateScrollbars() override;
        virtual void            UpdateRenderParams(RenderParams &_rp) override;

        //virtual void            SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom) override;

}; // class ViewStd
