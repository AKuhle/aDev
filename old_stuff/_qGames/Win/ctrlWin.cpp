/*******************************************************************************
* \file CtrlWin.cpp
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
#include "qGamesDefs.h"

#include "ctrlWin.h"
#include "qLayoutHoriVert.h"
#include "qLabel.h"
#include "qSpacer.h"


using namespace qLib;



/*******************************************************************************
* CtrlWin::CtrlWin
*******************************************************************************/
CtrlWin::CtrlWin()
{
} // CtrlWin::CtrlWin


/*******************************************************************************
* CtrlWin::~CtrlWin
*******************************************************************************/
CtrlWin::~CtrlWin()
{
} // ~CtrlWin::CtrlWin


/*******************************************************************************
* CtrlWin::OnCreate
*******************************************************************************/
bool CtrlWin::OnCreate()
{
    qSpacer *pSpacer;

    // create the layout
    unique_ptr<qLayoutHoriVert> pHori1 = make_unique<qLayoutHoriVert> ();

    // team-row
    m_pLblTeam1 = new qLabel(this, LBL_TEAM_1);
    m_pLblTeam1->CreateWin();
    pHori1->AddChild(m_pLblTeam1);

    pSpacer = new qSpacer(this);
    pSpacer->CreateWin();
    pHori1->AddChild(pSpacer);

    m_pLblTeam2 = new qLabel(this, LBL_TEAM_2);
    m_pLblTeam2->CreateWin();
    pHori1->AddChild(m_pLblTeam2);

    // set the layout
    SetLayout(std::move(pHori1));

    return true;
} // CtrlWin::OnCreate


/*******************************************************************************
* CtrlWin::OnClose
*******************************************************************************/
bool CtrlWin::OnClose()
{
    return true;
} // CtrlWin::OnClose
