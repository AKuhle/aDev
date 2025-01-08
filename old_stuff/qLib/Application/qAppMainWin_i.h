/*******************************************************************************
* \file qAppMainWinI.h
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
#include <QApplication>

#include "Win/FrameWin/qMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
using namespace qLib::Win;

namespace qLib {
namespace Application {


/*******************************************************************************
* \class qAppMainWinI
*******************************************************************************/
class qAppMainWinI
{
    public:
        qAppMainWinI() = default;
        virtual ~qAppMainWinI() = default;

    private:
        qAppMainWinI(const qAppMainWinI	&_rhs) = delete;
        qAppMainWinI(qAppMainWinI	&&_rhs) = delete;
        qAppMainWinI& operator=(const qAppMainWinI	&_rhs) = delete;
        qAppMainWinI& operator=(qAppMainWinI &&_rhs) = delete;


    protected:
        virtual void        onCreateMainWin(qMainWin *&_pMainWin) = 0;
}; // class qAppMainWinI


} // namespace Application
} // namespace qLib
