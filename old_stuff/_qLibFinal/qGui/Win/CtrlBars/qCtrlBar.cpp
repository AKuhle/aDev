/*******************************************************************************
* \file qCtrlBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qCtrlBar.h"
#include "qLayoutHoriVert.h"


namespace qLib
{
    /*******************************************************************************
    * qCtrlBar::qCtrlBar
    *******************************************************************************/
    qCtrlBar::qCtrlBar(qWin  *_pParent  /* = nullptr */)
    : qCtrlBarBase(_pParent)
    {
    } // qCtrlBar::qCtrlBar


    /*******************************************************************************
    * qCtrlBar::~qCtrlBar
    *******************************************************************************/
    qCtrlBar::~qCtrlBar()
    {
    } // qCtrlBar::~qCtrlBar


    /*******************************************************************************
    * qCtrlBar::OnCreate
    *******************************************************************************/
    bool qCtrlBar::OnCreate()
    {
        // create the layout
        unique_ptr<qLayoutHoriVert> pLayout = make_unique<qLayoutHoriVert> ();

        // move the layout to the base class
        SetLayout(std::move(pLayout));

        return true;
    } // qCtrlBar::OnCreate

} // namespace qLib
