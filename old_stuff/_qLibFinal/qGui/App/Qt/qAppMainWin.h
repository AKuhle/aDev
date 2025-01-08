/*******************************************************************************
* \file qAppMainWin.h
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
#include <QApplication>

#include "qAppBase.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qMainWin;


    /*******************************************************************************
    * globals
    *******************************************************************************/
    qMainWin& Get_qMainWin();


    /*******************************************************************************
    * \class qAppMainWin
    *******************************************************************************/
    class qAppMainWin : public qAppBase
	{
        private:
            qMainWin        *m_pMainWin { nullptr };

        protected:
            qAppMainWin(/*const qVersion	&_version*/);
            virtual ~qAppMainWin();

        public:
            qMainWin*           GetMainWin() const;

        private:
            qAppMainWin(const qAppMainWin	&_rhs) = delete;
            qAppMainWin(qAppMainWin	&&_rhs) = delete;
            qAppMainWin& operator=(const qAppMainWin	&_rhs) = delete;
            qAppMainWin& operator=(qAppMainWin	&&_rhs) = delete;


        protected:
            virtual void   OnCreateMainWin(qMainWin *&_pMainWin) = 0;


        /*******************************************************************************
        * qAppBase interface
        *******************************************************************************/
        protected:
            virtual int         OnAppCreate(int		_argc,
                                            char	*_argv[],
                                            char 	**_envp) override;

    }; // class qAppMainWin

} // namespace qLib

#endif // _USE_QT_
