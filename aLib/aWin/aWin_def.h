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
namespace aWin {


/*******************************************************************************
* classes
*******************************************************************************/
// layout
class aLayoutObj;
class aLayout;


// FrameWin
#ifdef _USE_QT_
    namespace SysQt
    {
        class aSysWinQt;
    } // namespace SysQt

    using aSysWin = aLib::aWin::SysQt::aSysWinQt;
#endif // _USE_QT_

class aSysWinI;

class aBaseWin;
class aMainWin;
class aMdiMainWin;

class aTitleBar;

} // namespace aWin
} // namespace aLib
