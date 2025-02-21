/*******************************************************************************
* \file qPhotoLab.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLib.h"

#include "qPhotoLab.h"
#include "mainWin.h"



/*******************************************************************************
* the one and only instance of the the application
*******************************************************************************/
qPhotoLab	AppInstance;


/*******************************************************************************
* qPhotoLab::qPhotoLab
*******************************************************************************/
qPhotoLab::qPhotoLab()
: qAppMainWin(qVersionInfo(0, 1, 0, 0))
{
    unique_ptr<qWinStyleFactoryDark>   pFactory = std::make_unique<qWinStyleFactoryDark> ();

    qWin::setWinStyleFactory(std::move(pFactory));
} // qPhotoLab::qPhotoLab


/*******************************************************************************
* qPhotoLab::~qPhotoLab
*******************************************************************************/
qPhotoLab::~qPhotoLab()
{
} // qPhotoLab::~qPhotoLab


/*******************************************************************************
* qPhotoLab::onCreateMainWin
*******************************************************************************/
void qPhotoLab::onCreateMainWin(qMainWin *&_pMainWin)
{
    _pMainWin = new MainWin;

    if (!_pMainWin->createWin())
    {
        _pMainWin = nullptr;
    }
} // qPhotoLab::onCreateMainWin
