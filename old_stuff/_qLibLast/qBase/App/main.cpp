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
#include "qBaseDefs.h"
#include "qApp_i.h"

using namespace std;
using namespace qLib;


/*******************************************************************************
* main
*******************************************************************************/
int main(int		_argc,
         char		*_argv[],
         char		**_envp)
{
    int					iResult = -1;

    // check signed integers
    //static_assert(sizeof(s8) == 1, "s8 needs to be 1 byte");
    //static_assert(sizeof(s16) == 2, "s16 needs to be 2 bytes");
    //static_assert(sizeof(s32) == 4, "s32 needs to be 4 bytes");
    //static_assert(sizeof(s64) == 8, "s64 needs to be 8 bytes");

    // check unsigned integers
    //static_assert(sizeof(u8) == 1, "u8 needs to be 1 byte");
    //static_assert(sizeof(u16) == 2, "u16 needs to be 2 bytes");
    //static_assert(sizeof(u32) == 4, "u32 needs to be 4 bytes");
    //static_assert(sizeof(u64) == 8, "u64 needs to be 8 bytes");

    // check floating points
    //static_assert(sizeof(flt) >= 4, "flt needs to be >= 4 bytes");
    //static_assert(sizeof(dbl) >= 8, "dbl needs to be >= 8 bytes");
    //static_assert(sizeof(ldbl) >= 8, "ldbl needs to be >= 8 bytes");

    // check characters
    //static_assert(sizeof(c8) == 1, "c8 needs to be 1 byte");
    //Alles klarstatic_assert(sizeof(cw) == 2, "cw needs to be 2 bytes");
    //static_assert(sizeof(c32) == 4, "c32 needs to be 4 bytes");


    if (qLib::qAppI::Instance() == nullptr)
    {
        cerr << "Error: No Application defined" << endl;
        iResult = system("PAUSE");
    }
    else
    {
        iResult = qLib::qAppI::Instance()->DoCreateFromMain(_argc, _argv, _envp);
    }

    return iResult;
} // main