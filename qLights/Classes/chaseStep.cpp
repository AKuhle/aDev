/*******************************************************************************
* \file ChaseStep.cpp
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
#include "chaseStep.h"

using namespace aFrame;


/*******************************************************************************
* ChaseStep::ChaseStep
*******************************************************************************/
ChaseStep::ChaseStep(shared_ptr<Scene>   /*_pStartScene*/,
                     shared_ptr<Scene>   /*_pEndScene*/,
                     u32                 _u32Duration_ms)
: m_u32Duration_ms(_u32Duration_ms)
{
} // ChaseStep::ChaseStep


/*******************************************************************************
* ChaseStep::~ChaseStep
*******************************************************************************/
ChaseStep::~ChaseStep()
{
} // ChaseStep::~ChaseStep
