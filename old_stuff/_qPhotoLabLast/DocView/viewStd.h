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

class DocPl;


/*******************************************************************************
* class ViewStd
*******************************************************************************/
class ViewStd : public ViewBase
{
    public:
        ViewStd(SysWin_t                  *_pParent,
                std::shared_ptr<DocPl>    _pDoc);

        virtual ~ViewStd();


    /*******************************************************************************
    * ViewBase interface
    *******************************************************************************/
    protected:
        virtual void            UpdateRenderParams(RenderParams &_rp) override;

        virtual void            SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom) override;

}; // class ViewStd
