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
#include "qApp_i.h"

// Collection
#include "qList.h"
#include "qMap.h"
#include "qPtrList.h"
#include "qSharedPtrDeque.h"
#include "qUniquePtrDeque.h"
#include "qSharedPtrList.h"
#include "qUniquePtrList.h"
#include "qUniquePtrVec.h"
#include "qVec.h"

// Classes
#include "qFile.h"
#include "qIoDevice.h"
#include "qLog.h"
#include "qProgress.h"
#include "qMargin.h"
#include "qRgba.h"
#include "qString16.h"
#include "qThreadCb.h"
#include "qVersion.h"

// Qt-Classes
#include "qJsonValue.h"
#include "qJsonFile.h"
#include "qPath.h"
#include "qThread.h"
#include "qUrl.h"

// Cmd
#include "qCmd_i.h"
#include "qCmdMgr.h"
#include "qCmdStack.h"
#include "qCmdThread.h"

// VarPool
#include "qPoolVar_I.h"
#include "qPoolVarBool.h"
#include "qPoolVarS32.h"
#include "qBaseVarPool.h"
