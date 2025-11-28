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
#include "aLayer_i.h"

using namespace std;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* \class aLayerStackI
*******************************************************************************/
class aLayerStackI
{
    private:
        std::vector<shared_ptr<aLayerI>>    m_vLayer;


    public:
        aLayerStackI();

        virtual ~aLayerStackI();

        bool                    isValid() const;

        void                    addLayer(shared_ptr<aLayerI> _pLayer);

        virtual bool            load(const aPath  &_sFileName) = 0;

}; // class aLayerStackI


} // namespace aPic
} // namespace aFrame
