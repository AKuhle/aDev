/*******************************************************************************
* \file qAppBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#include "qAppBase.h"
#include "qFile.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * global variables
    *******************************************************************************/
    qAppBase	*qAppBase::g_pApp	{ nullptr };


    /*******************************************************************************
    * qAppBase::qAppBase
    *******************************************************************************/
    qAppBase::qAppBase(/*const qVersion	&_version*/)
    //: m_version(_version)
	{
        g_pApp = this;

        //qRegisterMetaType<u16> ("u16");
    } // qAppBase::qAppBase


    /*******************************************************************************
    * qAppBase::DoCreateFromMain
    *******************************************************************************/
    int qAppBase::DoCreateFromMain(int	_argc,
                                   char *_argv[],
                                   char **_envp)
	{
        ParseArgs(_argc, _argv, _envp);

        return OnAppCreate(_argc, _argv, _envp); // ==0 => succes, !=0 => error
    } // qAppBase::DoCreateFromMain


    /*******************************************************************************
    * qAppBase::ParseArgs
    *******************************************************************************/
    void qAppBase::ParseArgs(int	/*_argc*/,
                             char   *_argv[],
                             char	** /*_envp*/)
    {
//        int			i;
        qString16       sArgv0(_argv[0]), sPath, sName, sExt, sFullName;

        // save the program name
       qFile::SplitPath(sArgv0, sPath, sName, sExt, sFullName);
       m_sProgramPath      = sPath;
       m_sProgramName      = sName;
       m_sProgramFullName  = sFullName;

//        // iterate over all arguments
//        for (i = 1; i < _argc; i++)
//        {
//            aString		sArg(_argv[i]);

//            // print version
//            if (sArg == ARG_VERSION)
//            {
//                ShowVersionInfo();
//                exit(0);
//            }

//            // check data type
//            else if (sArg == ARG_CHECK_DATA_TYPE)
//            {
//                cout << endl;
//                cout << "sizeof(s8) should be 1 byte - " << ((sizeof(s8) == 1) ? "ok" : "error") << " (" << sizeof(s8) << " byte)" << endl;
//                cout << "sizeof(s16) should be 2 byte - " << ((sizeof(s16) == 2) ? "ok" : "error") << " (" << sizeof(s16) << " byte)" << endl;
//                cout << "sizeof(s32) should be 4 byte - " << ((sizeof(s32) == 4) ? "ok" : "error") << " (" << sizeof(s32) << " byte)" << endl;
//                cout << "sizeof(s64) should be 8 byte - " << ((sizeof(s64) == 8) ? "ok" : "error") << " (" << sizeof(s64) << " byte)" << endl << endl;

//                cout << "sizeof(u8) should be 1 byte - " << ((sizeof(u8) == 1) ? "ok" : "error") << " (" << sizeof(u8) << " byte)" << endl;
//                cout << "sizeof(u16) should be 2 byte - " << ((sizeof(u16) == 2) ? "ok" : "error") << " (" << sizeof(u16) << " byte)" << endl;
//                cout << "sizeof(u32) should be 4 byte - " << ((sizeof(u32) == 4) ? "ok" : "error") << " (" << sizeof(u32) << " byte)" << endl;
//                cout << "sizeof(u64) should be 8 byte - " << ((sizeof(u64) == 8) ? "ok" : "error") << " (" << sizeof(u64) << " byte)" << endl << endl;

//                cout << "sizeof(flt) should be >= 4 byte - " << ((sizeof(flt) >= 4) ? "ok" : "error") << " (" << sizeof(flt) << " byte)" << endl;
//                cout << "sizeof(dbl) should be >= 8 byte - " << ((sizeof(dbl) >= 8) ? "ok" : "error") << " (" << sizeof(dbl) << " byte)" << endl;
//                cout << "sizeof(ldbl) should be >= 12 byte - " << ((sizeof(ldbl)>=12)? "ok" : "error") << " (" << sizeof(ldbl) << " byte)" << endl << endl;

//                cout << "sizeof(c8) should be = 1 byte - " << ((sizeof(c8) == 1) ? "ok" : "error") << " (" << sizeof(c8) << " byte)" << endl;
//                cout << "sizeof(c16) should be >= 2 byte - " << ((sizeof(c16) == 2) ? "ok" : "error") << " (" << sizeof(c16) << " byte)" << endl;
//                cout << "sizeof(c32) should be >= 4 byte - " << ((sizeof(c32) == 4)? "ok" : "error") << " (" << sizeof(c32) << " byte)" << endl;
//                cout << endl;

//                exit(0);
//            }

//            // print usage
//            else if (sArg == ARG_HELP)
//            {
//                ShowProgramHelp();
//                exit(0);
//            }

//            // add to parameter class
//            else
//            {
//                m_argument.ParseAndAddArgument(sArg);
//            }
//        } // for (i=1; i<argc; i++)

//        // set the verbose level, after all args are passed
//        //m_argument.GetValue(ARG_VERBOSE, m_s16VerboseLevel);
    } // qAppBase::ParseArgs


    /*******************************************************************************
    * qAppBase::ShowVersionInfo
    *******************************************************************************/
//    void qAppBase::ShowVersionInfo()
//    {
//        cout << endl;
//        cout << GetProgramName().To_StdString() << " ---> " << m_version.GetVersionString().To_StdString() << endl;
//        cout << endl;
//    } // qAppBase::ShowVersionInfo


    /*******************************************************************************
    * qAppBase::ShowProgramHelp
    *******************************************************************************/
//    void qAppBase::ShowProgramHelp()
//    {
//        aArgument::ArgReport(ARG_HELP, "show help info");
//        aArgument::ArgReport(ARG_CHECK_DATA_TYPE, "check the data types");
//        aArgument::ArgReport(ARG_VERSION, "print version info");
//        //aArgument::ArgReport(ARG_VERBOSE, "=1 => verbose output");

//        cout << endl;

//        aArgument::ArgReport("Example:", "qAppBase.exe 17 1.9 arg44 --verbose=1 --list=1,2,3");
//    } // qAppBase::ShowProgramHelp

} // namespace qLib
