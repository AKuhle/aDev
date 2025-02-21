/*******************************************************************************
* \file qLayerI.h
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
#include "qBaseDefs.h"
#include "qPicDefs.h"
#include "qRect2D.h"
#include "qDimension2D.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    using namespace std;

    class qRgba;


    /*******************************************************************************
    * class qLayerI
    *******************************************************************************/
    class qLayerI
	{
        //friend class qLayerGrayscale16;
        //friend class qLayerGrayscale8;
        //friend class qLayerRgb16;
        //friend class qLayerRgb8;

        private:
            static u32                  m_u32NextId;

            u32                         m_u32Id         { 0 };
            qRect2D<s32>                m_rctGeometry;
            bool                        m_bVisible      { true };
            dbl                         m_dOpacity      { 1. };
            qString16                   m_sName;


        protected:
            qLayerI(const qLayerI &_rhs) = delete;

            qLayerI(const qRect2D<s32> &_rct);			// => new qLayerID for new Layer

        public:
            virtual ~qLayerI();

        //void                            CloneqLayerI_WoImageData(qLayerI   *pSrc);

        public:
            virtual enumLayerType           Type() const = 0;

            u32								Id() const;
            void							SetId(u32 _u32ID);

            const qRect2D<s32>&             Geometry() const;
            qDimension2D<s32>               Dimension() const;
            s32								w() const;
            s32								h() const;

            qString16                       Name() const;
            void							SetName(qString16 _sLayerName);

            // clone: same qLayerID's, Layers copies also the image data on demand
            virtual unique_ptr<qLayerI>		CreateClone(bool    _bSameID,
                                                        bool    _bCopyData) const = 0;

            // clone: same qLayerID's, empty Layers, different size
            virtual unique_ptr<qLayerI>		CreateCloneSwapWH(bool    _bSameID) const = 0;

            void                            CloneBaseData(const qLayerI &_pRhs,
                                                          bool          _bSameID);

            bool                            Visible() const;
            void                            SetVisible(bool _bVisible);

            dbl                             Opacity() const;
            void                            SetOpacity(dbl  _dOpacity);

            virtual void                    Clear() = 0;


        /*******************************************************************************
        * pixel access
        *******************************************************************************/
		public:
            virtual void					Pixel(s32   _s32X,
                                                  s32   _s32Y,
                                                  qRgba &_qRgba) const = 0;

            virtual void                    SetPixel(s32            _s32X,
                                                     s32            _s32Y,
                                                     const qRgba    &_qRgba) = 0;

            virtual void                    SetPixel(s32    _s32X,
                                                     s32    _s32Y,
                                                     Rgba_t _r,
                                                     Rgba_t _g,
                                                     Rgba_t _b,
                                                     Rgba_t _a) = 0;

    }; // class qLayerI

} // namespace qLib
