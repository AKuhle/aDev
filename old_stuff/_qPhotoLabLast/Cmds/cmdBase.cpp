/*******************************************************************************
* \file cmdBase.cpp
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
CmdBase::CmdBase(const u32                  _u32CmdID,
                 const qString16&           _sCmdName,
                 const enumCmdType          _eCmdType,
                 shared_ptr<qLayerStack>    _pPreLS,
                 qProgress                  *_pProgress /*= nullptr*/)
: qCmdThread(_u32CmdID, _sCmdName, _eCmdType, _pProgress),
  m_pPreLS(_pPreLS)
  //m_pProgressCb(_pProgressCb)
{
} // CmdBase::CmdBase


/*******************************************************************************
* CmdBase::~CmdBase
*******************************************************************************/
CmdBase::~CmdBase()
{
} // CmdBase::~CmdBase


/*******************************************************************************
* CmdBase::PreLS
*******************************************************************************/
shared_ptr<qLayerStack>& CmdBase::PreLS()
{
    return m_pPreLS;
} // CmdBase::PreLS


/*******************************************************************************
* CmdBase::PostLS
*******************************************************************************/
shared_ptr<qLayerStack>& CmdBase::PostLS()
{
    return m_pPostLS;
} // CmdBase::PostLS


/*******************************************************************************
* CmdBase::Prepare
*******************************************************************************/
bool CmdBase::Prepare()
{
    // the default implementation creates a clone with no data of the previous layers
    // clone => same LayerID's, empty Layers
    if (m_pPreLS != nullptr)
    {
        m_pPostLS = m_pPreLS->CreateClone(true, false);
    }

    return true;
} // CmdBase::Prepare


/*******************************************************************************
* CmdBase::Undo
*******************************************************************************/
bool CmdBase::Undo()
{
    return this->CanUndo();
} // CmdBase::Undo


/*******************************************************************************
* CmdBase::Redo
*******************************************************************************/
bool CmdBase::Redo()
{
    return true;
} // CmdBase::Redo


/*******************************************************************************
* CmdBase::OpenProgressDisplay
*******************************************************************************/
// void CmdBase::OpenProgressDisplay(const qString16& _sInfoText) const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->OpenProgressDisplay(_sInfoText);
//     }
// } // CmdBase::OpenProgressDisplay


/*******************************************************************************
* CmdBase::OpenProgressDisplay
*******************************************************************************/
// void CmdBase::OpenProgressDisplay(const qString16&    _sInfoText,
//                                   s64                 _s64MinValue,
//                                   s64                 _s64MaxValue) const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->OpenProgressDisplay(_sInfoText, _s64MinValue, _s64MaxValue);
//     }
// } // CmdBase::OpenProgressDisplay


/*******************************************************************************
* CmdBase::ChangeProgressValues
*******************************************************************************/
// void CmdBase::ChangeProgressValues(s64   _s64MinValue,
//                                    s64   _s64MaxValue,
//                                    s64   _s64CurrentValue) const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->ChangeProgressValues(_s64MinValue, _s64MaxValue, _s64CurrentValue);
//     }
// } // CmdBase::ChangeProgressValues


/*******************************************************************************
* CmdBase::SetProgressValue
*******************************************************************************/
// void CmdBase::SetProgressValue(s64 _s64CurrentValue) const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->SetProgressValue(_s64CurrentValue);
//     }
// } // CmdBase::SetProgressValue


/*******************************************************************************
* CmdBase::IncrementProgressValue
*******************************************************************************/
// void CmdBase::IncrementProgressValue(s64 _s64Step /*= 1*/) const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->IncrementProgressValue(_s64Step);
//     }
// } // CmdBase::IncrementProgressValue


/*******************************************************************************
* CmdBase::CloseProgressDisplay
*******************************************************************************/
// void CmdBase::CloseProgressDisplay() const
// {
//     if (m_pProgressCb != nullptr)
//     {
//         m_pProgressCb->CloseProgressDisplay();
//     }
// } // CmdBase::CloseProgressDisplay
