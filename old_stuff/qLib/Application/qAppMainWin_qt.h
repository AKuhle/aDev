/*******************************************************************************
* \file qAppMainWinQt.h
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
#include "Application/qAppBase.h"
#include "Application/qAppMainWin_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
using namespace qLib::Win;

namespace qLib {
namespace Application {
namespace SysQt {


/*******************************************************************************
* \class qAppMainWinQt
*******************************************************************************/
class qAppMainWinQt : public qAppBase,
                      public qAppMainWinI
{
    private:
        static qMainWin *m_pMainWin;

    protected:
        qAppMainWinQt(const qVersionInfo	&_version);
        virtual ~qAppMainWinQt();

    public:
        static qMainWin*    mainWin()       { return m_pMainWin; }

    private:
        qAppMainWinQt(const qAppMainWinQt	&_rhs) = delete;
        qAppMainWinQt(qAppMainWinQt	&&_rhs) = delete;
        qAppMainWinQt& operator=(const qAppMainWinQt	&_rhs) = delete;
        qAppMainWinQt& operator=(qAppMainWinQt	&&_rhs) = delete;


    /*******************************************************************************
    * qAppBase interface
    *******************************************************************************/
    protected:
        virtual int         onAppCreate(int		_argc,
                                        char	*_argv[],
                                        char 	**_envp) override;

}; // class qAppMainWinQt


} // namespace SysQt
} // namespace Application
} // namespace qLib

#endif // _USE_QT_
