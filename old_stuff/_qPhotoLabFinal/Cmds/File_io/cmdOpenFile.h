/*******************************************************************************
* \file cmdOpenFile.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "cmdPL.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace std;
using namespace qLib;

class DocPl;


/*******************************************************************************
* class CmdOpenFile
*******************************************************************************/
class CmdOpenFile : public CmdPL
{
    private:
        qString16           m_sFileName;

    public:
        CmdOpenFile(qString16   _sFileName,
                    qProgress   *_pProgress);

        virtual ~CmdOpenFile();


    /*******************************************************************************
    * interface of qCmdI
    *******************************************************************************/
    public:
        virtual bool        Prepare() override;
        virtual bool        Do() override;
}; // class CmdFileOpen
