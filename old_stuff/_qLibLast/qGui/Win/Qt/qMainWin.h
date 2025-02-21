/*******************************************************************************
* \file qMainWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qSysWin.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qDocI;
    class qViewI;
    class qDockWin;


    /*******************************************************************************
    * class qMainWin
    *******************************************************************************/
    class qMainWin : public qSysWin<QMainWindow>
    {
        protected:
            qMainWin(SysWin_t  *_pParent = nullptr);
            ~qMainWin();

            void                SaveWinGeometry(const qString16    &_sCompany,
                                                const qString16    &_sApplication);

            void                RestoreWinGeometry(const qString16    &_sCompany,
                                                   const qString16    &_sApplication);

            virtual void        OnUpdateCmd(u64        _u64Cmd,
                                            qDocI      *_pDoc,
                                            qViewI     *_pView,
                                            s64        _s64Param1,
                                            s64        _s64Param2,
                                            u64        _u64Param1,
                                            u64        _u64Param2,
                                            flt        _fltParam1,
                                            flt        _fltParam2,
                                            dbl        _dblParam1,
                                            dbl        _dblParam2,
                                            void       *_pParam1,
                                            void       *_pParam2) = 0;

        public:
            void                SendUpdateCmd(u64 _u64Cmd);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qDocI     *_pDoc);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qViewI    *_pView);

            void                SendUpdateCmd(u64       _u64Cmd,
                                              qDocI     *_pDoc,
                                              qViewI    *_pView);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              s64   _s64Param1);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              s64   _s64Param1,
                                              s64   _s64Param2);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              u64   _u64Param1);

            void                SendUpdateCmd(u64   _u64Cmd,
                                              u64   _u64Param1,
                                              u64   _u64Param2);

        protected:
            void                SetCentralWin(SysWin_t   *_pWin);
            SysWin_t*           CentralWin() const;

            void                AddDockWindow(const qString16   &_sTile,
                                              qDockWin          *_pDockWin,
                                              u32               _u32DockArea);


    }; // class qMainWin

} // namespace aLib

#endif // _USE_QT_
