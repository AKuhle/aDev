/*******************************************************************************
* \file aAppMainWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QApplication>

#include "aAppMainWin.h"
#include "aMainWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aApp {


/*******************************************************************************
* get_aMainWin
*******************************************************************************/
aMainWin* get_aMainWin()
{
    return aAppMainWin::mainWin();
} // get_aMainWin


/*******************************************************************************
* statics
*******************************************************************************/
aMainWin *aAppMainWin::m_pMainWin { nullptr };


/*******************************************************************************
* aAppMainWin::aAppMainWin
*******************************************************************************/
aAppMainWin::aAppMainWin(const aVersionInfo &_version)
: aAppBase(_version)
{
} // aAppMainWin::aAppMainWin


/*******************************************************************************
* aAppMainWin::~aAppMainWin
*******************************************************************************/
aAppMainWin::~aAppMainWin()
{
} // aAppMainWin::~aAppMainWin


/*******************************************************************************
* aAppMainWin::mainWin
*******************************************************************************/
aMainWin*aAppMainWin::mainWin()
{
    return m_pMainWin;
} // aAppMainWin::mainWin


/*******************************************************************************
* aAppMainWin::onAppCreate
*******************************************************************************/
int aAppMainWin::onAppCreate(int       _argc,
                             char     *_argv[],
                             char 	** /*_envp*/)
{
    // QCoreApplication::addLibraryPath(".");

    // create the app
    QApplication app(_argc, _argv);

    // // create the main window, constructor of qMainWinI sets g_pMainWin!
    onCreateMainWin(m_pMainWin);

    if (m_pMainWin == nullptr)
    {
        //qLog::Error("Error: No main window defined");
        //std::cout << ("Error: No main window defined") << std::endl;

        return 1;   // != 0 => error
    }
    else
    {
        m_pMainWin->show();

        // aCtrlMgr initialization
        // aCtrlMgr *pCtrlMgr = dynamic_cast<aCtrlMgr *> (m_pMainWin);
        // if (pCtrlMgr != nullptr)
        // {
        //     pCtrlMgr->updateAllCtrls();
        // }

        return app.exec();
    }

} // aAppMainWin::onAppCreate


} // namespace aApp
} // namespace aFrame

#endif // _USE_QT_
