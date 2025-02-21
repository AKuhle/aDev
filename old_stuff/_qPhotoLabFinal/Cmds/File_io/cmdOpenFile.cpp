/*******************************************************************************
* \file cmdOpenFile.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qPhotoLabDefs.h"
#include "cmdOpenFile.h"

using namespace std;
using namespace qLib;


/*******************************************************************************
* CmdOpenFile::CmdOpenFile
*******************************************************************************/
CmdOpenFile::CmdOpenFile(qString16  _sFileName,
                         qProgress  *_pProgress)
: CmdPL(ID_FILE_OPEN, "Open File", enumCmdType::CMD_TYPE_NO_UNDO, nullptr, _pProgress),
  m_sFileName(_sFileName)
{
    cout << __PRETTY_FUNCTION__ << endl;
    // no pre cmd for load-cmd. It's the beginning of a cmd chain
} // CmdOpenFile::CmdOpenFile


/*******************************************************************************
* CmdOpenFile::~CmdOpenFile
*******************************************************************************/
CmdOpenFile::~CmdOpenFile()
{
    cout << __PRETTY_FUNCTION__ << endl;
} // CmdOpenFile::~CmdOpenFile


/*******************************************************************************
* CmdOpenFile::Prepare
*******************************************************************************/
bool CmdOpenFile::Prepare()
{
    // nothing to prepare.
    // since the base class generates a copy of the PreLS, this method
    // is beeing overwritten to do nothing

    return true;
} // CmdOpenFile::Prepare


/*******************************************************************************
* CmdOpenFile::Do
*******************************************************************************/
bool CmdOpenFile::Do()
{
    cout << __PRETTY_FUNCTION__ << endl;

    m_pPostLS = make_shared<qLayerStack> ();

    bool bSuccess = m_pPostLS->LoadFromFile(m_sFileName);

    if (!bSuccess)
    {
        m_pPostLS = nullptr;
    }

    return bSuccess;
} // CmdOpenFile::Do
