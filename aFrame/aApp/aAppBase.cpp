/*******************************************************************************
* \file aAppBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#include "aFrame_def.h"
#include "aApp_def.h"

#include "aAppBase.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aApp {


/*******************************************************************************
* statics
*******************************************************************************/
aAppBase    *aAppBase::m_pApp   { nullptr };
aPath       aAppBase::m_sAppName;
aPath       aAppBase::m_sAppPath;


/*******************************************************************************
* get_aAppBase
*******************************************************************************/
aAppBase* get_aAppBase()
{
    return aAppBase::instance();
} // get_aAppBase


/*******************************************************************************
* get_appName
*******************************************************************************/
aPath get_appName()
{
    return (get_aAppBase() != nullptr)?   get_aAppBase()->appName() : aPath{};
} // get_appName


/*******************************************************************************
* get_appPath
*******************************************************************************/
aPath get_appPath()
{
    return (get_aAppBase() != nullptr)?   get_aAppBase()->appPath() : aPath{};
} // get_appPath


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

                                        // e.g.: "\temp\out\test.txt"
    aString                 sName;      // e.g.: "test"
    aString                 sExt;       // e.g.: ".txt"
    aString                 sFullName;  // e.g.: "test.txt"

    // save the program name
    m_sAppName = _argv[0];
    m_sAppName.splitPath(m_sAppPath, sName, sExt, sFullName);

    // iterate over all arguments
    for (s32 i = 1; i < _argc; i++)
    {
        aString		sArg(_argv[i]);

        // print version
        if (sArg == ARG_VERSION)
        {
            cout << appName().canonicalPath() << m_version.versionString() << endl;
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
} // namespace aFrame
