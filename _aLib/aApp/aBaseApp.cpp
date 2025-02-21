/*******************************************************************************
* \file aBaseApp.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#include "aLib_def.h"
#include "aApp_def.h"

#include "aBaseApp.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* statics
*******************************************************************************/
aBaseApp    *aBaseApp::m_pApp   { nullptr };


/*******************************************************************************
* aBaseApp::aBaseApp
*******************************************************************************/
aBaseApp::aBaseApp(const aVersionInfo &_version)
{
    m_pApp = this;

    m_version = _version;
} // aBaseApp::aBaseApp


/*******************************************************************************
* aBaseApp::printProgramHelp
*******************************************************************************/
void aBaseApp::printProgramHelp() const
{
    aArgument::reportArgument(ARG_HELP, "show help info");
    aArgument::reportArgument(ARG_VERSION, "print version info");
} // qAppI::ShowProgramHelp} // aBaseApp::printProgramHelp


/*******************************************************************************
* aBaseApp::createFromMain
*******************************************************************************/
int aBaseApp::createFromMain(int	_argc,
                             char *_argv[],
                             char **_envp)
{
    parseArgs(_argc, _argv, _envp);

    // print usage
    if (m_args.hasKey(ARG_HELP))
    {
        printProgramHelp();
        exit(-1);
    }

    return onAppCreate(_argc, _argv, _envp); // ==0 => succes, !=0 => error
} // aBaseApp::createFromMain


/*******************************************************************************
* aBaseApp::parseArgs
*******************************************************************************/
void aBaseApp::parseArgs(int	_argc,
                         char   *_argv[],
                         char	** /*_envp*/)
{
    aVector<aString>		vecToken;

    // save the program name
    m_sProgramName = _argv[0];

    // iterate over all arguments
    for (s32 i = 1; i < _argc; i++)
    {
        aString		sArg(_argv[i]);

        // print version
        if (sArg == ARG_VERSION)
        {
            cout << m_sProgramName << m_version.versionString() << endl;
            exit(-1);
        }

        // add to parameter class
        // else
        {
            m_args.parseAndAddArgument(sArg);
        }
    } // for (i=1; i<argc; i++)
} // aBaseApp::parseArgs


} // namespace aApp
} // namespace aLib
