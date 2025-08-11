/*******************************************************************************
* \file aStyleItemBorder.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aStyleItemBorder.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aMainWin.h"

using namespace std;


/**************************V*****************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aStyleItemBorder::aStyleItemBorder
*******************************************************************************/
aStyleItemBorder::aStyleItemBorder(const aMargin  &_margin,
                                   const aColor   &_col)
: m_margin(_margin),
  m_color(_col)
{
} // aStyleItemBorder::aStyleItemBorder


/*******************************************************************************
* aStyleItemBorder::~aStyleItemBorder
*******************************************************************************/
aStyleItemBorder::~aStyleItemBorder()
{
} // aStyleItemBorder::~aStyleItemBorder


} // namespace aWin
} // namespace aFrame
