/*******************************************************************************
* \file qViewBase.cpp
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
#include "qViewBase.h"


namespace qLib
{
    /*******************************************************************************
    * qViewBase::qViewBase
    *******************************************************************************/
    qViewBase::qViewBase(qWin * _pParent)
    : qWin(_pParent)
    {
    } // qViewBase::qViewBase


    /*******************************************************************************
    * qViewBase::qViewBase
    *******************************************************************************/
    qViewBase::qViewBase(qWin                               *_pParent,
                         const std::shared_ptr<qDocBase>    &_pDoc)
    : qWin(_pParent),
      m_pDoc(_pDoc)
    {
    } // qViewBase::qViewBase


    /*******************************************************************************
    * qViewBase::~qViewBase
    *******************************************************************************/
    qViewBase::~qViewBase()
    {
    } // qViewBase::~qViewBase

} // namespace qLib
