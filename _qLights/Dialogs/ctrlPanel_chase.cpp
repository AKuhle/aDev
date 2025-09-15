/*******************************************************************************
* \file CtrlPanel.cpp
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
#include "ctrlPanel.h"
#include "chase.h"


/*******************************************************************************
* CtrlPanel::saveChase
*******************************************************************************/
void CtrlPanel::saveChase(s32       _s32ChaseBtnIdx,
                          aString   _sChaseName)
{
    auto    pChaseBtn   = std::get<0> (m_vChaseTuples.at(_s32ChaseBtnIdx));
    auto    &pChase     = std::get<1> (m_vChaseTuples.at(_s32ChaseBtnIdx));

    // set the chase name
    pChaseBtn->setText(_sChaseName);

    // create the chase
    pChase = make_shared<Chase> (_sChaseName);


} // CtrlPanel::saveChase
