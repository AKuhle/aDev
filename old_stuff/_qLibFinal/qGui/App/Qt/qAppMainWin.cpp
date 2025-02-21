/*******************************************************************************
* \file qAppMainWin.cpp
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
#include "qAppMainWin.h"
#include "qAppMainWin.h"
#include "qMainWin.h"
#include "qWinStyleFactory_dark.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * Get_qMainWin
    *******************************************************************************/
    qMainWin& Get_qMainWin()
    {
        qAppMainWin *pApp = dynamic_cast<qAppMainWin *> (qAppBase::Instance());

        return *pApp->GetMainWin();
    } // Get_qMainWin


    /*******************************************************************************
    * qAppMainWin::qAppMainWin
    *******************************************************************************/
    qAppMainWin::qAppMainWin(/*const qVersion	&_version*/)
    : qAppBase(/*_version*/)
	{
    } // qAppMainWin::qAppMainWin


    /*******************************************************************************
    * qAppMainWin::~qAppMainWin
    *******************************************************************************/
    qAppMainWin::~qAppMainWin()
    {
    } // qAppMainWin::~qAppMainWin


    /*******************************************************************************
    * qAppMainWin::GetMainWin
    *******************************************************************************/
    qMainWin* qAppMainWin::GetMainWin() const
    {
        return m_pMainWin;
    } // qAppMainWin::GetMainWin


    /*******************************************************************************
    * qAppMainWin::OnAppCreate
    *******************************************************************************/
    int qAppMainWin::OnAppCreate(int    _argc,
                                 char	*_argv[],
                                 char 	** /*_envp*/)
    {
        //QCoreApplication::addLibraryPath(".");

        // create the app
        QApplication app(_argc, _argv);

        // create the main window, constructor of qMainWinI sets g_pMainWin!
        OnCreateMainWin(m_pMainWin);

        if (m_pMainWin == nullptr)
        {
            qLog::Error("Error: No main window defined");

            return 1;   // != 0 => error
        }
        else
        {
            m_pMainWin->SetVisible(true);
            return app.exec();
        }
    } // qAppMainWin::OnAppCreate

} // namespace qLib

#endif // _USE_QT_
