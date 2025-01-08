/*******************************************************************************
* \file qlBaseDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* classes
*******************************************************************************/
// FrameWin
#ifdef _USE_QT_
    namespace SysQt
    {
        class aPenQt;
        class aPainterQt;

    } // namespace SysQt

    using aPen = aLib::aGraphic::SysQt::aPenQt;
    using aPainter = aLib::aGraphic::SysQt::aPainterQt;
#endif // _USE_QT_


} // namespace aGraphic
} // namespace aLib
