/*******************************************************************************
* \file aAppBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#include "aLib_def.h"
#include "aApp_def.h"

#include "aAppBase.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* statics
*******************************************************************************/
aAppBase    *aAppBase::m_pApp   { nullptr };


/*******************************************************************************
* aAppBase::aAppBase
*******************************************************************************/
aAppBase::aAppBase(const aVersionInfo &_version)
{
    m_pApp = this;

    m_version = _version;
} // aAppBase::aAppBase


/*******************************************************************************
* aAppBase::printProgramHelp
*******************************************************************************/
void aAppBase::printProgramHelp() const
{
    aArgument::reportArgument(ARG_HELP, "show help info");
    aArgument::reportArgument(ARG_VERSION, "print version info");
} // qAppI::ShowProgramHelp} // aAppBase::printProgramHelp


/*******************************************************************************
* aAppBase::createFromMain
*******************************************************************************/
int aAppBase::createFromMain(int	_argc,
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
} // aAppBase::createFromMain


/*******************************************************************************
* aAppBase::parseArgs
*******************************************************************************/
void aAppBase::parseArgs(int	_argc,
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
} // aAppBase::parseArgs


} // namespace aApp
} // namespace aLib
