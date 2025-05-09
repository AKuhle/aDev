/*******************************************************************************
* \file Document.cpp
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
#include "photoLab_defs.h"
#include "mainWin.h"
#include "document.h"


/*******************************************************************************
* Document::Document
*******************************************************************************/
Document::Document(shared_ptr<CmdBase> _pInitialCmd)
{
    setCmd(std::move(_pInitialCmd));
} // Document::Documents


/*******************************************************************************
* Document::~Document
*******************************************************************************/
Document::~Document()
{
} // Document::~Document


/*******************************************************************************
* Document::activeLS
*******************************************************************************/
shared_ptr<SynchronizedLS> Document::activeLS() const
{
    CmdBase *pCmd = dynamic_cast<CmdBase *> (activeCmd());
    CHECK_PRE_CONDITION(pCmd != nullptr, nullptr);

    return pCmd->postLS();
} // Document::activeLS


/*******************************************************************************
* Document::onCmdProcessingStart
*******************************************************************************/
void Document::onCmdProcessingStart(const shared_ptr<aCmdBase> &/*_pCmd*/)
{
    MainWin &mw = getMainWin();

    mw.sendUpdateCmd(UPDATE_CMD_PROCESSING_START);
} // Document::onCmdProcessingStart


/*******************************************************************************
* Document::onCmdProcessingEnd
*******************************************************************************/
void Document::onCmdProcessingEnd(const shared_ptr<aCmdBase> &/*_pCmd*/)
{
    MainWin &mw = getMainWin();

    mw.sendUpdateCmd(UPDATE_CMD_PROCESSING_END);
    mw.sendUpdateCmd(UPDATE_VIEWS_BY_DOC, this);
} // Document::onCmdProcessingEnd
