/*******************************************************************************
* \file DocPl.cpp
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
#include "defsPl.h"
#include "docPl.h"
#include "mainWin.h"
#include "cmdBase.h"

using namespace qLib;

/*******************************************************************************
* DocPl::DocPl
*******************************************************************************/
DocPl::DocPl(unique_ptr<qCmdI> _pInitialCmd)
{
    SetCmd(std::move(_pInitialCmd));
} // DocPl::DocPls


/*******************************************************************************
* DocPl::~DocPl
*******************************************************************************/
DocPl::~DocPl()
{
} // DocPl::~DocPl


/*******************************************************************************
* DocPl::ActiveLS
*******************************************************************************/
shared_ptr<qLayerStack> DocPl::ActiveLS() const
{
    CmdBase *pCmd = dynamic_cast<CmdBase *> (ActiveCmd());
    CHECK_PRE_CONDITION(pCmd != nullptr, nullptr);

    return pCmd->PostLS();
} // DocPl::ActiveLS


/*******************************************************************************
* DocPl::OnCmdProcessingStart
*******************************************************************************/
void DocPl::OnCmdProcessingStart(qCmdI */*_pCmd*/)
{
    MainWin &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_CMD_PROCESSING_START);
    mw.SendUpdateCmd(UPDATE_VIEWS_BY_DOC, this);
} // DocPl::OnCmdProcessingStart


/*******************************************************************************
* DocPl::OnCmdProcessingEnd
*******************************************************************************/
void DocPl::OnCmdProcessingEnd(qCmdI */*_pCmd*/)
{
    MainWin &mw = GetMainWin();

    mw.SendUpdateCmd(UPDATE_CMD_PROCESSING_END);
    mw.SendUpdateCmd(UPDATE_VIEWS_BY_DOC, this);
} // DocPl::OnCmdProcessingEnd
