/*******************************************************************************
* \file mainWin.cpp
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
#include "mainWin.h"
#include "cmdOpenFile.h"

using namespace qLib;


/*******************************************************************************
* MainWin::OpenFile
*******************************************************************************/
void MainWin::OpenFile()
{
    qString16           sTitle { "Open Images" };
    static qString16    sPath;      // static => same start path for next call
    qString16           sFilter;

    sFilter		=	"JPEG - File (*.jpg)";
    sFilter		+=	";;Windows oder OS/2 Bitmap (*.bmp)";
    sFilter		+=	";;tagged Image File Format (*.tif)";
    sFilter		+=	";;All Files (*.*)";

    qVec<qString16> vecFileName = qSysDlg::GetFileOpenNames(sTitle, sPath, sFilter);

    for (const qString16& sFileName : vecFileName)
    {
        OpenFile(sFileName);
    }

} // MainWin::OpenFile


/*******************************************************************************
* MainWin::OpenFile
*******************************************************************************/
void MainWin::OpenFile(const qString16 &_sFileName)
{
    unique_ptr<CmdOpenFile> pCmd = make_unique<CmdOpenFile> (_sFileName, this);
    ExecuteCmd(std::move(pCmd));
} // MainWin::OpenFile

