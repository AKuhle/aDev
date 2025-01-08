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

#include "qApp_i.h"
#include "qList.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qAppMainWin;
    class qMainWin;


    /*******************************************************************************
    * globals
    *******************************************************************************/
    qAppMainWin*    Get_qAppMainWin();
    qMainWin*       Get_qMainWin();


    /*******************************************************************************
    * \class qAppMainWin
    *******************************************************************************/
    class qAppMainWin : public qAppI
	{
        private:
            //QApplication        *m_pQApp                { nullptr };
            static qMainWin     *m_pMainWin;

        public:
            qMainWin*           GetqMainWin() const;

        protected:
            qAppMainWin(const qVersion	&_version);
            virtual ~qAppMainWin();

        private:
            qAppMainWin(const qAppMainWin	&_rhs) = delete;
            qAppMainWin(qAppMainWin	&&_rhs) = delete;
            qAppMainWin&        operator=(const qAppMainWin	&_rhs) = delete;
            qAppMainWin&        operator=(qAppMainWin	&&_rhs) = delete;


        protected:
            virtual void        OnCreateMainWin(qMainWin *& _pMainWin) = 0;


        /*******************************************************************************
        * qlApp interface
        *******************************************************************************/
        protected:
            virtual int         OnAppCreate(int		_argc,
                                            char	*_argv[],
                                            char 	**_envp);

    }; // class qAppMainWin

} // namespace qLib

#endif // _USE_QT_
