/*******************************************************************************
* \file aLayerI.h
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
#include "aLib_def.h"
#include "aMath_def.h"
#include "qPicDefs.h"

#include "aString.h"

#include "aDimension2D.h"
#include "aRect2D.h"

using namespace std;
using namespace aLib::aUtil;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* class aLayerI
*******************************************************************************/
class aLayerI
{
    private:
        enumLayerType           m_eLayerType    { enumLayerType::None };
        aString                 m_sName;
        aRect2D<s32>            m_rctGeometry;
        bool                    m_bVisible      { true };
        dbl                     m_dOpacity      { 1. };


    private:
        aLayerI(const aLayerI &_rhs) = delete;


    protected:
        aLayerI(enumLayerType       _eLayerType,
                aString             _sName,
                const aRect2D<s32>  &_rctGeometry,
                bool                _bVisible   = true,
                dbl                 _dOpacity   = 1.);

        aLayerI(enumLayerType       _eLayerType,
                aString             _sName,
                s32                 _x,
                s32                 _y,
                s32                 _w,
                s32                 _h,
                bool                _bVisible   = true,
                dbl                 _dOpacity   = 1.);

    public:
        virtual ~aLayerI();

        const aRect2D<s32>&             geometry() const;
        aDimension2D<s32>               dimension() const;
        s32								w() const;
        s32								h() const;

        enumLayerType                   layerType() const;

        aString                         name() const;
        void							setName(aString _sLayerName);

        bool                            isVisible() const;
        void                            setVisible(bool _bVisible);

        dbl                             opacity() const;
        void                            setOpacity(dbl  _dOpacity);

        virtual unique_ptr<aLayerI>		createClone(bool _bCopyData) const = 0;

        virtual unique_ptr<aLayerI>		createClone(s32 _s32NewW,
                                                    s32 _s32NewH) const = 0;

        virtual void                    clear() = 0;


    /*******************************************************************************
    * pixel access
    *******************************************************************************/
    public:
        virtual void					pixel(s32       _x,
                                              s32       _y,
                                              aColor    &_qRgba) const = 0;

        virtual void                    setPixel(s32            _x,
                                                 s32            _y,
                                                 const aColor   &_qRgba) = 0;

        virtual void                    setPixel(s32        _x,
                                                 s32        _y,
                                                 color_t    _r,
                                                 color_t    _g,
                                                 color_t    _b,
                                                 color_t    _a) = 0;

}; // class aLayerI


} // namespace aPic
} // namespace aLib
