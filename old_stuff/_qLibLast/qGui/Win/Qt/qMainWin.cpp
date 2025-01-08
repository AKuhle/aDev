/*******************************************************************************
* \file qMainWin.cpp
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
#include "qGuiDefs.h"
#include "qMainWin.h"
#include "qDockWin.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qMainWin::qMainWin
    *******************************************************************************/
    qMainWin::qMainWin(SysWin_t  *_pParent  /* = nullptr */)
    : qSysWin<QMainWindow>(_pParent)
    {
    } // qMainWin::qMainWin


    /*******************************************************************************
    * qMainWin::~qMainWin
    *******************************************************************************/
    qMainWin::~qMainWin()
    {
    } // qMainWin::~qMainWin


    /*******************************************************************************
    * qMainWin::SaveWinGeometry
    *******************************************************************************/
    void qMainWin::SaveWinGeometry(const qString16    &_sCompany,
                                   const qString16    &_sApplication)
    {
        QSettings settings(_sCompany.ToQString(), _sApplication.ToQString());
        settings.setValue("geometry", saveGeometry());
        settings.setValue("state", saveState());
    } // qMainWin::SaveWinGeometry


    /*******************************************************************************
    * qMainWin::RestoreWinGeometry
    *******************************************************************************/
    void qMainWin::RestoreWinGeometry(const qString16    &_sCompany,
                                      const qString16    &_sApplication)
    {
        QSettings settings(_sCompany.ToQString(), _sApplication.ToQString());
        restoreGeometry(settings.value("geometry").toByteArray());
        restoreState(settings.value("state").toByteArray());
    } // qMainWin::RestoreWinGeometry


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64 _u64Cmd)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 qDocI   *_pDoc)
    {
        OnUpdateCmd(_u64Cmd, _pDoc, nullptr, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 qViewI  *_pView)
    {
        OnUpdateCmd(_u64Cmd, nullptr, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 qDocI   *_pDoc,
                                 qViewI  *_pView)
    {
        OnUpdateCmd(_u64Cmd, _pDoc, _pView, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                    s64     _s64Param1)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                    s64     _s64Param1,
                                    s64     _s64Param2)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, _s64Param1, _s64Param2, 0, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 u64     _u64Param1)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, 0, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SendUpdateCmd
    *******************************************************************************/
    void qMainWin::SendUpdateCmd(u64     _u64Cmd,
                                 u64     _u64Param1,
                                 u64     _u64Param2)
    {
        OnUpdateCmd(_u64Cmd, nullptr, nullptr, 0, 0, _u64Param1, _u64Param2, 0.0, 0.0, 0.0, 0.0, nullptr, nullptr);
    } // qMainWin::SendUpdateCmd


    /*******************************************************************************
    * qMainWin::SetCentralWin
    *******************************************************************************/
    void qMainWin::SetCentralWin(SysWin_t *_pWin)
    {
        setCentralWidget(_pWin);
    } // qMainWin::SetCentralWin


    /*******************************************************************************
    * qMainWin::CentralWin
    *******************************************************************************/
    SysWin_t* qMainWin::CentralWin() const
    {
        return centralWidget();
    } // qMainWin::CentralWin


    /*******************************************************************************
    * qMainWin::AddDockWindow
    *******************************************************************************/
    void qMainWin::AddDockWindow(const qString16    &_sTile,
                                 qDockWin           *_pDockWin,
                                 u32                _u32DockArea)
    {
        Qt::DockWidgetArea area = Qt::NoDockWidgetArea;

        if (BitsSet<u16>(_u32DockArea, DOCK_AREA_LEFT))
            area = Qt::LeftDockWidgetArea;
        else if (BitsSet<u16>(_u32DockArea, DOCK_AREA_RIGHT))
            area = Qt::RightDockWidgetArea;
        else if (BitsSet<u16>(_u32DockArea, DOCK_AREA_TOP))
            area = Qt::TopDockWidgetArea;
        else if (BitsSet<u16>(_u32DockArea, DOCK_AREA_BOTTOM))
            area = Qt::BottomDockWidgetArea;

        addDockWidget(area, _pDockWin);

        // set the title and object name
        _pDockWin->setObjectName(_sTile.ToQString());
        _pDockWin->setWindowTitle(_sTile.ToQString());
    } // qMainWin::AddDockWindow

} // namespace qLib

#endif // _USE_QT_
