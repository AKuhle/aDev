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
#include "photoLab_defs.h"

#include "cmdOpenFile.h"


/*******************************************************************************
* CmdOpenFile::CmdOpenFile
*******************************************************************************/
CmdOpenFile::CmdOpenFile(aPath          _pathFile,
                         aProgressCb    *_pProgressCb /*= nullptr*/)
: CmdBase(ID_FILE_OPEN, "Open File", enumCmdType::CMD_TYPE_NO_UNDO, nullptr, _pProgressCb),
  m_pathFile(_pathFile)
{
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
* CmdOpenFile::prepare
*******************************************************************************/
bool CmdOpenFile::prepare()
{
    m_pPostLS = make_shared<aSynchronized<shared_ptr<LayerStack>>> ();

    return true;
} // CmdOpenFile::prepare


/*******************************************************************************
* CmdOpenFile::execute
*******************************************************************************/
bool CmdOpenFile::execute()
{
    ExclusiveLS pPostLS(*m_pPostLS);

    pPostLS.get() = make_shared<LayerStack> ();

    bool bSuccess = pPostLS.get()->loadFromFile(m_pathFile.canonicalPath());

    if (!bSuccess)
    {
        m_pPostLS = nullptr;
    }

    return bSuccess;
} // CmdOpenFile::execute
