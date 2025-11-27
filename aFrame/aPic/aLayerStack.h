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
#include <QImage>

#include "aFrame_def.h"
#include "aUtil_def.h"

using namespace std;
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
class aLayerStack
{
    private:
        shared_ptr<QImage>      m_pImage   { nullptr };

    public:
        aLayerStack();

        virtual ~aLayerStack();

        bool                    isValid() const;

        bool                    load(const aPath  &_sFileName);

        shared_ptr<QImage>      getQImage() const;
}; // class aMargin


} // namespace aPic
} // namespace aFrame
