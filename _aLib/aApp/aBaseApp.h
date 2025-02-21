/*******************************************************************************
* \file aBaseApp.h
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
#include "aUtil/aVersionInfo.h"
#include "aUtil/aArgument.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* class aBaseApp
*******************************************************************************/
class aBaseApp
{
    private:
        static aBaseApp     *m_pApp;
        aVersionInfo        m_version       { 0, 0, 0, 0 };

        aString             m_sProgramName;
        aArgument           m_args;

    private:
        aBaseApp(const aBaseApp& _rhs) = delete;
        aBaseApp(aBaseApp&& _rhs) = delete;
        aBaseApp& operator=(const aBaseApp& _rhs) = delete;
        aBaseApp& operator=(aBaseApp&& _rhs) = delete;

    protected:
        aBaseApp(const aVersionInfo &_version);

        virtual void                printProgramHelp() const;


    public:
        static aBaseApp*            instance()                  { return m_pApp;}

        int                         createFromMain(int	_argc,
                                               char	*_argv[],
                                               char   **_envp);

        const aVersionInfo&         version() const             { return m_version; }

    private:
        void                        parseArgs(int	_argc,
                                              char  *_argv[],
                                              char  **_envp);


    /*******************************************************************************
    * interface of aBaseApp
    *******************************************************************************/
    protected:
        virtual int                 onAppCreate(int		_argc,
                                                char	*_argv[],
                                                char	**_envp) = 0;

}; // class aBaseApp


} // namespace aApp
} // namespace aLib
