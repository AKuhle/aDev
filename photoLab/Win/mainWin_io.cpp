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


/*******************************************************************************
* includes
*******************************************************************************/
#include "photoLab_defs.h"

#include "aString.h"
#include "mainWin.h"
#include "aMdiChild.h"
#include "editScrollWin.h"
#include "editView.h"

#include "cmdOpenFile.h"

using namespace aLib::aWin;
using namespace std;


/*******************************************************************************
* MainWin::openFile
*******************************************************************************/
void MainWin::openFile()
{
    // qString16           sTitle { "Open Images" };
    // static qString16    sPath;      // static => same start path for next call
    // qString16           sFilter;

    // sFilter		=	"JPEG - File (*.jpg)";
    // sFilter		+=	";;Windows oder OS/2 Bitmap (*.bmp)";
    // sFilter		+=	";;tagged Image File Format (*.tif)";
    // sFilter		+=	";;All Files (*.*)";

    // qVec<qString16> vecFileName = qSysDlg::GetFileOpenNames(sTitle, sPath, sFilter);

    // for (const qString16& sFileName : vecFileName)
    // {
    //     OpenFile(sFileName);
    // }

} // MainWin::openFile


/*******************************************************************************
* MainWin::openFile
*******************************************************************************/
void MainWin::openFile(const aPath &_path)
{
    //shared_ptr<CmdOpenFile> pCmd = make_shared<CmdOpenFile> (path, statusBar());
    shared_ptr<CmdOpenFile> pCmd = make_shared<CmdOpenFile> (_path, nullptr);

    executeCmd(pCmd);
} // MainWin::openFile
