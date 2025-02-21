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
#include "cmdBase.h"
#include "aPath.h"


/*******************************************************************************
* class CmdOpenFile
*******************************************************************************/
class CmdOpenFile : public CmdBase
{
    private:
        aPath       m_pathFile;

    public:
        CmdOpenFile(aPath           _pathFile,
                    aProgressCb    *_pProgressCb = nullptr);

        virtual ~CmdOpenFile();


    /*******************************************************************************
    * interface of qCmdI
    *******************************************************************************/
    public:
        bool            prepare() override;
        bool            execute() override;

}; // class CmdFileOpen
