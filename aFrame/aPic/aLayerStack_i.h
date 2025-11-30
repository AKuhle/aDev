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

#include "aPic_def.h"
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
    protected:
        enumLayerFormat                     m_eLayerFormat  { enumLayerFormat::None };
        s32                                 m_s32W          { 0 };
        s32                                 m_s32H          { 0 };
        std::vector<shared_ptr<aLayerI>>    m_vLayer;


    public:
        aLayerStackI(enumLayerFormat _eLayerFormat,
                     s32             _s32W,
                     s32             _s32H);
        virtual ~aLayerStackI();

        bool                    isValid() const;

        enumLayerFormat         layerFormat() const   { return m_eLayerFormat; }

        void                    addLayer(shared_ptr<aLayerI> _pLayer);

        virtual bool            load(const aPath  &_sFileName) = 0;

}; // class aLayerStackI


} // namespace aPic
} // namespace aFrame
