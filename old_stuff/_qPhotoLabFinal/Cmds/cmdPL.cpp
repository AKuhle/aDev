/*******************************************************************************
* \file CmdPL.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "cmdPL.h"


/*******************************************************************************
* CmdPL::CmdPL
*******************************************************************************/
CmdPL::CmdPL(const u32                  _u32CmdID,
             const qString16            &_sCmdName,
             const enumCmdType          _eCmdType,
             shared_ptr<qLayerStack>    _pPreLS,
             qProgress                  *_pProgress /*= nullptr*/)
: qCmdThread(_u32CmdID, _sCmdName, _eCmdType, _pProgress),
  m_pPreLS(_pPreLS)
{
} // CmdPL::CmdPL


/*******************************************************************************
* CmdPL::~CmdPL
*******************************************************************************/
CmdPL::~CmdPL()
{
} // CmdPL::~CmdPL


/*******************************************************************************
* CmdPL::GetPreLS
*******************************************************************************/
shared_ptr<qLayerStack>& CmdPL::GetPreLS()
{
    return m_pPreLS;
} // CmdPL::GetPreLS


/*******************************************************************************
* CmdPL::GetPreLS
*******************************************************************************/
const shared_ptr<qLayerStack>& CmdPL::GetPreLS() const
{
    return m_pPreLS;
} // CmdPL::GetPreLS


/*******************************************************************************
* CmdPL::GetPostLS
*******************************************************************************/
shared_ptr<qLayerStack>& CmdPL::GetPostLS()
{
    return m_pPostLS;
} // CmdPL::GetPostLS


/*******************************************************************************
* CmdPL::GetPostLS
*******************************************************************************/
const shared_ptr<qLayerStack>& CmdPL::GetPostLS() const
{
    return m_pPostLS;
} // CmdPL::GetPostLS


/*******************************************************************************
* CmdPL::Prepare
*******************************************************************************/
bool CmdPL::Prepare()
{
    // the default implementation creates a clone with no data of the previous layers
    // clone => same LayerID's, empty Layers
    if (m_pPreLS != nullptr)
    {
        m_pPostLS = m_pPreLS->CreateClone(true, false);
    }

    return true;
} // CmdPL::Prepare


/*******************************************************************************
* CmdPL::Undo
*******************************************************************************/
bool CmdPL::Undo()
{
    return this->CanUndo();
} // CmdPL::Undo


/*******************************************************************************
* CmdPL::Redo
*******************************************************************************/
bool CmdPL::Redo()
{
    return true;
} // CmdPL::Redo
