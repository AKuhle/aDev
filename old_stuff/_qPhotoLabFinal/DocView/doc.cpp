/*******************************************************************************
* \file Doc.cpp
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
//#include "defsPl.h"
#include "doc.h"
//#include "mainWin.h"
//#include "cmdBase.h"

using namespace qLib;


/*******************************************************************************
* Doc::Doc
*******************************************************************************/
Doc::Doc(unique_ptr<qCmdBase> _pInitialCmd)
{
    SetCmd(std::move(_pInitialCmd));
} // Doc::Docs


/*******************************************************************************
* Doc::~Doc
*******************************************************************************/
Doc::~Doc()
{
} // Doc::~Doc


/*******************************************************************************
* Doc::GetActiveLS
*******************************************************************************/
shared_ptr<qLayerStack> Doc::GetActiveLS() const
{
    CmdPL *pCmd = dynamic_cast<CmdPL *> (GetActiveCmd());
    CHECK_PRE_CONDITION(pCmd != nullptr, nullptr);

    return pCmd->GetPostLS();
} // Doc::GetActiveLS


/*******************************************************************************
* Doc::OnCmdProcessingStart
*******************************************************************************/
// void Doc::OnCmdProcessingStart(qCmdI */*_pCmd*/)
// {
//     MainWin &mw = GetMainWin();

//     mw.SendUpdateCmd(UPDATE_CMD_PROCESSING_START);
//     mw.SendUpdateCmd(UPDATE_VIEWS_BY_Doc, this);
// } // Doc::OnCmdProcessingStart


/*******************************************************************************
* Doc::OnCmdProcessingEnd
*******************************************************************************/
// void Doc::OnCmdProcessingEnd(qCmdI */*_pCmd*/)
// {
//     MainWin &mw = GetMainWin();

//     mw.SendUpdateCmd(UPDATE_CMD_PROCESSING_END);
//     mw.SendUpdateCmd(UPDATE_VIEWS_BY_Doc, this);
// } // Doc::OnCmdProcessingEnd
