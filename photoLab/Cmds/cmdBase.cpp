/*******************************************************************************
* \file CmdBase.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "cmdBase.h"


/*******************************************************************************
* CmdBase::CmdBase
*******************************************************************************/
CmdBase::CmdBase(const u32                  _u32ID,
                 const aString              &_sName,
                 const enumCmdType          _eType,
                 shared_ptr<SynchronizedLS> _pPreLS,
                 aProgressCb                *_pProgressCb)
: aCmdThread(_u32ID, _sName, _eType),
  m_pPreLS(_pPreLS)
{
    setProgressCb(_pProgressCb);
} // CmdBase::CmdBase


/*******************************************************************************
* CmdBase::~CmdBase
*******************************************************************************/
CmdBase::~CmdBase()
{
} // CmdBase::~CmdBase


/*******************************************************************************
* CmdBase::preLS
*******************************************************************************/
shared_ptr<SynchronizedLS>& CmdBase::preLS()
{
    return m_pPreLS;
} // CmdBase::preLS


/*******************************************************************************
* CmdBase::preLS
*******************************************************************************/
const shared_ptr<SynchronizedLS>& CmdBase::preLS() const
{
    return m_pPreLS;
} // CmdBase::preLS


/*******************************************************************************
* CmdBase::postLS
*******************************************************************************/
shared_ptr<SynchronizedLS>& CmdBase::postLS()
{
    return m_pPostLS;
} // CmdBase::postLS


/*******************************************************************************
* CmdBase::postLS
*******************************************************************************/
const shared_ptr<SynchronizedLS>& CmdBase::postLS() const
{
    return m_pPostLS;
} // CmdBase::postLS


/*******************************************************************************
* CmdBase::prepare
*******************************************************************************/
bool CmdBase::prepare()
{
    // the default implementation creates a clone with no data of the previous layers
    if (m_pPreLS != nullptr)
    {
        SharedLS        pPreLS(*m_pPreLS);

        m_pPostLS = make_shared<aSynchronized<shared_ptr<LayerStack>>> ();
        ExclusiveLS     pPostLS(*m_pPostLS);

        pPostLS.get() = make_shared<LayerStack> ();
        pPostLS.get()->createClone(pPreLS.get(), false);
    }

    return true;
} // CmdBase::prepare


/*******************************************************************************
* CmdBase::undo
*******************************************************************************/
bool CmdBase::undo()
{
    return this->canUndo();
} // CmdBase::undo


/*******************************************************************************
* CmdBase::redo
*******************************************************************************/
bool CmdBase::redo()
{
    return true;
} // CmdBase::redo
