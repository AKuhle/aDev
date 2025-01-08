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
namespace aApp {

#define         ARG_VERSION         "--version"
#define         ARG_HELP            "--help"


/*******************************************************************************
* classes
*******************************************************************************/
#ifdef _USE_QT_
    namespace SysQt
    {
        class aMainWinAppQt;
    } // namespace SysQt

    using aMainWinApp = aLib::aApp::SysQt::aMainWinAppQt;
#endif // _USE_QT_

class BaseApp;
class MainWinApp_i;


} // namespace aApp
} // namespace aLib
