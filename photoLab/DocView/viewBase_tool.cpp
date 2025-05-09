/*******************************************************************************
* \file ViewBase_coordinates.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "viewBase.h"



/*******************************************************************************
* ViewBase::onToolStarted
*******************************************************************************/
void ViewBase::onToolStarted(aToolBase */*_pTool*/)
{

} // ViewBase::onToolStarted


/*******************************************************************************
* ViewBase::onToolSuccess
*******************************************************************************/
void ViewBase::onToolSuccess(aToolBase */*_pTool*/)
{

} // ViewBase::onToolSuccess


/*******************************************************************************
* ViewBase::onToolCanceled
*******************************************************************************/
void ViewBase::onToolCanceled(aToolBase */*_pTool*/)
{

} // ViewBase::onToolCanceled


/*******************************************************************************
* ViewBase::onToolFinished
*******************************************************************************/
void ViewBase::onToolFinished(u32 /*_u32ToolId*/)
{

} // ViewBase::onToolFinished


/*******************************************************************************
* ViewBase::onToolMsg
*******************************************************************************/
void ViewBase::onToolMsg(aToolBase */*_pTool*/,
                         u32       /*_u32Msg*/,
                         s32       /*_s32Param*/,
                         u32       /*_u32Param*/,
                         s64       /*_s64Param*/,
                         u64       /*_u64Param*/,
                         flt       /*_fltParam*/,
                         dbl       /*_dblParam*/)
{

} // ViewBase::onToolMsg


/*******************************************************************************
* ViewBase::wheelEvent
*******************************************************************************/
// void ViewBase::wheelEvent(QWheelEvent *_pEvent)
// {
//     _pEvent->accept();

    // // Leite das WheelEvent an den Viewport weiter
    // if (viewport() != nullptr)
    // {
    //     QCoreApplication::sendEvent(viewport(), _pEvent);

    //     _pEvent->accept();
    // }
    // else
    // {
    //     // Fallback: Standardverhalten
    //     QAbstractScrollArea::wheelEvent(_pEvent);
    // }
// } // ViewBase::wheelEvent
