/*******************************************************************************
* \file qLib.h
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
* namespace
*******************************************************************************/


/*******************************************************************************
* all classes
*******************************************************************************/
// Collection
#include "Collection/collectionDefs.h"
#include "Collection/qUniquePtrList.h"

// Math
#include "Math/mathDefs.h"
#include "Math/qDimension2D.h"
#include "Math/qVector2D.h"
#include "Math/qRect2D.h"

// Object
#include "Object/objectDefs.h"
#include "Object/qColor.h"
#include "Object/qMargin.h"
#include "Object/qString16.h"
#include "Object/qVersionInfo.h"

#include "Object/Value/qValue_bool.h"
#include "Object/Value/qValue_s32.h"
#include "Object/Value/qValue_u32.h"
#include "Object/Value/qValue_dbl.h"

// Graphic
#include "Graphic/graphicDefs.h"
#include "Graphic/qPainter.h"
#include "Graphic/qPen.h"
#include "Graphic/qFillSolid.h"
#include "Graphic/qBorderSolid.h"

// Tool
#include "Tool/toolDefs.h"

// Application
#include "Application/applicationDefs.h"
#include "Application/main.h"
#include "Application/qAppMainWin.h"

// Win
#include "Win/winDefs.h"

#include "Win/Layout/qLayoutObj.h"

#include "Win/WinStyle/qWinStyle.h"
#include "Win/WinStyle/qWinStyleFactory_dark.h"

#include "Win/FrameWin/qMainWinMdi.h"
