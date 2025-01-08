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
#include "qLog.h"
#include "qString.h"
#include "qMainWin.h"

using namespace std;


namespace qLib
{
    qMainWin     *qAppMainWin::m_pMainWin   { nullptr };


    /*******************************************************************************
    * Get_qAppMainWin
    *******************************************************************************/
    qAppMainWin* Get_qAppMainWin()
    {
        return dynamic_cast<qAppMainWin *> (qAppI::Instance());
    } // Get_qAppMainWin


    /*******************************************************************************
    * Get_qMainWin
    *******************************************************************************/
    qMainWin* Get_qMainWin()
    {
        qAppMainWin *pApp = Get_qAppMainWin();

        return (pApp != nullptr)?   pApp->GetqMainWin() : nullptr;
    } // Get_qMainWin


    /*******************************************************************************
    * qAppMainWin::qAppMainWin
    *******************************************************************************/
    qAppMainWin::qAppMainWin(const qVersion	&_version)
    : qAppI(_version)
	{
    } // qAppMainWin::qAppMainWin


    /*******************************************************************************
    * qAppMainWin::~qAppMainWin
    *******************************************************************************/
    qAppMainWin::~qAppMainWin()
    {
    } // qAppMainWin::~qAppMainWin


    /*******************************************************************************
    * qAppMainWin::GetqMainWin
    *******************************************************************************/
    qMainWin* qAppMainWin::GetqMainWin() const
    {
        return m_pMainWin;
    } // qAppMainWin::GetqMainWin


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
            cerr << "Error: No main window defined" << endl;

            return 1;   // != 0 => error
        }
        else
        {
            m_pMainWin->show();
            return app.exec();
        }
    } // qAppMainWin::OnAppCreate

} // namespace qLib

#endif // _USE_QT_
