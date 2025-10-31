/*******************************************************************************
* \file Fixture.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QString>
#include "aFrame_def.h"

class Scene;

using namespace std;
using namespace aFrame;



/*******************************************************************************
* class ChaseStep
*******************************************************************************/
class ChaseStep
{
    private:
        u32                 m_u32Duration_ms    { 0 };

    public:
        ChaseStep(shared_ptr<Scene>   _pStartScene,
                  shared_ptr<Scene>   _pEndScene,
                  u32                 _u32Duration_ms);
        ~ChaseStep();
}; // class ChaseStep
