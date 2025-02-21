/*******************************************************************************
* \file ViewNavigator.h
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
* class ViewNavigator
*******************************************************************************/
class ViewNavigator : public ViewBase
{
    public:
        ViewNavigator(SysWin_t *_pParent);

        virtual ~ViewNavigator();


    /*******************************************************************************
    * ViewBase interface
    *******************************************************************************/
    protected:
        virtual void            UpdateRenderParams(RenderParams &_rp) override;

        virtual void            SetCenterPointInZoom(qVector2D<s32> _v2dCenter_zoom) override;


    /*******************************************************************************
    * qSysWin interface
    *******************************************************************************/
    protected:
        virtual bool            OnCreate() override;
        virtual void            OnPaintBg() override;
        virtual void            OnPaintMarker(const RenderParams &_rp) override;

    DECLARE_DOUBLE_CLICK_EVENT

}; // class ViewNavigator
