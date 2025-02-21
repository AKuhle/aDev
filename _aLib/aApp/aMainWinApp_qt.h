/*******************************************************************************
* \file aMainWinAppQt.h
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
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aApp/aBaseApp.h"
#include "aApp/aMainWinApp_i.h"


/*******************************************************************************
* globals
*******************************************************************************/
namespace aLib {
namespace aApp {

    aMainWin*    get_aMainWin();

} // namespace aApp
} // namespace aLib


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {
namespace SysQt {


/*******************************************************************************
* \class aMainWinAppQt
*******************************************************************************/
class aMainWinAppQt : public aBaseApp,
                      public aMainWinApp_i
{
    private:
        static aMainWin  *m_pMainWin;

    protected:
        aMainWinAppQt(const aVersionInfo &_version);
        virtual ~aMainWinAppQt();

    public:
        static aMainWin*     mainWin();

    private:
        aMainWinAppQt(const aMainWinAppQt	&_rhs) = delete;
        aMainWinAppQt(aMainWinAppQt	&&_rhs) = delete;
        aMainWinAppQt& operator=(const aMainWinAppQt	&_rhs) = delete;
        aMainWinAppQt& operator=(aMainWinAppQt	&&_rhs) = delete;


    /*******************************************************************************
    * qAppBase interface
    *******************************************************************************/
    protected:
        virtual int         onAppCreate(int		_argc,
                                        char	*_argv[],
                                        char 	**_envp) override;

}; // class aMainWinAppQt


} // namespace SysQt
} // namespace aApp
} // namespace aLib

#endif // _USE_QT_
