/*******************************************************************************
* \file qBase.h
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
* qBase defines
*******************************************************************************/
#include "qBaseDefs.h"


/*******************************************************************************
* qBase includes
*******************************************************************************/
#include "main.h"

#include "qList.h"
#include "qMap.h"
#include "qPtrList.h"
#include "qSharedPtrDeque.h"
#include "qSharedPtrList.h"
#include "qUniquePtrDeque.h"
#include "qUniquePtrList.h"
#include "qUniquePtrVec.h"
#include "qVec.h"

// classes
#include "qFile.h"
#include "qIoDevice.h"
#include "qJsonValue.h"
#include "qLog.h"
#include "qPath.h"
#include "qProgress.h"
#include "qColor.h"
#include "qString16.h"
#include "qThreadCb.h"
// classes/Qt
#include "qThread.h"
#include "qUrl.h"

#include "qCmdBase.h"
#include "qCmd.h"
#include "qCmdThread.h"
#include "qCmdMgr.h"
#include "qCmdStack.h"

// VarPool
#include "qPoolVar_i.h"

#include "qPoolVarBool.h"
#include "qPoolVarS32.h"
#include "qPoolVarDbl.h"
#include "qPoolVarColor.h"
#include "qBaseVarPool.h"

#include "qAppBase.h"
