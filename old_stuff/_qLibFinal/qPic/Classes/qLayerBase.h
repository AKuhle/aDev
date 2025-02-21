/*******************************************************************************
* \file qLayerBase.h
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

    class qColor;


    /*******************************************************************************
    * class qLayerBase
    *******************************************************************************/
    class qLayerBase
	{
        //friend class qLayerGrayscale16;
        //friend class qLayerGrayscale8;
        //friend class qLayerRgb16;
        //friend class qLayerRgb8;

        private:
            static u32                  m_u32NextId;

            u32                         m_u32Id         { 0 };
            enumLayerType               m_eType         { enumLayerType::None };
            qRect2D<s32>                m_rctGeometry;
            bool                        m_bVisible      { true };
            dbl                         m_dOpacity      { 1. };
            qString16                   m_sName;


        protected:
            qLayerBase(const qLayerBase &_rhs) = delete;

            qLayerBase(enumLayerType        _eType,
                       const qRect2D<s32>   &_rct);			// => new qLayerBase for new Layer

        public:
            virtual ~qLayerBase();

        //void                            CloneqLayerBase_WoImageData(qLayerBase   *pSrc);

        public:
            u32                             GetId() const;
            enumLayerType                   Type() const;

            const qRect2D<s32>&             GetGeometry() const;
            qDimension2D<s32>               GetDimension() const;
            s32								w() const;
            s32								h() const;

            qString16                       Name() const;
            void							SetName(qString16 _sLayerName);

            // clone: same qLayerBaseD's, Layers copies also the image data on demand
            virtual unique_ptr<qLayerBase>  CreateClone(bool    _bSameID,
                                                        bool    _bCopyData) const = 0;

            // clone: same qLayerBaseD's, empty Layers, different size
            virtual unique_ptr<qLayerBase>	CreateCloneSwapWH(bool    _bSameID) const = 0;

            void                            CloneBaseData(const qLayerBase &_pRhs,
                                                          bool          _bSameID);

            bool                            Visible() const;
            void                            SetVisible(bool _bVisible);

            dbl                             GetOpacity() const;
            void                            SetOpacity(dbl  _dOpacity);

            virtual void                    Clear() = 0;


        /*******************************************************************************
        * pixel access
        *******************************************************************************/
		public:
            virtual void					Pixel(s32       _s32X,
                                                  s32       _s32Y,
                                                  qColor    &_col) const = 0;

            virtual void                    SetPixel(s32            _s32X,
                                                     s32            _s32Y,
                                                     const qColor   &_col) = 0;

            virtual void                    SetPixel(s32    _s32X,
                                                     s32    _s32Y,
                                                     Rgba_t _r,
                                                     Rgba_t _g,
                                                     Rgba_t _b,
                                                     Rgba_t _a) = 0;

    }; // class qLayerBase

} // namespace qLib
