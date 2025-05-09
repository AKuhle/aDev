/*******************************************************************************
* \file aAppMainWin.h
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

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin_def.h"

#include "aAppBase.h"

using namespace aLib::aWin;


/*******************************************************************************
* globals
*******************************************************************************/
namespace aLib {
namespace aApp {


} // namespace aApp
} // namespace aLib


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aApp {


/*******************************************************************************
* global fungtions
*******************************************************************************/
aMainWin*    get_aMainWin();


/*******************************************************************************
* \class aAppMainWin
*******************************************************************************/
class aAppMainWin : public aAppBase
{
    private:
        static aMainWin  *m_pMainWin;

    protected:
        aAppMainWin(const aVersionInfo &_version);
        virtual ~aAppMainWin();

    public:
        static aMainWin*     mainWin();

    private:
        aAppMainWin(const aAppMainWin	&_rhs) = delete;
        aAppMainWin(aAppMainWin	&&_rhs) = delete;
        aAppMainWin& operator=(const aAppMainWin	&_rhs) = delete;
        aAppMainWin& operator=(aAppMainWin	&&_rhs) = delete;


    /*******************************************************************************
    * qAppBase interface
    *******************************************************************************/
    protected:
        virtual void        onCreateMainWin(aMainWin *&_pMainWin) = 0;

        virtual int         onAppCreate(int		_argc,
                                        char	*_argv[],
                                        char 	**_envp) override;

}; // class aAppMainWin

} // namespace aApp
} // namespace aLib

#endif // _USE_QT_
