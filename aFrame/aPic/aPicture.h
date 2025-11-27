/*******************************************************************************
* \file aMargin.h
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
#include "aFrame_def.h"
#include "aUtil_def.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* \class aMargin
* \brief baseclass for 2D math objects
*******************************************************************************/
class aPicture
{
    private:

    public:
        aPicture();

        aPicture(const aString  &_sFileName);

        virtual ~aPicture();


    private:
        void            openFile(const aString  &_sFileName);
}; // class aMargin


} // namespace aPic
} // namespace aFrame
