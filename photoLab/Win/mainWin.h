/*******************************************************************************
* \file BaseApp.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aMainWinMdi.h"
#include "aCmdMgr.h"

#ifdef _USE_QT_
    #include "ui_formMainWin.h"
#endif

using namespace aLib;
using namespace aLib::aWin;
using namespace aLib::aUtil;

class MainWin;


/*******************************************************************************
* globals
*******************************************************************************/
MainWin&    getMainWin();


/*******************************************************************************
* class MainWin
*******************************************************************************/
class MainWin : public aMainWinMdi,
                public aCmdMgr
{
    private:
        #ifdef _USE_QT_
            Ui::FormMainWin     *m_pUi              { nullptr };
        #endif

    public:
        MainWin();
        ~MainWin();


    /*******************************************************************************
    * aCmdMgr interface
    *******************************************************************************/
    protected:
        virtual void        onCmdProcessingStart(const shared_ptr<aCmdBase> &_pCmd);
        virtual void        onCmdProcessingEnd(const shared_ptr<aCmdBase> &_pCmd);

        void                onDoDone(const shared_ptr<aCmdBase> &_pCmd) override;


    /*******************************************************************************
    * aSysWin interface
    *******************************************************************************/
    protected:
        virtual bool        onCreate() override;
        virtual void        onDropUrl(const aUrl  &_url) override;


    /*******************************************************************************
    * aMainWin_i interface
    *******************************************************************************/
    protected:
        virtual void        onUpdateCmd(u64     _u64Cmd,
                                        aDoc    *_pDoc,
                                        aView   *_pView,
                                        s64     _s64Param1,
                                        s64     _s64Param2,
                                        u64     _u64Param1,
                                        u64     _u64Param2,
                                        flt     _fltParam1,
                                        flt     _fltParam2,
                                        dbl     _dblParam1,
                                        dbl     _dblParam2,
                                        void    *_pParam1,
                                        void    *_pParam2) override;

}; // class MainWin
