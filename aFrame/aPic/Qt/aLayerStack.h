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
#ifdef _USE_QT_

#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aLayerStack_i.h"

using namespace std;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* \class aLayerStack
*******************************************************************************/
class aLayerStack : public aLayerStackI
{
    private:

    public:
        aLayerStack();

        virtual ~aLayerStack();

        bool                    load(const aPath  &_sFileName) override;

        shared_ptr<QImage>      getQImage() const;


    private:
        bool                    loadRgb_8bit(const QImage &_img);

}; // class aLayerStack


} // namespace aPic
} // namespace aFrame


#endif // _USE_QT_
