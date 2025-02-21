/*******************************************************************************
* \file qAppI.h
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
#include "main.h"
#include "qVersion.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qAppI;


    /*******************************************************************************
    * class qAppI
    *******************************************************************************/
    class qAppI
	{
        private:
        static qAppI    *g_pApp;

            qVersion        m_version { 0, 0, 0, 0 };

            qString16       m_sProgramPath;
            qString16		m_sProgramName;         // e.g. "test"
            qString16		m_sProgramFullName;     // e.g. "test.jpg"
            // aArgument	m_argument;

		protected:
            qAppI(const qVersion	&_version);

		public:
            static qAppI*           Instance()                  { return g_pApp;}
            const qVersion&         Version() const             { return m_version; }

            const qString16&        GetProgramPath() const		{ return m_sProgramPath; }
            const qString16&        GetProgramName() const		{ return m_sProgramName; }
            const qString16&        GetProgramFullName() const	{ return m_sProgramFullName; }

        private:
            int                     test();

        public:
            int 					DoCreateFromMain(int	_argc,
                                                     char	*_argv[],
                                                     char   **_envp);

            void					ParseArgs(int		_argc,
                                              char*		_argv[],
                                              char**    _envp);

        /*******************************************************************************
        * interface of qAppI
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
            qAppI(const qAppI& _rhs) = delete;
            qAppI(qAppI&& _rhs) = delete;
            qAppI& operator=(const qAppI& _rhs) = delete;
            qAppI& operator=(qAppI&& _rhs) = delete;
    }; // class qAppI

} // namespace qLib
