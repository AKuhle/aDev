/*******************************************************************************
* \file qSysWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "qSysWin.h"


namespace qLib
{
    /*******************************************************************************
    * qSysWin<T>::OnSysCreate
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnSysCreate()
    {
        return true;
    } // qSysWin<T>::OnSysCreate


    /*******************************************************************************
    * qSysWin<T>::OnCreate
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnCreate()
    {
        return true;
    } // qSysWin<T>::OnCreate


    /*******************************************************************************
    * qSysWin<T>::OnClose
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnClose()
    {
        return true;
    } // qSysWin<T>::OnClose


    /*******************************************************************************
    * qSysWin<T>::OnSysResize
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnSysResize(const qDimension2D<s32>    &/*_d2dOld*/,
                                 const qDimension2D<s32>    &/*_d2dNew*/)
    {
    } // qSysWin<T>::OnSysResize


    /*******************************************************************************
    * qSysWin<T>::OnResize
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnResize(const qDimension2D<s32>    &/*_d2dOld*/,
                              const qDimension2D<s32>    &/*_d2dNew*/)
    {
    } // qSysWin<T>::OnResize


    /*******************************************************************************
    * qSysWin<T>::OnPaintBg
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnPaintBg()
    {
    } // qSysWin<T>::OnPaintBg


    /*******************************************************************************
    * qSysWin<T>::OnPaint
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnPaint()
    {
    } // qSysWin<T>::OnPaint


    /*******************************************************************************
    * qSysWin<T>::OnDropUrl
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnDropUrl(const qUrl &/*_url*/)
    {
    } // qSysWin<T>::OnDropUrl


    /*******************************************************************************
    * qSysWin<T>::OnWheel
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnWheel(u32                     /*_u32Modifiers*/,
                             s32                     /*_s32Degree*/,
                             const qVector2D<s32>    &/*_v2dLocal*/,
                             const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return false;
    } // qSysWin<T>::OnWheel


    /*******************************************************************************
    * qSysWin<T>::OnDoubleClick
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnDoubleClick(u32                   /*_u32Modifiers*/,
                                   u32                   /*_u32MouseButton*/,
                                   const qVector2D<s32>  &/*_v2dLocal*/,
                                   const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return false;
    } // qSysWin<T>::OnDoubleClick

    /*******************************************************************************
    * qSysWin<T>::OnMousePress
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnMousePress(u32                   /*_u32Modifiers*/,
                                  u32                   /*_u32MouseButton*/,
                                  const qVector2D<s32>  &/*_v2dLocal*/,
                                  const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return false;
    } // qSysWin<T>::OnMousePress


    /*******************************************************************************
    * qSysWin<T>::OnMouseMove
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnMouseMove(u32                   /*_u32Modifiers*/,
                                 u32                   /*_u32MouseButton*/,
                                 const qVector2D<s32>  &/*_v2dLocal*/,
                                 const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return false;
    } // qSysWin<T>::OnMouseMove


    /*******************************************************************************
    * qSysWin<T>::OnMouseRelease
    *******************************************************************************/
    template <class T>
    bool qSysWin<T>::OnMouseRelease(u32                   /*_u32Modifiers*/,
                                    u32                   /*_u32MouseButton*/,
                                    const qVector2D<s32>  &/*_v2dLocal*/,
                                    const qVector2D<s32>  &/*_v2dGlobal*/)
    {
        return false;
    } // qSysWin<T>::OnMouseRelease


    /*******************************************************************************
    * qSysWin<T>::OnRegisterCtrl
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnRegisterCtrl()
    {
    } // qSysWin<T>::OnRegisterCtrl


    /*******************************************************************************
    * qSysWin<T>::OnUpdateCtrl
    *******************************************************************************/
    template <class T>
    void qSysWin<T>::OnUpdateCtrl(qCtrlI */*_pCtrl*/)
    {
    } // qSysWin<T>::OnUpdateCtrl

} // namespace qLib

#endif // _USE_QT_
