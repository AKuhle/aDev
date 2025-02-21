/*******************************************************************************
* \file Document.h
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
#include "aLib_def.h"
#include "aUtil/aUtil_def.h"

#include "aDoc.h"
#include "aLayerStack.h"
#include "aCmdStack.h"
#include "cmdBase.h"


using namespace std;
using namespace aLib::aUtil;
using namespace aLib::aWin;
using namespace aLib::aPic;


/*******************************************************************************
* class Document
*******************************************************************************/
class Document : public aDoc,
                 public aCmdStack
{
    public:
        Document(shared_ptr<CmdBase> _pInitialCmd);
        virtual ~Document();

        shared_ptr<SynchronizedLS>  activeLS() const;


    /*******************************************************************************
    * interface of aCmdManager
    *******************************************************************************/
    protected:
        void                        onCmdProcessingStart(const shared_ptr<aCmdBase> &_pCmd) override;
        void                        onCmdProcessingEnd(const shared_ptr<aCmdBase> &_pCmd) override;

}; // class Document
