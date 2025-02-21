/*******************************************************************************
* \file qLayerStack.h
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
#include "qPicDefs.h"
#include "qUniquePtrList.h"
#include "qString16.h"
#include "qDimension2D.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    using namespace std;

    class qString16;
    class qLayerI;


    /*******************************************************************************
    * class qLayerStack
    *******************************************************************************/
    class qLayerStack :  public qUniquePtrList<qLayerI>
	{
        // front() is the background layer, which defines
        // the basic layerformat of this stack

        protected:
            enumLayerType       m_eType      { enumLayerType::None };
            qDimension2D<s32>   m_d2dDimension;
            qString16           m_sName;   // e.g. the filename

        public:
            qLayerStack();
            //qLayerStack(const qLayerStack& _rhs);
            virtual ~qLayerStack();

            shared_ptr<qLayerStack>     CreateClone(bool    _bSameLayerID,
                                                    bool    _bCopyImageData) const;

            shared_ptr<qLayerStack>     CreateCloneSwapWH(bool _bSameLayerID) const;

            enumLayerType               Type() const;
            void                        SetType(enumLayerType  _eType);

            qDimension2D<s32>           Dimension() const;
            void                        SetDimension(const qDimension2D<s32> &_s2dDim);
            void                        SetDimension(s32        _s32W,
                                                     s32        _s32H);

            s32                         w() const;
            s32                         h() const;

            qString16                   Name() const;
            void                        SetName(const qString16& _sName);

            bool                        IsValid() const;

            void                        RemoveAllLayers();
            void                        AddLayer(unique_ptr<qLayerI> _pLayer);
            qLayerI*                    FindLayer(u32   _u32LayerID);

        public:
            bool                        LoadFromFile(const qString16    &_sFileName);
                                                     //qProgress*         _pProgressCb = nullptr);
    }; // class qLayerStack

} // namespace qLib
