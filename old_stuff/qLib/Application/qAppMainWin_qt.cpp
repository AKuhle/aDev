/*******************************************************************************
* \file qAppMainWinQt.cpp
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

#include "Application/applicationDefs.h"
#include "Win/winDefs.h"

#include "Application/qAppMainWin_qt.h"


/*******************************************************************************
* namespace
*******************************************************************************/
using namespace qLib::Win;

namespace qLib {
namespace Application {
namespace SysQt {


/*******************************************************************************
* statics
*******************************************************************************/
qMainWin *qAppMainWin::m_pMainWin { nullptr };


/*******************************************************************************
* qAppMainWinQt::qAppMainWinQt
*******************************************************************************/
qAppMainWinQt::qAppMainWinQt(const qVersionInfo	&_version)
: qAppBase(_version)
{
} // qAppMainWinQt::qAppMainWinQt


/*******************************************************************************
* qAppMainWinQt::~qAppMainWinQt
*******************************************************************************/
qAppMainWinQt::~qAppMainWinQt()
{
} // qAppMainWinQt::~qAppMainWinQt


/*******************************************************************************
* qAppMainWinQt::onAppCreate
*******************************************************************************/
int qAppMainWinQt::onAppCreate(int    _argc,
                               char	*_argv[],
                               char 	** /*_envp*/)
{
    //QCoreApplication::addLibraryPath(".");

    // create the app
    QApplication app(_argc, _argv);

    // create the main window, constructor of qMainWinI sets g_pMainWin!
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
} // qAppMainWinQt::onAppCreate


} // namespace qQt
} // namespace qApplication
} // namespace qLib

#endif // _USE_QT_
