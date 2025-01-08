/*******************************************************************************
* \file Doc.h
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
#include "cmdPL.h"

using namespace std;
using namespace qLib;

class CmdPL;

/*******************************************************************************
* class Doc
*******************************************************************************/
class Doc : public qDocBase,
            public qCmdStack
{
    public:
        Doc(unique_ptr<qCmdBase> _pInitialCmd);
        virtual ~Doc();

        shared_ptr<qLayerStack>     GetActiveLS() const;


    /*******************************************************************************
    * interface of aCmdManager
    *******************************************************************************/
    protected:
        //virtual void                OnCmdProcessingStart(qCmdI *_pCmd) override;
        //virtual void                OnCmdProcessingEnd(qCmdI *_pCmd) override;

}; // class Doc
