/*******************************************************************************
* \file qAppBase.h
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
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * class qAppBase
    *******************************************************************************/
    class qAppBase
	{
        private:
            static qAppBase    *g_pApp;

            //qVersion        m_version { 0, 0, 0, 0 };

            qString16       m_sProgramPath;
            qString16		m_sProgramName;         // e.g. "test"
            qString16		m_sProgramFullName;     // e.g. "test.jpg"
            // aArgument	m_argument;

		protected:
            qAppBase(/*const qVersion	&_version*/);

		public:
            static qAppBase*        Instance()                  { return g_pApp;}
            //const qVersion&         Version() const             { return m_version; }

            const qString16&        GetProgramPath() const		{ return m_sProgramPath; }
            //const qString16&        GetProgramName() const		{ return m_sProgramName; }
            //const qString16&        GetProgramFullName() const	{ return m_sProgramFullName; }

        public:
            int 					DoCreateFromMain(int	_argc,
                                                     char	*_argv[],
                                                     char   **_envp);

            void					ParseArgs(int	_argc,
                                              char  *_argv[],
                                              char  **_envp);

        /*******************************************************************************
        * interface of qAppBase
        *******************************************************************************/
        protected:
            virtual int 			OnAppCreate(int		_argc,
												char	*_argv[],
												char	**_envp) = 0;

//            virtual void			ShowVersionInfo();
//            virtual void			ShowProgramHelp();



        /*******************************************************************************
        * disable defaults
        *******************************************************************************/
        private:
            qAppBase(const qAppBase& _rhs) = delete;
            qAppBase(qAppBase&& _rhs) = delete;
            qAppBase& operator=(const qAppBase& _rhs) = delete;
            qAppBase& operator=(qAppBase&& _rhs) = delete;
    }; // class qAppBase

} // namespace qLib
