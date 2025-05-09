/*******************************************************************************
* \file aAppBase.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aVersionInfo.h"
#include "aArgument.h"
#include "aPath.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* forward
*******************************************************************************/
class aAppBase;


/*******************************************************************************
* global fungtions
*******************************************************************************/
aAppBase*   get_aAppBase();
aPath       get_appName();
aPath       get_appPath();


/*******************************************************************************
* class aAppBase
*******************************************************************************/
class aAppBase
{
    private:
        static aAppBase     *m_pApp;
        aVersionInfo        m_version       { 0, 0, 0, 0 };

        static aPath        m_sAppName;     // full app path and name
        static aPath        m_sAppPath;     // path to application
        aArgument           m_args;

    private:
        aAppBase(const aAppBase& _rhs) = delete;
        aAppBase(aAppBase&& _rhs) = delete;
        aAppBase& operator=(const aAppBase& _rhs) = delete;
        aAppBase& operator=(aAppBase&& _rhs) = delete;

    protected:
        aAppBase(const aVersionInfo &_version);

        virtual void                printProgramHelp() const;


    public:
        static aAppBase*            instance()                  { return m_pApp;}

        static const aPath&         appName()                   { return m_sAppName; }
        static const aPath&         appPath()                   { return m_sAppPath; }

        int                         createFromMain(int	_argc,
                                               char	*_argv[],
                                               char   **_envp);

        const aVersionInfo&         version() const             { return m_version; }

    private:
        void                        parseArgs(int	_argc,
                                              char  *_argv[],
                                              char  **_envp);


    /*******************************************************************************
    * interface of aAppBase
    *******************************************************************************/
    protected:
        virtual int                 onAppCreate(int		_argc,
                                                char	*_argv[],
                                                char	**_envp) = 0;

}; // class aAppBase


} // namespace aApp
} // namespace aLib
