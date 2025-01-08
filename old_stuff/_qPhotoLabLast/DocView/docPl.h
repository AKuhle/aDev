/*******************************************************************************
* \file DocPl.h
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
#include "qLib.h"
#include "cmdBase.h"

using namespace std;
using namespace qLib;


/*******************************************************************************
* class DocPl
*******************************************************************************/
class DocPl : public qDocI,
              public qCmdStack
{
    public:
        DocPl(unique_ptr<qCmdI> _pInitialCmd);
        virtual ~DocPl();

        shared_ptr<qLayerStack>     ActiveLS() const;


    /*******************************************************************************
    * interface of aCmdManager
    *******************************************************************************/
    protected:
        virtual void                OnCmdProcessingStart(qCmdI *_pCmd) override;
        virtual void                OnCmdProcessingEnd(qCmdI *_pCmd) override;

}; // class DocPl
