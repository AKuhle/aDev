/*******************************************************************************
* \file qMdiWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMdiWin.h"
#include "qMdiChild.h"


namespace qLib
{
    /*******************************************************************************
    * qMdiWin::qMdiWin
    *******************************************************************************/
    qMdiWin::qMdiWin(qWin  *_pParent  /* = nullptr */)
    : qWin(_pParent)
    {
    } // qMdiWin::qMdiWin


    /*******************************************************************************
    * qMdiWin::~qMdiWin
    *******************************************************************************/
    qMdiWin::~qMdiWin()
    {
    } // qMdiWin::~qMdiWin


    /*******************************************************************************
    * qMdiWin::AddMdiChild
    *******************************************************************************/
    void qMdiWin::AddMdiChild(qMdiChild *_pChild)
    {
        _pChild->SetParent(this);

        m_lstChilds.push_front(_pChild);

        ActivateMdiChild(_pChild);
    } // qMdiWin::AddMdiChild


    /*******************************************************************************
    * qMdiWin::ActivateMdiChild
    *******************************************************************************/
    void qMdiWin::ActivateMdiChild(qMdiChild *_pChild)
    {
        for (qMdiChild *pChild : m_lstChilds)
        {
            pChild->Activate(pChild == _pChild);
        }
    } // qMdiWin::ActivateMdiChild

} // namespace qLib
