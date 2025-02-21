/*******************************************************************************
* \file qButtonBase.inl
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
#include "qButtonBase.h"
#include "qPixmap.h"
#include "qButtonTool.h"


namespace qLib
{
    /*******************************************************************************
    * qButtonBase::qButtonBase
    *******************************************************************************/
    qButtonBase::qButtonBase(qWin  *_pParent,
                             u32   _u32Id)
    : qCtrlBase(_pParent, _u32Id)
	{
    } // qButtonBase::qButtonBase


    /*******************************************************************************
    * qButtonBase::~qButtonBase
    *******************************************************************************/
    qButtonBase::~qButtonBase()
	{
    } // qButtonBase::~qButtonBase


    /*******************************************************************************
    * qButtonBase::OnSysCreate
    *******************************************************************************/
    bool qButtonBase::OnSysCreate()
    {
        // enable mouse tracking for border resize
        SetMouseTracking(true);

        // start the border resize tool
        unique_ptr<qButtonTool> pTool = make_unique<qButtonTool> (this);
        SetTool(std::move(pTool));

        return true;
    } // qButtonBase::OnSysCreate


    /*******************************************************************************
    * qButtonBase::GetPixmap
    *******************************************************************************/
    qPixmap* qButtonBase::GetPixmap() const
    {
        return m_pPixmap.get();
    } // qButtonBase::GetPixmap


    /*******************************************************************************
    * qButtonBase::SetPixmap
    *******************************************************************************/
    void qButtonBase::SetPixmap(const char    *_pRscName)
    {
        m_pPixmap = make_unique<qPixmap> (_pRscName);
    } // qButtonBase::SetPixmap


} // namespace qLib
