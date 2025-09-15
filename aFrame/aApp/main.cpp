/*******************************************************************************
* \file main.cpp
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
#include "aFrame_def.h"

#include "aAppBase.h"

using namespace std;
using namespace aFrame::aApp;


/*******************************************************************************
* main
*******************************************************************************/
#ifndef __NO_FRAME_main__

int main(int	_argc,
         char   *_argv[],
         char	**_envp)
{
    int					iResult = -1;


    if (aAppBase::instance() == nullptr)
    {
        //qLog::Error("Error: No Application defined");
        std::cout << "Error: No Application defined" << std::endl;
        iResult = system("PAUSE");
    }
    else
    {
        iResult = aAppBase::instance()->createFromMain(_argc, _argv, _envp);
    }

    return iResult;
} // main

#endif
