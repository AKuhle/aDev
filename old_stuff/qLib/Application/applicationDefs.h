/*******************************************************************************
* \file qlBaseDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


namespace qLib {
namespace Application {


/*******************************************************************************
* classes
*******************************************************************************/
namespace SysQt {
    class qAppMainWinQt;
} // namespace SysQt

class qAppBase;
class qAppMainWinI;

#ifdef _USE_QT_
    using qAppMainWin = qLib::Application::SysQt::qAppMainWinQt;
#endif // _USE_QT_


} // namespace Application
} // namespace qLib
