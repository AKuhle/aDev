/*******************************************************************************
* \file VarPoolPl.cpp
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
#include "qLib.h"
#include "defsPl.h"
#include "VarPoolPl.h"


using namespace qLib;


/*******************************************************************************
* VarPoolPl::VarPoolPl
*******************************************************************************/
VarPoolPl::VarPoolPl()
: qGuiVarPool()
{
    qPath   pathJson;

    AddVariables();

    // read values from json file
    pathJson = Get_qAppMainWin()->GetProgramPath().ToStdU16String();
    pathJson += qString16("/") + VAR_POOL_FILE_NAME;
    ReadFromJsonFile(pathJson.CanonicalPath());

} // VarPoolPl::VarPoolPl


/*******************************************************************************
* VarPoolPl::~VarPoolPl
*******************************************************************************/
VarPoolPl::~VarPoolPl()
{
    // save the var pool to a json file
    qPath   pathJson;

    pathJson = Get_qAppMainWin()->GetProgramPath().ToStdU16String();
    pathJson += qString16("/") + VAR_POOL_FILE_NAME;

    WriteToJsonFile(pathJson.CanonicalPath());
} // ~VarPoolPl::VarPoolPl


/*******************************************************************************
* VarPoolPl::AddVariables
*******************************************************************************/
void VarPoolPl::AddVariables()
{
    AddEnum<enumSection>(ID_ENUM_SECTION, enumSection::NoCut, enumSection::NoCut);
} // VarPoolPl::AddVariables
