/*******************************************************************************
* \file aMainWinAppQt.cpp
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

#include "aApp/aMainWinApp_qt.h"
#include "aWin/Framework/aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {
namespace SysQt {


/*******************************************************************************
* statics
*******************************************************************************/
aMainWin *aMainWinAppQt::m_pMainWin { nullptr };


/*******************************************************************************
* aMainWinAppQt::aMainWinAppQt
*******************************************************************************/
aMainWinAppQt::aMainWinAppQt(const aVersionInfo &_version)
: aBaseApp(_version)
{
} // aMainWinAppQt::aMainWinAppQt


/*******************************************************************************
* aMainWinAppQt::~aMainWinAppQt
*******************************************************************************/
aMainWinAppQt::~aMainWinAppQt()
{
} // aMainWinAppQt::~aMainWinAppQt


/*******************************************************************************
* aMainWinAppQt::mainWin
*******************************************************************************/
aMainWin*aMainWinAppQt::mainWin()
{
    return m_pMainWin;
} // aMainWinAppQt::mainWin


/*******************************************************************************
* aMainWinAppQt::onAppCreate
*******************************************************************************/
int aMainWinAppQt::onAppCreate(int       _argc,
                              char     *_argv[],
                              char 	** /*_envp*/)
{
    // //QCoreApplication::addLibraryPath(".");

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
        return app.exec();
    }

} // aMainWinAppQt::onAppCreate


} // namespace qQt
} // namespace aApp
} // namespace aLib

#endif // _USE_QT_
